#include "Menu.h"
#include <iostream>

Menu::Menu(sf::RenderWindow& window)
    : window(window), iniciarJuego(false) {

    
    if (!font.loadFromFile("arial.ttf")) {
        std::cerr << "Error al cargar la fuente.\n";
    }

   
    textoIniciar.setFont(font);
    textoIniciar.setString("P: Iniciar Juego");
    textoIniciar.setCharacterSize(24);
    textoIniciar.setFillColor(sf::Color::White);
    textoIniciar.setPosition(300, 200);

   
    textoSalir.setFont(font);
    textoSalir.setString("Q: Salir");
    textoSalir.setCharacterSize(24);
    textoSalir.setFillColor(sf::Color::White);
    textoSalir.setPosition(300, 250);

    
    textoInstruccionesJuego.setFont(font);
    textoInstruccionesJuego.setString("Instrucciones:\n"
        "- Dispara a los enemigos y evita disparar a los aliados.\n"
        "- Si disparas a un aliado, perderás 1 vida y 5 puntos.\n"
        "- Si disparas a un enemigo, ganarás 10 puntos.\n"
        "- Si no le disparas al enemigo antes que desaparezca, perderás 1 vida y 5 puntos.");
    textoInstruccionesJuego.setCharacterSize(18);
    textoInstruccionesJuego.setFillColor(sf::Color::White);
    textoInstruccionesJuego.setPosition(100, 300); 
}

bool Menu::manejarEventos() {
    sf::Event event;
    while (window.pollEvent(event)) {
        if (event.type == sf::Event::Closed) {
            window.close();
        }

        if (event.type == sf::Event::KeyPressed) {
            if (event.key.code == sf::Keyboard::P) {
                iniciarJuego = true;
                return true;
            }
            else if (event.key.code == sf::Keyboard::Q) {
                window.close();
            }
        }
    }
    return false;
}

void Menu::dibujar() {
    window.clear(); 
    window.draw(textoIniciar);
    window.draw(textoSalir);
    window.draw(textoInstruccionesJuego);

    window.display(); 
}
