#include "Hora.hpp"
#include <iostream>
#include <iomanip>



// Constructor con y sin parametros 

Hora::Hora():hora{0},minutos{0}{
}
Hora::Hora(int hor, int min){
    setHora(hor);
    setMin(min);
}

// getters
int Hora::getHora()const{
    return hora;
}

int Hora::getMin()const{
    return minutos;
}

//setters

void Hora::setHora(int hor){
    if (hor >= 0 && hor <= 23){
        hora=hor;
    }
    
}

void Hora::setMin(int min){
    if (min >= 0 && min <= 59){
        minutos=min;
    }
    
}


// imprime

void Hora::imprime() const{
    std::cout<<std::setfill('0')<< std::setw(2)<<hora<<":"<<std::setfill('0')<<std::setw(2)<<minutos<<std::endl;
}