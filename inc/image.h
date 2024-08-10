#ifndef _IMAGE_H_
#define _IMAGE_H_

#include "data_loader.h"

using namespace std;

class Image{
protected:
    int w;
    int h;
    Data_Loader data_loader;

public: 
// member function
    Image(int width, int height);
    ~Image(){};
    int get_w();
    int get_h();

// virtual function
    virtual bool LoadImage(string file) = 0;
    virtual void DumpImage(string file) = 0;
    virtual void Display_ASCII(){};
    virtual void Display_CMD(){};
};

#endif