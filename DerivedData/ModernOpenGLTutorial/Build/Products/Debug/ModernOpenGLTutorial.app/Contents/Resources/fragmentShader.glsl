#version 150 core

uniform vec4 colour;
uniform sampler2D tex;

in vec2 TexCoord;

out vec4 fragColour;



void main(){
   fragColour = colour * texture(tex, TexCoord);
}