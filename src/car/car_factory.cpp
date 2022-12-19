
#include <map>
#include "car/car_factory.hpp"

std::shared_ptr<Car>
CarFactory::get(const std::string &name, CarColor color, Vector2d position, const std::shared_ptr<Scene> &scene) {
    const std::map<CarColor, std::string> sprites{
            {Blue,   "./assets/cars/blue_car.png"},
            {Red,    "./assets/cars/red_car.png"},
            {Yellow, "./assets/cars/yellow_car.png"},
            {Green,  "./assets/cars/green_car.png"},
            {Orange, "./assets/cars/orange_car.png"},
            {Pink,   "./assets/cars/pink_car.png"},
            {Purple, "./assets/cars/purple_car.png"},
            {Black,  "./assets/cars/black_car.png"},
    };

    return std::make_shared<Car>(name, sprites.at(color), position, scene);
}

