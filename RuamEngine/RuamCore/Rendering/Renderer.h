#pragma once

#include "RenderingCore.h"
#include "VertexBuffer.h"
#include "VertexArray.h"
#include "IndexBuffer.h"
#include "VertexBufferLayout.h"
#include "DrawingData.h"
#include "Shader.h"

#include <unordered_map>

class VertexBuffer;
class VertexArray;
class IndexBuffer;
class Shader;
class VertexBufferLayout;
class DrawingData;

namespace RuamEngine
{
	class DrawingData;

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

	static const unsigned int maxVertexAtribs = (3 + 4 + 2 + 1); // Position, Color, TexCoords, TexID
	static const unsigned int maxVertexSize = sizeof(float) * maxVertexAtribs; // 3 position, 4 color, 2 tex coords, 1 tex id
    static const unsigned int maxQuadCount = 1000;
    static const unsigned int maxVertexCount = maxQuadCount * 4;
    static const unsigned int maxIndexCount = maxQuadCount * 6;
    static const unsigned int maxTextureSlots = 32; // Note for CoolFede97: Remember to change this according to the machine you are using!

    class Renderer
    {
    public:
        
        static void Init();
        static void Shutdown();
        static void BeginBatch();
        static void EndBatch();
        static void ClearScreen();
        static void Flush();
        
		// Setters for RendererConfig
        static void SetWindowSize(int width, int height);
        static void SetWindowTitle(const char* title);
        static void SetClearColor(const glm::vec4& color);
        static void SetDepthTest(bool enable);
        static void SetBlend(bool enable, GLenum sfactor = GL_SRC_ALPHA, GLenum dfactor = GL_ONE_MINUS_SRC_ALPHA);
       

		// Getters for RendererConfig
        static int GetWindowWidth() { return m_config.windowWidth; }
        static int GetWindowHeight()  { return m_config.windowHeight; }
        static const char* GetWindowTitle()  { return m_config.windowTitle; }
        static glm::vec4 GetClearColor()  { return m_config.clearColor; }
        static bool GetUseClearColor()  { return m_config.useClearColor; }
        static bool GetDepthTest()  { return m_config.depthTest; }
        static bool GetBlend()  { return m_config.blend; }
        static GLFWmonitor* GetMonitor()  { return m_config.monitor; }
        static GLFWwindow* GetShare()  { return m_config.share; }
        static GLenum GetBlendSFactor()  { return m_config.blendSFactor; }
        static GLenum GetBlendDFactor()  { return m_config.blendDFactor; }


		static GLFWwindow* GetWindow() { return m_window; }

        static void Draw();
		static void DrawQuads();

        static DrawingData m_basicDrawingData;
        static std::unordered_map<int, DrawingData> m_drawingDataMap;
    private:
        static RendererConfig m_config;
        static GLFWwindow* m_window;
    };

}
