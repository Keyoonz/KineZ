#version 330 core

layout (location=0) in vec3 aPos;
layout (location=1) in vec3 aNormal;
layout (location=2) in vec2 aTexCoords;

out vec2 texCoords;

uniform mat4 viewMatrix;
uniform mat4 projectionMatrix;
uniform mat4 transformationMatrix;

void main()
{
	gl_Position =   projectionMatrix * viewMatrix * transformationMatrix * vec4(aPos, 1.0);
	texCoords = aTexCoords;
};