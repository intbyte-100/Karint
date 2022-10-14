#pragma once
#include "glm/glm.hpp"

namespace karint {
    class Uniform
    {
    public:
        int id;

        void setFloat(float r, float g, float b, float a);
        void setFloat(float r, float g, float b);
        void setFloat(float x, float y);
        void setFloat(float value);

        void setVec3(glm::vec3 &vector);
        void setBool(bool value);
        void setInt(int value);
        void setMatrix(glm::mat4 &matrix, bool transpose);
    };
}
