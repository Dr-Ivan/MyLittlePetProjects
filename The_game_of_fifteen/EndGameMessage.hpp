#pragma once

#include <FL/Fl.h>
#include <Fl/Fl_Window.H>
#include <Fl/Fl_Box.H>
#include <memory>


class EndGameMessage : public Fl_Window 
{
private:
    char* m_message;
    std::unique_ptr<Fl_Box> m_label;

public:
    EndGameMessage(int x, int y, int w, int h, const char* title);

    void setMessage(char* msg);
};