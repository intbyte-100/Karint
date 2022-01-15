#pragma once

#include <glm/vec3.hpp>
#include <glm/ext/matrix_float4x4.hpp>

namespace lite {
    class PerspectiveCamera {
    private:
        glm::mat4 projection;
    public:
        PerspectiveCamera(){};
        PerspectiveCamera(float far, float near, float viewAngle);
        float near;
        float far;
        float viewAngle;
        glm::mat4 view;
        glm::vec3 direction = glm::vec3(0);
        glm::vec3 position = glm::vec3(0);


        glm::mat4 getProjection();
        void update(int width, int height);
        void update();
    };
}
