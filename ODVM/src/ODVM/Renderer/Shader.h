#pragma once

#include <string.h>

namespace ODVM
{

	class Shader
	{
	public:
		virtual ~Shader() {}

		virtual void Bind() const = 0;
		virtual void Unbind() const = 0;

		static Shader* Create(std::string vertexSrc, std::string pixelSrc);
	};

}