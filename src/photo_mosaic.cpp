#include "photo_mosaic.h"

void PhotoMosaic::GetRGB_val(string src) {
    vector<string> files;
    data_loader.List_Directory(src, files);

    for(int i = 0; i < files.size(); i++) {
    
        // record loaded img
        RGBImage *small_img = new RGBImage();
        small_img->Load(files[i]);
        small_imgs.push_back(small_img);

        // compute RGB_val

        int h = small_img->get_h();
        int w = small_img->get_w();

        pix p;
        p.R = 0, p.G = 0, p.B = 0;
        for(int y = 0; y < h; y++) {
            for(int x = 0; x < w; x++) {

                p.R += small_img->pixels[y][x][0];
                p.G += small_img->pixels[y][x][1];
                p.B += small_img->pixels[y][x][2];

            }
        }
        p.R /= (h*w), p.G /= (h*w), p.B /= (h*w);

        RGB_val.push_back(p);

    }
}

PhotoMosaic::PhotoMosaic(string target, string src) {

    GetRGB_val(src);

    img = new RGBImage();
    img->LoadImage(target);

}

PhotoMosaic::~PhotoMosaic() {
    ;
}

RGBImage *PhotoMosaic::GetMosaic(){
    
}