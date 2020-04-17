#include "odvmpch.h"
#include "Renderer3D.hpp"

#include "Buffer.hpp"
#include "VertexArray.hpp"
#include "Shader.hpp"

#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

#include "RenderCommand.hpp"

namespace ODVM
{
    struct Renderer3DData
    {
        Ref<VertexBuffer> CubeVB;
        Ref<IndexBuffer> CubeIB;
        Ref<VertexArray> CubeVA;
        Ref<Shader> TDShader;
    };

    static Renderer3DData s_3DData;

    void Renderer3D::Init()
    {
        ODVM_PROFILE_FUNCTION();

        s_3DData.CubeVA = VertexArray::Create();

        float cubeVertices[36 * 3] = {
            -0.5f, -0.5f, -0.5f,  
            0.5f, -0.5f, -0.5f,  
            0.5f,  0.5f, -0.5f,  
            0.5f,  0.5f, -0.5f,  
            -0.5f,  0.5f, -0.5f,  
            -0.5f, -0.5f, -0.5f,  
            -0.5f, -0.5f,  0.5f,  
            0.5f, -0.5f,  0.5f,  
            0.5f,  0.5f,  0.5f,  
            0.5f,  0.5f,  0.5f,  
            -0.5f,  0.5f,  0.5f,  
            -0.5f, -0.5f,  0.5f,  
            -0.5f,  0.5f,  0.5f,  
            -0.5f,  0.5f, -0.5f,  
            -0.5f, -0.5f, -0.5f,  
            -0.5f, -0.5f, -0.5f,  
            -0.5f, -0.5f,  0.5f,  
            -0.5f,  0.5f,  0.5f,  
            0.5f,  0.5f,  0.5f,  
            0.5f,  0.5f, -0.5f,  
            0.5f, -0.5f, -0.5f,  
            0.5f, -0.5f, -0.5f,  
            0.5f, -0.5f,  0.5f,  
            0.5f,  0.5f,  0.5f,  
            -0.5f, -0.5f, -0.5f,  
            0.5f, -0.5f, -0.5f,  
            0.5f, -0.5f,  0.5f,  
            0.5f, -0.5f,  0.5f,  
            -0.5f, -0.5f,  0.5f,  
            -0.5f, -0.5f, -0.5f,  
            -0.5f,  0.5f, -0.5f,  
            0.5f,  0.5f, -0.5f,  
            0.5f,  0.5f,  0.5f,  
            0.5f,  0.5f,  0.5f,  
            -0.5f,  0.5f,  0.5f,  
            -0.5f,  0.5f, -0.5f,  
        };
        
        s_3DData.CubeVB = VertexBuffer::Create(cubeVertices, sizeof(cubeVertices));

        BufferLayout layout = {
            {ShaderDataType::Float3, "a_Position"}
        };
        
        s_3DData.CubeVB->SetLayout(layout);
        s_3DData.CubeVA->AddVertexBuffer(s_3DData.CubeVB);

        uint32_t indices[36] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 31, 32, 33, 34, 35};
        s_3DData.CubeIB = IndexBuffer::Create(indices, sizeof(indices) / sizeof(uint32_t));
        s_3DData.CubeVA->SetIndexBuffer(s_3DData.CubeIB);

        s_3DData.TDShader = Shader::Create("assets/shaders/3D.glsl");
    }

    void Renderer3D::BeginScene(const PerspectiveCamera& camera)
    {
        s_3DData.TDShader->Bind();
        s_3DData.TDShader->SetMat4("u_View", camera.GetViewMatrix());
        s_3DData.TDShader->SetMat4("u_Projection", camera.GetProjectionMatrix());

    }

    void Renderer3D::EndScene()
    {

    }

    void Renderer3D::DrawCube(const glm::vec3& pos, const glm::vec4& color)
    {
        s_3DData.TDShader->Bind();
        s_3DData.TDShader->SetFloat4("u_Color", color);
        
        glm::mat4 model = glm::mat4(1.0f);
        model = glm::rotate(model, glm::radians(-55.0f), glm::vec3(1.0f, 0.0f, 0.0f));

        s_3DData.TDShader->SetMat4("u_Model", model);

        RenderCommand::DrawIndexed(s_3DData.CubeVA);
    }
}