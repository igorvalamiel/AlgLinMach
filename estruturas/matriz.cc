#include <iostream>
#include <vector>
using namespace std;

template <typename T>
class Matrix {
    public:
        Matrix(int n, int m, bool matrix_I=0, bool matrix_of_0=0) {
            lin = n;
            col = m;
            identity = matrix_I;

            vector <vector <T>> MAT; // matriz será representadas por uma vetor de vetores com {linha, coluna, valor}

            if (identity) {
                if (lin != col) {
                    throw "Erro: Matrizes identidades devem ser quadradas!";
                } else {
                    for (int i=0; i<lin; i++) {
                        for (int j=0; j<col; j++) {
                            MAT.push_back({i, j, (i == j)});
                        }
                    }
                }
            } else if (matrix_of_0) {
                for (int i=0; i<lin; i++) {
                    for (int j=0; j<col; j++) {
                        MAT.push_back({i, j, 0});
                    }
                }
            } else {
                for (int i=0; i<lin; i++) {
                    for (int j=0; j<col; j++) {
                        cout << "Insira o valor da posição M[" << i << "][" << j << "]: "; 
                        MAT.push_back({i, j, cin});
                    }
                }
            }
        }

    private:
        int lin, col;
        bool identity, zero_matrix;
};
