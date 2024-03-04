#pragma once
#include <iostream>

class Hora{
    public:
        //Constructores default y con parametros
        Hora();
        Hora(int, int);

        // getters
        int getHora() const;
        int getMin() const;

        //setters
        void setHora(int);
        void setMin(int);

        

        //otros
        void imprime() const;

      

    private:
        int hora;
        int minutos;

   
};