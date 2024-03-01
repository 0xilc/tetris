#version 420 core
out vec4 FragColor;

in vec2 TexCoord;

// Texture samplers
uniform sampler2D textureDiffuse;
uniform sampler2D textureSpecular;
uniform sampler2D textureNormal;

void main() {
   
    vec3 diffuse = texture(textureDiffuse, TexCoord).rgb;
    vec3 specular = texture(textureSpecular, TexCoord).rgb;
    vec3 normal = texture(textureNormal, TexCoord).rgb;

    vec3 result = mix(diffuse, specular, 0.5); // Mix diffuse and specular for demonstration
    FragColor = vec4(result, 1.0);
}
