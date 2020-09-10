class ToStringDefault {
  private int data;
  
  ToStringDefault(int data) {this.data = data;}
  
  public static void main(String[] args) {
      ToStringDefault test1 = new ToStringDefault(42);
      ToStringDefault test2 = new ToStringDefault(127);
      System.out.println("test = " + test1  // NOTE: toString implicitly called!
                     + "\nand    " + test2);
  }
}
