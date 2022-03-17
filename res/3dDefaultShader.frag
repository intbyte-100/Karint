#version 330 core
out vec4 FragColor;

in vec4 diffuse;
in vec2 TexCoord;

uniform vec4 ambient = vec4(1.0);
uniform sampler2D texture1;

uniform Material {
    vec3 color;
    float diffuse;
    float specularity;
} material;

void main()
{
    // linearly interpolate between both textures (80% container, 20% awesomeface)
    FragColor = texture(texture1, TexCoord) * (ambient + diffuse * material.diffuse);
    FragColor.rgb*=material.color;
}
