public class Book2 {
    private String title;
    private int pages;
    
    public Book2(String title, int pages) {this.title = title; this.pages = pages;}
    public Book2() {this("Unknown", 0);}
    @Overload
    public String toString() {return title + " (" + pages + " pages)";}
    
    public static void main(String[] args) {
        Book2 book1 = new Book2();
        Book2 book2 = new Book2("War and Peace", 1225);
        System.out.println(book1 + "\n" + book2);
    }
}

