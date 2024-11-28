#pragma once
#ifndef MENU_H
#define MENU_H

#include <SFML/Graphics.hpp>

class Menu {
public:
    Menu(sf::RenderWindow& window);

    
    bool manejarEventos();

    
    void dibujar();

private:
    sf::RenderWindow& window;
    sf::Font font;
    sf::Text textoIniciar;
    sf::Text textoInstrucciones;
    sf::Text textoSalir;
    sf::Text textoInstruccionesJuego;
    bool iniciarJuego;
};

#endif
