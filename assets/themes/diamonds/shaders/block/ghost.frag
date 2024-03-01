#version 420 core
out vec4 FragColor;

in vec2 TexCoord;

// Texture samplers
uniform sampler2D textureDiffuse;

void main() {
    
    FragColor = vec4(0.5, 0.5, 0.5 , 0.5);
}
