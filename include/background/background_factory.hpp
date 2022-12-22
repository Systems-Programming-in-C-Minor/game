#ifndef BACKGROUND_FACTORY_HPP
#define BACKGROUND_FACTORY_HPP

#include <memory>
#include <string>
#include <vector>

class Scene;
class Animator;

class BackgroundFactory
{
public:
	explicit BackgroundFactory(std::vector<std::string> paths, int ptm, int resolution, int min_fps = 0, int max_fps = 3);
	void get(Scene& scene, int x, int y, int order_in_layer = -1);
	void get_static(Scene & scene, int x, int y, int order_in_layer = -1);
	void get(Scene& scene, int x, int y, int origin_x, int origin_y, int order_in_layer = -1);
private:
	std::vector<std::string> _paths;
	int _ptm;
	int _min_fps;
	int _max_fps;
	int _resolution;

	std::shared_ptr<Animator> get_tile(int order_in_layer = -1);
};

#endif // BACKGROUND_FACTORY_HPP