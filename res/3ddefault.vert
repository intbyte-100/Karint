#version 330 core

layout (location = 0) in vec3 aPos;
layout (location = 1) in vec3 aNormal;
layout (location = 2) in vec2 aTexCoord;

out vec4 diffuse;
out vec2 TexCoord;

uniform mat4 model;
uniform mat4 view;
uniform mat4 projection;

uniform vec3 lightColor;
uniform vec3 lightPosition;

out vec3 fragPosition;
out vec3 norm;
out vec3 lightDir;

void main()
{
        fragPosition = vec3(model * vec4(aPos, 1.0));
        norm = normalize(aNormal);
        vec3 normal = normalize(mat3(transpose(inverse(model))) * aNormal);
        vec4 vertex = model * vec4(aPos, 1.0);
        lightDir = normalize(lightPosition - fragPosition);

        diffuse = vec4(lightColor * max(dot(lightDir, normal), 0.0), 1.0);
        TexCoord = vec2(aTexCoord.x, aTexCoord.y);
        gl_Position = projection * view * vertex;
}
