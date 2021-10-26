#include "Grafica.h"
#include <math.h>
#include <iostream>
#include <chrono>

using namespace std::chrono;
using namespace std;
using namespace sf;

#define min(a,b) (a>b?b:a)
double Grafica::toRadians(double degree)
	{
	    double pi = 3.14159265359;
	    return (degree * (pi / 180));
	}

void Grafica::getPoints(int x0,int y0,int r,int noOfDividingPoints, int (x)[], int (y)[])
	{

	   double angle = 0;



	   for(int i = 0 ; i < noOfDividingPoints  ;i++)
	   {
	       angle = i * (360/noOfDividingPoints);

	       x[i] = (int) (x0 + r * cos(toRadians(angle)));
	       y[i] = (int) (y0 + r * sin(toRadians(angle)));

	   }

	}


struct LineaDinamica{

	int id;
	bool esiste;
	double timeAnimation;//ms
	double curTimeSpent;//ms
	double curTimeMS;
	void drawGrosso(int i, double mult, vector<GraficNode>* nodi, RenderWindow* window){
		float x1=(*nodi)[i].shape->getPosition().x;
		float y1=(*nodi)[i].shape->getPosition().y;

		float x2=(*nodi)[i].prevNode->shape->getPosition().x;
		float y2=(*nodi)[i].prevNode->shape->getPosition().y;

		double vx=x1-x2;
		double vy=y1-y2;

		double mag=hypot(vx, vy);
		vx/=mag;
		vy/=mag;
		float distance=mag*mult;
		float x22=x2+vx * distance;
		float y22=y2+vy * distance;

		sf::Vertex line1[] =
			{
				sf::Vertex((*nodi)[i].prevNode->shape->getPosition(), sf::Color::Green),
				sf::Vertex(Vector2f(x22, y22), sf::Color::Green)
			};
			sfLine l2(Vector2f(x22, y22), (*nodi)[i].prevNode->shape->getPosition());


			l2.setColor(Color::Green);
			//l2.color(sf::Color::Yellow);
			(*window).draw(l2);

	};
	void stepForward(vector<GraficNode>* nodi, RenderWindow* window){

	    unsigned long now = std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();
	    cout<<now<<endl;
		double realCurrentTimeMS = now;
		double timeSpent = realCurrentTimeMS-curTimeMS;
		curTimeMS = realCurrentTimeMS;
		curTimeSpent+=timeSpent;
		double mult=min(1, curTimeSpent/timeAnimation);
		drawGrosso(id, mult, nodi, window);
	}
};
vector<LineaDinamica> lineeDinamiche(100);


void Grafica::drawDijkstra(){
    unsigned long now = std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();


	for(int i=0; i<V;i++){
		if((*nodi)[i].prevNode != NULL){
			if(!lineeDinamiche[i].esiste){
				lineeDinamiche[i]={i, 1, 5000, 0,  now};
			}
			for(LineaDinamica linea:lineeDinamiche){
				if(linea.esiste)
					linea.stepForward(nodi, window);
			}

		}
	}
}

void Grafica::init(Font &font){
	buttonShape = sf::RectangleShape(sf::Vector2f(100, 50));

	calculateDijkstra.setFont(font); // font is a sf::Font
		calculateDijkstra.setString("Exec Dijkstra");
		calculateDijkstra.setCharacterSize(24); // in pixels, not points!
		calculateDijkstra.setFillColor(sf::Color::White);
		calculateDijkstra.setStyle(sf::Text::Bold | sf::Text::Underlined);
		calculateDijkstra.setOrigin((calculateDijkstra.getLocalBounds().width/2), calculateDijkstra.getLocalBounds().height/2);
		calculateDijkstra.setPosition(50.f, 50.f);

		buttonShape.setFillColor(sf::Color::Black);
		buttonShape.setOrigin(buttonShape.getLocalBounds().width/2, buttonShape.getLocalBounds().height/2);
		buttonShape.setPosition(50.f, 50.f);

}

void Grafica::drawGraph(Font &font, int val, int i, int j){
	sf::Vertex line1[] =
		{
			sf::Vertex((*nodi)[i].shape->getPosition(), sf::Color::Black),
			sf::Vertex((*nodi)[j].shape->getPosition(), sf::Color::Black)
		};
	sf::Vertex line2[] =
			{
				sf::Vertex(Vector2f((*nodi)[i].shape->getPosition().x+1,(*nodi)[i].shape->getPosition().y) , sf::Color::Black),
				sf::Vertex(Vector2f((*nodi)[j].shape->getPosition().x+1,(*nodi)[j].shape->getPosition().y), sf::Color::Black)
			};
	sf::Vertex line3[] =
			{
				sf::Vertex(Vector2f((*nodi)[i].shape->getPosition().x,(*nodi)[i].shape->getPosition().y+1) , sf::Color::Black),
				sf::Vertex(Vector2f((*nodi)[j].shape->getPosition().x,(*nodi)[j].shape->getPosition().y+1), sf::Color::Black)
			};

		window->draw(line1, 2, sf::Lines);
		window->draw(line2, 2, sf::Lines);
		window->draw(line3, 2, sf::Lines);

		 sf::Text text;
		text.setFont(font);
		string sVal=to_string(val);
		text.setString(sVal);
		text.setCharacterSize(24);
		text.setFillColor(sf::Color::Red);
		text.setStyle(sf::Text::Bold);
		text.setColor(sf::Color::Red);
		text.setOrigin((text.getLocalBounds().width/2), text.getLocalBounds().height/2);
		float x1=(*nodi)[i].shape->getPosition().x;
		float x2=(*nodi)[j].shape->getPosition().x;
		float y1=(*nodi)[i].shape->getPosition().y;
		float y2=(*nodi)[j].shape->getPosition().y;
		text.setPosition(min(x1,x2)+((max(x1,x2)-min(x1,x2))/2)+10, min(y1,y2)+((max(y1,y2)-min(y1,y2))/2)+10);
		window->draw(text);
}
