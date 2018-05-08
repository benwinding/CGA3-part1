
#version 330

in vec3 colour; 
out vec4 fragColour;

void main(void) {

    fragColour = vec4(colour, 1.0);
    // We now just have to set the already smoothed colour as our frag colour
}
