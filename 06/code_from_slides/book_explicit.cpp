#include <iostream>

class Book {
  public:
    Book(std::string title, int pages) : _title{title}, _pages{pages} { }
    Book() : Book("Unknown", 0) { }
    friend std::ostream& operator<<(std::ostream& ost, const Book& book) {
        ost << book._title << " (" << book._pages << " pages)";
        return ost;
    }
  private:
    std::string _title;
    int _pages;
};

int main() {
    Book book1;
    Book book2{"War and Peace", 1225};
    std::cout << book1 << '\n' << book2 << std::endl;
}
