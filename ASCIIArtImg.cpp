#include "CharSpitter.h"
#include <string>
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <memory>
int main(int argc, char **argv){
    //consider transferring everything to a class
    std::unique_ptr<CharSpitter> spitter;
    std::string guide = "guide.txt";
    std::string img;
    int compression;
    switch (argc){
        case 1:
            std::cerr << "Usage: ASCIIArtImg: [image file] [compression factor] [guide file]";
            std::cerr << std::endl << "Default guide file: guide.txt";
            std::cerr << std::endl << "Default compression: 5";
            return -1;
        case 2:
            std::cout << "Setting guide.txt as guide file..." << std::endl;
            img = argv[1]; //operator=(char*)
            spitter = std::unique_ptr<CharSpitter>(new CharSpitter(guide, img));
            break;
        case 3:case 4:
            img = argv[1];
            compression = std::atoi(argv[2]);
            if (argc == 4) guide = argv[3];
            spitter = std::unique_ptr<CharSpitter>(new CharSpitter(guide, img, compression));
            break;
    }
    while (spitter->spit(std::cout));
    return 0;
}
