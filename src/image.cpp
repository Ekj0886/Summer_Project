#include <bits/stdc++.h>
#include "image.h"

#define F first 
#define S second

using namespace std;

Image::Image(int width, int height) {
    w = width;
    h = height;
}

int Image::get_w() {
    return w;
}

int Image::get_h() {
    return h;
}
