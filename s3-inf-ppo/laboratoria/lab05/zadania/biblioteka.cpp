#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <vector>
#include <string>

using namespace std;

class Book {
	protected:
		string title;
	
	public:			
		Book(string title) {
			this->title = title;
		}
		
		string getTitle() {
			return title;
		}
		
		virtual string getType() const = 0;
};

class Novel : public Book {

	public:	
		Novel(string title) : Book(title) {}
		
		string getType() const {
			return "powieœæ";
		}
	
};

class ComicBook : public Book {
	
	public:
		ComicBook(string title) : Book(title) {}
		
		string getType() const {
			return "komiks";
		}
		
};

class CourseBook : public Book {
	
	public:
		CourseBook(string title) : Book(title) {}
		
		string getType() const {
			return "podrêcznik";
		}
};

class Library {
	public:
		vector<Novel> novels;
		vector<ComicBook> comicbooks;
		vector<CourseBook> coursebooks;
		
		Library* addNovel(Novel novel) {
			this->novels.push_back(novel);
			return this;
		}
		
		Library* addComicBook(ComicBook comicbook) {
			this->comicbooks.push_back(comicbook);
			return this;
		}
		
		Library* addCourseBook(CourseBook coursebook) {
			this->coursebooks.push_back(coursebook);
			return this;
		}
		
		vector<Novel> getNovels() {
			return novels;
		}
		
		vector<ComicBook> getComicBooks() {
			return comicbooks;
		}
		
		vector<CourseBook> getCourseBooks() {
			return coursebooks;
		}
};

int main() {
	setlocale(LC_ALL, "");
	
	Library library = Library();
	library.addNovel(Novel("Wektor pierwszy"));
	library.addNovel(Novel("Gwiazda po gwieŸdzie"));
	library.addNovel(Novel("Jednocz¹ca Moc"));
	library.addComicBook(ComicBook("Batman"));
	library.addComicBook(ComicBook("Ironman"));
	library.addComicBook(ComicBook("Superman"));
	library.addCourseBook(CourseBook("Symfonia C++ standard"));
	library.addCourseBook(CourseBook("Java podstawy"));
	library.addCourseBook(CourseBook("Anatomia PC"));
	
	for(int i = 0; i < library.novels.size(); i++) {
		Novel novel = library.getNovels().at(i);
		cout << novel.getType() << " || " << novel.getTitle() << endl;
	}
	
	for(int i = 0; i< library.comicbooks.size(); i++) {
		ComicBook comicbook = library.getComicBooks().at(i);
		cout << comicbook.getType() << " || " << comicbook.getTitle() << endl;
	}
	
	for(int i = 0; i< library.coursebooks.size(); i++) {
		CourseBook coursebook = library.getCourseBooks().at(i);
		cout << coursebook.getType() << " || " << coursebook.getTitle() << endl;
	}
	
	return 0;
}

