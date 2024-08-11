#ifndef _RGB_IMAGE_H_
#define _RGB_IMAGE_H_

#include "image.h"

class RGBImage : public Image {

private:
    int ***pixels;
    
public:
    RGBImage();
    RGBImage(int width, int height, int ***pixels);
    ~RGBImage();
    bool LoadImage(string file);
    void DumpImage(string file);
    void Display_ASCII();
    void Display_CMD();

    void Box_Filter  (int k, string out_img);
    void Sobel_Filter();
    void Contrast_Filter();
    void Mosaic_Filter();
    friend class PhotoMosaic;
};

#endif