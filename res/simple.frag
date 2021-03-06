#version 330

in vec2 TexCoords;
in vec3 Normal;
in vec3 FragPos;

out vec4 FragColor;

uniform int debugMode;

void main(void)
{
    if (debugMode == 0)
        FragColor = vec4(FragPos, 1.0);
    else if (debugMode == 1)
        FragColor = vec4(Normal, 1.0);
    else
        FragColor = vec4(1.0);
}
