import javax.swing.*; // JFrame,JPanel,JTextArea, JButton,
//JOptionPane, JMenuBar, etc.
import java.awt.event.*; // ActionEvent, ActionListener
import java.awt.BorderLayout;
class GUIDemo extends JFrame implements ActionListener {
   public GUIDemo(String title) {
      super(title); // calling JFrame constructor
      setBounds(10,10,600,400);
      setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
      JButton hitButton = new JButton("Hit me");
      hitButton.addActionListener(this);
      JPanel panel = new JPanel();
      panel.add(hitButton);
      add(panel,BorderLayout.CENTER);
   }
   // actionPerformed() required when implementing ActionListener
   public void actionPerformed(ActionEvent ae) {
      String choice = ae.getActionCommand();
      if (choice.equals("Hit me")) {
         JOptionPane.showMessageDialog(this,"clicked on Hit me");
      }
   }
   public static void main(String[] args) {
      GUIDemo myApp = new GUIDemo("GUI Demonstration");
      myApp.setVisible(true);
   }
}
