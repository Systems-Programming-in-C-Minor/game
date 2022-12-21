#ifndef GAME_TRACK_FACTORY_HPP
#define GAME_TRACK_FACTORY_HPP

#include <optional>
#include "gameobject.hpp"
#include "string"

class TrackFactory {
public:
    static std::shared_ptr<GameObject>
    get(const std::string &name, const std::shared_ptr<Scene> &scene, std::string sprite_path, float pixels_to_meters,
        const std::vector<std::string> &track_inner_paths = {},
        std::optional<std::string> track_outer_path = std::nullopt, std::optional<std::string> bg_sprite_path = std::nullopt);
};

#endif //GAME_TRACK_FACTORY_HPP
