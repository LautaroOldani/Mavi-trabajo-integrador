#pragma once
#ifndef INOCENTE_H
#define INOCENTE_H

#include <SFML/Graphics.hpp>
#include <string>
#include <iostream>

class Inocente {
private:
    sf::Texture texture;
    sf::Sprite sprite;

public:
   
    Inocente(const std::string& textureFile, float x, float y);

   
    sf::Sprite& getSprite();

    
    void cambiarPosicion();

   
    void dibujar(sf::RenderWindow& window);

    
    sf::FloatRect getBounds() const {
        return sprite.getGlobalBounds();
    }
};

#endif 
