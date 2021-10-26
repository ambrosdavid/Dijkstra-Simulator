#ifndef GRAFIC_NODE_H
#define GRAFIC_NODE_H

#include <SFML/Graphics.hpp>
using namespace std;
using namespace sf;


class GraficNode
{
	public:
		string _nodeName;
		CircleShape* shape;
		Text* text;
		GraficNode* prevNode;
		GraficNode(string nodeName);
		void setPosition(float x, float y);
};


#endif
