import javax.swing.*;
import java.awt.event.*;

public class HelloButtonActive extends JFrame implements ActionListener {
    public HelloButtonActive() {
        super();  // Initialize JFrame
        setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE); // Close on X click
        
        JButton button = new JButton("Hello, Java!");
        button.setBounds(20,20,120, 30);  // position & size
        button.addActionListener(this);   // call actionPerformed on click
        add(button);                      // Add the button to the JFrame
		
        setSize(160,110); // Set the JFrame size
        setLayout(null);  // setBounds avoids layout manager need
        setVisible(true); // Make the JFrame visible
    }

    // Define an action listener that prints to the console
    @Override
    public void actionPerformed(ActionEvent event) {
        String str = event.getActionCommand();  // Button text
        System.out.println(str);
    }
    
    public static void main(String[] args) {
       HelloButtonActive app = new HelloButtonActive();
       app.setVisible(true);
    }
}
