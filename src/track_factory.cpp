#include "track_factory.hpp"

GameObject TrackFactory::get(const std::string& name, const std::string& tag, const std::string& sprite_path) {
    return GameObject(name, tag);
}
