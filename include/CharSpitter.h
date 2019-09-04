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
        friend std::ostream& operator<<(std::ostream&, CharSpitter&);
        CharSpitter(std::string guide, std::string img, int _compression = 5);
        void openGuide(std::string guide);
        void openImage(std::string img);
        int getGuiderCount(){ return palette.size(); }
        bool spit(std::ostream &out);
        float getAreaPixelShading();
        void setCompressionFactor(int _factor){ compressionFactor = _factor; }

    protected:

    private:
        std::string palette;
        Image imageContainer;
        int currRow;
        int currCol;
        int width;
        int height;
        int compressionFactor;
};

std::ostream& operator<<(std::ostream &out, CharSpitter& cs);     //provides no way to deterministically identify if the object is no longer spitting out anything




#endif // CHARSPITTER_H
