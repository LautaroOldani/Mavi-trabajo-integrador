#pragma once
#ifndef JUEGO_H
#define JUEGO_H

#include <SFML/Graphics.hpp>
#include <cstdlib>
#include <ctime>
#include "Enemigo.h"
#include "Inocente.h"
#include "Jugador.h"
#include "Mira.h"


enum EstadoJuego {
    Jugando,
    GameOver
};

class Juego {
private:
    sf::RenderWindow window;
    sf::Texture cieloTexture;
    sf::Sprite cieloSprite;
    sf::Font font;
    sf::Text textPuntaje, textEnemigosMuertos, textVidas;
    Enemigo enemigo;
    Inocente inocente;
    Mira mira;
    Jugador jugador;
    sf::Clock relojAliado, relojEnemigo, relojEsperaEnemigo;
    int spriteVisible; 
    const float tiempoVisibleEnemigo;
    const float tiempoVisibleAliado;
    const float tiempoLimiteEspera;

    EstadoJuego estadoJuego; 

    void manejarEventos();
    void actualizar();
    void dibujar();
    void mostrarGameOver(); 

public:
    Juego();
    void ejecutar();
};

#endif 
