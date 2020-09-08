public class Main {
  public static void main(String[] args) {
    TrafficLight tl = new TrafficLight();
    System.out.println("Light starts as " + tl.thisColor());
    for(int i=0; i<24; ++i) 
        System.out.println("  next color is " + tl.nextColor());
  }
}
