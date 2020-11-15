#include <iostream>
#include <cstdlib>
#include <string>
#include <sstream>
#include <vector>

using namespace std;

#define STUDENTS_COUNT 10

string getRandomStudentNumber() {
	ostringstream ss;
	int randomNumber = rand() % 2000 + 38000;
	
	ss << randomNumber;
	
	return ss.str();
}

string getRandomStudentFName(string fnames[]) {
	int randomNumber = rand() % STUDENTS_COUNT;
	return fnames[randomNumber];
}

string getRandomStudentLName(string lnames[]) {
	int randomNumber = rand() % STUDENTS_COUNT;
	return lnames[randomNumber];
}

string getRandomStudentStatus() {
	int randomNumber = rand() % 2;
	string status;
	if (randomNumber == 1) status = "aktywny";
	else status = "nie aktywny";
	return status;
}

int main() {
	string studentsNrI[STUDENTS_COUNT];
	string studentsFn[STUDENTS_COUNT];
	string studentsLn[STUDENTS_COUNT];
	string studentsSt[STUDENTS_COUNT];
	string fnames[STUDENTS_COUNT] =
	{"Janusz", "Agnieszka", "Joanna", "Aleksander", "Jakub", "Tomasz", "Patryk", "Lukasz", "Izabela", "Karolina"};
	string lnames[STUDENTS_COUNT] =
	{"Kowalski", "Nowakowski", "Januszowski", "Legnicki", "Polski", "Warszawski", "Jaki", "Taki",
	"Piotrowski", "Andrzejewski"};
	
	for(int i = 0; i < STUDENTS_COUNT; i++) {
		studentsNrI[i] = getRandomStudentNumber();
		studentsFn[i] = getRandomStudentFName(fnames);
		studentsLn[i] = getRandomStudentLName(lnames);
		studentsSt[i] = getRandomStudentStatus();
	}
	
	int number;
	char character;
	char a = 'a';
	
	for(int i = 0; i < STUDENTS_COUNT; i++) {
		number = studentsFn[i].length();
		character = studentsFn[i].find(number-1);
		if(character == a) {
			number = studentsLn[i].length();
			studentsLn[i].erase(number-1);
			studentsLn[i].append("a");
		}
	}
	
	cout  << "Students group have been filled." << endl << endl;
	
	for(int i = 0; i < STUDENTS_COUNT; i++) {
		cout << studentsNrI[i] << " " << studentsFn[i] << " " << studentsLn[i] << " " << studentsSt[i] << endl;
	}
	
	cout << "Gelczynski (Jakub 40300)" << endl;
	
	return 0;
}
