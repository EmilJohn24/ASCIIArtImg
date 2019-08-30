#ifndef CHARSPITTER_H
#define CHARSPITTER_H
#include <Magick++.h>
#include <fstream>
#include <vector>
#include <string>
#include <ostream>
#include <iostream>
#include <math.h>
using namespace Magick;
class CharSpitter
{
    public:
        static const int MAX_PIXEL = 255;
        CharSpitter(std::string guide, std::string img, int _compression = 5);
        virtual ~CharSpitter();
        void openGuide(std::string guide);
        void openImage(std::string img);
        int getGuiderCount(){ return palette.size(); }
        bool spit(std::ostream &out);
        float getCurrentPixelShading();
        float getAreaPixelShading();
        void setCompressionFactor(int _factor){ compressionFactor = _factor; }

    protected:

    private:
        std::string palette;
        Image *imageContainer;
        int currRow;
        int currCol;
        int width;
        int height;
        int compressionFactor;
};

#endif // CHARSPITTER_H
