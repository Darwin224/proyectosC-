#include <iostream>
#include <fstream>
using namespace std;

class Matriz {
private:
    double elementos[20][20];
    int filas;
    int columnas;

public:
    Matriz() : filas(20), columnas(20) {
        for (int i = 0; i < filas; ++i) {
            for (int j = 0; j < columnas; ++j) {
                elementos[i][j] = 0.0;
            }
        }
    }

    Matriz(const Matriz& otraMatriz) : filas(otraMatriz.filas), columnas(otraMatriz.columnas) {
        for (int i = 0; i < filas; ++i) {
            for (int j = 0; j < columnas; ++j) {
                elementos[i][j] = otraMatriz.elementos[i][j];
            }
        }
    }

    Matriz(int filas, int columnas) : filas(filas), columnas(columnas) {
        for (int i = 0; i < filas; ++i) {
            for (int j = 0; j < columnas; ++j) {
                elementos[i][j] = 0.0;
            }
        }
    }

    Matriz(string nombreArchivo) {
        string linea;
      /*  ifstream archivo(nombreArchivo);
        if (archivo.is_open()) {

            getline(archivo,linea);
            archivo >> filas >> columnas;
            for (int i = 0; i < filas; ++i) {
                for (int j = 0; j < filas; ++j) {
                    archivo >> elementos[i][j];
                }
            }
            archivo.close();
        } else {
            cerr << "Error al abrir el archivo." << endl;
        }*/

        cout<<"Hola";
    }

    void imprimir() const {
        for (int i = 0; i < filas; ++i) {
            for (int j = 0; j < columnas; ++j) {
                cout << elementos[i][j] << "\t";
            }
            cout << endl;
        }
    }

    Matriz operator+(const Matriz& otraMatriz) const {
        Matriz resultado(filas, columnas);
        for (int i = 0; i < filas; ++i) {
            for (int j = 0; j < columnas; ++j) {
                resultado.elementos[i][j] = elementos[i][j] + otraMatriz.elementos[i][j];
            }
        }
        return resultado;
    }

    Matriz operator-(const Matriz& otraMatriz) const {
        Matriz resultado(filas, columnas);
        for (int i = 0; i < filas; ++i) {
            for (int j = 0; j < columnas; ++j) {
                resultado.elementos[i][j] = elementos[i][j] - otraMatriz.elementos[i][j];
            }
        }
        return resultado;
    }

    Matriz operator*(const double escalar) const {
        Matriz resultado(filas, columnas);
        for (int i = 0; i < filas; ++i) {
            for (int j = 0; j < columnas; ++j) {
                resultado.elementos[i][j] = elementos[i][j] * escalar;
            }
        }
        return resultado;
    }

    Matriz operator*(const Matriz& otraMatriz) const {
        Matriz resultado(filas, otraMatriz.columnas);
        for (int i = 0; i < filas; ++i) {
            for (int j = 0; j < otraMatriz.columnas; ++j) {
                for (int k = 0; k < columnas; ++k) {
                    resultado.elementos[i][j] += elementos[i][k] * otraMatriz.elementos[k][j];
                }
            }
        }
        return resultado;
    }

    Matriz resolverJacobi(const Matriz& b, int iteraciones, double tolerancia) const {
        Matriz x(filas, 1);

        for (int k = 0; k < iteraciones; ++k) {
            Matriz xNuevo(filas, 1);

            for (int i = 0; i < filas; ++i) {
                double suma = 0.0;
                for (int j = 0; j < columnas; ++j) {
                    if (j != i) {
                        suma += elementos[i][j] * x.elementos[j][0];
                    }
                }
                xNuevo.elementos[i][0] = (b.elementos[i][0] - suma) / elementos[i][i];
            }

            Matriz residuo = b - (*this) * xNuevo;
            double normaResiduo = 0.0;
            for (int i = 0; i < filas; ++i) {
                normaResiduo += residuo.elementos[i][0] * residuo.elementos[i][0];
            }

            if (normaResiduo < tolerancia * tolerancia) {
                cout << "Convergencia alcanzada en la iteración " << k + 1 << "." << endl;
                return xNuevo;
            }

            x = xNuevo;
        }

        cerr << "El método de Jacobi no converge después de " << iteraciones << " iteraciones." << endl;
        return x;
    }
};

int main() {
    // Ejemplo de uso
    Matriz matriz1;
    Matriz matriz2(5, 5);
    Matriz matriz3("matriz.txt");

    cout << "Matriz 1:" << endl;
    matriz1.imprimir();

    cout << "\nMatriz 2:" << endl;
    matriz2.imprimir();

    cout << "\nMatriz 3:" << endl;
    matriz3.imprimir();

    Matriz suma = matriz1 + matriz2;
    cout << "\nSuma de Matriz 1 y Matriz 2:" << endl;
    suma.imprimir();

    Matriz resta = matriz1 - matriz2;
    cout << "\nResta de Matriz 1 y Matriz 2:" << endl;
    resta.imprimir();

    Matriz multEscalar = matriz1 * 2.0;
    cout << "\nMultiplicación de Matriz 1 por escalar (2.0):" << endl;
    multEscalar.imprimir();

    Matriz multMatriz = matriz1 * matriz2;
    cout << "\nMultiplicación de Matriz 1 y Matriz 2:" << endl;
    multMatriz.imprimir();

    // Resolver Ax=b usando Jacobi
    Matriz b(20, 1);
    Matriz solucionJacobi = matriz1.resolverJacobi(b, 1000, 1e-6);

    cout << "\nSolución usando Jacobi:" << endl;
    solucionJacobi.imprimir();

    return 0;
}