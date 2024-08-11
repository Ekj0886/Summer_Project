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

void RGBImage::Box_Filter(int k) {

    cout << "use Box Filter" << endl;
    
    int **buff = new int*[h];
    k /= 2;

    for(int c = 0; c < 3; c++) {
        for(int i = 0; i < h; i++) {
            buff[i] = new int[w];
            for(int j = 0; j < w; j++) {
                buff[i][j] = 0;
                int coef = 0;

                for(int i_k = i - k; i_k <= i + k; i_k++) {
                    for(int j_k = j - k; j_k <= j + k; j_k++) {
                        if(i_k >= 0 && i_k < h && j_k >= 0 && j_k < w) {
                            buff[i][j] += pixels[i_k][j_k][c];
                            coef ++;
                        }
                    }
                }
                buff[i][j] /= coef;

            }
        }

        for(int i = 0; i < h; i++) {
            for(int j = 0; j < w; j++) {
                pixels[i][j][c] = buff[i][j];
            }
        }

    }

    for(int i = 0; i < h; i++) delete[] buff[i];
    delete[] buff;

    return;

}

void RGBImage::Sobel_Filter() {
    cout << "use Sobel Filter" << endl;
}

void RGBImage::Contrast_Filter() {
    cout << "use Contrast Filter" << endl;
}

void RGBImage::Mosaic_Filter() {
    cout << "use Mosaic Filter" << endl;
}