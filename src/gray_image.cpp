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
    data_loader.Dump_Gray(w, h, pixels, string(file));
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
    const string cmd_str = "rm " + file;
    system(cmd_str.c_str());
    return;
}

void GrayImage::Box_Filter(int k) {
    
    cout << "use Box Filter" << endl;
    
    int **buff = new int*[h];
    k /= 2;

    for(int i = 0; i < h; i++) {
        buff[i] = new int[w];
        for(int j = 0; j < w; j++) {
            buff[i][j] = 0;
            int coef = 0;
            for(int i_k = i - k; i_k <= i + k; i_k++) {
                for(int j_k = j - k; j_k <= j + k; j_k++) {
                    if(i_k >= 0 && i_k < h && j_k >= 0 && j_k < w) {
                        buff[i][j] += pixels[i_k][j_k];
                        coef ++;
                    }
                }
            }
            buff[i][j] /= coef;
            
        }
    }

    for(int i = 0; i < h; i++) {
        for(int j = 0; j < w; j++) {
            pixels[i][j] = buff[i][j];
        }
    }

    for(int i = 0; i < h; i++) delete[] buff[i];
    delete[] buff;

    return;
    
}

void GrayImage::Sobel_Filter() {
    cout << "use Sobel Filter" << endl;
}

void GrayImage::Contrast_Filter() {
    cout << "use Contrast Filter" << endl;
}

void GrayImage::Mosaic_Filter() {
    cout << "use Mosaic Filter" << endl;
}