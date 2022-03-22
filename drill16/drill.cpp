/*
#include <FL/Fl.h>
#include <FL/Fl_Box.h>
#include <FL/Fl_Window.h>
*/


struct Lines_window : Window
{
        Lines_window(Point xy, int w, int h, const string& title);
        Open_polyline lines;
    private:
    Button next_button;
    // add (next_x,next_y) to lines
    Button quit_button;In_box next_x;
    In_box next_y;
    Out_box xy_out;
    void next();
    void quit();
};
/*
struct Lines_window : Window
{
    Lines_window(Point xy, int w, int h, const string& title);
    Open_polyline lines;
    Menu color_menu;
    static void cb_red(Address, Address);
    static void cb_blue(Address, Address);
    static void cb_black(Address, Address);
    // callback for red button
    // callback for blue button
    // callback for black button
    // the actions:
    void red_pressed() { change(Color::red); }
    void blue_pressed() { change(Color::blue); }
    void black_pressed() { change(Color::black); }
    void change(Color c) { lines.set_color(c); }
    // . . . as before . . .
};
*/

int main()
{
/*
Fl_Window window(200, 200, "Window title");
Fl_Box box(0,0,200,200, "Hey, I mean, Hello, World!");
window.show();
return Fl::run();
*/

Lines_window::Lines_window(Point xy, int w, int h, const string& title)
:Window{xy,w,h,title},
next_button{Point{x_max() - 150,0}, 70, 20, "Next point", [](Address, Address pw) 
{reference_to<Lines_window>(pw).next();},
quit_button{Point{x_max() - 70,0}, 70, 20, "Quit", [](Address, Address pw) 
{reference_to<Lines_window>(pw).quit();},
next_x{Point{x_max() - 310,0}, 50, 20, "next x:"},
next_y{Point{x_max() - 210,0}, 50, 20, "next y:"},
xy_out{Point{100,0}, 100, 20, "current (x,y):"}
{
attach(next_button);
attach(quit_button);
attach(next_x);
attach(next_y);
attach(xy_out);
attach(lines);

}

/*
1. Make a completely new project with linker settings for FLTK (as described in Appendix D).
2. Using the facilities of Graph_lib, type in the line-drawing program from §16.5 and get it to run.
3. Modify the program to use a pop-up menu as described in §16.7 and get it to run.
4. Modify the program to have a second menu for choosing line styles and get it to run.
*/