#pragma once

#include <iostream>
#include <array>
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

    // General data 
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

    static const size_t vertexSize = 3;
    static const size_t maxQuadCount = 1000;
    static const size_t maxVertexCount = maxQuadCount * 4;
    static const size_t maxIndexCount = maxQuadCount * 6;
    static const size_t maxTextureSlots = 32; // Note for CoolFede97: Remember to change this according to the machine you are using!

    // Data for current drawing
    struct RendererState
    {
        // Primitives data

        GLenum primitiveType = GL_TRIANGLES;

        Shader* m_shader;
        VertexArray* m_vertexArray;
        VertexBuffer* m_vertexBuffer;
        VertexBufferLayout* m_layout;
		IndexBuffer* m_indexBuffer;

        std::array<uint32_t, maxTextureSlots> textureSlots;
        
        // Which texture slot we can insert our new texture into
        uint32_t textureSlotIndex = 1;
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

		// Setters for RendererConfig
        static void SetWindowSize(int width, int height);
        static void SetWindowTitle(const char* title);
        static void SetClearColor(const glm::vec4& color);
        static void SetDepthTest(bool enable);
        static void SetBlend(bool enable, GLenum sfactor = GL_SRC_ALPHA, GLenum dfactor = GL_ONE_MINUS_SRC_ALPHA);
        

        // Setters for RendererState
        void SetPrimitiveType(GLenum type) { m_state.primitiveType = type; }
        void SetShader(Shader* shader) { m_state.m_shader = shader; }
        void SetVertexArray(VertexArray* vertexArray) { m_state.m_vertexArray = vertexArray; }
        void SetVertexBuffer(VertexBuffer* vertexBuffer) { m_state.m_vertexBuffer = vertexBuffer; }
        void SetLayout(VertexBufferLayout* layout) { m_state.m_layout = layout; }
        void SetIndexBuffer(IndexBuffer* indexBuffer) { m_state.m_indexBuffer = indexBuffer; }
        void SetTextureSlots(const std::array<uint32_t, maxTextureSlots>& slots) { m_state.textureSlots = slots; }
        void SetTextureSlotIndex(uint32_t index) { m_state.textureSlotIndex = index; }


		// Getters for RendererConfig
        int GetWindowWidth() const { return m_config.windowWidth; }
        int GetWindowHeight() const { return m_config.windowHeight; }
        const char* GetWindowTitle() const { return m_config.windowTitle; }
        glm::vec4 GetClearColor() const { return m_config.clearColor; }
        bool GetUseClearColor() const { return m_config.useClearColor; }
        bool GetDepthTest() const { return m_config.depthTest; }
        bool GetBlend() const { return m_config.blend; }
        GLFWmonitor* GetMonitor() const { return m_config.monitor; }
        GLFWwindow* GetShare() const { return m_config.share; }
        GLenum GetBlendSFactor() const { return m_config.blendSFactor; }
        GLenum GetBlendDFactor() const { return m_config.blendDFactor; }


		// Getters for RendererState
        GLenum GetPrimitiveType() const { return m_state.primitiveType; }
        Shader* GetShader() const { return m_state.m_shader; }
        VertexArray* GetVertexArray() const { return m_state.m_vertexArray; }
        VertexBuffer* GetVertexBuffer() const { return m_state.m_vertexBuffer; }
        VertexBufferLayout* GetLayout() const { return m_state.m_layout; }
        IndexBuffer* GetIndexBuffer() const { return m_state.m_indexBuffer; }
        const std::array<uint32_t, maxTextureSlots>& GetTextureSlots() const { return m_state.textureSlots; }
        uint32_t GetTextureSlotIndex() const { return m_state.textureSlotIndex; }




		static GLFWwindow* GetWindow() { return m_window; }

        void Draw();

    private:
        static RendererConfig m_config;
		static RendererState m_state;
        static GLFWwindow* m_window;
    };

}
