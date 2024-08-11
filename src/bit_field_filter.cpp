#include "bit_field_filter.h"

Filter::Filter(string filename) {
    file = filename;
}

Filter::~Filter() {
    ;
}

void Filter::PutFilter_Gray(int8_t option) {

    Image *img = new GrayImage();
    img->LoadImage(file);

    // modify kernel size here
    int k_size = 3;
    
    if(option & Box     ) img->Box_Filter  (k_size);
    if(option & Sobel   ) img->Sobel_Filter();
    if(option & Contrast) img->Contrast_Filter();
    if(option & Mosaic  ) img->Mosaic_Filter();

    img->Display_CMD();

}

void Filter::PutFilter_RGB(int8_t option) {
    
    Image *img = new RGBImage();
    img->LoadImage(file);
    
    // modify kernel size here
    int k_size = 11;

    if(option & Box     ) img->Box_Filter  (k_size);
    if(option & Sobel   ) img->Sobel_Filter();
    if(option & Contrast) img->Contrast_Filter();
    if(option & Mosaic  ) img->Mosaic_Filter();

    img->Display_CMD();
    return;

}