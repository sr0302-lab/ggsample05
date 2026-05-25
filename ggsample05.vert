#version 410 core

layout(location = 0) in vec4 p0;
layout(location = 1) in vec4 p1;

uniform float t;
uniform mat4 mc;

void main(void)
{
  float morph = 0.5 - 0.5 * cos(6.2831853 * t);
  
  vec4 p = mix(p0, p1, morph);
  
  gl_Position = mc * p;
}
