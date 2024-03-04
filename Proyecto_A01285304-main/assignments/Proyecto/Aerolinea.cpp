#include "Aerolinea.hpp"


// Constructor con y sin parametros 

Aerolinea::Aerolinea():clave{},tipo{},nombre{}{
}
Aerolinea::Aerolinea(std::string clav, std::string tip, std::string nomb):clave{clav},tipo{tip},nombre{nomb}{
}

// getters
std::string Aerolinea::getClave()const{
    return clave;
}

std::string Aerolinea::getTipo()const{
    return tipo;
}
std::string Aerolinea::getNombre()const{
    return nombre;
}

//setters

void Aerolinea::setClave(std::string clav){
    clave=clav;
}

void Aerolinea::setTipo(std::string tip){
    tipo=tip;
}

void Aerolinea::setNombre(std::string nomb){
    nombre=nomb;
}

void Aerolinea::imprime() const{
    std::cout<<"En cuestiones de la Aerolinea, la clave de vuelo es: " << clave <<", el tipo es de: "<< tipo << ", y el nombre es: "<< nombre<< std::endl;
}