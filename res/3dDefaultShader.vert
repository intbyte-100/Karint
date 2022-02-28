#version 330 core
layout (location = 0) in vec3 aPos;
layout (location = 1) in vec3 aNormal;
layout (location = 2) in vec2 aTexCoord;

out vec4 ourColor;
out vec2 TexCoord;

uniform mat4 model;
uniform mat4 view;
uniform mat4 projection;

uniform vec3 diffuseColor;
uniform vec3 diffusePosition;

void main()
{
        vec3 normal = normalize(mat3(transpose(inverse(model))) * aNormal);
        vec3 lightDir = normalize(diffusePosition - aPos);



        ourColor = vec4(diffuseColor * max(dot(lightDir, normal), 0.0), 1.0);
        TexCoord = vec2(aTexCoord.x, aTexCoord.y);
        gl_Position = projection * view * model * vec4(aPos, 1.0);
}
