#version 330 core

layout (location=0) in vec3 aPos;
layout (location=1) in vec2 aTexCoord;

out vec2 texCoord;

uniform mat4 viewMatrix;
uniform mat4 projectionMatrix;
uniform mat4 transformationMatrix;

void main()
{
	gl_Position =   projectionMatrix * viewMatrix * transformationMatrix * vec4(aPos.x,aPos.y, aPos.z, 1.0f);
	texCoord = aTexCoord;
};