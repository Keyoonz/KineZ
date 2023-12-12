#include "Texture.h"


KineZ::Texture::Texture(const char* path)
	:m_id(0)
{
	extern Logger KZlogger;
	int nrChannels;
	unsigned char* data = stbi_load(path, &m_width, &m_height, &nrChannels, 0);

	glGenTextures(1, &m_id);

	Bind();


	if (data) {
		glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, m_width, m_height, 0, GL_RGB, GL_UNSIGNED_BYTE, data);
		glGenerateMipmap(GL_TEXTURE_2D);
	}
	else
	{
		KZlogger.Error("Failed to load texture");
	}
	stbi_image_free(data);
	
	
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);

	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST_MIPMAP_NEAREST);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
}

KineZ::Texture::~Texture()
{
	glDeleteTextures(1, &m_id);
}

void KineZ::Texture::Bind()
{
	glBindTexture(GL_TEXTURE_2D, m_id);
}

void KineZ::Texture::Unbind()
{
	glBindTexture(GL_TEXTURE_2D, 0);
}
