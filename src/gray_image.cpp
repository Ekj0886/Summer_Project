#include "gray_image.h"

GrayImage::GrayImage() : Image(0, 0), pixels(nullptr){};

GrayImage::GrayImage(int width, int height, int **pixels) : Image(width, height), pixels(pixels){};

GrayImage::~GrayImage() {
    for(int i = 0; i < h; ++i) delete[] pixels[i];
    delete[] pixels;
}

bool GrayImage::LoadImage(string file) {
    pixels = data_loader.Load_Gray(file, &w, &h); // get pixels, w, h based on file
    return (pixels != nullptr);
}

void GrayImage::DumpImage(string file) {
    data_loader.Dump_Gray(w, h, pixels, string("Gray_" + file));
    return;
}

void GrayImage::Display_ASCII() {
    data_loader.Display_Gray_ASCII(w, h, pixels);
    return;
}

void GrayImage::Display_CMD() {
    string file = "CMD_Gray.jpg";
    data_loader.Dump_Gray(w, h, pixels, file);
    data_loader.Display_Gray_CMD(file);
    const string cmd_str = "rm" + file;
    system(cmd_str.c_str());
    return;
}

