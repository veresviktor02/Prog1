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

    Simple_window win {Point{100,100}, xmax, ymax, "Kanvasz"};

    int height = 100;
    int width = 100;

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

    //átlós négyzetek megcsinálása
    
    int atlox = 0;
    int atloy = 0;

    Vector_ref<Rectangle> rekt;
	for (int i = 0; i < 8; ++i)
	{
		rekt.push_back(new Rectangle{Point{atlox,atloy},100,100});
		rekt[rekt.size()-1].set_fill_color(Color::red);
		atlox += 100;
		atloy += 100;
	}
    
    for (int i = 0; i < rekt.size(); ++i)
    {
        win.attach(rekt[i]);
    }

    Image kep1 {Point{200,200},"badge.jpg"};
	Image kep2 {Point{600,600},"badge.jpg"};
	Image kep3 {Point{400,800},"badge.jpg"};

    win.attach(kep1);
    win.attach(kep2);
    win.attach(kep3);

    Image ketszaz {Point{0,0}, "200.png"};
    win.attach(ketszaz);
    win.wait_for_button();

    for (int i = 0; i < 8; ++i)
    {
        for (int j = 0; j < 7; ++j)
        {
            ketszaz.move(100, 0);
            win.wait_for_button();
        }
        ketszaz.move(-700, 100);
        win.wait_for_button();
    }

    win.wait_for_button();
}