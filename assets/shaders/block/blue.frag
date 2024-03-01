#version 420 core
out vec4 FragColor;

in vec2 TexCoord;

// Texture samplers
uniform sampler2D textureDiffuse;

void main() {
   
    vec3 diffuse = texture(textureDiffuse, TexCoord).rgb;
    
    FragColor = vec4(diffuse, 1.0);
}
