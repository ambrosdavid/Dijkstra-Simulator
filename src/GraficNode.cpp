#include <SFML/Graphics.hpp>
#include <iostream>
#include "GraficNode.h"
using namespace std;
using namespace sf;


GraficNode::GraficNode(string nodeName){
			prevNode=NULL;
			_nodeName = nodeName;
			shape = new sf::CircleShape(20.f);
			(*shape).setPointCount(500);
			(*shape).setFillColor(sf::Color::Black);
			(*shape).setOrigin((*shape).getLocalBounds().width/2, (*shape).getLocalBounds().height/2);
			(*shape).setPosition(300.f, 300.f);


			text=new sf::Text;
			sf::Font font;//Amatic-Bold.ttf
			if (!font.loadFromFile("src/res/Amatic-Bold.ttf"))
			{
				std::cout << "Crasha font!! " << std::endl;
			}
			// select the font
			(*text).setFont(font); // font is a sf::Font
			// set the string to display
			(*text).setString(_nodeName);
			// set the character size
			(*text).setCharacterSize(24); // in pixels, not points!
			// set the color
			(*text).setFillColor(sf::Color::White);
			// set the text style
			(*text).setStyle(sf::Text::Bold | sf::Text::Underlined);
			(*text).setOrigin(((*text).getLocalBounds().width/2), (*text).getLocalBounds().height/2);
			(*text).setPosition(300.f, 300.f);
		}

void GraficNode::setPosition(float x, float y){
			(*text).setPosition(x, y);
			(*shape).setPosition(x, y);
		}
