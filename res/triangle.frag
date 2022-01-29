#version 330 core
out vec4 FragColor;

in vec3 ourColor;
in vec2 TexCoord;

uniform vec4 ambient = vec4(1.0);
// texture samplers
uniform sampler2D texture1;


void main()
{
        // linearly interpolate between both textures (80% container, 20% awesomeface)
        FragColor = texture(texture1, TexCoord) * ambient;
}
