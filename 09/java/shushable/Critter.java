import java.util.concurrent.TimeUnit;
import java.util.ArrayList;

abstract class Critter implements Shushable {
    public Critter(int frequency) {this.frequency = frequency; timer = 0; shushed = false;}
    public void count() {if (++timer > frequency) timer = 0;}
    public abstract void speak();
    
    protected int frequency;
    protected int timer;
    
    // Implementing Shushable interface
    private boolean shushed;
    
    public void shush() {shushed = true;}
    public void unshush() {shushed = false;}
    public boolean isShushed() {return shushed;}
    
    // End of Shushable implementation

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
        
        TimeUnit ms = TimeUnit.MILLISECONDS;

        System.out.println("W E L C O M E   T O   T H E   B A R N Y A R D !");
        for (int i=0; i<120; ++i) {
            for (Critter c: critters) { c.count(); c.speak(); }
            if(i%20 == 0) {
                System.out.println("==> Unshushing the barnyard animals! Earplugs in!");                
                for (Critter c: critters) { c.unshush(); }
            } else if ((i+10)%20 == 0) {
                System.out.println("==> Shushing the barnyard animals... zzz...");                
                for (Critter c: critters) { c.shush(); }
            }
            try {ms.sleep(50L);} catch (InterruptedException e) { }
        }
    }
}
