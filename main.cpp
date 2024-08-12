#include "image.h"
#include "gray_image.h"
#include "rgb_image.h"
#include "photo_mosaic.h"
#include "bit_field_filter.h"

int main(int argc, char *argv[]){

    // Image *img1 = new GrayImage();
    // img1->LoadImage("Image-Folder/mnist/img_100.jpg");
    // img1->DumpImage("img1.jpg");
    // img1->Display_CMD();
    // img1->Display_ASCII();
    

    // Image *img2 = new RGBImage();
    // img2->LoadImage("Image-Folder/lena.jpg");
    // img2->DumpImage("img2.jpg");
    // img2->Display_CMD(); 
    // img2->Display_ASCII();

// some bit field filter design driven code here

    // case1
    // int8_t option = Box;
    // string dir     = "Image-Folder/";
    // string img     = "lena.jpg";
    // string out_img = "Box_" + img;
    
    // Filter filter(dir + img);
    // filter.PutFilter_RGB(option, out_img);


    // some photo mosaic driven code here
    string src    = "Image-Folder/cifar10";
    string target = "Image-Folder/4k_owl.jpg";

    PhotoMosaic mosaic (target, src); 
    RGBImage *mosaic_img = mosaic.GetMosaic();
    mosaic_img->Display_CMD();
    mosaic_img->DumpImage("Mosaic_img.jpg");

    // more ...
    return 0;
}
