#ifndef BIT_FIELD_FILTER_H
#define BIT_FIELD_FILTER_H
#include <bits/stdc++.h>
#include "image.h"
#include "gray_image.h"
#include "rgb_image.h"

#define Box       0b00000001
#define Sobel     0b00000010
#define Contrast  0b00000100
#define Mosaic    0b00001000

using namespace std;

class Filter {

private:
    string file;

public:
    Filter(string filename);
    ~Filter();
    void PutFilter_Gray(int8_t option, string out_img);
    void PutFilter_RGB (int8_t option, string out_img);

};

#endif