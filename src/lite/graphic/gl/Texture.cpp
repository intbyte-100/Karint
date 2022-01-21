#include "Texture.h"
#include "lite/graphic/gl/gl.h"
#include "glad/glad.h"
#include "stb_image.h"

#include "lite/util/FileNotFoundException.h"

void lite::Texture::dispose() {
    glDeleteTextures(1, &id);
}

void lite::Texture::setImage(int mipmapLevel, int sourceChanel, int glChanel, int width, int height, unsigned char *image) {
    glTexImage2D(GL_TEXTURE_2D, mipmapLevel, sourceChanel, width, height, 0, glChanel, GL_UNSIGNED_BYTE, image);
}

void lite::Texture::setParameter(int type, int value) {
    glTexParameteri(GL_TEXTURE_2D, type, value);
}

void lite::Texture::generateMipmap() {
    glGenerateMipmap(GL_TEXTURE_2D);
}

void lite::Texture::bind() {
    glBindTexture(GL_TEXTURE_2D, id);
}

void lite::Texture::bind(char activeTextureIndex) {
    bind();
    activeTexture(activeTextureIndex);
}

void lite::Texture::create() {
    glGenTextures(1, &id);
}

lite::Texture lite::Texture::load(const std::string &file) {
    int width;
    int height;
    int channels;
    auto *image = stbi_load(file.c_str(), &width, &height, &channels, 0);

    if (image == nullptr) {
        throw FileNotFoundException("file " + file + " is not found");
    }

    Texture texture;
    texture.create();

    texture.bind();
    channels = (channels == 3) ? GL_RGB : GL_RGBA;

    texture.setImage(0, channels, channels, width, height, image);

    texture.setParameter(TEXTURE_WRAP_X, REPEAT);
    texture.setParameter(TEXTURE_WRAP_Y, REPEAT);
    texture.setParameter(TEXTURE_MIN_FILTER, LINEAR_MIPMAP_NEAREST);
    texture.setParameter(TEXTURE_MAG_FILTER, NEAREST);

    texture.generateMipmap();
    stbi_image_free(image);
    return texture;
}
