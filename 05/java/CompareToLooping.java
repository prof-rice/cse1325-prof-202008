class CompareToLooping implements Comparable<CompareToLooping> {
  private int data;
  
  CompareToLooping(int data) {this.data = data;}
  
  @Override
  public String toString() {return Integer.toString(data);}
  
  @Override
  public int compareTo(CompareToLooping rhs) {return Integer.compare(data, rhs.data);}

  public void inc() {++this.data;}
  
  public static void main(String[] args) {
      
      CompareToLooping start = new CompareToLooping(0);
      CompareToLooping max = new CompareToLooping(5);
      for(CompareToLooping i = start; i.compareTo(max) < 0; i.inc()) 
          System.out.print(i + " ");
      System.out.println();
  }
}
