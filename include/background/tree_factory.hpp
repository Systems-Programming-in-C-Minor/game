
#ifndef GAME_TREE_FACTORY_HPP
#define GAME_TREE_FACTORY_HPP

#include "gameobject.hpp"

class TreeFactory {

public:
    enum TreeType {
        Tree1 = 0,
        Tree2
    };

    static std::shared_ptr<GameObject> get(TreeType tree_type, Vector2d position);

private:
    static std::vector<std::vector<std::string>> animation_paths;
};

#endif //GAME_TREE_FACTORY_HPP
