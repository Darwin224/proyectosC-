#include <iostream>
#include <cstring>
#include <string>

using namespace std;
//Prototipos

int main(){

string id;
int opcion;
int bandera = 1;
string p;

while (bandera == 1) {

    cout<<"Ingrese numero de identidad, separado por guiones por favor\n";//0815-1999-00094
    
    getline(cin,id);//capitulo 12.5


     p=id.substr(0,id.find("-")-2);
    //0815-1999-00094
    opcion=stoi(p);

        switch (opcion)
            {
            case 1:
                cout<<"Ubicacion: Atlantida";
                
                break;
            case 2:
                cout<<"Ubicacion: Colon";
                break;
            case 3:
                cout<<"Ubicacion: Comayagua";
                break;
            case 4:
                cout<<"Ubicacion: Copan";
                break;
            case 5:
                cout<<"Ubicacion: Cortes";
                break;
            case 6:
                cout<<"Ubicacion: Choluteca";
                break;
            case 7:
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

            cout<<endl<<"*********************************************";
            cout <<endl<< "Desea seguir\n1. si\n2. no\n";
            cin >> bandera;

            cin.ignore();
    }

    cout<<"\n*********************************************";
    cout << endl << "Programa finalizado";





    return 0;
}
