#include "Mira.h"


Mira::Mira() {
    shape.setRadius(20);  
    shape.setFillColor(sf::Color::Red);  
}


void Mira::actualizarPosicion(sf::RenderWindow& window) {
    sf::Vector2i mousePos = sf::Mouse::getPosition(window);
    shape.setPosition(mousePos.x - shape.getRadius(), mousePos.y - shape.getRadius());
}


void Mira::dibujar(sf::RenderWindow& window) {
    window.draw(shape);
}


sf::FloatRect Mira::getBounds() const {
    return shape.getGlobalBounds();
}
