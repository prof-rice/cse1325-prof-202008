import javax.swing.*;
import java.awt.event.*;  

public class HelloWorld2 {   
    public static void main(String[] args) {
      JButton btn = new JButton("Demo Button");
      ActionListener actionListener = new ActionListener() {
         public void actionPerformed(ActionEvent event) {
            String str = event.getActionCommand();
            System.out.println("Clicked = " + str);
         }
      };
      btn.setActionCommand("FirstButton");
      btn.addActionListener(actionListener);
      JOptionPane.showMessageDialog(null, btn);
   }
}
