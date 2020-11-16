#include <iostream>
#include <stdlib.h>
#include <time.h>

using namespace std;

class Points {
	public:
		float x1, y1, x2, y2, x3, y3, x4, y4;
		Points(float x1, float y1, float x2, float y2, float x3, float y3, float x4, float y4) {
			this->x1 = x1;
			this->y1 = y1;
			this->x2 = x2;
			this->y2 = y2;
			this->x3 = x3;
			this->y3 = y3;
			this->x4 = x4;
			this->y4 = y4;
			cout << this->x1 << endl;
		}
};

class Square {
	public:
		Points vertices;
		Square(Points vertices): vertices(vertices) {
			this->vertices = vertices;
		}
		
		void printCoordinates() {
			cout << "wierzcholki kwadratu:" << endl;
			cout << "[" << this->vertices.x1 << ", " << this->vertices.y1 << "]" << endl;
			cout << "[" << this->vertices.x2 << ", " << this->vertices.y2 << "]" << endl;
			cout << "[" << this->vertices.x3 << ", " << this->vertices.y3 << "]" << endl;
			cout << "[" << this->vertices.x4 << ", " << this->vertices.y4 << "]" << endl;
		}
};

int main() {
	float x1, y1, x2, y2, x3, y3, x4, y4;
	cout << "Podaj wierzcholek x1"<< endl;
	cin >> x1;
	cout << "Podaj wierzcholek y1"<< endl;
	cin >> y1;
	cout << "Podaj wierzcholek x2"<< endl;
	cin >> x2;
	cout << "Podaj wierzcholek y2"<< endl;
	cin >> y2;
	cout << "Podaj wierzcholek x3"<< endl;
	cin >> x3;
	cout << "Podaj wierzcholek y3"<< endl;
	cin >> y3;
	cout << "Podaj wierzcholek x4"<< endl;
	cin >> x4;
	cout << "Podaj wierzcholek y4"<< endl;
	cin >> y4;
	Points vertices(x1, y1, x2, y2, x3, y3, x4, y4);
	Square square(vertices);
	square.printCoordinates();
		
	system("PAUSE");
	return 0;
}
