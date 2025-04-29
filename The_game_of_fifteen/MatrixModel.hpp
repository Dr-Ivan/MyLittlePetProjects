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
    bool getWinState() {return win;};

    void printMatrix();

private:
    void shuffleMatrix();
    void checkWin();

    const int c_gridSize = 4;
    bool win = false;
    std::vector<int> matrix;

};
