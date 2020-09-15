class RectangleException {
    private int length;
    private int width;
    
    public RectangleException(int length, int width) {
        if(length < 0 || width < 0) throw new IllegalArgumentException("Bad area");
        this.length = length;
        this.width = width;
    }
    int area() {
        return length*width;
    }
    public static void main(String[] args) {
        RectangleException r;
        try {
            r = new RectangleException(-2, 14);
            System.out.println("Area is " + r.area());
        } catch (IllegalArgumentException e) {
            System.err.println("Failed to create Rectangle: " + e);
        }
    }
}
