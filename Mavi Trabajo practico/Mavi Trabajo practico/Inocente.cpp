#include "Inocente.h"


Inocente::Inocente(const std::string& textureFile, float x, float y) {
    if (!texture.loadFromFile("avionAnimado.PNG")) {
        std::cerr << "Error al cargar la textura del inocente." << std::endl;
    }
    sprite.setTexture(texture);
    sprite.setPosition(x, y);
    sprite.setScale(0.2f, 0.2f);  
}

sf::Sprite& Inocente::getSprite() {
    return sprite;
}


void Inocente::cambiarPosicion() {
    float x = static_cast<float>(std::rand() % 500);
    float y = static_cast<float>(std::rand() % 300);

    sprite.setPosition(x, y);    
}


void Inocente::dibujar(sf::RenderWindow& window) {
    window.draw(sprite);
}
