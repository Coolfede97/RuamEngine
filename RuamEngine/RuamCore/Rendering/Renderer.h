#pragma once

#include <iostream>
#include <GL/glew.h>
#include "GLFW/glfw3.h"
#include "VertexArray.h"
#include "IndexBuffer.h"
#include "Shader.h"

#include "GLM/glm.hpp"
#include "GLM/gtc/matrix_transform.hpp"

#if defined(_WIN32)
#define ASSERT(x) do {if(!(x)) __debugbreak();} while(false)
#endif
#ifdef linux
#include <csignal>
#define ASSERT(x) do {if(!(x)) raise(SIGTRAP);} while (false)
#endif

#define GLCall(x) do { GLClearError();\
    x; \
    ASSERT(GLLogCall(#x, __FILE__, __LINE__));\
	} while(false)

void GLClearError();

bool GLLogCall(const char* function, const char* file, int line);

namespace RuamEngine
{
    struct RendererConfig
    {
        int windowWidth = 640;
        int windowHeight = 480;
        const char* windowTitle = "Cool Window";

        glm::vec4 clearColor = glm::vec4(0.24f, 0.24f, 0.16f, 1.0f);
        bool useClearColor = true;
        bool depthTest = true;
        bool blend = true;

        GLFWmonitor* monitor = NULL;
        GLFWwindow* share = NULL;

		GLenum blendSFactor = GL_SRC_ALPHA;
		GLenum blendDFactor = GL_ONE_MINUS_SRC_ALPHA;
    };

    class Renderer
    {
    public:
        static void Init();
        static void Shutdown();
        static void BeginDraw();
        static void EndDraw();
        static void Clear();

        static void CreateWindow(); // Should be called just once
        static void SetWindowSize(int width, int height);
        static void SetWindowTitle(const char* title);
        static void SetClearColor(const glm::vec4& color);
        static void SetDepthTest(bool enable);
        static void SetBlend(bool enable, GLenum sfactor = GL_SRC_ALPHA, GLenum dfactor = GL_ONE_MINUS_SRC_ALPHA);
        
		static GLFWwindow* GetWindow() { return m_window; }

        void Draw(const VertexArray& va, const IndexBuffer& ib, const Shader& shader) const
        {
            shader.Bind();
            va.Bind();
            ib.Bind();

            GLCall(glDrawElements(GL_TRIANGLES, ib.GetCount(), GL_UNSIGNED_INT, nullptr));
        }

    private:
        static RendererConfig m_config;
        static GLFWwindow* m_window;
    };

}
