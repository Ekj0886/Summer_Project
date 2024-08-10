#ifndef _GRAY_IMAGE_H_
#define _GRAY_IMAGE_H_

#include "image.h"

class GrayImage : public Image{
private:
    int **pixels;
public:
    GrayImage();
    GrayImage(int width, int height, int **pixels);
    ~GrayImage();
    bool LoadImage(string file);
    void DumpImage(string file);
    void Display_ASCII();
    void Display_CMD();
};

#endif