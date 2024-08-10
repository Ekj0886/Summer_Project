#include "image.h"
#include "gray_image.h"
#include "rgb_image.h"
#include "photo_mosaic.h"
#include "bit_field_filter.h"

int main(int argc, char *argv[]){
    Image *img1 = new GrayImage();
    img1->LoadImage("Image-Folder/mnist/img_100.jpg");
    img1->DumpImage("img1.jpg");
    // img1->Display_X_Server();
    cout << "Show Gray Image" << endl;
    img1->Display_CMD();
    cout << "Show ASCII Image" << endl;
    img1->Display_ASCII();
    

    Image *img2 = new RGBImage();
    img2->LoadImage("Image-Folder/lena.jpg");
    img2->DumpImage("img2.jpg");
    // img2->Display_X_Server();
    cout << "Show RGB Image" << endl;
    img2->Display_CMD(); 
    cout << "Show ASCII Image" << endl;
    img2->Display_ASCII();

    // some bit field filter design driven code here

    // some photo mosaic driven code here

    // more ...
    return 0;
}
