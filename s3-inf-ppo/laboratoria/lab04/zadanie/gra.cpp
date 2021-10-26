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
	private:
		int IloscScian;
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
			return this->roll();
		}
		int GetterSides()
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

class Board
{
	private:
		int maxPosition;
		int turnsCounter;
		int MaxTurnsCounter = 0;
		vector<Pawn> pawns;
		Dice dice;
		Pawn winner;
		
	public:
		Board()
		{
			this->turnsCounter = 0;
		}
		
		Board(int maxPosition, int MaxTurnsCounter, vector<Pawn> pawns, int IloscScian)
		{
			this->maxPosition = maxPosition;
			this->MaxTurnsCounter = MaxTurnsCounter;
			this->pawns = pawns;
			this->dice = Dice(IloscScian);
		}
		
		Board(int maxPosition, vector<Pawn> pawns, int IloscScian)
		{
			this->maxPosition = maxPosition;
			this->pawns = pawns;
			this->dice = Dice(IloscScian);
		}
		
		string GetterWinnerName()
		{
			return winner.GetterPawnName();
		}
		
		void performTurn()
		{
			this->turnsCounter++;
			
			ostringstream ss;
			ss << "Ruch " << this->turnsCounter;
			Log::info();
			Log::info(ss.str());
			
			for(int i = 0; i < pawns.size(); i++) {
				int rollResult = dice.GetterRoll();
				
				Pawn &pawn = this->pawns[i];
				int PawnPozycja = pawn.GetterPawnPosition();
				
				if(rollResult == dice.GetterSides() && (PawnPozycja % 7 == 0))
				{
					cout << "\nWyrzucono najwyzszy wynik rzutu kostki." << endl;
					cout << "Pionek ma pozycje " << PawnPozycja << " i jest podzielna przez 7." << endl;
					cout << "Dodatkowy rzut kostka dla " << pawn.GetterPawnName() << "!\n" << endl;
					i--;
				}
				
				PawnPozycja += rollResult;
				pawn.SetterPosition(PawnPozycja);
				
				ostringstream ss;
				ss << pawn.GetterPawnName() << " nowa pozycja: " << pawn.GetterPawnPosition();
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
			
			if(nazwa.length() > 30 || nazwa.length() < 3)
			{
				decyzja = false;
				
				cout << "Nazwa nie moze byc za krotka lub za dluga!" << endl;
				cout << "Nazwa powinnna zawierac od 3 do 25 znakow!" << endl;
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

int main() {
	srand(time(NULL));
	
	string nazwa;
	float TestIlosci;
	int liczba;
	bool decyzja = false;
	string Odpowiedz;
	vector<Pawn> pionki;
	
	Board board = Board();
	
	cout << "Ile graczy ma wziac udzial w tej grze? minimalnie od 3 do maksymalnie 10" << endl;
	
	Sprawdz sprawdz = Sprawdz();
	
	do
	{
		cin >> TestIlosci;
		
		decyzja = sprawdz.SprawdzajLiczbeGraczy(TestIlosci);
	} while(decyzja == false);
	
	cin.clear();
    cin.ignore(10000,'\n');
	
	int IloscGraczy = TestIlosci;
	decyzja = false;
	
	for(int i = 0; i < IloscGraczy; i++)
	{
		cout << "Nazwa dla gracza nr " << i+1 << ":" << endl;
		
		do
		{
			getline(cin, nazwa);
			decyzja = sprawdz.SprawdzajNazweGracza(nazwa, i);
		} while(decyzja == false);
		
		pionki.push_back(Pawn(nazwa));
	}
	
	decyzja = false;
	
	cout << "Ile scian musi miec kostka?" << endl;
	
	do
	{
		cin >> TestIlosci;
		decyzja = sprawdz.SprawdzajKostke(TestIlosci);
	} while(decyzja == false);
	
	int IloscScian = TestIlosci;
	decyzja = false;
	
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
		board = Board(maxPosition, pionki, IloscScian);
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
		
		board = Board(maxPosition, MaxTurnsCounter, pionki, IloscScian);
	}
	
	try {
		while(true) {
			board.performTurn();
		}
	} catch(const char* exception) {
		Log::info();
		Log::info(board.GetterWinnerName() + " wygral");
	}
	
	return 0;
}
