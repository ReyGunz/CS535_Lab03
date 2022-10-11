#include "Shader.h"

std::string file_string(const char* filename)
{
	std::ifstream in(filename, std::ios::binary);
	if (in)
	{
		std::string contents;
		in.seekg(0, std::ios::end);
		contents.resize(in.tellg());
		in.seekg(0, std::ios::beg);
		in.read(&contents[0], contents.size());
		in.close();
		return contents;
	}
}

Shader::Shader(const char* v, const char* f)
{
	std::string v_code = file_string(v);
	std::string f_code = file_string(f);

	const char* v_src = v_code.c_str();
	const char* f_src = f_code.c_str();

	GLuint v_shader = glCreateShader(GL_VERTEX_SHADER);
	glShaderSource(v_shader, 1, &v_src, NULL);
	glCompileShader(v_shader);
	error_callback(v_shader, "VERTEX");

	GLuint f_shader = glCreateShader(GL_FRAGMENT_SHADER);
	glShaderSource(f_shader, 1, &f_src, NULL);
	glCompileShader(f_shader);
	error_callback(f_shader, "FRAGMENT");

	ID = glCreateProgram();
	glAttachShader(ID, v_shader);
	glAttachShader(ID, f_shader);
	glLinkProgram(ID);
	error_callback(ID, "PROGRAM");

	//glUniform4f(glGetUniformLocation(ID, "color"), color[0], color[1], color[2], color[3]);

	//send_color("color");

	glDeleteShader(v_shader);
	glDeleteShader(f_shader);
}

void Shader::on()
{
	glUseProgram(ID);
}

void Shader::deleet()
{
	glDeleteProgram(ID);
}

void Shader::error_callback(unsigned int shader, const char* type)
{
	GLint compiled;

	char info[1024];

	if (type != "PROGRAM")
	{
		glGetShaderiv(shader, GL_COMPILE_STATUS, &compiled);
		if (compiled == GL_FALSE)
		{
			glGetShaderInfoLog(shader, 1024, NULL, info);
			std::cout << "SHADER_COMPILATION_ERROR for:" << type << "\n" << info << std::endl;
		}
	}
	else
	{
		glGetProgramiv(shader, GL_LINK_STATUS, &compiled);
		if (compiled == GL_FALSE)
		{
			glGetProgramInfoLog(shader, 1024, NULL, info);
			std::cout << "SHADER_LINKING_ERROR for:" << type << "\n" << info << std::endl;
		}
	}
}

void Shader::send_color()
{
	glUniform4f(glGetUniformLocation(ID, "color"), color[0], color[1], color[2], color[3]);
}

void Shader::update_color(float* _color)
{
	color[0] = _color[0];
	color[1] = _color[1];
	color[2] = _color[2];
	color[3] = _color[3];

	send_color();
}