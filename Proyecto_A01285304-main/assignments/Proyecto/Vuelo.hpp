#pragma once
#include "Hora.hpp"
#include "Aerolinea.hpp"


class Vuelo{
    public:
        //Constructores default y con parametros

        Vuelo();
        //Vuelo(std::string aidi, std::string orig, Aerolinea aerolinea, int num, int nume);
        Vuelo(std::string, std::string, Aerolinea, int, Hora);

        // getters

        std::string getId() const;
        std::string getOrigen() const;
        Aerolinea getAerolinea() const;
        int getnumPas() const;
        Hora getHoraEstim() const;
        Hora getHoraReal() const;
        

        //setters

        void setId(std::string);
        void setOrigen(std::string);
        void setnumPas(int);
        void setAerolinea(Aerolinea);
        void setHoraEstim(Hora);
        void setHoraReal(Hora);

        //otros

        int calculaTiempoRetraso();
        void imprime() const;

    private:

        std::string Id;
        std::string origen;
        Aerolinea aerolinea;
        int numPas;
        Hora horaEstim;
        Hora horaReal;
};