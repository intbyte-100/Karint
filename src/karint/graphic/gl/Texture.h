#ifndef TEXTURE_H
#define TEXTURE_H

#include <string>

namespace karint {
    class Texture
    {
    public:
        unsigned int id;
        void setImage(int mipmapLevel, int sourceChanel, int glChanel, int width, int height, unsigned char *image);
        void setParameter(int type, int value);
        void generateMipmap();
        void bind();
        void bind(char activeTextureIndex);
        void create();
        void dispose();
        static Texture load(const std::string &file);
    };
}
#endif // TEXTURE_H
