#include <iostream>
#include <cstring>
#include <fstream>
using namespace std;
//Prototipos

void busqueda(int);

int main(){
string linea;
string contenido;
ifstream archivo("matriz.txt");
while (getline(archivo, linea))
{
  contenido=linea;
}



cout<<contenido;


    return 0;
}

void busqueda(int bandera){

//compara el valor que tiene la bandera para hacer la asignacion correspondiente
switch (bandera)
    {
    case 01:
        cout<<"Ubicacion: Atlantida";
        break;
    case 02:
        cout<<"Ubicacion: Colon";
        break;
    case 03:
        cout<<"Ubicacion: Comayagua";
        break;
    case 04:
        cout<<"Ubicacion: Copan";
        break;
    case 05:
        cout<<"Ubicacion: Cortes";
        break;
    case 06:
        cout<<"Ubicacion: Choluteca";
        break;
    case 07:
        cout<<"Ubicacion: El paraiso";
        break;
    case 8:
        cout<<"Ubicacion: Francisco Morazan";
        break;
    case 9:
        cout<<"Ubicacion: Gracias a Dios";
        break;
    case 10:
        cout<<"Ubicacion: Intibuca";
        break;
    case 11:
        cout<<"Ubicacion: Islas de la bahia";
        break;
    case 12:
        cout<<"Ubicacion: La paz";
        break;
    case 13:
        cout<<"Ubicacion: Lempira";
        break;
    case 14:
        cout<<"Ubicacion: Ocotepeque";
        break;
    case 15:
        cout<<"Ubicacion: Olancho";
        break;
    case 16:
        cout<<"Ubicacion: Santa Barbara";
        break;
    case 17:
        cout<<"Ubicacion: Valle";
        break;
    case 18:
        cout<<"Ubicacion: Yoro";
        break;                                                            
    default:
        cout<<"Error, intente de nuevo";
        break;
    }

}

