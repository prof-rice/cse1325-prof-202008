class RectangleAssert {
    private int length;
    private int width;
    
    public RectangleAssert(int length, int width) {
        assert(length >= 0 && width >= 0) : "Bad area";
        this.length = length;
        this.width = width;
    }
    int area() {
        return length*width;
    }
    public static void main(String[] args) {
        RectangleAssert r = new RectangleAssert(-2, 14);
        System.out.println("Area is " + r.area());
    }
}
