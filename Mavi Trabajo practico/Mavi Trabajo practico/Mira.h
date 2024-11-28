#pragma once
#ifndef MIRA_H
#define MIRA_H

#include <SFML/Graphics.hpp>

class Mira {
private:
    sf::CircleShape shape; 

public:
   
    Mira();

    
    void actualizarPosicion(sf::RenderWindow& window);

    
    void dibujar(sf::RenderWindow& window);

    
    sf::FloatRect getBounds() const;
};

#endif
