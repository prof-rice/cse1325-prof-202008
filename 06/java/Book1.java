public class Book1 {
    private String title;
    private int pages;
    
    public void setBook(String title, int pages) {this.title = title; this.pages = pages;}
    @Overload
    public String toString() {return title + " (" + pages + " pages)";}
    
    public static void main(String[] args) {
        Book1 book = new Book1();
        System.out.println(book);
    }
}

