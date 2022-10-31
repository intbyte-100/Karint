#version 120


out vec4 fragColor;

in vec3 fragPosition;
in vec3 normal;
in vec2 textureCoords;
in vec3 diffuse;

uniform vec3 u_ambient;
uniform vec3 u_cameraPosition;
uniform vec3 u_color;

uniform Material {
    vec3 color;
    float diffuse;
    float specularity;
} u_material;

uniform Light {
    vec3 color;
    vec3 position;
} u_light;

vec3 cameraDirection = vec3(0);

vec3 getPhongSpecular(in vec3 lightPosition, in vec3 color){
    vec3 lightDir = normalize(lightPosition - fragPosition);
    vec3 reflectDir = reflect(-lightDir, normal);
    return pow(max(reflectDir, cameraDirection), 64) * color;
}


void main() {
    cameraDirection = normalize(cameraDirection - fragPosition);

    vec3 specular = getPhongSpecular(u_light.position, u_light.color) * u_material.specularity;

    fragColor = vec4(u_color * (u_ambient + diffuse * u_matrial.diffuse + specular), 1.0);
}
