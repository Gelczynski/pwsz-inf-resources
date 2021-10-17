#include <iostream>
#include <stdlib.h>
#include <time.h>

using namespace std;

class Point
{
	public:
		float x, y;
		
		Point(float x, float y)
		{
			this->x = x;
			this->y = y;
		}
};

class Square
{
	public:
		float h = 0;
		Point a = Point(h, h);
		Point b = Point(h, h);
		Point c = Point(h, h);
		Point d = Point(h, h);
		
		Square(Point point, float side, char pointchar)
		{
			if(pointchar == 'a')
			{
				this->a = point;
				this->b.x = point.x;
				this->b.y = point.y + side;
				this->c.x = point.x + side;
				this->c.y = point.y;
				this->d.x = point.x + side;
				this->d.y = point.y + side;
			}
			else if(pointchar == 'b')
			{
				this->a.x = point.x;
				this->a.y = point.y - side;
				this->b = point;
				this->c.x = point.x + side;
				this->c.y = point.y - side;
				this->d.x = point.x + side;
				this->d.y = point.y;
			}
			else if(pointchar == 'c')
			{
				this->a.x = point.x - side;
				this->a.y = point.y;
				this->b.x = point.x - side;
				this->b.y = point.y;
				this->c.x = point.x;
				this->c.y = point.y - side;
				this->d.x = point.x;
				this->d.y = point.y + side;
			}
			else if(pointchar == 'd')
			{
				this->a.x = point.x - side;
				this->a.y = point.y - side;
				this->b.x = point.x;
				this->b.y = point.y - side;
				this->c.x = point.x - side;
				this->c.y = point.y;
				this->d = point;
			}
		}
		
		void printCoordinates()
		{
			cout << "wierzcholki kwadratu:" << endl;
			cout << "(" << this->a.x << ", " << this->a.y << ")" << endl;
			cout << "(" << this->b.x << ", " << this->b.y << ")" << endl;
			cout << "(" << this->c.x << ", " << this->c.y << ")" << endl;
			cout << "(" << this->d.x << ", " << this->d.y << ")" << endl;
		}
};

int main() {
	float x, y;
	float n;
	float side;
	int n1;
	char pointchar;
	cout << "Podaj ilosc kwadratow:" << endl;
	
	int licznik = 0;
	
	while(licznik == 0)
	{
		licznik++;
		cin >> n;
		n1 = n;
		if(n <= 0 || n > n1)
		{
			cout << "Liczba kwadratow nie moze wyniesc 0 ani mniejsza od 0, nie moze tez byc z ulamkiem!" << endl;
			cout << "Podaj ponownie ilosc kwadratow:" << endl;
			licznik = 0;
		}
	}
	
	cout << "Ktory wierzcholek kwadratu chcesz wybrac i podac wspolrzedne dla tego wierzcholka?" << endl;
	cout << "wpisz b(lewy gorny rog) lub d(prawy gorny rog)" << endl;
	cout << "      a(lewy dolny rog) lub c(prawy dolny rog)." << endl;
	
	licznik = 0;
	
	while(licznik == 0)
	{
		licznik++;
		cin >> pointchar;
		if(pointchar == 'a' || pointchar == 'b' || pointchar == 'c' || pointchar == 'd')
		{
			cout << "Wybrales: " << pointchar << endl;
		}
		else
		{
			cout << "Nie podano prawidlowa odpowiedz!\n" << endl;
			cout << "Wybierz ponownie wierzcholek, dla ktorego chcesz podac wspolrzedne:" << endl;
			cin >> pointchar;
			licznik = 0;
		}
	}
	
	cout << "Jaka dlugosc chcesz wybrac dla boku kwadratu?" << endl;
	
	licznik = 0;
	
	while(licznik == 0)
	{
		licznik++;
		cin >> side;
		if(side <= 0)
		{
			cout << "Dlugosc boku nie moze byc rowna 0 lub mniejsza od 0!\n" << endl;
			cout << "Podaj ponownie dlugosc boku, ktorego chcesz wybrac:" << endl;
			licznik = 0;
		}
	}
	
	for(int i = 0; i < n; i++) 
	{
		cout << "\nKwadrat nr: " << i + 1 << endl;
		cout << "Podaj wspolrzedne dla wierzcholka " << pointchar << " (rozdzielac liczby tylko spacja!):" << endl;
		cin >> x >> y;
		
		Point punkt(x, y);
		Square square(punkt, side, pointchar);
		square.printCoordinates();
	}
	
	
	system("PAUSE");
	return 0;
}
