#pragma once

#include <memory>
#include <functional>

#include "MatrixModel.hpp"
#include "GameView.hpp"
#include "EndGameMessage.hpp"

class Controller
{
private:
    MatrixModel m_model;
    std::unique_ptr<GameView> m_gameView;
    std::unique_ptr<EndGameMessage> m_endGameMessage;
    
public:
    Controller();
    ~Controller() {};

    void startGame();
    void newGameCallback();
    void buttonGridCallback(std::pair<int,int> coords);
    void showEndMessage();

};