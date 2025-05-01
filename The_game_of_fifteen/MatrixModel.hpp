#pragma once

#include <vector>
#include <random>
#include <algorithm>
#include <iostream>


class MatrixModel
{
public:
    MatrixModel();
    ~MatrixModel();

    const int getNum(int x, int y) const;
    void moveNum(std::pair<int, int> coords);
    void restart();
    bool getWinState() {return m_win;};
    int getMovesCount() {return m_movesCount;};

    void printMatrix();

private:
    bool isSolvable();
    void shuffleMatrix();
    void checkWin();

    const int c_gridSize = 4;
    int m_movesCount = 0;
    bool m_win = false;
    std::vector<int> m_matrix;

};
