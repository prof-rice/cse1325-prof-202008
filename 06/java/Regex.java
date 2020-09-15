import java.util.Scanner;
import java.util.NoSuchElementException;

class Regex {
    public static void main(String[] args) {
        String pattern = "-?\\d+";
        System.out.println("Enter some integers:");
        
        Scanner in = new Scanner(System.in);
        String line = null;

        while(true) {
            try {
                line = in.next(pattern);
                System.out.println("That's an int!");
            } catch (NoSuchElementException e) {
                if(!in.hasNext()) break;
                System.err.println("***INVALID INPUT*** ");
                line = in.nextLine();
            }
        }
    }
}
        
