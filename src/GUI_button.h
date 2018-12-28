
#ifndef _GUI_BUTTON_H
#define _GUI_BUTTON_H

#include "common_headers.h"
using namespace std;


typedef struct _Rect4f
{
    float x1, y1, x2, y2;
} Rect4f;

typedef enum _BUTTON_TYPE
{
    NONE,
    CLASSIFY,
    CLEAR
} BUTTON_TYPE;

class Button
{
  private:
    Rect4f _rect4f;
    BUTTON_TYPE _bt;
    sf::Text _text;
    sf::Font _font;
    sf::RectangleShape _rect;
    sf::RenderWindow *_p_window;

  public:
    // Button(): _rect4f{0,0,0,0}{}
    Button(Rect4f rect4f, BUTTON_TYPE bt, sf::RenderWindow *p_window);
    bool checkClick(float x, float y);
    void draw_to_window();
    BUTTON_TYPE getButtonType(){return _bt;}
    void setButtonString(string s){_text.setString(s);}
};

#endif