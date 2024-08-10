#include "rgb_image.h"

RGBImage::RGBImage() : Image(0, 0), pixels(nullptr){};

RGBImage::RGBImage(int width, int height, int ***pixels) : Image(width, height), pixels(pixels){};

RGBImage::~RGBImage() {
    for(int i = 0; i < h; i++) {
        for(int q = 0; q < w; q++) {
            delete[] pixels[i][q];
        }delete[] pixels[i];
    }
    delete[] pixels;
    return;
}

bool RGBImage::LoadImage(string file) {
    pixels = data_loader.Load_RGB(file, &w, &h); // get pixels, w, h based on file
    return(pixels != nullptr);
}

void RGBImage::DumpImage(string file) {
    data_loader.Dump_RGB(w, h, pixels, file);
    return;
}

void RGBImage::Display_ASCII() {
    data_loader.Display_RGB_ASCII(w, h, pixels);
    return;
}

void RGBImage::Display_CMD() {
    string file = "CMD_RGB.jpg";
    data_loader.Dump_RGB(w, h, pixels, file);
    data_loader.Display_RGB_CMD(file);
    const string cmd_str = "rm " + file;
    system(cmd_str.c_str());
    return;
}