class EqualsCustom {
  private int data;
  
  EqualsCustom(int data) {this.data = data;}
  
  @Override
  public String toString() {return Integer.toString(data);}
  
  @Override
  public boolean equals(Object rhs) {
      if(!(rhs instanceof EqualsCustom)) return false;
      return this.data == ((EqualsCustom)rhs).data;
  }
  
  public static void main(String[] args) {
      EqualsCustom test1a = new EqualsCustom(42);
      EqualsCustom test1b = test1a;

      if(test1a == test1b) System.out.println("test1a == test1b");
      if(test1a.equals(test1b)) System.out.println("test1a equals test1b");
      
      EqualsCustom test2  = new EqualsCustom(42);

      if(test1a == test2) System.out.println("test1a == test2");
      if(test1a.equals(test2)) System.out.println("test1a equals test2");
  }
}
