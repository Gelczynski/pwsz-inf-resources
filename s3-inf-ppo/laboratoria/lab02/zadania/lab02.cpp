#include <iostream>
#include <cstdlib>
#include <string>
#include <sstream>
#include <vector>
#include <ctime>

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
	if (randomNumber == true) status = "aktywny";
	else status = "nieaktywny";
	return status;
}

int main() {
	srand(time(0));
	string studentsNrI[STUDENTS_COUNT];
	string studentsFn[STUDENTS_COUNT];
	string studentsLn[STUDENTS_COUNT];
	string studentsSt[STUDENTS_COUNT];
	string fnames[] =
	{"Janusz", "Agnieszka", "Joanna", "Aleksander", "Jakub", "Tomasz", "Patryk", "Lukasz", "Izabela",
	"Karolina", "Piotr", "Marian"};//8 kolejnych i losowanie
	string lnames[] =
	{"Kowalski", "Nowakowski", "Januszowski", "Legnicki", "Polski", "Warszawski", "Jaki", "Taki",
	"Piotrowski", "Andrzejewski", "Chojnowski", "Jaworzynski"}; //8 kolejnych i losowanie
	
	for(int i = 0; i < STUDENTS_COUNT; i++) {
		studentsNrI[i] = getRandomStudentNumber();
		studentsFn[i] = getRandomStudentFName(fnames);
		studentsLn[i] = getRandomStudentLName(lnames);
		studentsSt[i] = getRandomStudentStatus();
	}
	char character;
	
	for(int i = 0; i < STUDENTS_COUNT; i++) {
		character = studentsFn[i][studentsFn[i].size()-1];
		if(character == 'a') {
			studentsLn[i].pop_back();
			studentsLn[i].append("a");
			studentsSt[i].pop_back();
			studentsSt[i].append("a");
		}
	}
	
	cout << "Lista aktywnych studentow:\n" << endl;
	
	for(int i = 0; i < STUDENTS_COUNT; i++)
	{
		if(studentsSt[i] == "aktywny" || studentsSt[i] == "aktywna") {
			cout << studentsLn[i] << " " << studentsFn[i] << " (" << studentsNrI[i] << ")" << endl;
		}
	}
	
	cout << "\nlista nieaktywnych studentow:\n" << endl;
	
	for(int i = 0; i < STUDENTS_COUNT; i++)
	{
		if(studentsSt[i] == "nieaktywny" || studentsSt[i] == "nieaktywna") {
			cout << studentsLn[i] << " " << studentsFn[i] << " (" << studentsNrI[i] << ")" << endl;
		}
	}
	
	return 0;
}
