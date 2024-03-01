#version 420 core
layout (location = 0) in vec3 aPos;
layout (location = 1) in vec2 aTexCoord;

out vec2 TexCoord;

uniform mat4 modelMatrix;

layout(std140, binding = 1) uniform CameraData {
    mat4 viewMatrix;
    mat4 projectionMatrix;
};

void main() {
    gl_Position =  projectionMatrix * viewMatrix * modelMatrix * vec4(aPos, 1.0);
    TexCoord = aTexCoord;
}
