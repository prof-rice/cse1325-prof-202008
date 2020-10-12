import java.awt.*;
import javax.swing.*;

public class BorderLayoutDemo2 extends JFrame {
    public BorderLayoutDemo2(String title) {
        super(title); // calling JFrame constructor
        // NOTE: JFrame uses BorderLayout manager by default
        setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        setSize(400, 200);
        
        // Create and configure 5 labels as content
        JLabel northLabel = new JLabel("Top - North", JLabel.CENTER);
        JLabel southLabel = new JLabel("Bottom - South", JLabel.CENTER);
        JLabel eastLabel = new JLabel("Right - East", JLabel.CENTER);
        JLabel westLabel = new JLabel("Left - West", JLabel.CENTER);
        JLabel centerLabel = new JLabel("Center (everything else)", JLabel.CENTER);
        
        northLabel.setOpaque(true);
        northLabel.setBackground(Color.GREEN);
        southLabel.setOpaque(true);
        southLabel.setBackground(Color.GREEN);
        eastLabel.setOpaque(true);
        eastLabel.setBackground(Color.RED);
        westLabel.setOpaque(true);
        westLabel.setBackground(Color.RED);
        centerLabel.setOpaque(true);
        centerLabel.setBackground(Color.YELLOW);

        // The second parameter specifies to which region
        //     of the BorderLayout the widget is to be added
        add(northLabel, BorderLayout.NORTH);
        add(southLabel, BorderLayout.SOUTH);
        add(eastLabel,  BorderLayout.EAST);
        add(westLabel,  BorderLayout.WEST); 
        add(centerLabel, BorderLayout.CENTER);
    } 
    public static void main( String[] args ) {
        BorderLayoutDemo2 myApp = new BorderLayoutDemo2("BorderLayout Demo");
        myApp.setVisible(true);
    }
}
