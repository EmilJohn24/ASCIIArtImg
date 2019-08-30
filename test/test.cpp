#include "CharSpitter.h"
#include <string>
#include <iostream>
#include <fstream>
int main(){
    CharSpitter *test = new CharSpitter("guide.txt", "test.png");
    while (test->spit(std::cout));
    delete test;
}
