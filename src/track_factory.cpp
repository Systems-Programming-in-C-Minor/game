#include "track_factory.hpp"

#include <utility>

#include "components/sprite.hpp"
#include "color.hpp"

std::shared_ptr<GameObject>
TrackFactory::get(const std::string &name, const std::string &tag, std::string sprite_path) {
    std::shared_ptr<GameObject> obj = std::make_shared<GameObject>(name, tag);
    std::shared_ptr<Sprite> sprite = std::make_shared<Sprite>(std::move(sprite_path), Color(0, 0, 0, 0), false, false,
                                                              1, 1);
    obj->add_component(sprite);
    return obj;
}
