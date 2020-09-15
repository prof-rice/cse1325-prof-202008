public class Isbn {
    private String number;
    private int size;
    
    public Isbn(String number) {
        size = number.length();
        if(size != 10 && size != 13)
            throw new IllegalArgumentException();
        this.number = number;
    }

    public boolean isIsbn13() {return size == 13;}
    @Override
    public String toString() {return number;}
}
                 
         
