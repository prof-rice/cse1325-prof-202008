class ToStringCustom {
  private int data;
  
  ToStringCustom(int data) {this.data = data;}
  @Override
  public String toString() {return Integer.toString(data);}
  
  public static void main(String[] args) {
      ToStringCustom test1 = new ToStringCustom(42);
      ToStringCustom test2 = new ToStringCustom(127);
      System.out.println("test = " + test1  // NOTE: toString implicitly called!
                     + "\nand    " + test2);
  }
}
