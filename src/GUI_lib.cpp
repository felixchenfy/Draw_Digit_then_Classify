
#include "common_headers.h"
#include "GUI_lib.h"
#include "GUI_button.h"
using namespace std;


float calc_dist (float x1, float y1, float x2, float y2){
    float dx=x1-x2, dy=y1-y2;
    return sqrt(dx*dx+dy*dy); 
} 
void clear_window(sf::RenderWindow& window){
    window.clear(sf::Color::White);
}
sf::Image captureWindow(sf::RenderWindow& window){
    // sf::Image screenshot = window.capture();
    sf::Vector2u windowSize = window.getSize();
    sf::Texture texture;
    texture.create(windowSize.x, windowSize.y);
    texture.update(window);
    sf::Image screenshot = texture.copyToImage();
    return screenshot;
}

sf::Text createText(string str_text, sf::Font &font, float x, float y)
{
    sf::Text text;
    text.setFont(font);
    text.setString(str_text);
    // text.setString(str_text);
    text.setCharacterSize(30); // in pixels, not points!
    text.setFillColor(sf::Color::Black);
    text.setStyle(sf::Text::Bold);
    text.setPosition(sf::Vector2f(x, y));
    return text;
}


vector<Button> setup_buttons(sf::RenderWindow *p_window)
{
    const int NUM_BUTTONS = 3;
    float x1 = WINDOW_HEIGHT, x2 = WINDOW_WIDTH;
    float dy = 1.0 * WINDOW_HEIGHT / NUM_BUTTONS;
    vector<Button> buttons;
    BUTTON_TYPE bts[NUM_BUTTONS] = {BUTTON_TYPE::NONE, BUTTON_TYPE::CLASSIFY, BUTTON_TYPE::CLEAR};
    for (int i = 0; i < NUM_BUTTONS; i++)
    {
        Rect4f rect4f{
            x1 : x1,
            y1 : dy * i,
            x2 : x2,
            y2 : dy * (i + 1)
        };
        // cout << rect4f.x1 << ", "<< rect4f.x2 << ", "<< rect4f.y1 <<  ", "<< rect4f.y2 << endl;
        Button button(rect4f, bts[i], p_window);
        buttons.push_back(button);
    }
    return buttons;
}

void isMousePressed(sf::Event event, bool &mouse_first_press, bool &mouse_pressed_moving)
{
    static bool mouse_pressed = false;
    bool prev_mouse_pressed = mouse_pressed;
    // update mouse press state
    if (event.type == sf::Event::MouseButtonPressed &&
        event.mouseButton.button == sf::Mouse::Left)
    {
        mouse_pressed = true;
    }
    else if (event.type == sf::Event::MouseButtonReleased &&
             event.mouseButton.button == sf::Mouse::Left)
    {
        mouse_pressed = false;
    }
    // return mouse state
    mouse_first_press = false;
    mouse_pressed_moving = false;
    if (prev_mouse_pressed == false && mouse_pressed == true)
    {
        mouse_first_press = true;
    }
    else if (mouse_pressed && event.type == sf::Event::MouseMoved)
    {
        mouse_pressed_moving = true;
    }
    return;
}

sf::CircleShape draw_circle(float x, float y)
{

    // draw circle to window
    sf::CircleShape circle(RADIUS_OF_DRAWING);
    circle.setPosition(sf::Vector2f(x-RADIUS_OF_DRAWING, y-RADIUS_OF_DRAWING));
    circle.setFillColor(sf::Color::Black);

    // draw circle to the image
    return circle;

}

void add_circles_between_xy_and_lastone(float x, float y, 
    std::vector<sf::CircleShape> &circles,
    int min_dist_gap)
{
    if (circles.empty())
        return;
    sf::Vector2f p2 = circles.back().getPosition();
    float p1x=x, p1y=y;
    float p2x=p2.x+RADIUS_OF_DRAWING, p2y=p2.y+RADIUS_OF_DRAWING;
    float dist=calc_dist(p1x, p1y, p2x, p2y);
    int num_new_circles = floor(dist / min_dist_gap) + 1;
    for (int i = 1; i <= num_new_circles; i++)
    {
        sf::Vector2f p(
            p2x + (p1x - p2x) * i / num_new_circles,
            p2y + (p1y - p2y) * i / num_new_circles);
        circles.push_back(draw_circle(p.x, p.y));
    }
    return;
}