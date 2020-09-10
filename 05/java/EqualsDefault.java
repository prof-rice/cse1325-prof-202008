class EqualsDefault {
  private int data;
  
  EqualsDefault(int data) {this.data = data;}
  
  @Override
  public String toString() {return Integer.toString(data);}
  
  public static void main(String[] args) {
      EqualsDefault test1a = new EqualsDefault(42);
      EqualsDefault test1b = test1a;

      if(test1a == test1b) System.out.println("test1a == test1b");
      if(test1a.equals(test1b)) System.out.println("test1a equals test1b");
      
      EqualsDefault test2  = new EqualsDefault(42);

      if(test1a == test2) System.out.println("test1a == test2");
      if(test1a.equals(test2)) System.out.println("test1a equals test2");
  }
}
