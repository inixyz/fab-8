#include "map.hpp"

using namespace dcm;

Map dcm::map;

void Map::reset(size_t width, size_t height){
	cells = std::vector<std::vector<Cell>>(width, std::vector<Cell>(height));
}