
#include <iostream>
#include <ctime>
#include <vector>
#include <math.h>

#include <SFML/Graphics.hpp>
#include "../src/digit_classifier.h"

using namespace std;
typedef unsigned char uchar;
typedef vector<vector<uchar>> Image2d;

// testing by using the image generated from Python (by passing an empty vector)
void test_using_image_from_python(){
    Image2d image;
    int res_digit_value = classify_digit(image);
    cout << endl << "Recognition result: " << res_digit_value << endl;
    return;
};

// testing by using the image of ./test/test_image.png
void test_using_image_from_file(){

    // read a test image
    string image_filename="./test/test_image";
    sf::Image image;
    if(!image.loadFromFile(image_filename+".png")){
        cout << "Error: Failed to load image" << endl;
    }

    // resize the image
    Image2d image_for_classify = resize_sfImage_to_28x28(image);

    // recognize the digit in image
    int res_digit_value = classify_digit(image_for_classify);
    cout << endl << "Recognition result: " << res_digit_value << endl;

    // output the image to see if the above manipulation is correct
    sf::Image image_output;
    int image_length=image_for_classify.size();
    image_output.create(image_length, image_length, sf::Color::White);
    sf::Color color(0,0,0,255);
    for(int i=0;i<image_length;i++){
        for(int j=0;j<image_length;j++){
            uchar v = image_for_classify[i][j];
            color.r=v;
            color.g=v;
            color.b=v;
            image_output.setPixel(j, i, color);
        }
    }
    if (// Save the image to file
        !image_output.saveToFile(image_filename+"_resized"+".png"))
        cout<<"Error writing image to file"<<endl;

    return;
};

int main(){
    clock_t time_stt = clock(); // count time

    // test:
    // test_using_image_from_python();
    test_using_image_from_file();

    double time_cost=1000* (clock() - time_stt)/(double)CLOCKS_PER_SEC;
    cout <<"\nTime cost is " << time_cost << "ms"<< endl;
    cout<<"\n\n--------------------------------\n"; return 1;
}




