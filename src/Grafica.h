#include <SFML/Graphics.hpp>
#include "GraficNode.h"
#include <sfLine.h>
using namespace std;
using namespace sf;


class Grafica{
public:
	int V;
	sf::RenderWindow* window;
	vector<GraficNode>* nodi;
	double toRadians(double degree);
	void getPoints(int x0,int y0,int r,int noOfDividingPoints, int (x)[], int (y)[]);
	void drawDijkstra();
	void init(Font &font);
	int *X;
	int *Y;
	sf::Text calculateDijkstra;
	sf::RectangleShape buttonShape;
	void drawGraph(Font &font, int val,int i ,int j);

};
