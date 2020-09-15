public class Book3 {
    private String title;
    private int pages;
    private Isbn isbn;
    
    public Book3(String title, int pages, String isbn) {
        this.title = title;
        this.pages = pages;
        this.isbn =  new Isbn(isbn);
    }
    public Book3() {this("Unknown", 0, "??????????");}
    public void updateIsbn(String isbn) {this.isbn.update(isbn);}
    @Override
    public String toString() {return title + " (ISBN " + isbn + ", " + pages + " pages)";}
    
    public static void main(String[] args) {
        Book3 hardcover = new Book3("War and Peace", 1225, "1535299533");
        Book3 paperback = new Book3(hardcover);
        
        System.out.println(hardcover + "\n" + paperback);
    }
}

