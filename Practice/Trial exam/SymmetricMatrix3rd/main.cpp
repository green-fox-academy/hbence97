#include <iostream>
#include <vector>

bool isSymmetric(std::vector<std::vector<int>> matrix);

int main() {
    std::vector<std::vector<int>> matrix1 = {{1,0,1}, {0,2,2}, {1,2,5}};
    if(isSymmetric(matrix1)){
        std::cout << "The vector is symmetric" << std::endl;
    } else {
        std::cout << "The vector is not symmetric" << std::endl;
    }
    std::vector<std::vector<int>> matrix2 = {{7, 7, 7}, {6, 5, 7}, {1, 2, 1}};
    if(isSymmetric(matrix2)){
        std::cout << "The vector is symmetric" << std::endl;
    } else {
        std::cout << "The vector is not symmetric" << std::endl;
    }
    return 0;
}

bool isSymmetric(std::vector<std::vector<int>> matrix){
    for (int i = 0; i < matrix.size(); ++i) {
        for (int j = 0; j < matrix[i].size() ; ++j) {
            if (matrix [j][i] != matrix[i][j]) {
                return false;
            }
        }
    }
    return true;
}