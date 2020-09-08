public class Complex {
    private double re;
    private double im;
    private static boolean polar;
    
    Complex(double re, double im) {this.re = re; this.im = im; polar = false;}
    // NO destructors - Java is "garbage collected", so destruction occurs automatically
    // NO friends, so we use a static "factory" method to create a Complex from polar values
    static Complex makePolarComplex(double r, double theta) {
        Complex c = new Complex(r * Math.cos(theta), r*Math.sin(theta));
        polar = true;
        return c;
    }
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
    static void set_polar(boolean p) {polar = p;}
    static boolean get_polar() {return polar;} 
    public static void main(String[] args) {
        Complex c1 = new Complex(3, 4);
        System.out.print(c1 + " or ");
        Complex c2 = Complex.makePolarComplex(10.0, 0.6435);
        System.out.print(c1 + "\n" + c2 + " or ");
        Complex.set_polar(false);
        System.out.println(c2);
    }
}
