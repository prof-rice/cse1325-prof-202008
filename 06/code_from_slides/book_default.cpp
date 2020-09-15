#include <iostream>

class Book {
  public:
    void set_book(std::string title, int pages) {_title=title; _pages=pages;}
    friend std::ostream& operator<<(std::ostream& ost, const Book& book) {
        ost << book._title << " (" << book._pages << " pages)";
        return ost;
    }
  private:
    std::string _title;
    int _pages;
};

int main() {
    Book book;
    std::cout << book << std::endl;
}
