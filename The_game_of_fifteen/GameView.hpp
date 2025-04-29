#pragma once

#include <FL/Fl.h>
#include <Fl/Fl_Window.H>
#include <Fl/Fl_Box.H>
#include <Fl/Fl_Button.H>
#include <vector>
#include <memory>
#include <functional>

#include "MatrixModel.hpp"


class GameView : public Fl_Window {
public:
    GameView(int w, int h, char const* title, MatrixModel& m);

    void update_window();

    void show_finish_window();

    void setButtonGridCallback(std::function<void(std::pair<int, int>)> callback) {
        m_buttonPressed = std::move(callback);
    };

    void setRestartCallback(std::function<void(void)> callback) {
        m_restartCallback = std::move(callback);
    };

    // // Запрет копирования
    // GameView(const GameView&) = delete;
    // GameView& operator=(const GameView&) = delete;

    ~GameView();

private:
    const int c_gridSize = 4;
    const int c_buttonWidth = 30;
    const int c_buttonHeight = 30;
    
    MatrixModel& model;

    std::vector<std::unique_ptr<Fl_Button>> m_buttonGrid;
    std::vector<std::pair<int, int>> m_buttonGridIndexes;
    std::vector<std::unique_ptr<std::function<void()>>> m_lambdaCallbacks;

    std::unique_ptr<Fl_Button> m_restartButton;
    std::function<void(std::pair<int, int>)> m_buttonPressed;
    std::function<void()> m_restartCallback;

};

