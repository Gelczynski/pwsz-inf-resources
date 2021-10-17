#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <vector>
#include <math.h>
#include <string>
#include <sstream>

using namespace std;

class Log {
	public:
		static void info(string message = "")
		{
			cout << message << endl;
		}
};

class Dice {
	private:		
		int roll()
		{
			int result = (rand() % 6) + 1;
			
			ostringstream ss;
			ss << "Dice roll: " << result;
			Log::info(ss.str());
			
			return result;
		}
	public:
		int getter()
		{
			return roll();
		}
};

class Pawn {
	private:
		int position; //settery do zmieniania pozycji podczas gry, getter jesli trzeba
		string name; //getter jesli trzeba
		
	public:
		Pawn() {}
		
		Pawn(string name)
		{
			this->name = name;
			this->position = 0;
			
			Log::info(name + " joined the game.");
		}
};

class Board {
	private:
		static const int maxPosition;//konstruktor, uwzglednic min i max. obowiazkowy, getter jesli trzeba
		int turnsCounter; //getter jesli trzeba
		int MaxTurnsCounter;//konstruktor, zmienna nieobowiazkowa, wystarczy dodac do warunku wygrania
		//getter jesli trzeba
		
	public:
		vector<Pawn> pawns;
		Dice dice;
		Pawn winner;

		Board()
		{
			this->turnsCounter = 0;
		}
		
		Board(int maxPosition, MaxTurnsCounter) //w przypadku wybrania opcjonalnej liczby ruchow
		{
			this->maxPosition = maxPosition;
			this->maxTurnsCounter = MaxTurnsCounter;
		}
		
		Board(int maxPosition) //w przypadku podania jedynie maxPosition
		{
			this->maxPosition = maxPosition;
		}
		
		void performTurn()
		{
			this->turnsCounter++;
			
			ostringstream ss;
			ss << "Turn " << this->turnsCounter;
			Log::info();
			Log::info(ss.str());
			
			for(int i = 0; i < this->pawns.size(); i++) {
				int rollResult = this->dice.roll();
				Pawn &pawn = this->pawns.at(i);
				pawn.position += rollResult;//problem? getter moze?
				
				ostringstream ss;
				ss << pawn.name << " new position: " << pawn.position;
				Log::info(ss.str());
								
				if(pawn.position >= this->maxPosition) {
					this->winner = pawn;
					throw "Winner was called!";
				}
			}
		}
};

int main() {
	srand(time(NULL));
	
	string nazwa;
	
	Board board = Board();
	board.dice = Dice();
	board.pawns.push_back(Pawn("Luke Skywalker"));
	board.pawns.push_back(Pawn("Darth Vader"));
	
	try {
		while(true) {
			board.performTurn();
		}
	} catch(const char* exception) {
		Log::info();
		Log::info(board.winner.name + " won");
	}
	
	return 0;
}
