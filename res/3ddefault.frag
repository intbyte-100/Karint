#version 330 core
out vec4 FragColor;

in vec4 diffuse;
in vec2 TexCoord;
in vec3 fragPosition;
in vec3 normal;

uniform vec3 lightPosition;
uniform vec3 lightColor;
uniform vec4 ambient = vec4(1.0);
uniform sampler2D texture1;
uniform vec3 viewPos;

uniform Material {
    vec3 color;
    float diffuse;
    float specularity;
} material;

void main()
{

    vec3 viewDir = normalize(viewPos - fragPosition);
    vec3 lightDir = normalize(lightPosition - fragPosition);
    vec3 reflectDir = reflect(-lightDir, normal);
    float spec = pow(max(dot(viewDir, reflectDir), 0.0), 128);

    vec3 specular = material.specularity * spec * lightColor;

    FragColor = texture(texture1, TexCoord) * (ambient + diffuse * material.diffuse);
    FragColor.rgb+=specular;
    FragColor.rgb*=material.color;
}
