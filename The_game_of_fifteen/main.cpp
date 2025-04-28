#include <FL/Fl.h>
#include <iostream>
#include "GameView.hpp"


void printPair(std::pair<int, int> p){
    std::cout << "Pressed button with coords: " << p.first << " /-/ " << p.second << std::endl;
};

void print(){
    std::cout << " RESTART " << std::endl;
};

int main() {
    GameView game {145, 220, "15"};
    game.setButtonGridCallback(printPair);
    game.setRestartCallback(print);
    game.show();

    
    return Fl::run();
}