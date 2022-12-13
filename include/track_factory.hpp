#ifndef GAME_TRACK_FACTORY_HPP
#define GAME_TRACK_FACTORY_HPP

#include "gameobject.hpp"
#include "string"

class TrackFactory {
public:
    static std::shared_ptr<GameObject>
    get(const std::string &name, const std::string &tag, std::string sprite_path, std::string track_inner_path,
        std::string track_outer_path, const std::shared_ptr<Scene> &scene);
};

#endif //GAME_TRACK_FACTORY_HPP
