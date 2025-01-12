#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

const int NUM_EQUIPOS = 10;

// Generar un cuadro de goles aleatorio
void generarCuadroGoles(int goles[NUM_EQUIPOS][NUM_EQUIPOS]) {
 
    for (int i = 0; i < NUM_EQUIPOS; i++) {
        for (int j = 0; j < NUM_EQUIPOS; j++) {
            if (i == j) {
                goles[i][j] = 0; // No hay goles de un equipo contra sí mismo
            } else {
                goles[i][j] = rand() % 6; // Goles aleatorios entre 0 y 5
            }
        }
    }
}

// Mostrar el cuadro de goles
void mostrarCuadroGoles(int goles[NUM_EQUIPOS][NUM_EQUIPOS]) {
    cout << "Cuadro de goles:\n";
    for (int i = 0; i < NUM_EQUIPOS; i++) {
        for (int j = 0; j < NUM_EQUIPOS; j++) {
            cout << goles[i][j] << " ";
        }
        cout << endl;
    }
}

// Calcular el total de goles recibidos por cada equipo
void calcularGolesRecibidos(int goles[NUM_EQUIPOS][NUM_EQUIPOS], int recibidos[NUM_EQUIPOS]) {
    for (int i = 0; i < NUM_EQUIPOS; i++) {
        recibidos[i] = 0;
        for (int j = 0; j < NUM_EQUIPOS; j++) {
            recibidos[i] += goles[j][i];
        }
    }
}

// Determinar el equipo que más goles anotó
int equipoMasGoleador(int goles[NUM_EQUIPOS][NUM_EQUIPOS]) {
    int anotados[NUM_EQUIPOS] = {0};
    for (int i = 0; i < NUM_EQUIPOS; i++) {
        for (int j = 0; j < NUM_EQUIPOS; j++) {
            anotados[i] += goles[i][j];
        }
    }

    int maxGoles = 0, equipo = 0;
    for (int i = 0; i < NUM_EQUIPOS; i++) {
        if (anotados[i] > maxGoles) {
            maxGoles = anotados[i];
            equipo = i + 1; // Equipos numerados del 1 al 10
        }
    }
    return equipo;
}

// Determinar el número de juegos empatados
int contarJuegosEmpatados(int goles[NUM_EQUIPOS][NUM_EQUIPOS]) {
    int empates = 0;
    for (int i = 0; i < NUM_EQUIPOS; i++) {
        for (int j = i + 1; j < NUM_EQUIPOS; j++) { // Evitar repeticiones y diagonales
            if (goles[i][j] == goles[j][i]) {
                empates++;
            }
        }
    }
    return empates;
}

int main() {
    int goles[NUM_EQUIPOS][NUM_EQUIPOS];
    int recibidos[NUM_EQUIPOS];
    
    // Generar cuadro de goles
    generarCuadroGoles(goles);
    
    // Mostrar cuadro de goles
    mostrarCuadroGoles(goles);
    
    // Calcular goles recibidos por equipo
    calcularGolesRecibidos(goles, recibidos);
    cout << "\nGoles recibidos por equipo:\n";
    for (int i = 0; i < NUM_EQUIPOS; i++) {
        cout << "Equipo " << i + 1 << ": " << recibidos[i] << " goles\n";
    }

    // Determinar el equipo que más goles anotó
    int equipo = equipoMasGoleador(goles);
    cout << "\nEl equipo que más goles anotó fue el Equipo " << equipo << ".\n";

    // Contar juegos empatados
    int empates = contarJuegosEmpatados(goles);
    cout << "El número de juegos empatados en el torneo fue: " << empates << ".\n";

    return 0;
}
