
#include "AI.h"
#include "Engine.h"
#include "MovementComponent.h"
#include "SpriteDirectionComponent.h"
#include "SpriteMovementAnimationComponent.h"
#include "SpriteColliderComponent.h"
#include "FollowComponent.h"

namespace XYZRoguelike
{
    AI::AI(const XYZEngine::Vector2Df& position, XYZEngine::GameObject* player)
    {
        gameObject = XYZEngine::GameWorld::Instance()->CreateGameObject("AI");
        auto transform = gameObject->GetComponent<XYZEngine::TransformComponent>();
        transform->SetWorldPosition(position);

        auto renderer = gameObject->AddComponent<XYZEngine::SpriteRendererComponent>();
        renderer->SetTexture(*XYZEngine::ResourceSystem::Instance()->GetTextureMapElementShared("AI", 0));
        renderer->SetPixelSize(100, 100);

        auto follower = gameObject->AddComponent<XYZEngine::FollowComponent>();
        follower->SetTarget(player);
        follower->SetSpeed(120.0f);

        auto rigidbody = gameObject->AddComponent<XYZEngine::RigidbodyComponent>();
        rigidbody->SetKinematic(false);

        auto collider = gameObject->AddComponent<XYZEngine::SpriteColliderComponent>();
    }

    XYZEngine::GameObject* AI::GetGameObject()
    {
        return gameObject;
    }
}