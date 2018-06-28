#version 300 es

uniform float uniformTest;  

layout(location = 0) in vec4 a_position;   
layout(location = 1) in vec4 a_color;

out vec4 v_color;

void main()                                
{
    v_color = a_color;
    gl_Position = vec4(a_position.x + uniformTest,a_position.y,a_position.z,a_position.w);
}