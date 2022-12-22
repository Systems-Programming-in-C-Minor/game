#include "background/background_factory.hpp"
#include "scene.hpp"
#include "components/animator.hpp"
#include "utils/random.hpp"

#include <memory>

#include "background/tree_factory.hpp"


BackgroundFactory::BackgroundFactory(std::vector<std::string> paths, int ptm, int resolution, int min_fps, int max_fps) :
	_paths(std::move(paths)),
	_ptm(ptm),
	_min_fps(min_fps),
	_max_fps(max_fps),
	_resolution(resolution)
{}

void BackgroundFactory::get(Scene& scene, int x, int y, int order_in_layer)
{
	for(int i = -x+1; i < x; ++i) {
		for(int j = -y+1; j < y; ++j) {
			const auto gameobject = std::make_shared<GameObject>(
			"bg_image", 
			"bg", Transform{Vector2d{static_cast<float>(_resolution/_ptm*i), static_cast<float>(_resolution/_ptm*j)}, Vector2d{}});
			gameobject->add_component(std::make_shared<Sprite>(_paths[0], -1, _ptm));
			gameobject->add_component(get_tile(order_in_layer));
			scene.gameobjects.push_back(gameobject);
		}
	}
}

void BackgroundFactory::get_static(Scene& scene, int x, int y, int order_in_layer)
{
	for(int i = -x+1; i < x; ++i) {
		for(int j = -y+1; j < y; ++j) {
			const auto gameobject = std::make_shared<GameObject>(
			"bg_image", 
			"bg", Transform{Vector2d{static_cast<float>(_resolution/_ptm*i), static_cast<float>(_resolution/_ptm*j)}, Vector2d{}});
			int random = Random::random(static_cast<int>(_paths.size()-1), 0);
			gameobject->add_component(std::make_shared<Sprite>(_paths[random], -1, _ptm));
			scene.gameobjects.push_back(gameobject);
		}
	}
}

void BackgroundFactory::get(Scene& scene, int x, int y, int origin_x, int origin_y, int order_in_layer)
{
	for(int i = origin_x+1; i < origin_x+x; ++i) {
		for(int j = origin_y+1; j < origin_y+y; ++j) {
			const auto gameobject = std::make_shared<GameObject>(
			"bg_"+std::to_string(i)+"_"+std::to_string(j), 
			"bg", Transform{Vector2d{static_cast<float>(_resolution/_ptm*i), static_cast<float>(_resolution/_ptm*j)}, Vector2d{}});
			gameobject->add_component(std::make_shared<Sprite>(_paths[0], -1, _ptm));
			gameobject->add_component(get_tile(order_in_layer));
			scene.gameobjects.push_back(gameobject);
		}
	}
}

std::shared_ptr<Animator> BackgroundFactory::get_tile(int order_in_layer)
{
	std::vector<std::shared_ptr<Sprite>> sprites;
	sprites.reserve(_paths.size());
	for (auto& path : _paths)	{
		sprites.push_back(std::make_shared<Sprite>(path, order_in_layer, _ptm));
	}
	auto animator = std::make_shared<Animator>(sprites, Random::random(_max_fps, _min_fps));
	animator->play(true);
	return animator;
}

