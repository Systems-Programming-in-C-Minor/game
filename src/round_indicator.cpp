#include "round_indicator.hpp"

#include "uiobjects/text.hpp"
#include "enums/alignment.hpp"
#include "color.hpp"

GameObject RoundIndicator::get(const std::string& name, const std::string& tag, Car& playerCar) {
    GameObject obj(name, tag);

    std::shared_ptr<Text> text = std::make_shared<Text>(name, tag, 10, 10, std::to_string(playerCar.get_current_round()), "Calibri", 10, Alignment::CENTER, Color(0,0,0,0));
    obj.add_child(text);

    return obj;
}
