#include <SFML/Graphics.hpp>
#include "Menu.h"
#include "Juego.h"

int main() {
    
    sf::RenderWindow window(sf::VideoMode(800, 600), "Juego de Disparos");

    
    Menu menu(window);

    bool iniciarJuego = false;

    
    while (window.isOpen()) {
        iniciarJuego = menu.manejarEventos();

        
        if (iniciarJuego) {
            
            Juego juego;
            juego.ejecutar();
            break; 
        }

        
        menu.dibujar();
    }

    return 0;
}


