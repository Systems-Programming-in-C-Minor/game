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
	explicit BackgroundFactory(std::vector<std::string> paths);
	void get(Scene& scene, int x, int y);
private:
	std::vector<std::string> _paths;

	std::shared_ptr<Animator> get_tile(int fps = 1, int ptm = 8);
};

#endif // BACKGROUND_FACTORY_HPP