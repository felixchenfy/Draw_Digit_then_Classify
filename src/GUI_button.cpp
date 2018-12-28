
#include "common_headers.h"
#include "GUI_lib.h"
#include "GUI_button.h"
using namespace std;

Button::Button(Rect4f rect4f, BUTTON_TYPE bt, sf::RenderWindow *p_window) : _rect4f(rect4f), _bt(bt), _p_window(p_window)
{

    // set sf::RectangleShape
    sf::RectangleShape rect;
    float width = rect4f.x2 - rect4f.x1;
    float height = rect4f.y2 - rect4f.y1;
    float x = rect4f.x1, y = rect4f.y1;
    rect.setSize(sf::Vector2f(width, height));
    rect.setOutlineColor(sf::Color::Black);
    rect.setOutlineThickness(5);
    rect.setPosition(x, y);
    _rect = rect;

    // set sf::Font
    string FONT_PATH = "./fonts/Times-New-Roman.ttf";
    // string font_path="./fonts/TabarraPro-Black-FFP.ttf";
    if (!_font.loadFromFile(FONT_PATH))
    {
        cout << "Error loading font from " + FONT_PATH << endl;
    }

    // set sf::Text
    if (_bt == BUTTON_TYPE::NONE)
    {
        string str = "";
        _text = createText(str, _font, x + 70, y + 35);
        _text.setCharacterSize(50);
    }
    else if (_bt == BUTTON_TYPE::CLASSIFY)
    {
        string str = "press to \nClassify";
        _text = createText(str, _font, x + 30, y + 20);
    }
    else if (_bt == BUTTON_TYPE::CLEAR)
    {
        string str = "press to \n  Clear";
        _text = createText(str, _font, x + 30, y + 20);
    }
}
bool Button::checkClick(float x, float y)
{
    return (x >= _rect4f.x1) && (x <= _rect4f.x2) &&
           (y >= _rect4f.y1) && (y <= _rect4f.y2);
}

void Button::draw_to_window()
{
    _p_window->draw(_rect);
    _text.setFont(_font); // This is so weired. If I put this sentence in the construct, it gives a segmentation fault error.
    _p_window->draw(_text);
}
