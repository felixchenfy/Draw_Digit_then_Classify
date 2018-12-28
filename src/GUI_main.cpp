

#include "common_headers.h"
#include "GUI_lib.h"
#include "GUI_button.h"
#include "digit_classifier.h"
using namespace std;

const int WINDOW_HEIGHT = 400;
const int WINDOW_WIDTH = 570;
const int RADIUS_OF_DRAWING = 15;

int main()
{
    sf::RenderWindow window;
    window.create(sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), "Draw_and_Classify_Digit");
    // sf::RenderWindow window(sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), "Draw_and_Classify_Digit");
    clear_window(window);

    std::vector<sf::CircleShape> circles;
    bool mouse_first_press = false, mouse_pressed_moving = false; // mouse states, whether pressed or not

    vector<Button> buttons = setup_buttons(&window);

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed || sf::Keyboard::isKeyPressed(sf::Keyboard::Q))
                window.close();

            isMousePressed(event, mouse_first_press, mouse_pressed_moving);
            sf::Vector2f mouse_pos = sf::Vector2f(sf::Mouse::getPosition(window));
            float x = mouse_pos.x, y = mouse_pos.y;

            if (mouse_first_press)
            {
                // Add a circle if mouse is pressed
                circles.push_back(draw_circle(x, y));
            }

            if (mouse_pressed_moving)
            {
                // Add many circles between the new circle and last circle, to fill the gap
                add_circles_between_xy_and_lastone(x, y, circles);
            }

            // detect button clicks
            for (auto button : buttons)
            {
                if (mouse_first_press && button.checkClick(x, y))
                {
                    switch (button.getButtonType())
                    {

                    case BUTTON_TYPE::NONE:
                    {
                        // This button area is only for displaying image
                    }
                    break;

                    case BUTTON_TYPE::CLASSIFY:
                    {
                        cout << "Press button: CLASSIFY" << endl;
                        sf::Image screenshot = captureWindow(window);
                        // screenshot.saveToFile("./test/test_image.png");
                        Image2d image_for_classify = resize_sfImage_to_28x28(screenshot);
                        int digit_value = classify_digit(image_for_classify);
                        buttons[0].setButtonString(to_string(digit_value));
                    }
                    break;

                    case BUTTON_TYPE::CLEAR:
                    {
                        cout << "Press button: CLEAR" << endl;
                        buttons[0].setButtonString("");
                        circles.clear();
                    }
                    break;
                    }
                }
            } // end of checking 3 buttons
        } // end while (window.pollEvent(event))

        // clear and draw
        clear_window(window);

        for (const auto &c : circles) // many circles form the digit
            window.draw(c);

        for (auto &b : buttons) // draw button
            b.draw_to_window();
        window.display();

    } // end while (window.isOpen())
}