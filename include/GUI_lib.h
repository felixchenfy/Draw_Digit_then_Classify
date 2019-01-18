
#ifndef _GUI_LIB_H_
#define _GUI_LIB_H_

#include "common_headers.h"
#include "GUI_button.h"
using namespace std;

extern const int WINDOW_HEIGHT;
extern const int WINDOW_WIDTH;
extern const int RADIUS_OF_DRAWING;

// ----------- Math funtions ----------- 

float calc_dist(float x1, float y1, float x2, float y2);

// ----------- functions for SFML window ----------- 

void clear_window(sf::RenderWindow& window);
sf::Text createText(string str_text, sf::Font &font, float x, float y);
sf::Image captureWindow(sf::RenderWindow& window);

// ----------- GUI functions ----------- 

vector<Button> setup_buttons(sf::RenderWindow *p_window);


// Check if mouse is pressed, and pressed while moving
void isMousePressed(sf::Event event,
    bool &mouse_first_press, bool &mouse_pressed_moving);

// Draw circle to the window
sf::CircleShape draw_circle(float x, float y);

// Draw a bunch of circles to window,
//  between (x, y) and last circle with a min_dist_gap
void add_circles_between_xy_and_lastone(
    float x, float y, std::vector<sf::CircleShape> &circles,
    int min_dist_gap=5);
    
#endif

