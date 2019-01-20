#include <iostream>
#include <string>
    // - Create (dynamically) a two dimensional array
    //   with the following matrix. Use a loop!
    //   by dynamically, we mean here that you can change the size of the matrix
    //   by changing an input value or a parameter or this combined
    //
    //   1 0 0 0
    //   0 1 0 0
    //   0 0 1 0
    //   0 0 0 1
    //
    // - Print this two dimensional array to the output
    int main(int argc, char* args[]) {
        int matrix[4][4];
        int k = 0;
        for (int i = 0; i < 4; i++)
            for (int j = 0; j < 4; j++) {
                if (j == k) {
                    matrix[i][j] = 1;
                } else {
                    matrix[i][j] = 0;
                }
            }
        k++;

    //for (int i = 0 ; i < 4; i++) {
      //  for (int j = 0; j < 4; i++){
    //        std::cout << matrix[i][j] << " ";
  //      }
//            std::cout << std::endl;



    return 0;
}