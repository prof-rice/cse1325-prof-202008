import java.util.concurrent.TimeUnit;
import java.util.ArrayList;

class Critter implements Lockable {
    public Critter(int frequency) {this.frequency = frequency; timer = 0; locked = false;}
    public void speak() {System.out.println("Generic critter sound!");}

    protected int frequency;
    protected int timer;
    
    // Implementing Lockable interface
    private boolean locked;
    
    public void lock() {locked = true;}
    public void unlock() {locked = false;}
    public boolean isLocked() {return locked;}

    public void count() {
        if (isLocked()) throw new RuntimeException("This critter is locked!");
        if (++timer > frequency) timer = 0;
    }
    
    // End of implementation

    public static void main(String[] args) {
        ArrayList<Critter> critters = new ArrayList<> () {{
            add(new Cow(13));
            add(new Dog(11));
            add(new Dog(9));
            add(new Cow(7));
            add(new Chicken(5));
            add(new Dog(3));
            add(new Chicken(2));

        }};
        
        critters.get(0).lock(); // Test lock on a critter
        TimeUnit ms = TimeUnit.MILLISECONDS;

        System.out.println("W E L C O M E   T O   T H E   B A R N Y A R D !");
        for (int i=0; i<120; ++i) {
            for (Critter c: critters) { c.count(); c.speak(); }
            try {ms.sleep(50L);} catch (InterruptedException e) { }
        }
    }
}
