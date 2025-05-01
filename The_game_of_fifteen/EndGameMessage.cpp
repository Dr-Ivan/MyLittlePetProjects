#include "EndGameMessage.hpp"

EndGameMessage::EndGameMessage(int x, int y, int w, int h, const char* title) 
    : Fl_Window(x,y,w,h,title)
    , m_label(std::make_unique<Fl_Box>(10, 0, 200, 80))
    {};

void EndGameMessage::setMessage(char* msg){
    m_label->copy_label(msg);
    m_label->redraw();
};