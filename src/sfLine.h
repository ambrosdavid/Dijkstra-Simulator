#ifndef SFLINE_H
#define SFLINE_H

#include <SFML/Graphics.hpp>
#include <math.h>
class sfLine : public sf::Drawable
{
public:
    sfLine(const sf::Vector2f& point1, const sf::Vector2f& point2);

    void draw(sf::RenderTarget &target, sf::RenderStates states) const;

    void setColor(sf::Color col);


private:
    sf::Vertex vertices[4];
    float thickness;
    sf::Color color;
};


#endif
