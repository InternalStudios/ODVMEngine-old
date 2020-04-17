#pragma once

#include <glm/glm.hpp>

#include "Cameras.hpp"

namespace ODVM
{
    class Renderer3D
    {
    public:
        static void Init();
        static void BeginScene(const PerspectiveCamera& camera);
        static void EndScene();
        static void DrawCube(const glm::vec3& pos, const glm::vec4& color);
    private:
    };
}