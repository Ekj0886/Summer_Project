#ifndef _RGB_IMAGE_H_
#define _RGB_IMAGE_H_

#include "image.h"

class RGBImage : public Image{
private:
    int ***pixels;
public:
    RBGImage();
    RBGImage(int width, int height, int ***pixels);
    ~RGBImage();
    bool LoadImage(string file);
    void DumpImage(string file);
    void Display_ASCII();
    void Display_CMD();
};

#endif