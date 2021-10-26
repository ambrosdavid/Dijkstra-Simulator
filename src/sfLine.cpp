
#include <SFML/Graphics.hpp>
#include <math.h>
#include "sfLine.h"
using namespace std;
using namespace sf;

sfLine::sfLine(const sf::Vector2f& point1, const sf::Vector2f& point2):
        color(sf::Color(46, 204, 113)), thickness(6.f)
    {
        sf::Vector2f direction = point2 - point1;
        sf::Vector2f unitDirection = direction/std::sqrt(direction.x*direction.x+direction.y*direction.y);
        sf::Vector2f unitPerpendicular(-unitDirection.y,unitDirection.x);

        sf::Vector2f offset = (thickness/2.f)*unitPerpendicular;

        vertices[0].position = point1 + offset;
        vertices[1].position = point2 + offset;
        vertices[2].position = point2 - offset;
        vertices[3].position = point1 - offset;

        for (int i=0; i<4; ++i)
            vertices[i].color = color;
    }

    void sfLine::draw(sf::RenderTarget &target, sf::RenderStates states) const
    {
        target.draw(vertices,4,sf::Quads);
    }
    void sfLine::setColor(sf::Color col){
    	color=col;
    }

