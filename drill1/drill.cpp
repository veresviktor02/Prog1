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

    /*
    for(int i = 0; i < xmax/width+1; i++) //hányszor fut le a for ciklus (vízszintesen)
    {
        for(int j = 0; j < ymax/height+1; j++) //hányszor fut le a for ciklus (függőlegesen)
        {
            valami.add(Point{width*i,height*j}, Point{width*i+100,height*j}); //két pontot köt össze
            win.attach(valami);
        }
    }
    */

    //függőleges vonalak ... in process
    for(int i = 0; i < ymax/height+1; i++)
    {
        uj.add(Point{1,height*i}, Point{xmax-1,height*i});
        win.attach(uj);
    }


    win.wait_for_button();
}