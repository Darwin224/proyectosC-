#include <iostream>
#include <cstring>

using namespace std;

int main() {
    char id[18]; // Ajustado el tamaño del array para permitir números de identidad de hasta 18 caracteres
    int bandera = 1;
    bool banderaAtlantida=false;
    while (bandera == 1) {

        cout<<"Ingrese numero de identidad, separado por guiones por favor\n";
        cin.get(id, 18); // Ajustado el tamaño para leer hasta 18 caracteres, asi incluyendo los - ejemplo 0801-1999-12345
       
        banderaAtlantida=false;//cambia el valor de la bandera para que pueda entrar al switch

    if (id[0] == '0'&& id[1]=='1') { //si la primera posicion es 0 y la segunda posicion es 1
       cout << "Ubicacion: Atlantida"; //imprime atlantida
        banderaAtlantida=true; //cambia el valor de la bandera para que no entre al switch y pregunte directamente si desea agregar mas
    }else if(id[0] == '0'){//if la primera posicion del id es 0, entonces cambia la posicion [0] por lo que hay en la posicion [1]
        id[0]=id[1];//  ejemplo 0815 id[0]=0, id[1]=8, entonces intercambia id[0]=8 para que se tome en cuenta solo el segundo numero
    }
        
    
    if(banderaAtlantida==false){//si la banderaAtlantida es falsa entonces entra al switch
         switch (id[0]) {//valida que la primera posicion del arreglo de caracteres sea 1,2,.., o ,9
            case '1':
                if (id[1] == '0') {//la primera posicion id[0]=1, valida la segunda id[1]= 1, 2,..,8
                    cout << "Ubicacion: Intibuca";
                } else if (id[1] == '1') {//ejemplo 1101 id[0]=1 ahora valida la segunda posicion id[1]=1 por tanto es islas Islas de la bahia
                    cout<<"valor: "<<id[0];
                    cout << "Ubicacion: Islas de la bahia";
                } else if (id[1] == '2') {
                    cout << "Ubicacion: La paz";
                } else if (id[1] == '3') {
                    cout << "Ubicacion: Lempira";
                } else if (id[1] == '4') {
                    cout << "Ubicacion: Ocotepeque";
                } else if (id[1] == '5') {
                    cout << "Ubicacion: Olancho";
                } else if (id[1] == '6') {
                    cout << "Ubicacion: Santa Barbara";
                } else if (id[1] == '7') {
                    cout << "Ubicacion: Valle";
                } else if (id[1] == '8') {
                    cout << "Ubicacion: Yoro";
                } else {
                    cout << "Error, intente de nuevo";
                }
                break;
            case '2':
                cout << "Ubicacion: Colon";
                break;
            case '3':
                cout << "Ubicacion: Comayagua";
                break;
            case '4':
                cout << "Ubicacion: Copan";
                break;
            case '5':
                cout << "Ubicacion: Cortes";
                break;
            case '6':
                cout << "Ubicacion: Choluteca";
                break;
            case '7':
                cout << "Ubicacion: El paraiso";
                break;
            case '8':
                cout << "Ubicacion: Francisco Morazan";
                break;
            case '9':
                cout << "Ubicacion: Gracias a Dios";
                break;
            default:
                cout << "Error, intente de nuevo";
                break;
        }
    }

            cout<<endl<<"*********************************************";
            cout <<endl<< "Desea seguir\n1. si\n2. no\n";
            cin >> bandera;//maneja el while si manda un 1, sigue la ejecucion el 2 la detiene
            
            cin.ignore();//capitulo 5.12 limpia el buffer o limpia la variable para poder seguir usando
    }

    cout<<"\n*********************************************";
    cout << endl << "Programa finalizado";

    return 0;
}
