#include "GameView.hpp"

#include<iostream>


GameView::GameView(int w, int h, char const* title) : Fl_Window(w, h, title) {

    m_restartButton = std::make_unique<Fl_Button>(22, 160, 100, 50, "New game");
    m_restartButton->callback([](Fl_Widget*, void* data) {
        GameView* view = static_cast<GameView*>(data);
        if (view->m_restartCallback) {
            view->m_restartCallback();
        }
    }, this);

    int curX = 5;
    int curY = 0;
    for (int i = 0; i < c_gridSize; ++i){
        for (int j = 0; j < c_gridSize; ++j){
            m_buttonGrid.emplace_back(std::make_unique<Fl_Button>(curX, curY, c_buttonWidth, c_buttonHeight, " "));
            m_buttonGridIndexes.emplace_back(std::make_pair(i, j));
            curX += c_buttonWidth + 5;
        }
        curY += c_buttonHeight + 5;
        curX = 5;
    }


    int k = 0;
    for (std::pair<int, int> p : m_buttonGridIndexes) {
        auto func = std::make_unique<std::function<void()>>([p, this]() {
            if (m_buttonPressed) {
                m_buttonPressed(p);
            }
        });
    
        auto* funcPtr = func.get();
        m_lambdaCallbacks.push_back(std::move(func));

        m_buttonGrid[k++]->callback([](Fl_Widget* w, void* data) {
            auto& func = *static_cast<std::function<void()>*>(data);
            func();
        }, funcPtr);
    }

    end();
};


void GameView::update_window() {
    

    // end();

    // this->redraw();

};

void GameView::show_finish_window() {
    
};

GameView::~GameView() {
    m_buttonGrid.clear();
    m_buttonGridIndexes.clear();
    m_lambdaCallbacks.clear();
};


