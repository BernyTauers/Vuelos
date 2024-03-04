#include <iostream>
#include "Aerolinea.hpp"
#include "Vuelo.hpp"
#include "Hora.hpp"
#include <fstream>
using namespace std;


//busca la posicion de la aerolinea y la regresa
int buscaAerolinea(Aerolinea listAero[], int cantAero, string claveABuscar){
    for (int i = 0; i < cantAero; i++){
        if (listAero[i].getClave() == claveABuscar){
            
            return i;
        }        
    }
    cout<<"Clave incorrecta"<< endl;
    return -1;
}



void cargaAerolineas(Aerolinea listAero[], int& num){
    string clave,tip,aerolin;
    ifstream archivo;
    archivo.open("aerolineas.txt");
    if (archivo.is_open()){
        while (archivo>> clave>> tip>>aerolin){
            listAero[num].setClave(clave);
            listAero[num].setTipo(tip);
            listAero[num].setNombre(aerolin);
            num++;
        }
        archivo.close();
    }else{
        cout<< "No se pudo abrir el archivo"<<endl;
    }
}

void cambiarHoras(Vuelo listVuel[],int& numVuel){
    string i_d;
    int hora,min;
    cout<<"Selecciona el id del vuelo"<<endl;
    cin>>i_d;
    cout<<"Ingresa la hora y los minutos separados por un espacio"<<endl;
    cin>>hora>>min;
    for (int i=0; i<numVuel; i++){
        if(listVuel[i].getId()==i_d){
            listVuel[i].setHoraEstim(Hora{hora,min});
        }
    }



}
// faltan los otros parametros que vienen de otras clases
void cargaVuelos(Vuelo listVuel[], int& num,Aerolinea listAero[], int cantAero){
    string id,origen,clave;
    int cantPas, h,min,pos;
    ifstream archivoD;
    archivoD.open("vuelos.txt");
    if (archivoD.is_open()){
        while (archivoD>> id>> origen>>clave>>cantPas>>h>>min){
            listVuel[num].setId(id);
            listVuel[num].setOrigen(origen);
            listVuel[num].setnumPas(cantPas);
            listVuel[num].setHoraEstim(Hora{h,min});
            pos = buscaAerolinea(listAero,cantAero,clave);
            listVuel[num].setAerolinea(listAero[pos]);
            num++;
        }
        archivoD.close();
    }else{
        cout<<"No se pudo abrir el archivo"<<endl;
    }
}

void imprimeAerolineas(Aerolinea listAero[], int numAero){
    for (int i= 0; i< numAero; i++){
        listAero[i].imprime();
    }
}

void imprimeVuelos(Vuelo listVuel[], int numVuelo){
    for (int i= 0; i< numVuelo; i++){
        listVuel[i].imprime();
    }
}


void vuelosDet(Vuelo listVuel[], int& numVuelo){
    string ciudad;
    int horauno,horados;
    cout<<"Seleciona la ciudad"<< endl;
    cin>> ciudad;
    cout<<"Seleciona las horas a las que te gustaria salir y llegar, separalas con un espacio"<< endl;
    cin>> horauno, horados;
    for (int i = 0; i < numVuelo; i++){
        if (listVuel[i].getOrigen()==ciudad && listVuel[i].getHoraEstim().getHora() >= horauno && listVuel[i].getHoraEstim().getHora() <= horados ){
            cout << listVuel[i].getId()<<endl;
            cout << listVuel[i].getOrigen()<<endl;
            cout << listVuel[i].getAerolinea().getNombre()<<endl;
            
        }

    }


}

void vuelosPart(Vuelo listVuel[], int numVuelo){
    int opcion;
    string buscar;
    cout<<"Seleccione su opcion: Buscar por clave (1), Buscar por aerolinea (2)"<<endl;
    cin>>opcion;
    if (opcion==1){
        cout<< "Teclee la clave" <<endl;
        cin>> buscar;
        for (int i = 0; i<numVuelo; i++){
            if (listVuel[i].getAerolinea().getClave()==buscar){
                cout<<listVuel[i].getId() << endl;
                cout<<listVuel[i].getOrigen() << endl;
            }
        }

    }
    else if (opcion==2){
        cout<< "Teclee el nombre" <<endl;
        cin>> buscar;
        for (int i = 0; i<numVuelo; i++){
            if (listVuel[i].getAerolinea().getNombre()==buscar){
                cout<<listVuel[i].getId() << endl;
                cout<<listVuel[i].getOrigen() << endl;
            }
        }
    }
}

    


    





int main() {

 const int MAX = 20;
 Aerolinea listaAerolinea[MAX];
 Vuelo listaVuelo[MAX];
 int numAero = 0;
 int numVuelo = 0;
 char opcion;
 cargaAerolineas(listaAerolinea,numAero);
 cargaVuelos(listaVuelo,numVuelo, listaAerolinea, numAero);
 
    do {
        cout << endl;
        cout << "Opciones disponibles " << endl;
        cout << " 1) Desplegar lista de Aerolineas " << endl;
        cout << " 2) Desplegar lista de Vuelos " << endl;
        cout << " 3) Desplegar Vuelos de una Aerolinea en particular" << endl; //despliega los vendedores de un departamento en particular
        cout << " 4) Desplegar Vuelos con ciudad y tiempo determinado "<< endl;
        cout << " 5) Desplegar la hora de llegada real de un vuelo"<< endl;
        cout << " 6) Salir del programa" << endl; //buscar vuelo en arreglo, modificar su ateributo de llegada real (preguntar usuario hora y min)
        cin >> opcion;
        switch (opcion) {
            case '1':
                imprimeAerolineas( listaAerolinea, numAero );
                cin.ignore();
                cout << "Enter para continuar...";
                cin.get();
                break;
            case '2':
                imprimeVuelos(listaVuelo,numVuelo);
                cin.ignore();
                cout << "Enter para continuar...";
                cin.get();
                break;
            case '3': 
                imprimeAerolineas(listaAerolinea,numAero);
                vuelosPart(listaVuelo,numVuelo);
                cin.ignore();
                cout << "\nEnter para continuar...";
                cin.get();
                break;
            case '4': 
                vuelosDet(listaVuelo,numVuelo);
                cin.ignore();
                cout << "Enter para continuar...";
                cin.get();
                break;

              case '5': 
                cambiarHoras(listaVuelo, numVuelo);
                cin.ignore();
                cout << "Enter para continuar...";
                cin.get();
                break;

            case '6':
                cout << "Elegiste salir del programa..."<< endl;
                break;
            default:
                cout << "Opcion invalida"<<endl;
        }
        system("clear");
    } while (opcion != '6');

}
