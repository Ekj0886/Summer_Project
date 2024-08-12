#include "photo_mosaic.h"

void PhotoMosaic::GetRGB_val(string src) {
    vector<string> files;
    data_loader.List_Directory(src, files);

    cout << "Start loading source images" << endl;

    for(unsigned int i = 0; i < files.size(); i++) {

        // record loaded img
        RGBImage *small_img = new RGBImage();
        small_img->LoadImage(files[i]);
        small_imgs.push_back(small_img);

        // compute RGB_val

        int h = small_img->get_h();
        int w = small_img->get_w();

        pix p = {0, 0, 0};
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
    cout << "Image source loading complete" << endl;
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
    
    cout << "Generating mosaic image" << endl;

    int h_s = small_imgs[0]->get_h();
    int w_s = small_imgs[0]->get_w();
    int h_b = img->get_h();
    int w_b = img->get_w();

    // crop the image
    int h = h_b - (h_b % h_s);
    int w = w_b - (w_b % w_s);

    int ***pixels = img->pixels;

    data_loader.Dump_RGB(w, h, pixels, "crop.jpg");
    img->LoadImage("crop.jpg");

    const string cmd_str = "rm crop.jpg";
    system(cmd_str.c_str());

    for(int y = 0; y <= h - h_s; y += h_s) {
        for(int x = 0; x <= w - w_s; x += w_s) {
            
            // y, x is the each starting point of the grid
            pix g = {0, 0, 0};
            for(int i = y; i < y + h_s; i++) {
                for(int j = x; j < x + w_s; j++) {
                    // i, j is the individual pixel of the grid
                    g.R += img->pixels[i][j][0];
                    g.G += img->pixels[i][j][1];
                    g.B += img->pixels[i][j][2];
                }
            }
            g.R /= (h_s*w_s), g.G /= (h_s*w_s), g.B /= (h_s*w_s);

            // find smallest diff
            int sml = 0;
            int diff_min = 255*255*3;
            for(unsigned int i = 0; i < RGB_val.size(); i++) {
                pix p = RGB_val[i];
                int diff_new = pow((g.R - p.R), 2) + pow((g.G - p.G), 2) + pow((g.B - p.B), 2);
                if(diff_new < diff_min) {
                    sml = i;
                    diff_min = diff_new;
                }
            }
            
            // get mosaic img
            int *** sml_pixels = small_imgs[sml]->pixels;
            for(int i = y; i < y + h_s; i++) {
                for(int j = x; j < x + w_s; j++) {
                    // i, j is the individual pixel of the grid
                    img->pixels[i][j][0] = sml_pixels[i-y][j-x][0];
                    img->pixels[i][j][1] = sml_pixels[i-y][j-x][1];
                    img->pixels[i][j][2] = sml_pixels[i-y][j-x][2];
                }
            }

        }
    }

    return img;

}