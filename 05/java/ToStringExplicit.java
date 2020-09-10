class ToStringExplicit {
  private int data;
  
  ToStringExplicit(int data) {this.data = data;}
  
  public static void main(String[] args) {
      ToStringExplicit test1 = new ToStringExplicit(42);
      ToStringExplicit test2 = new ToStringExplicit(127);
      System.out.println("test = " + test1.toString()
                     + "\nand    " + test2.toString());
  }
}
