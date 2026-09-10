#include "ComponentsInitializer.h"
#include "BoxCollider.h"
#include "GlobalLight.h"
#include "ModelRenderer.h"
#include "Rigidbody.h"
#include "Transform.h"
#include "Sandbox.h"
#include "GameCamera.h"

namespace RuamEngine
{
    void ComponentsInitializer::InitComponents()
    {
        Transform::TransformRegister();
        GlobalLight::GlobalLightRegister();
        ModelRenderer::ModelRendererRegister();
        Sandbox::SandboxRegister();
        GameCamera::GameCameraRegister();
        Rigidbody::RigidbodyRegister();
        BoxCollider::BoxColliderRegister();
    }
}
