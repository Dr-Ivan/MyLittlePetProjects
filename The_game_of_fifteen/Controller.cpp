#include "Controller.hpp"


Controller::Controller()
    : m_model(MatrixModel())
    , m_gameView(std::make_unique<GameView>(650, 200, 145, 220, "15", m_model))
    , m_endGameMessage(std::make_unique<EndGameMessage>(650, 200, 255, 80, "You won!"))
{
    m_gameView->setButtonGridCallback(std::bind(&Controller::buttonGridCallback, this, std::placeholders::_1));
    m_gameView->setRestartCallback(std::bind(&Controller::newGameCallback, this));
    m_gameView->setEndGameCallback(std::bind(&Controller::showEndMessage, this));
    m_gameView->updateWindow();
};

void Controller::startGame(){
    m_gameView->show();
};

void Controller::newGameCallback(){
    m_model.restart();
    m_gameView->updateWindow();
};

void Controller::buttonGridCallback(std::pair<int, int> coords){
    m_model.moveNum(coords);
    m_gameView->updateWindow();
};

void Controller::showEndMessage(){
    char msg[60];  
    snprintf(msg, sizeof(msg), "Congratulations!\nYou solved this puzzle in %d moves.", m_model.getMovesCount());

    m_endGameMessage->setMessage(msg);
    m_endGameMessage->show();
};