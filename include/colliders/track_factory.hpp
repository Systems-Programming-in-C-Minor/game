#ifndef GAME_TRACK_FACTORY_HPP
#define GAME_TRACK_FACTORY_HPP

#include <optional>
#include "gameobject.hpp"
#include "string"

class TrackFactory {
public:
    static std::shared_ptr<GameObject>
    get(const std::string &name, const std::shared_ptr<Scene> &scene, std::string sprite_path, std::string bg_sprite_path, const std::string& track_inner_path,
        const std::string& track_outer_path);
};

#endif //GAME_TRACK_FACTORY_HPP
