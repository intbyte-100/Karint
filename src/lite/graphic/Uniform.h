#pragma once

namespace lite {
    class Uniform
    {
    public:
        int id;

        void setFloat(float r, float g, float b, float a);
        void setFloat(float r, float g, float b);
        void setFloat(float x, float y);
        void setFloat(float value);

        void setBool(bool value);
        void setInt(int value);
    };
}
