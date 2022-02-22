#include "Simple_window.h"
#include "Graph.h"

/*
g++ drill.cpp Graph.cpp Window.cpp GUI.cpp Simple_window.cpp -o drill `fltk-config --ldflags --use-images` -std=c++11
*/

int main()
{
    using namespace Graph_lib;

    int xmax = 800;
    int ymax = 1000;

    Simple_window win {Point{100,100}, xmax, ymax, "Canvas"};

    int height = 100;
    int width = 100;

    Lines valami;
    Lines uj;

    //8 by 8 négyzet

    //vízszintes vonalak
    for(int i = 0; i < ymax/height+1; i++)
    {
        uj.add(Point{1,height*i}, Point{xmax-1,height*i});
        win.attach(uj);
    }

    //függőleges vonalak
    for(int i = 0; i < ymax/width+1; i++)
    {
        uj.add(Point{width*i, 1}, Point{width*i,ymax-1});
        win.attach(uj);
    }

    win.wait_for_button();
}