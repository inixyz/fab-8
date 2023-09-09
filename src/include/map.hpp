#pragma once

#include <vector>
#include <list>

namespace dcm{
	class Map{
	private:
		struct Position{
			unsigned int x, y;
		};

		struct WireGroup{
			bool state;
			std::vector<Position> connected_inputs;
		};

		struct Cell{
			enum Type{
				EMPTY, WIRE, GATE
			}type;

			union{
				WireGroup* wire_group;
				void (*behaviour)();
			};
		};

	public:
		size_t width, height;
		std::vector<std::vector<Cell>> cells;
		std::list<WireGroup> wire_groups;

	public:
		void reset(size_t width, size_t height);
	};

	extern Map map;
}