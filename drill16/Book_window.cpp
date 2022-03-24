#include "Book_window.h"

Book_window::Book_window(Point xy, int w, int h, const string& title)
    :Window{xy,w,h,title},
    next_button{Point{x_max()-300,0}, 150, 40, "Next point",
        [](Address, Address pw) {reference_to<Book_window>(pw).next();}},
    quit_button{Point{x_max()-150,0}, 150, 40, "Quit",
        [](Address, Address pw) {reference_to<Book_window>(pw).quit();}},
    next_x{Point{300,0}, 50, 40, "next x:"},
    next_y{Point{450,0}, 50, 40, "next y:"},
    xy_out{Point{100,0}, 100, 40, "current (x,y):"},

    color_menu_button{Point{x_max()-300, 40}, 150, 40, "Colors",
    	[](Address, Address pw) {reference_to<Book_window>(pw).toggle_color_menu();}},
    color_menu{Point{x_max()-300, 40}, 150, 40, Menu::vertical, "color"},

    line_style_menu_button{Point{x_max()-150, 40}, 150, 40, "Line Styles",
    	[](Address, Address pw) {reference_to<Book_window>(pw).toggle_line_style_menu();}},
    line_style_menu{Point{x_max()-150, 40}, 150, 40, Menu::vertical, "lines"}
{
    attach(next_button);
    attach(quit_button);
    attach(next_x);
    attach(next_y);
    attach(xy_out);
    attach(lines);

    attach(color_menu_button);
    attach(line_style_menu_button);

    color_menu.attach(new Button{Point{0, 0}, 0,0, "Red", 
        [](Address, Address pw) {reference_to<Book_window>(pw).change_color(Color::red);} });  
      
    color_menu.attach(new Button{Point{0, 0}, 0,0, "Blue", 
        [](Address, Address pw) {reference_to<Book_window>(pw).change_color(Color::blue);} }); 
    
    color_menu.attach(new Button{Point{0, 0}, 0,0, "Black", 
        [](Address, Address pw) {reference_to<Book_window>(pw).change_color(Color::black);} }); 

    color_menu.attach(new Button{Point{0, 0}, 0,0, "Green", 
        [](Address, Address pw) {reference_to<Book_window>(pw).change_color(Color::green);} }); 

    attach(color_menu);    
    color_menu.hide();  

    line_style_menu.attach(new Button{Point{0, 0}, 0,0, "Solid", 
        [](Address, Address pw) {reference_to<Book_window>(pw).change_line_style(Line_style::solid);} });  
      
    line_style_menu.attach(new Button{Point{0, 0}, 0,0, "Dashed", 
        [](Address, Address pw) {reference_to<Book_window>(pw).change_line_style(Line_style::dash);} });  
      
    line_style_menu.attach(new Button{Point{0, 0}, 0,0, "Dotted", 
        [](Address, Address pw) {reference_to<Book_window>(pw).change_line_style(Line_style::dot);} });  
 
    attach(line_style_menu);
    line_style_menu.hide();
}

void Book_window::change_color(Color color)
{ 
	lines.set_color(color); 
	toggle_color_menu();
}

void Book_window::change_line_style(Line_style style)
{
	lines.set_style(style);
	toggle_line_style_menu();
}

void Book_window::toggle_color_menu()
{
    if(isColorMenuShown)
    {
        color_menu.hide();
        color_menu_button.show();
    }
    else
    {
        color_menu.show();
        color_menu_button.hide();
    }
    
    isColorMenuShown = !isColorMenuShown;
}

void Book_window::toggle_line_style_menu(){
	if(isLineStyleMenuShown){
		line_style_menu.hide();
		line_style_menu_button.show();
	} else {
		line_style_menu.show();
		line_style_menu_button.hide();
	}
	
	isLineStyleMenuShown = !isLineStyleMenuShown;
}

void Book_window::quit()
{
    hide();
}

void Book_window::next()
{
    int x = next_x.get_int();
    int y = next_y.get_int();

    lines.add(Point{x,y});

    ostringstream ss;
    ss << '(' << x << ',' << y << ')';

    xy_out.put(ss.str());

    redraw();
}