#include <FL/Fl.h>
#include "Controller.hpp"


int main() {
    Controller game{};
    game.startGame();
    
    return Fl::run();
}