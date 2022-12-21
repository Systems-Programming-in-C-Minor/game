#include "objects/debug_draw_target_factory.hpp"

#include "scene.hpp"
#include "components/colliders/circlecollider.hpp"

DebugDrawTargetFactory::DebugDrawTargetFactory(std::vector<Vector2d> vectors, float radius, float randomize_radius)
    : GameObject("ui-debug-draw-target", "ui-debug"), _vectors(std::move(vectors)), _radius(radius), _randomize_radius(randomize_radius)
{}

void DebugDrawTargetFactory::get(Scene& scene)
{
    for (int i = 0; i < static_cast<int>(_vectors.size()); ++i)
    {
        const auto debug_draw_circle = std::make_shared<GameObject>(std::string("ui-debug-draw-target-" + std::to_string(i)), "ui-debug");
        const auto debug_draw_circle_rb = std::make_shared<RigidBody>(scene, 999, BodyType::static_body, _vectors[i], Color{0, 0, 255, 0});
        debug_draw_circle_rb->set_collider(std::make_shared<CircleCollider>(_radius, true));
        debug_draw_circle->add_component(debug_draw_circle_rb);
        scene.gameobjects.push_back(debug_draw_circle);
    }

    for (int i = 0; i < static_cast<int>(_vectors.size()); ++i)
    {
        const auto debug_draw_circle = std::make_shared<GameObject>(std::string("ui-debug-draw-target-randomize-" + std::to_string(i)), "ui-debug");
        const auto debug_draw_circle_rb = std::make_shared<RigidBody>(scene, 999, BodyType::static_body, _vectors[i], Color{ 0, 100, 255, 0 });
        debug_draw_circle_rb->set_collider(std::make_shared<CircleCollider>(_randomize_radius, true));
        debug_draw_circle->add_component(debug_draw_circle_rb);
        scene.gameobjects.push_back(debug_draw_circle);
    }
}
