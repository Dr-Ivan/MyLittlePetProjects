#include "MatrixModel.hpp"

MatrixModel::MatrixModel()
{
    matrix = std::vector<int> (c_gridSize*c_gridSize, 0);

    for (int i = 0; i < c_gridSize*c_gridSize; ++i)
        matrix[i] = i;

    shuffleMatrix();
}

void MatrixModel::shuffleMatrix(){
    std::random_device rd;
    std::mt19937 g(rd());
    std::shuffle(matrix.begin(), matrix.end(), g);
}

const int MatrixModel::getNum(int x, int y) const{
    int ind = x * c_gridSize + y;
    if (ind < matrix.size())
        return matrix[ind];
    else
        return -1;
}

void MatrixModel::moveNum(std::pair<int, int> coords){
    int toMoveIndex = coords.first * c_gridSize + coords.second;
    if (matrix[toMoveIndex] == 0) return;

    int switchWithIndex = -1;

    if (getNum(coords.first, coords.second+1) == 0)
        switchWithIndex = coords.first * c_gridSize + (coords.second + 1);

    else if (getNum(coords.first, coords.second-1) == 0)
        switchWithIndex = coords.first * c_gridSize + (coords.second - 1);

    else if (getNum(coords.first+1, coords.second) == 0)
        switchWithIndex = (coords.first + 1) * c_gridSize + coords.second;

    else if (getNum(coords.first-1, coords.second) == 0)
        switchWithIndex = (coords.first - 1) * c_gridSize + coords.second;
    
    if (switchWithIndex == -1) return;

    int temp = matrix[toMoveIndex];
    matrix[toMoveIndex] = matrix[switchWithIndex];
    matrix[switchWithIndex] = temp;

    checkWin();
};


void MatrixModel::restart(){
    win = false;
    shuffleMatrix();
};

void MatrixModel::checkWin(){
    for (int i = 0; i < c_gridSize*c_gridSize-1; ++i)
        if (matrix[i] != i+1){
            win = false;
            return;
        };
    win = true;
};

void MatrixModel::printMatrix() {
    std::cout << "Matrix: " << '\n';
    for (int i = 0; i < c_gridSize; ++i) {
        for (int j = 0; j < c_gridSize; ++j) {
            std::cout << getNum(i, j) << ' ';
        }
        std::cout << '\n';
    }
    std::cout << '\n';
}


MatrixModel::~MatrixModel()
{
    matrix.clear();
}
