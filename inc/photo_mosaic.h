#ifndef _PHOTO_MOSAIC_H_
#define _PHOTO_MOSAIC_H_

#include "image.h"
#include "rgb_image.h"

struct pix {
    int R;
    int G;
    int B
};

class PhotoMosaic : public RGBImage{

private:
    RGBImage *img;
    vector<pix> RGB_val;
    vector<RGBImage *> small_imgs;

public:
    PhotoMosaic(string target, string src);
    ~PhotoMosaic();

    void GetRGB_val(string src);
    RGBImage *GetMosaic();

};

#endif