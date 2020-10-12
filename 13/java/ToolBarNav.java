import java.awt.*;
import javax.swing.*;

public class ToolBarNav extends JFrame {
    public ToolBarNav(String title) {
        super(title);
        // NOTE: JFrame uses BorderLayout manager by default
        setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        setSize(400, 200);

        JButton left  = new JButton("<");
        JButton up    = new JButton("^");
        JButton right = new JButton(">");

        JPanel panel = new JPanel();
        panel.add(left);
        panel.add(up);
        panel.add(right);
        
        JToolBar toolbar = new JToolBar("Navigation");
        toolbar.add(panel);
        
        add(toolbar, BorderLayout.NORTH);
        
        setVisible(true); 
    }
    public static void main(String[] args) {
        ToolBarNav myApp = new ToolBarNav("Tool Bar Demo");
        myApp.setVisible(true);
    }
}
