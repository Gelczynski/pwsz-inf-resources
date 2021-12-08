#include <iostream>
#include <string>

#include "Library.h"
#include "Book.h"

using namespace std;

int main() {
	setlocale (LC_ALL, "");
	
	Library library = Library("Biblioteka nr 1");
	library += Book("Wektor pierwszy", "R. A. Salvatore");
	library += Book("Mroczny przyp�yw I: Szturm", "Michael Stackpole");
	library += Book("Mroczny przyp�yw II: Inwazja", "Michael Stackpole");
	library += Book("Agenci chaosu I: Pr�ba bohatera", "James Luceno");
	
	library.print();
	
	return 0;
}
