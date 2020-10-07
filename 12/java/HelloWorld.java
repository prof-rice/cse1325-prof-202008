import javax.swing.*;
import java.awt.event.*;  

public class HelloWorld extends JFrame{
    private JFrame f;

    public HelloWorld() {
        JButton button = new JButton("Hello, Java!");
        button.setBounds(20,20,120, 30);  // position & size
/*
		button.addActionListener(new ActionListener() {
		    public void actionPerformed(ActionEvent e) {
                System.out.println("Ouch!");
            }
        });
*/
        add(button);      // Add the button to the JFrame
		
        setSize(160,110); // Set the JFrame size
        setLayout(null);  // setBounds avoids layout manager need
        setVisible(true); // Make the JFrame visible
    }
    
    public static void main(String[] args) {
        new HelloJava();  // Instance and run the JFrame
    }
}
