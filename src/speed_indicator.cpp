#include "speed_indicator.hpp"

#include "uiobjects/text.hpp"

GameObject SpeedIndicator::get(const std::string &name, const std::string &tag, Car &playerCar) {
    GameObject obj(name, tag);

//    std::shared_ptr<Text> text = std::make_shared<Text>(name, tag, 10, 10, std::to_string(playerCar.get_current_speed()), "Calibri", 10, Alignment::CENTER, Color(0,0,0,0));
//    obj.add_child(text);

    return obj;
}