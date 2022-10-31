#version 120

layout (location = 0) in vec3 a_vertexPosition;
layout (location = 1) in vec3 a_normal;
layout (location = 2) in vec2 a_textureCoords;

out vec3 diffuse;
out vec2 textureCoords;

uniform mat4 u_model;
uniform mat4 u_view;
uniform mat4 u_projection;

uniform Light {
    vec3 color;
    vec3 position;
} u_light;


out vec3 fragPosition;
out vec3 normal;



void main() {
    vec4 vertex = model * vec4(a_vertexPosition, 1.0);
    normal = normalize(mat3(transpose(inverse(u_model))) * a_normal);
    fragPosition = vec3(vertex);

    diffuse = u_light.color * max(dot(normalize(u_light.position - fragPosition), normal), 0);

    gl_Position = u_projection * u_view * vertex;
    textureCoords = a_textureCoords;
}
