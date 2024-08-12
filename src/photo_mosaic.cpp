#include "photo_mosaic.h"

void PhotoMosaic::GetRGB_val(string src) {
    vector<string> files;
    data_loader.List_Directory(src, files);

    cout << "start GetRGB_val" << endl;
    for(unsigned int i = 0; i < files.size(); i++) {

        // record loaded img
        RGBImage *small_img = new RGBImage();
        small_img->LoadImage(files[i]);
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
    
    int h_sml = small_imgs[0]->get_h();
    int w_sml = small_imgs[0]->get_w();

    int h_big = img->get_h();
    int w_big = img->get_w();

    cout << "origin: " << h_big << " " << w_big << endl;

    // crop the image
    int h = h_big - (h_big % h_sml);
    int w = w_big - (w_big % w_sml);

    int ***pixels = img->pixels;
    
    cout << "compute: " << h << " " << w << endl;

    data_loader.Dump_RGB(w, h, pixels, "crop.jpg");
    img->LoadImage("crop.jpg");

    const string cmd_str = "rm crop.jpg";
    system(cmd_str.c_str());

    cout << "crop: " << img->get_h() << " " << img->get_w() << endl;

    return img;

}