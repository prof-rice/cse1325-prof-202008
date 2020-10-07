import javax.swing.*;
import java.awt.event.*; 
 
public class HelloDialog {   
    public static void main(String[] args) {
      //JFrame frame = new JFrame();
      //frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
      
      JOptionPane.showMessageDialog(null, "Hello, Java!");
/*
      //Custom button text
      Object[] options = {"Yes, please",
                    "No, thanks",
                    "No eggs, no ham!"};
      int n = JOptionPane.showOptionDialog(frame,
          "Would you like some green eggs to go "
          + "with that ham?",
          "A Silly Question",
          JOptionPane.YES_NO_CANCEL_OPTION,
          JOptionPane.QUESTION_MESSAGE,
          null,
          options,
          options[2]);
          
          // Click the X programmatically
          frame.dispatchEvent(new WindowEvent(frame, WindowEvent.WINDOW_CLOSING));
*/
   }
}
