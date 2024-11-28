#pragma once
#ifndef ENEMIGO_H
#define ENEMIGO_H

#include <SFML/Graphics.hpp>
#include <string>

class Enemigo {
private:
    sf::Sprite sprite;
    sf::Texture textura;

public:
    
    Enemigo(const std::string& archivoTextura, float x, float y);

    
    void dibujar(sf::RenderWindow& window);

   
    sf::FloatRect getBounds() const;

   
    void cambiarPosicion();
};

#endif 

