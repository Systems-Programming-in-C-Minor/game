#include "objects/high_score_ui_factory.hpp"

std::shared_ptr<GameObject>
HighScoreUIFactory::get(const std::string &new_high_score, const std::string& level_name) {

    Transform level1 {Vector2d{10.f, -90.f}, Vector2d{}, 0.0f, 1.f};
    Transform level2 {Vector2d{-42.f, -85.f}, Vector2d{}, 0.f, 0.8f};

    auto high_score_ui = std::make_shared<GameObject>(
            "show-high-score", "high-score", level_name == "level 1" ? level1 : level2);
    high_score_ui->add_component(
            std::make_shared<Text>(new_high_score, "./assets/fonts/roboto/Roboto-Medium.ttf", 350, 10,
                                   Color{255, 255, 255, 0}, Color{0, 0, 0, 1}, 1));
    return high_score_ui;
}
