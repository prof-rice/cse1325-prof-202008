/**
 * @author      George F. Rice <george.rice@uta.edu>
 * @version     1.0
 * @since       1.0
 */
public class Complex {
    private double re;
    private double im;
    private static boolean polar;
    
    /**
     * Creates a Complex instance.
     *
     * <p>Use {@link #makePolarComplex(double r, double theta)} to use polar coordinates.
     *
     * @param re       the real component of the Complex number
     * @param im       the imaginary component of the Complex number
     * @since             1.0
     */
     public Complex(double re, double im) {this.re = re; this.im = im; polar = false;}
     
    // NO destructors - Java is "garbage collected", so destruction occurs automatically
    // NO friends, so we use a static "factory" method to create a Complex from polar values
    
    /**
     * Creates a Complex instance.
     *
     * Use {@link #Complex(double re, double im)} to use rectangular coordinates.
     *
     * @param r        the magnitude component of the Complex number
     * @param theta    the angle component of the Complex number
     * @since             1.0
     */
    public static Complex makePolarComplex(double r, double theta) {
        Complex c = new Complex(r * Math.cos(theta), r*Math.sin(theta));
        polar = true;
        return c;
    }
    
    /**
     * Creates a string representation of this object.
     *
     * Use {@link #setPolar(boolean p)} to specify if this should be in polar or rectangular format.
     */
    @Override
    public String toString() {
        if(polar) {
            double r = Math.sqrt(re*re + im*im);
            double theta = Math.atan(im/re);
            return r + "(cos(" + theta + ")+i*sin(" + theta + "))";
        } else {
            return re + "+" + im + 'i';
        }
    }

    /**
     * setPolar configures toString to use polar format if true, rectangular if false.
     *
     * Check the current setting using {@link #getPolar()}.
     *
     * @see #makePolarComplex(double, double)
     * @see #Complex(double, double)
     */ 
    public static void setPolar(boolean p) {polar = p;}

    /**
     * getPolar returns true if toString is using polar format, false otherwise.
     * Change the format using {@link #setPolar(boolean p)}.
     */ 
    public static boolean getPolar() {return polar;}
    
    /**
     * main runs simple examples for this class
     *
     */ 
    public static void main(String[] args) {
        Complex c1 = new Complex(3, 4);
        System.out.print(c1 + " or ");
        Complex c2 = Complex.makePolarComplex(10.0, 0.6435);
        System.out.print(c1 + "\n" + c2 + " or ");
        Complex.setPolar(false);
        System.out.println(c2);
    }
}
