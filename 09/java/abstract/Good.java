// NOTE: This class will NOT compile
//       The point is for you to understand why!

abstract class A {
    public abstract void m();
}

class B extends A {
    public void x() {System.out.println("x of B");}
    @Override
    public void m() {System.out.println("m of B");}
}

public class Good {
    public static void main(String[] args) {
        B b = new B();
        b.x();
    }
}
