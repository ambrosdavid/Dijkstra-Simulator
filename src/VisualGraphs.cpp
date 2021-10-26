#include <iostream>
#include<bits/stdc++.h>
#include <SFML/Graphics.hpp>
#include <math.h>
#include <windows.h>
#include <thread>
#include <chrono>
#include <sfLine.h>
#include "Graph.h"
#include "Model.h"
#include "Grafica.h"
using namespace std;
using namespace sf;
# define INF 0x3f3f3f3f

Model model;
vector<GraficNode> nodi;
int V = 9;
Graph g(V);
Grafica graphics;


DWORD WINAPI ThreadFunc(void *data) {
	model.shortestPath(0, nodi, V, g.adj);
  return 0;
}

void execDijkstra(){
	CreateThread(NULL, 0, ThreadFunc, NULL, 0, NULL);
}

sf::RenderWindow window(sf::VideoMode(800,800), "Dijkstra Simulator");

int main()
{
	graphics.V=V;
	graphics.window=&window;
	graphics.nodi=&nodi;

    for(int i=0; i<V; i++){
    	GraficNode gN(to_string(i));
		nodi.push_back(gN);
    }

	for(int i=0; i<V; i++){
		for(int j=0; j<V; j++)
			g.matAdj[i][j]=-1;
	}
	model.popolateGraph(g);

    int *x = new int[V];
    int *y = new int[V];

    graphics.X = x;
	graphics.Y = y;

    graphics.getPoints(400, 400, 250, V, x, y);

	sf::Font font;//Amatic-Bold.ttf
	if (!font.loadFromFile("src/res/Amatic-Bold.ttf")){}
    for(int i=0; i<V; i++){
    	nodi[i].setPosition(x[i], y[i]);
    	nodi[i].text->setFont(font);
    }

	graphics.init(font);
	RectangleShape buttonShape= graphics.buttonShape;
	Text calculateDijkstra=graphics.calculateDijkstra;
	int leftButton=0;
        while (window.isOpen())
        {
            sf::Event event;
            while (window.pollEvent(event))
            {
                if (event.type == sf::Event::Closed)
                    window.close();
                if (event.type == sf::Event::MouseButtonPressed)
                {
                    if (event.mouseButton.button == sf::Mouse::Left)
                    	leftButton=1;

                	if(buttonShape.getGlobalBounds().contains(event.mouseMove.x, event.mouseMove.y)  && event.mouseButton.button == sf::Mouse::Right){
                		for(int i=0; i<V; i++)
                			nodi[i].prevNode=NULL;
                		execDijkstra();
                	}

                }
                if (event.type == sf::Event::MouseButtonReleased)
                {
                    if (event.mouseButton.button == sf::Mouse::Left)
                    	leftButton=0;
                }
                if (event.type == sf::Event::MouseMoved)
                {
                    std::cout << "new mouse x: " << event.mouseMove.x << std::endl;
                    std::cout << "new mouse y: " << event.mouseMove.y << std::endl;
                    if(leftButton)
                    	for(int i=0; i<V; i++)
                    		if( (*(nodi[i].shape)).getGlobalBounds().contains(event.mouseMove.x, event.mouseMove.y))
                    			nodi[i].setPosition(event.mouseMove.x, event.mouseMove.y);

                }
            }

            window.clear(sf::Color::White);

        	for(int i=0; i<V;i++)
        		for(int j=0; j<V; j++)
        			if(g.matAdj[i][j]!=-1)
        				graphics.drawGraph(font, g.matAdj[i][j], i, j);

        	graphics.drawDijkstra();

            for(int i=0; i<V; i++){
                	window.draw( *(nodi[i].shape));
                	window.draw( *(nodi[i].text));
                }

            window.draw(buttonShape);
            window.draw(calculateDijkstra);

            window.display();
        }

        return 0;
}










