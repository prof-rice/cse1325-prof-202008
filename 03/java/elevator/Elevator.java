class Elevator {
    Elevator(int startingFloor)  {currentFloor = startingFloor;}
    Elevator() {this(1);}
    void move(int targetFloor) {
        floorsTraversed += Math.abs(targetFloor - currentFloor);
         currentFloor = targetFloor;
    }
    static int getFloorsTraversed() {return floorsTraversed;}
    
    private static int floorsTraversed;
    private int currentFloor;
    
    public static void main(String[] args) {
        Elevator e = new Elevator();
        e.move(4);
        e.move(2);
        e.move(7);
        e.move(1);
        System.out.println("Elevator traversed " 
                         + e.getFloorsTraversed() + " floors.");
    }
}

