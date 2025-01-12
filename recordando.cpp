#include <iostream>

using namespace std;

int main(){


//Declarando numero de equipos
int numEquipos=10;
 //Declarando arreglo-Bidimensional
int matriz[numEquipos][numEquipos];
//Semilla con hora actual para funcion rand
 srand(time(NULL));

cout<<"\tCUADRO DE GOLES INTER-BARRIALES"<<endl;

//Generando cuadro de goles aleatorios
for (int i = 0; i < numEquipos; i++)
{
    for (int j = 0; j < numEquipos; j++)
    {
        if (i==j){
            matriz[i][j]=0;
        }else{
        matriz[i][j]=rand() % 6; //Rand genera un numero aleatorio entre 0 y 5
        }
    }
}
cout<<"******************************************"<<endl;
//Imprime los numeros de los equipos por fila
for (int i = 0; i < numEquipos; i++)
{
    cout<<"| "<<i+1<<"\t";
}
cout<<endl;


//Imprimiendo Cuadro de goles aleatorios
for (int i = 0; i < numEquipos; i++)
{
    cout << i+1 <<"|";
    for (int j = 0; j < numEquipos; j++)
    {
        cout<<matriz[i][j] <<"\t";
    }
    cout<<endl;
}


//Generando el Maximo goleador
int maxGoles = 0;  // Variable para almacenar el máximo de goles anotados
int equipoMaxGoles = 0;  // Variable para almacenar el índice del equipo con más goles

// Recorrer todos los equipos
for (int i = 0; i < numEquipos; i++) {
    int golesAnotados = 0;  // Variable para contar los goles anotados por el equipo i
    // Sumar los goles de todos los partidos para el equipo i
    for (int j = 0; j < numEquipos; j++) {
        golesAnotados += matriz[i][j];
    }
    
    // Comparar si el equipo actual tiene más goles que el máximo registrado
    if (golesAnotados > maxGoles) {
        maxGoles = golesAnotados;  // Actualizar el máximo de goles
        equipoMaxGoles = i;  // Actualizar el índice del equipo con más goles
    }
}
// Imprimir el equipo con más goles
cout << "\nEl equipo con más goles es el equipo " << equipoMaxGoles + 1 << " con: " << maxGoles << " goles." << endl<<endl;

cout<<"******************************************"<<endl;

//sumando los goles recibidos por equipo
cout<<"Total de goles recibidos por equipo: "<<endl;
for (int i = 0; i < numEquipos; i++)
{
    int golesRecibidos=0;
    for (int j = 0; j < numEquipos; j++)
    {
       golesRecibidos+=matriz[j][i];
    }
    cout<<"El equipo "<<i+1<<" recibio: "<<golesRecibidos<<" goles"<<endl;
}

//Calculando cantidad de empates

    int empates = 0;
    for (int i = 0; i < numEquipos; i++) {
        for (int j = i + 1; j < numEquipos; j++) { // Evitar repeticiones y diagonales
            if (matriz[i][j] == matriz[j][i]) {
                empates++;
            }
        }
    }
   
 cout<<"******************************************"<<endl;
   cout << "Número de empates: " << empates << endl;

return 0;
}