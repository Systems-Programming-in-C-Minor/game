
#include <map>
#include "car/car_factory.hpp"
#include "scene.hpp"
#include "components/audiosource.hpp"

#include "listeners/car_audio_listener.hpp"

std::shared_ptr<Car>
CarFactory::get(CarColor color, Vector2d position, const std::shared_ptr<Scene> &scene) {
    const std::map<CarColor, std::pair<std::string, std::string>> sprites
            {
                    {Blue,   std::pair("Blue  ", "./assets/cars/blue_car.png")},
                    {Red,    std::pair("Red   ", "./assets/cars/red_car.png")},
                    {Yellow, std::pair("Yellow", "./assets/cars/yellow_car.png")},
                    {Green,  std::pair("Green ", "./assets/cars/green_car.png")},
                    {Orange, std::pair("Orange", "./assets/cars/orange_car.png")},
                    {Pink,   std::pair("Pink  ", "./assets/cars/pink_car.png")},
                    {Purple, std::pair("Purple", "./assets/cars/purple_car.png")},
                    {Black,  std::pair("Black ", "./assets/cars/black_car.png")},
            };

    const auto car = std::make_shared<Car>(sprites.at(color).first, sprites.at(color).second, position, scene, false);
    return car;
}

