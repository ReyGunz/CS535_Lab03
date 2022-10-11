#pragma once
#include "glad/glad.h"
#include "stb/stb_image.h"
#include "Shader.h"

class Texture
{
public:
	GLuint ID;
	GLenum type;

	Texture(const char* image, GLenum texture, GLenum slot, GLenum format, GLenum pixel)
	{
		type = texture;

		int w, h, n;

		stbi_set_flip_vertically_on_load(true);
		unsigned char* bytes = stbi_load(image, &w, &h, &n, 0);

		glGenTextures(1, &ID);
		glActiveTexture(slot);
		glBindTexture(texture, ID);

		glTexParameteri(texture, GL_TEXTURE_MIN_FILTER, GL_NEAREST_MIPMAP_LINEAR);
		glTexParameteri(texture, GL_TEXTURE_MAG_FILTER, GL_NEAREST);

		glTexParameteri(texture, GL_TEXTURE_WRAP_S, GL_REPEAT);
		glTexParameteri(texture, GL_TEXTURE_WRAP_T, GL_REPEAT);

		glTexImage2D(texture, 0, GL_RGBA, w, h, 0, format, pixel, bytes);
		glGenerateMipmap(texture);

		stbi_image_free(bytes);

		glBindTexture(texture, 0);
	}

	void send(Shader& shader, const char* variable, GLuint value)
	{
		GLuint tex_variable = glGetUniformLocation(shader.ID, variable);
		shader.on();
		glUniform1i(tex_variable, value);
	}

	void bind()
	{
		glBindTexture(type, ID);
	}

	void unbind()
	{
		glBindTexture(type, 0);
	}

	void deleet()
	{
		glDeleteTextures(1, &ID);
	}

};