class Rectangle {
    private int length;
    private int width;
    
    public Rectangle(int length, int width) {
        if(length < 0 || width < 0) {
            System.err.println("Bad area");
            System.exit(-1);
        }
        this.length = length;
        this.width = width;
    }
    int area() {
        return length*width;
    }
    public static void main(String[] args) {
        Rectangle r = new Rectangle(-2, 14);
        System.out.println("Area is " + r.area());
    }
}
