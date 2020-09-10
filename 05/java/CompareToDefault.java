class CompareToDefault implements Comparable<CompareToDefault> {
  private int data;
  
  CompareToDefault(int data) {this.data = data;}
  
  @Override
  public String toString() {return Integer.toString(data);}
  
  @Override
  public int compareTo(CompareToDefault rhs) {return Integer.compare(data, rhs.data);}
  
  public static void main(String[] args) {
      CompareToDefault test1a = new CompareToDefault(42);
      CompareToDefault test1b = test1a;
      System.out.println("test1a.compareTo(test1b) = " + test1a.compareTo(test1b));
      
      CompareToDefault test2  = new CompareToDefault(47);
      System.out.println("test1a.compareTo(test2) = " + test1a.compareTo(test2));
  }
}
