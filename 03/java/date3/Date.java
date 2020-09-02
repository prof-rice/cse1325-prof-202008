public class Date {
    public Date(int year, Month month, int day) {
        // Java does NOT use initialization lists
        this.year = year;
        this.month = month;
        this.day = day;
        
        // Month is an enum, so known good
        // Throw an "exception" if the day is invalid
        if(1 > day || day > 31) throw new IllegalArgumentException(
                                "Day must be between 1 and 31");
    }

    @Override
    public String toString() {
        return day + " " + month + ", " + year;
    }
    
    private int year;
    private Month month;
    private int day;

    public static void main(String[] args) {
        // For non-primitives, assign a new value with the "new" keyword
        Date birthday = new Date(1950, Month.December, 30);
        System.out.println(birthday);
    }    
}
