#include "Renderer.h"

void GLClearError()
{
    while (glGetError() != GL_NO_ERROR);
}

bool GLLogCall(const char* function, const char* file, int line)
{
    while (GLenum error = glGetError())
    {
        std::cout << "[OpenGL Error] (" << error << "): " << "\n" <<
            "in file: " << file << "\n" <<
            "in line: " << line << "\n" <<
            "in function: " << function << "\n";

        return false;
    }
    return true;    
}
namespace RuamEngine
{
    RendererConfig Renderer::m_config;
    DrawingData Renderer::m_basicDrawingData;
	GLFWwindow* Renderer::m_window = nullptr;
    std::unordered_map<int, DrawingData> Renderer::m_drawingDataMap;
    void Renderer::Init()
    {
        glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
        glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
        glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
        
        ASSERT(glfwInit());
        
        m_window = glfwCreateWindow(m_config.windowWidth, m_config.windowHeight, m_config.windowTitle, m_config.monitor, m_config.share);
        ASSERT(m_window);

        glfwMakeContextCurrent(m_window);

        glfwSwapInterval(1);

        ASSERT(glewInit() == GLEW_OK);

        if (m_config.depthTest) GLCall(glEnable(GL_DEPTH_TEST));
        if (m_config.blend)
        {
            GLCall(glEnable(GL_BLEND));
            GLCall(glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA));
        }


        {
			DrawingData basicDrawingData = *(new DrawingData());
            m_basicDrawingData.m_layout = std::make_shared<VertexBufferLayout>();
            Renderer::m_basicDrawingData.m_layout->Reset();
            Renderer::m_basicDrawingData.m_layout->Push<float>(3);
            Renderer::m_basicDrawingData.m_layout->Push<float>(4);
			m_basicDrawingData.m_vertexArray = std::make_shared<VertexArray>();
			m_basicDrawingData.m_vertexBuffer = std::make_shared<VertexBuffer>(maxVertexSize * maxVertexCount, GL_DYNAMIC_DRAW);
            m_basicDrawingData.m_vertexArray->AddBuffer(*m_basicDrawingData.m_vertexBuffer, *m_basicDrawingData.m_layout);
            m_basicDrawingData.m_indexBuffer = std::make_shared<IndexBuffer>(maxIndexCount, GL_DYNAMIC_DRAW);
            m_basicDrawingData.m_shader = std::make_shared<Shader>("assets/shaders/GeneralVertexShader.glsl", "assets/shaders/GeneralFragmentShader.glsl");
			m_drawingDataMap[0] = m_basicDrawingData;
        }

    }
    void Renderer::Shutdown()
    {
        glfwTerminate();
    }
    void Renderer::EndDraw()
    {
        glfwSwapBuffers(m_window);
    }
    void Renderer::BeginBatch()
    {
        Flush();
    }
    void Renderer::EndBatch()
    {
        for (auto& pair : m_drawingDataMap)
        {
            pair.second.SubmitBatchData();
        }
    }
    void Renderer::EndBatch(DrawingData& drawingData)
    {
        drawingData.SubmitBatchData();
    }
    void Renderer::Flush()
    {
        for (auto& pair : m_drawingDataMap)
        {
            pair.second.Flush();
        }
    }

    void Renderer::ClearScreen()
    {
        if (m_config.useClearColor) GLCall(glClear(GL_COLOR_BUFFER_BIT));
		if (m_config.depthTest) GLCall(glClear(GL_DEPTH_BUFFER_BIT));
    }

    void Renderer::SetWindowSize(int width, int height)
    {
		m_config.windowWidth = width;
		m_config.windowHeight = height;
        glfwSetWindowSize(m_window, m_config.windowWidth, m_config.windowHeight);
    }

    void Renderer::SetWindowTitle(const char* title)
    {
		m_config.windowTitle = title;
		glfwSetWindowTitle(m_window, m_config.windowTitle);
    }

    void Renderer::SetClearColor(const glm::vec4& color)
    {
        m_config.clearColor = color;
		GLCall(glClearColor(m_config.clearColor.r, m_config.clearColor.g, m_config.clearColor.b, m_config.clearColor.a));
    }

    void Renderer::SetDepthTest(bool enable)
    {
        m_config.depthTest = enable;
        if (m_config.depthTest) GLCall(glEnable(GL_DEPTH_TEST));
		else GLCall(glDisable(GL_DEPTH_TEST));
    }

    void Renderer::SetBlend(bool enable, GLenum sfactor, GLenum dfactor)
    {
		m_config.blend = enable;
		m_config.blendSFactor = sfactor;
		m_config.blendDFactor = dfactor;
        if (m_config.blend)
        {
            GLCall(glEnable(GL_BLEND));
            GLCall(glBlendFunc(m_config.blendSFactor, m_config.blendDFactor));
        }
        else
        {
			GLCall(glDisable(GL_BLEND));
        }
    }

    void Renderer::Draw()
    {
        for (auto& pair : m_drawingDataMap)
        {
            pair.second.m_shader->Bind();
            pair.second.m_vertexArray->Bind();
            pair.second.m_indexBuffer->Bind();
            GLCall(glDrawElements(GL_TRIANGLES, pair.second.m_indexBuffer->GetIndexCount(), GL_UNSIGNED_INT, nullptr));
        }
    }

    void Renderer::Draw(DrawingData& drawingData)
    {
        drawingData.m_shader->Bind();
        drawingData.m_vertexArray->Bind();
        drawingData.m_indexBuffer->Bind();
        GLCall(glDrawElements(GL_TRIANGLES, drawingData.m_indexBuffer->GetIndexCount(), GL_UNSIGNED_INT, nullptr));   
    }

    void Renderer::DrawQuads()
    {
        
    }
}
