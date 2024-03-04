#include "Vuelo.hpp"
#include "Hora.hpp"
#include "Aerolinea.hpp"


// Constructor con y sin parametros 

Vuelo::Vuelo():Id{"D"},origen{"Mexico"},numPas{0}{
}
// Aerolinea y hora son parametros por referencia? como afecta los getters y setters
Vuelo::Vuelo(std::string aidi, std::string orig, Aerolinea aerolinea, int num, Hora h): Id{aidi},origen{orig},aerolinea{aerolinea},numPas{num},horaEstim{h}{
}


// getters
std::string Vuelo::getId()const{
    return Id;
}

std::string Vuelo::getOrigen()const{
    return origen;
}

Aerolinea Vuelo::getAerolinea() const{
    return aerolinea;
}


int Vuelo::getnumPas()const{
    return numPas;
}

Hora Vuelo::getHoraEstim() const{
    return horaEstim;
}



//setters

void Vuelo::setId(std::string aidi){
    Id=aidi;
}

void Vuelo::setOrigen(std::string orig){
    origen=orig;
}

void Vuelo::setnumPas(int num){
    numPas=num;
}

void Vuelo::setAerolinea(Aerolinea aer){
    aerolinea=aer;
}

void Vuelo::setHoraEstim( Hora h){
    horaEstim=h;
}



void Vuelo::imprime() const{
    std::cout<<"Id del vuelo: "<< Id <<", Origen: "<< origen<< "El numero de pasajeros es: "<< numPas<<std::endl;
    std::cout<<"Aerolinea: ";
    aerolinea.imprime();
    std::cout <<"Hora estimada de llegada";
    horaEstim.imprime();
    std::cout << std::endl <<"Hora real de llegada: ";
    horaReal.imprime();
}

int Vuelo::calculaTiempoRetraso(){
    int hestimada,hllegada,min;
    hestimada= horaEstim.getHora()*60 + horaEstim.getMin();
    hllegada= horaReal.getHora()*60 + horaReal.getMin();
    min= hllegada-hestimada;
    if (min<0 ){
        return 0;
    }else{
        return min;
    }   
}