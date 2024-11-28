#include "Enemigo.h"
#include <iostream>
#include <cstdlib>  

Enemigo::Enemigo(const std::string& archivoTextura, float x, float y) {
    if (!textura.loadFromFile("nave Animada.PSD")) {
        std::cerr << "Error al cargar la textura del enemigo." << std::endl;
    }
    sprite.setTexture(textura);
    sprite.setScale(0.3f, 0.3f);
    sprite.setPosition(x, y); 
}


void Enemigo::dibujar(sf::RenderWindow& window) {
    window.draw(sprite);
}


sf::FloatRect Enemigo::getBounds() const {
    return sprite.getGlobalBounds();
}

void Enemigo::cambiarPosicion() {
    
    float x = static_cast<float>(std::rand() % 500);
    float y = static_cast<float>(std::rand() % 300);

    sprite.setPosition(x, y);     
}
