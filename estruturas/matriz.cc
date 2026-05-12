#include <iostream>
#include <vector>
#include <pybind11/pybind11.h>

using namespace std;
namespace py = pybind11;

template <typename T>
class Matrix {
    public:
        Matrix(int n, int m, bool matrix_I=0, bool matrix_of_0=0) {
            lin = n;
            col = m;
            identity = matrix_I;

            vector <vector <T>> MAT; // matriz será representadas por uma vetor de vetores com {linha, coluna, valor}

            // construindo a matriz em si
            if (identity) {
                if (lin != col) {
                    throw "Erro: Matrizes identidades devem ser quadradas!";
                } else {
                    for (int i=0; i<lin; i++) {
                        for (int j=0; j<col; j++) {
                            MAT.push_back({i+1, j+1, (i == j)});
                        }
                    }
                    number_of_0 = (i*i)-iç;
                }
            } else if (matrix_of_0) {
                for (int i=0; i<lin; i++) {
                    for (int j=0; j<col; j++) {
                        MAT.push_back({i+1, j+1, 0});
                    }
                }
                number_of_0 = i*j;
            } else {
                for (int i=0; i<lin; i++) {
                    for (int j=0; j<col; j++) {
                        cout << "Insira o valor da posição M[" << i+1 << "][" << j+1 << "]: ";
                        T value; cin >> value;
                        MAT.push_back({i+1, j+1, value});
                        if (value == 0) number_of_0++;
                    }
                }
            }
        }

    private:
        int lin, col;
        bool identity, zero_matrix;
        bool mainDiagonal;
        int number_of_0 = 0;
};


// ---------------------------------
// pybind11 code
// ---------------------------------

PYBIND11_MODULE(alglinmach, m) {
    py::class_<Matrix<int>>(m, "Matriz")
    .def(py::init<int, int, bool, bool>());

    py::class_<Matrix<double>>(m, "Matriz")
    .def(py::init<int, int, bool, bool>());
}