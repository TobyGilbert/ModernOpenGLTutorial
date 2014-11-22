#version 150 core

uniform mat4 projection;
uniform mat4 view;
uniform mat4 model;

in vec4 position;
in vec2 texCoord;

out vec2 TexCoord;

void main(){
   
   TexCoord = texCoord;
   gl_Position = projection * view * model * position;
   
}