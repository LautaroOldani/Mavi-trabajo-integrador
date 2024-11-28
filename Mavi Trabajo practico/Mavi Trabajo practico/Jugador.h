#pragma once
#ifndef JUGADOR_H
#define JUGADOR_H

#include <SFML/Graphics.hpp>

class Jugador {
private:
    int vidas;
    int puntaje;
    int enemigosMuertos;

public:
    
    Jugador() : vidas(3), puntaje(0), enemigosMuertos(0) {}

  
    void perderVida() {
        if (vidas > 0) vidas--;
    }

    
    void aumentarPuntaje(int cantidad) {
        puntaje += cantidad;
    }

    
    void aumentarEnemigosMuertos() {
        enemigosMuertos++;
    }

    
    int getVidas() const {
        return vidas;
    }

    
    int getPuntaje() const {
        return puntaje;
    }

    
    int getEnemigosMuertos() const {
        return enemigosMuertos;
    }
};

#endif 


