#ifndef TEXTURE_H
#define TEXTURE_H

#include <string>

namespace lite {
    class Texture
    {
    public:
        unsigned int id;
        Texture();
        ~Texture();
        void setImage(int mipmapLevel, int width, int height, unsigned char *image);
        void setParameter(int type, int value);
        void generateMipmap();
        static Texture *load(const std::string &file);
    };
}
#endif // TEXTURE_H
