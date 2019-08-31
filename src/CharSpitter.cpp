#include "CharSpitter.h"

std::ostream& operator<<(std::ostream& out, CharSpitter& cs){
    //provides no way to deterministically identify if the object is no longer spitting out anything
    cs.spit(out);
    return out;
}

CharSpitter::CharSpitter(std::string guide, std::string img, int _compression)
{
    //ctor
    currCol = 0;
    currRow = 0;
    imageContainer = nullptr;
    setCompressionFactor(_compression);
    openGuide(guide);
    openImage(img);
}

CharSpitter::~CharSpitter()
{
    //dtor
    delete imageContainer;
}


float CharSpitter::getAreaPixelShading(){
    float sum = 0;
    float average;
    for (int r = currRow; r != currRow + compressionFactor; r++){
        for (int c = currCol; c != currCol + compressionFactor; c++){
                Color colorContainer = imageContainer->pixelColor(c, r);
                ColorGray gray(colorContainer);
                float averagePercent = gray.shade();
                sum += averagePercent;
        }
    }

    average = sum / pow(compressionFactor, 2);
    return average;


}
bool CharSpitter::spit(std::ostream &out){
    //deliberately removes the leftmost pixel of every column
    //to speed up loading the newline
    if (currRow >= height) return false;
    if (currCol >= width) {
        out << '\n';
        currRow += compressionFactor;
        currCol = 0;
    }
    float pixelShading = getAreaPixelShading();
    //std::cout << pixelShading << std::endl;
    out << palette[pixelShading * getGuiderCount()];
    currCol+=compressionFactor;

    return true;


}
void CharSpitter::openGuide(std::string guide){
    std::fstream guideFile(guide);
    guideFile >> palette;
    guideFile.close();
}

void CharSpitter::openImage(std::string img){
    imageContainer = new Image(img);
    imageContainer->modifyImage();
    //std::cout << imageContainer->magick() << std::endl;
    width = imageContainer->columns();
    height = imageContainer->rows();
}
