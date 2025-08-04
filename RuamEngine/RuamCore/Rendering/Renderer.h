#pragma once

#include <iostream>
#include <GL/glew.h>
#include "VertexArray.h"
#include "IndexBuffer.h"
#include "Shader.h"

#if defined(__WIN32)
#define ASSERT(x) (if(!(x)) __debugbreak();)
#elif defined(__linux__)
#include <csignal>
#define ASSERT(x) do {if(!(x)) raise(SIGTRAP);} while (false)
#endif

#define GLCall(x) do { GLClearError();\
    x; \
    ASSERT(GLLogCall(#x, __FILE__, __LINE__));\
	} while(false)

void GLClearError();

bool GLLogCall(const char* function, const char* file, int line);

class Renderer
{
public:
    void Clear() const;
    void Draw(const VertexArray& va, const IndexBuffer& ib, const Shader& shader) const;    
};
