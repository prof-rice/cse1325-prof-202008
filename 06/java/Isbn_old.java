public class Isbn {
    private char[] digits;
    private bool isIsbn13;
    
    public Isbn(String number) {
        int size = number.length();
        if (size < 9 || size == 11 || size > 13)
            throw new IllegalArgumentException();
        digits = number.toCharArray();
        if(size <= 10) {
            int weight = 10;
            int sum = 0;
            for (int i=0; i<size; ++i) {
                if(digits[i] == 'X') sum += weight-- * 10;
                else sum += weight-- * (digits[i]-48);
            }
            if (size == 9) {
                if(11 - (sum % 11)) == 10) digits[9] = 'X';
                else digits[9] = 48 + (11 - (sum % 11));
            }
            if (size == 10 && (sum % 11) != 0)
                throw new IllegalArgumentException();
        } else {
            
        }
                 
         
