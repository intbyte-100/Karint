#include "Texture.h"
#include "karint/graphic/gl/gl.h"
#include "glad/glad.h"
#include "stb_image.h"

#include "karint/util/FileNotFoundException.h"
#include "gl.h"

void karint::Texture::dispose() {
    glDeleteTextures(1, &id);
}

void karint::Texture::setImage(int mipmapLevel, int sourceChanel, int glChanel, int width, int height, unsigned char *image) {
    glTexImage2D(GL_TEXTURE_2D, mipmapLevel, sourceChanel, width, height, 0, glChanel, GL_UNSIGNED_BYTE, image);
}

void karint::Texture::setParameter(int type, int value) {
    glTexParameteri(GL_TEXTURE_2D, type, value);
}

void karint::Texture::generateMipmap() {
    glGenerateMipmap(GL_TEXTURE_2D);
}

void karint::Texture::bind() {
    glBindTexture(GL_TEXTURE_2D, id);
}

void karint::Texture::bind(char activeTextureIndex) {
    bind();
    gl::activeTexture(activeTextureIndex);
}

void karint::Texture::create() {
    glGenTextures(1, &id);
}

karint::Texture karint::Texture::load(const std::string &file) {
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

    texture.setParameter(gl::TEXTURE_WRAP_X, gl::REPEAT);
    texture.setParameter(gl::TEXTURE_WRAP_Y, gl::REPEAT);
    texture.setParameter(gl::TEXTURE_MIN_FILTER, gl::LINEAR_MIPMAP_LINEAR);
    texture.setParameter(gl::TEXTURE_MAG_FILTER, gl::LINEAR);

    texture.generateMipmap();
    stbi_image_free(image);
    return texture;
}
