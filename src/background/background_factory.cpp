#include "background/background_factory.hpp"
#include "scene.hpp"
#include "components/animator.hpp"

#include <memory>


BackgroundFactory::BackgroundFactory(std::vector<std::string> paths) : _paths(std::move(paths))
{

}

void BackgroundFactory::get(Scene& scene, int x, int y)
{
	for(int i = 0; i < x; ++i) {
		for(int j = 0; j < y; ++j) {
			const auto gameobject = std::make_shared<GameObject>(
			"bg_"+std::to_string(i)+"_"+std::to_string(j), 
			"bg", Transform{Vector2d{64.f*static_cast<float>(i), 64.f*static_cast<float>(j)}});
			gameobject->add_component(get_tile());

		}
	}
}

std::shared_ptr<Animator> BackgroundFactory::get_tile(int fps, int ptm)
{
	std::vector<std::shared_ptr<Sprite>> sprites;
	for (auto& path : _paths)	{
		sprites.push_back(std::make_shared<Sprite>(path, -1, ptm));
	}
	auto animator = std::make_shared<Animator>(sprites, fps);
	return animator;
}

