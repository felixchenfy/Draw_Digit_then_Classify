
# ifndef _DIGIT_CLASSIFIER_
# define _DIGIT_CLASSIFIER_

#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <math.h>
#include <climits>

#include <SFML/Graphics.hpp>

using namespace std;
typedef unsigned char uchar;
typedef vector<vector<uchar>> myImage;

myImage resize_sfImage_to_28x28(sf::Image image);
int classify_digit(vector<vector<uchar>> image_for_classify);

uchar getPixel_uint8(sf::Image image, int x, int y); // This is incredibly slow.
uchar getPixel_uint8(const uchar* pByteBuffer, int x, int y, int cols);

#endif