#include "tree_factory.hpp"
#include <color.hpp>
#include <components/sprite.hpp>
#include <components/animator.hpp>

std::shared_ptr<GameObject>
TreeFactory::get(TreeType tree_type, Vector2d position) {
    auto game_object = std::make_shared<GameObject>("tree", "tree", true, Transform{position});

    Sprites sprites;

    for (const auto& animation_path: animation_paths[tree_type]) {
        auto sprite = std::make_shared<Sprite>(animation_path, Color(0, 0, 0, 0), false, false, 1,
                                               200 - (position.y > 0 ? position.y : position.y * -1), 36.f);
        sprites.emplace_back(sprite);
    }

    game_object->add_component(sprites[0]);

    auto animator = std::make_shared<Animator>(sprites, 2);
    animator->play(true);
    game_object->add_component(animator);

    return game_object;
}

std::vector<std::vector<std::string>> TreeFactory::animation_paths = {
        {
                {"./assets/trees/tree1/tree1_center.png"},
                {"./assets/trees/tree1/tree1_right_1.png"},
                {"./assets/trees/tree1/tree1_right_2.png"},
                {"./assets/trees/tree1/tree1_right_1.png"},
                {"./assets/trees/tree1/tree1_center.png"},
                {"./assets/trees/tree1/tree1_left.png"},
        },
        {
                {"./assets/trees/tree2/tree2_center.png"},
                {"./assets/trees/tree2/tree2_right.png"},
                {"./assets/trees/tree2/tree2_center.png"},
                {"./assets/trees/tree2/tree2_left_1.png"},
                {"./assets/trees/tree2/tree2_left_2.png"},
                {"./assets/trees/tree2/tree2_left_1.png"},
        },
};