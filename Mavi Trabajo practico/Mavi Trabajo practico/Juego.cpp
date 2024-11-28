#include "Juego.h"
#include <iostream>

Juego::Juego()
    : window(sf::VideoMode(800, 600), "Juego de Disparos"),
    enemigo("enemigo.png", 100, 100),
    inocente("Aliado.PNG", 100, 150),
    spriteVisible(-1),
    tiempoVisibleEnemigo(5.0f),
    tiempoVisibleAliado(2.0f),
    tiempoLimiteEspera(3.0f),
    estadoJuego(Jugando) { 

    
    if (!cieloTexture.loadFromFile("cieloNoche.JFIF")) {
        std::cerr << "Error al cargar la textura del cielo." << std::endl;
    }
    cieloSprite.setTexture(cieloTexture);
    cieloSprite.setScale(
        static_cast<float>(window.getSize().x) / cieloTexture.getSize().x,
        static_cast<float>(window.getSize().y) / cieloTexture.getSize().y
    );

   
    if (!font.loadFromFile("arial.ttf")) {
        std::cerr << "Error al cargar la fuente." << std::endl;
    }


    textPuntaje.setFont(font);
    textPuntaje.setCharacterSize(24);
    textPuntaje.setFillColor(sf::Color::White);
    textPuntaje.setPosition(10, 10);

    textEnemigosMuertos.setFont(font);
    textEnemigosMuertos.setCharacterSize(24);
    textEnemigosMuertos.setFillColor(sf::Color::White);
    textEnemigosMuertos.setPosition(10, 40);

    textVidas.setFont(font);
    textVidas.setCharacterSize(24);
    textVidas.setFillColor(sf::Color::White);
    textVidas.setPosition(10, 70);

    
    std::srand(static_cast<unsigned>(std::time(nullptr)));
}

void Juego::ejecutar() {
    while (window.isOpen()) {
        manejarEventos();

        if (estadoJuego == Jugando) {
            actualizar();
            dibujar();
        }
        else if (estadoJuego == GameOver) {
            mostrarGameOver();
            return; 
        }
    }
}

void Juego::manejarEventos() {
    sf::Event event;
    while (window.pollEvent(event)) {
        if (event.type == sf::Event::Closed)
            window.close();

        if (event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Left) {
            if (spriteVisible == 0 && mira.getBounds().intersects(enemigo.getBounds())) {
                enemigo.cambiarPosicion();
                jugador.aumentarPuntaje(10);
                jugador.aumentarEnemigosMuertos();
                spriteVisible = -1;
                relojEnemigo.restart();
                relojEsperaEnemigo.restart();
            }
            else if (spriteVisible == 1 && mira.getBounds().intersects(inocente.getBounds())) {
                inocente.cambiarPosicion();
                jugador.aumentarPuntaje(-5);
                jugador.perderVida();
                spriteVisible = -1;
                relojAliado.restart();
            }
        }
    }
}

void Juego::actualizar() {
    if (jugador.getEnemigosMuertos() >= 10 || jugador.getVidas() <= 0) {
        estadoJuego = GameOver; 
        return;
    }

    if (spriteVisible == 0 && relojEsperaEnemigo.getElapsedTime().asSeconds() >= tiempoLimiteEspera) {
        jugador.perderVida();
        jugador.aumentarPuntaje(-5);
        spriteVisible = -1;
        relojEsperaEnemigo.restart();
    }

    mira.actualizarPosicion(window);

    if (spriteVisible == 0 && relojEnemigo.getElapsedTime().asSeconds() >= tiempoVisibleEnemigo) {
        spriteVisible = -1;
        relojEnemigo.restart();
    }
    else if (spriteVisible == 1 && relojAliado.getElapsedTime().asSeconds() >= tiempoVisibleAliado) {
        spriteVisible = -1;
        relojAliado.restart();
    }

    if (spriteVisible == -1) {
        if (relojEnemigo.getElapsedTime().asSeconds() >= tiempoVisibleEnemigo) {
            enemigo.cambiarPosicion();
            spriteVisible = 0;
            relojEnemigo.restart();
            relojEsperaEnemigo.restart();
        }
        else if (relojAliado.getElapsedTime().asSeconds() >= tiempoVisibleAliado) {
            inocente.cambiarPosicion();
            spriteVisible = 1;
            relojAliado.restart();
        }
    }
}

void Juego::dibujar() {
    window.clear();
    window.draw(cieloSprite);
    mira.dibujar(window);

    if (spriteVisible == 0)
        enemigo.dibujar(window);
    else if (spriteVisible == 1)
        inocente.dibujar(window);

    textPuntaje.setString("Puntaje: " + std::to_string(jugador.getPuntaje()));
    textEnemigosMuertos.setString("Enemigos Muertos: " + std::to_string(jugador.getEnemigosMuertos()));
    textVidas.setString("Vidas: " + std::to_string(jugador.getVidas()));

    window.draw(textPuntaje);
    window.draw(textEnemigosMuertos);
    window.draw(textVidas);

    window.display();
}

void Juego::mostrarGameOver() {
    window.clear();
    sf::Text textoGameOver("¡Juego Terminado!", font, 50);
    textoGameOver.setFillColor(sf::Color::Red);
    textoGameOver.setPosition(200, 200);

    sf::Text textoPuntaje("Puntaje Final: " + std::to_string(jugador.getPuntaje()), font, 30);
    textoPuntaje.setFillColor(sf::Color::White);
    textoPuntaje.setPosition(200, 300);

    window.draw(cieloSprite);
    window.draw(textoGameOver);
    window.draw(textoPuntaje);
    window.display();

    
    sf::sleep(sf::seconds(3));

    window.close(); 
}
