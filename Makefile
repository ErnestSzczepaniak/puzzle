all:
	g++ -std=c++1z main.cpp source/display.cpp source/game.cpp source/item_generic.cpp source/item_square.cpp -Iinclude/ -lX11 -o puzzle.elf

doxy:
	mkdir -p doxygen/
	doxygen doxyconfig