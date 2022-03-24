/*
    g++ drill.cpp Graph.cpp Window.cpp GUI.cpp Book_window.cpp -o ./drill `fltk-config --ldflags --use-images` -std=c++11
*/

#include "Book_window.h"
#include "Graph.h"

int main()
{
    using namespace Graph_lib;

	Book_window win{Point{100,100}, 1280, 720, "Drill 16"};

	return gui_main();

}