#pragma once
#include <iostream>

class Aerolinea{
    public:
        //Constructores default y con parametros
        Aerolinea();
        Aerolinea(std::string, std::string, std::string);

        // getters
        std::string getClave() const;
        std::string getTipo() const;
        std::string getNombre() const;

        //setters
        void setClave(std::string);
        void setTipo(std::string);
        void setNombre(std::string);

        //otros
        void imprime() const;

      

    private:
        std::string clave;
        std::string tipo;
        std::string nombre;

};