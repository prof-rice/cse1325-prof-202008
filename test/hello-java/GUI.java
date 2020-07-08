import javax.swing.*; 

public class GUI extends JFrame {
    JFrame f;  // Frame (window) as an attribute
    GUI() {
        // Add a button to the frame (window)
        JButton b=new JButton("Click me!");
        b.setBounds(130,100,100, 40);  
        add(b);    // Add button to frame
        
        // Configure the frame
        setSize(400,500);  
        setLayout(null);  
        setVisible(true);  
    }  
    public static void main(String[] args) {  
        new GUI();  
    }
}  
