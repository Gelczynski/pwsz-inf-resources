#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <vector>
#include <math.h>
#include <string>
#include <sstream>

using namespace std;

class Log 
{
	public:
		static void info(string message = "")
		{
			cout << message << endl;
		}
};

class Dice
{
	public:
		int IloscScian = 0;//druga zmienna ma przypisana wartosc z wprowadzonej zmiennej
		//ta zmienna jest przyspisywana do ilosc scian w returnie
		// lub przypisac 0 do ilosc scian
	public:
		Dice()
		{
			
		}
		Dice(int IloscScian)
		{
			this->IloscScian = IloscScian;
		}
	private:
		int roll()
		{
			int result = (rand() % this->IloscScian) + 1;
			ostringstream ss;
			ss << "Rzut kostka: " << result;
			Log::info(ss.str());
			
			return result;
		}
	public:
		int GetterRoll()
		{
			return this->IloscScian;
		}
};

class Pawn
{
	private:
		int position;
		string name;
		
	public:
		Pawn() {}
		
		Pawn(string name)
		{
			this->name = name;
			this->position = 0;
			
			Log::info(name + " dolaczyl do gry.");
		}
		
		int GetterPawnPosition()
		{
			return this->position;
		}
		string GetterPawnName()
		{
			return this->name;
		}
		
		void SetterPosition(int SetPawnPosition)
		{
			this->position = SetPawnPosition;
		}
};


class Sprawdz
{
	public:
		
		bool SprawdzajLiczbeGraczy(float TestIlosci)
		{
			int ilosc = TestIlosci;
			bool decyzja = true;
			
			if(ilosc < 3 || ilosc > 10 || TestIlosci > ilosc)
			{
				decyzja = false;
				
				cout << "Liczba nie moze byc wieksza od 10 lub mniejsza od 3!" << endl;
				cout << "Nie moze byc tez liczby z ulamkiem!" << endl;
				cout << "Ile graczy ma wziac udzial w tej grze?" << endl;
			}
			
			return decyzja;
		}
		
		bool SprawdzajNazweGracza(string nazwa, int i)
		{
			bool decyzja = true;
			
			if(nazwa.length() > 14 || nazwa.length() < 3)
			{
				decyzja = false;
				
				cout << "Nazwa nie moze byc za krotka lub za dluga!" << endl;
				cout << "Nazwa powinnna zawierac od 3 do 14 znakow!" << endl;
				cout << "Nazwa dla gracza nr " << i+1 << ":" << endl;
			}
			
			return decyzja;
		}
		
		bool SprawdzajKostke(float TestIlosci)
		{
			bool decyzja = true;
			
			int ilosc = TestIlosci;
						
			if(ilosc <= 3 || ilosc > 20 || TestIlosci > ilosc)
			{
				decyzja = false;
				
				cout << "Kostka nie moze miec mniej niz 4 lub wiecej niz 20 scian!" << endl;
				cout << "Nie moze byc tez liczby z ulamkiem!" << endl;
				cout << "Ile scian musi miec kostka?" << endl;
			}
			
			return decyzja;
		}
		
		bool SprawdzajMaxLiczbyRuchow(float TestIlosci)
		{
			bool decyzja = true;
			
			int MaxTurnsCounter = TestIlosci;
						
			if(MaxTurnsCounter < 10 || TestIlosci > MaxTurnsCounter)
			{
				decyzja = false;
				
				cout << "Maksymalna liczba ruchow nie moze byc mniejsza od 10!" << endl;
				cout << "Nie moze byc tez liczby z ulamkiem!" << endl;
				cout << "Jaka maksymalna liczbe pol ustawic?" << endl;
			}
			
			return decyzja;
		}
		
		bool SprawdzajOdpowiedz(string Odpowiedz)
		{
			bool decyzja = true;
			
			if(Odpowiedz != "tak"  && Odpowiedz != "nie")
			{
				decyzja = false;
				
				cout << "Podano odpowiedz inna niz tak lub nie!" << endl;
				cout << "Odpowiedz musi brzmiec dokladnie: 'nie' lub 'tak'!" << endl;
				cout << "Czy maks liczba ruchow ma zostac ustawiona?" << endl;
			}
			
			return decyzja;
		}
		
		bool SprawdzajMaxPozycje(float TestIlosci)
		{
			bool decyzja = true;
			
			int maxPosition = TestIlosci;
						
			if(maxPosition < 40 || maxPosition > 200 || TestIlosci > maxPosition)
			{
				decyzja = false;
				cout << "Maksymalna liczba pozycji nie moze byc wieksza od 200 i mniejsza od 40!" << endl;
				cout << "Nie moze byc tez liczby z ulamkiem!" << endl;
				cout << "Jaka maksymalna liczbe pol ustawic?" << endl;
			}
			
			return decyzja;
		}
};


class Board
{
	private:
		int maxPosition;
		int turnsCounter;
		int MaxTurnsCounter = 0;
		
	public:
		Pawn pawns[10];
		Dice dice;
		Pawn winner;
		Board()
		{
			this->turnsCounter = 0;
		}
		
		Board(int maxPosition, int MaxTurnsCounter)
		{
			this->maxPosition = maxPosition;
			this->MaxTurnsCounter = MaxTurnsCounter;
		}
		
		Board(int maxPosition)
		{
			this->maxPosition = maxPosition;
		}
		
		void SetterDice(int IloscScian)
		{
			dice.IloscScian = IloscScian;
			cout << "ilosc scian:  " << dice.IloscScian << endl;
		}//jesli sie nie uda, to przypisac na sztywno w tej metodzie
		
		void SetterPawns(int IloscGraczy)
		{
			string nazwa;
			bool decyzja = false;
			Sprawdz sprawdz = Sprawdz();
			cout << IloscGraczy << endl;
			for(int i = 0; i < IloscGraczy; i++)
			{
			cout << "Nazwa dla gracza nr " << i+1 << ":" << endl;
			
			do
			{
				cin >> nazwa;
				decyzja = sprawdz.SprawdzajNazweGracza(nazwa, i);
			} while(decyzja == false);
			
			pawns[i] = Pawn(nazwa);
			}
		}
		
		int GetterRollDice()
		{
			int result = dice.GetterRoll();
			return result;
		}
		
		void performTurn(Pawn pawns[10])
		{
			this->turnsCounter++;
			
			this->pawns[10] = pawns;
			
			ostringstream ss;
			ss << "Ruch " << this->turnsCounter;
			Log::info();
			Log::info(ss.str());
			cout << "ilosc scian  " << dice.IloscScian << endl;
			for(int i = 0; i < 10; i++) {
				int rollResult = GetterRollDice();
				cout << "nazwa pionka " << pawns[i].GetterPawnName() << endl;
				cout << "wynik posrednio z zmiennej po wykonaniu metody getterroll" << rollResult << endl;
				cout << "wynik bezposrednio z metody dice getterroll" << this->dice.GetterRoll() << endl;
				cout << "rozmiar tablicy: " << sizeof(this->pawns) << endl;
				Pawn &pawn = this->pawns[i];
				cout << pawn.GetterPawnName()<< endl;
				pawn = this->pawns[1];
				cout << pawn.GetterPawnName()<< endl;
				pawn = this->pawns[2];
				cout << pawn.GetterPawnName()<< endl;
				pawn = this->pawns[3];
				cout << pawn.GetterPawnName()<< endl;
				int PawnPozycja = pawn.GetterPawnPosition();
				cout << "pozycja pionka z zmiennej po odczytaniu wartosci: " << PawnPozycja << endl;
				PawnPozycja += rollResult;
				cout << "pozycja pionka po dodaniu wyniku rzutu kosztki: " << PawnPozycja << endl;
				pawn.SetterPosition(PawnPozycja);
				cout << "pozycja pionka po zapisaniu wyniku" << endl;
				ostringstream ss;
				ss << pawn.GetterPawnName() << " Nowa pozycja: " << pawn.GetterPawnPosition();
				Log::info(ss.str());
				
				if(pawn.GetterPawnPosition() >= this->maxPosition ||
				(this->turnsCounter >= this->MaxTurnsCounter) && this->MaxTurnsCounter != 0)
				{
					this->winner = pawn;
					throw "Winner was called!";
				}
			}
		}
};



int main() {
	srand(time(NULL));
	
	string nazwa;
	float TestIlosci;
	bool decyzja = false;
	string Odpowiedz;
	
	Board board = Board();
	board.dice = Dice();
	
	cout << "Ile graczy ma wziac udzial w tej grze? minimalnie od 3 do maksymalnie 10" << endl;
	
	Sprawdz sprawdz = Sprawdz();
	
	do
	{
		cin >> TestIlosci;
		decyzja = sprawdz.SprawdzajLiczbeGraczy(TestIlosci);
	} while(decyzja == false);
	
	int IloscGraczy = TestIlosci;
	decyzja = false;
	
	board.SetterPawns(IloscGraczy);
	
	decyzja = false;
	
	cout << "Ile scian musi miec kostka?" << endl;
	
	do
	{
		cin >> TestIlosci;
		decyzja = sprawdz.SprawdzajKostke(TestIlosci);
	} while(decyzja == false);
	
	int IloscScian = TestIlosci;
	decyzja = false;
	
	board.SetterDice(IloscScian);
	
	cout << "Jaka maksymalna liczbe pol ustawic?" << endl;
	
	do
	{
		cin >> TestIlosci;
		decyzja = sprawdz.SprawdzajMaxPozycje(TestIlosci);
	} while(decyzja == false);
	
	int maxPosition = TestIlosci;
	decyzja = false;
	
	cout << "Czy maks liczba ruchow ma zostac ustalona? Jesli tak wpisac tak, a jesli nie wpisac nie." << endl;
		
	do
	{
		cin >> Odpowiedz;
		decyzja = sprawdz.SprawdzajOdpowiedz(Odpowiedz);
	} while(decyzja == false);
	
	decyzja = false;
	
	if(Odpowiedz == "nie")
	{
		board = Board(maxPosition);
	}
	else if(Odpowiedz == "tak")
	{
		cout << "Jaka maksymalna liczbe ruchow ustawic?" << endl;
		
		do
		{
			cin >> TestIlosci;
			decyzja = sprawdz.SprawdzajMaxLiczbyRuchow(TestIlosci);
		} while(decyzja == false);
		
		int MaxTurnsCounter = TestIlosci;
		
		board = Board(maxPosition, MaxTurnsCounter);
	}
	
	try {
		while(true) {
			board.performTurn(board.pawns);
		}
	} catch(const char* exception) {
		Log::info();
		Log::info(board.winner.GetterPawnName() + " wygral");
	}
	
	return 0;
}
