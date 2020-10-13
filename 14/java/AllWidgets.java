import javax.swing.*;
import java.awt.*;
import java.awt.event.*;
import java.lang.Math;

public class AllWidgets extends JFrame {
    private final static int width = 300;
    private final static int height = 110;
    
    private JButton button;
    private JTextField text;
    private JComboBox combo;
    private JToggleButton toggle;
    private JCheckBox check;
    private JRadioButton radio1, radio2;
    private JSpinner spinner;
    private JLabel number;
    private JSlider slider;
    private JProgressBar progress;
    
    public AllWidgets() {
        super("Demo of Swing Widgets");  // Initialize JFrame
        setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE); // Close on X click
        setSize(width,height); // Set the JFrame size
        setLayout(new GridBagLayout());
        GridBagConstraints constraints = new GridBagConstraints(); // Specify cell for widgets

        // /////////////////////////////////////////////////////////
        // Button
        button = new JButton("Click this button!");
        button.addActionListener(
		    (var event) -> JOptionPane.showMessageDialog(this, "Ouch!"));
		constraints.gridy++;                           // Assign button to the next cell
        add(button, constraints);                      // Add the button to the JFrame
		
        // /////////////////////////////////////////////////////////
        // Text Field
        text = new JTextField(20); // parameter is number of chars visible at once (not max length!)
        text.addActionListener(
		    (var event) -> JOptionPane.showMessageDialog(this, text.getText()));
        constraints.gridy++;
        add(text, constraints);

        // /////////////////////////////////////////////////////////
		// Combo Box
		String[] options = {"JComboBox Row 1", "JComboBox Row 2", "JComboBox Row 3"};
		combo = new JComboBox<String>(options); // This is a template (coming soon!)
		combo.addActionListener(
		    (var event) -> JOptionPane.showMessageDialog(this, (String)combo.getSelectedItem()));
		constraints.gridy++;
		add(combo, constraints);
		
        // /////////////////////////////////////////////////////////
		// Toggle Button
		toggle = new JToggleButton("Toggle Button");
		toggle.addActionListener(
		    (var event) -> JOptionPane.showMessageDialog(this, toggle.isSelected() ? "Down" : "Up"));
		/* Or more verbosely,
		toggle.addItemListener(
		    (var event) -> {
		        if(event.getStateChange() == ItemEvent.SELECTED)   JOptionPane.showMessageDialog(this, "SELECTED");		        
		        else if(event.getStateChange() == ItemEvent.DESELECTED) JOptionPane.showMessageDialog(this, "DESELECTED");
		        else JOptionPane.showMessageDialog(this, event.paramString());  // "Impossible" case
		    });
		*/
		constraints.gridy++;
		add(toggle, constraints);

        // /////////////////////////////////////////////////////////
        // Check Box
        check = new JCheckBox("Check Box (enables Slider)");
        check.setSelected(true); // start checked
        check.addActionListener(
            (var event) -> {
                slider.setEnabled(check.isSelected());
                JOptionPane.showMessageDialog(this, check.isSelected() ? "Checked" : "Unchecked");
            });
		constraints.gridy++;
        add(check, constraints);
        
        // /////////////////////////////////////////////////////////
        // Radio Buttons
        ButtonGroup radioGroup = new ButtonGroup();            // Logical grouping - only one button in group may be down at a time
        JPanel radioPanel = new JPanel();                      // Physical grouping - visually group the radio buttons
        radioPanel.setLayout(new BoxLayout(radioPanel, BoxLayout.PAGE_AXIS));
        // radioPanel.setLayout(new FlowLayout());             // Choose one: BoxLayout is vertical, FlowLayout is horizontal
        radioPanel.setBorder(BorderFactory.createTitledBorder("This Border visually groups the JRadioButtons"));
        
        radio1 = new JRadioButton("Radio Button 1");
        radio1.setSelected(true);
        radio1.addActionListener(
            (var event) -> JOptionPane.showMessageDialog(this, "Radio 1"));
        radioGroup.add(radio1);  // Add to logical grouping
        radioPanel.add(radio1);  // Add to physical grouping
        
        radio2 = new JRadioButton("Radio Button 2");
        radio2.addActionListener(
            (var event) -> JOptionPane.showMessageDialog(this, "Radio 2"));
        radioGroup.add(radio2);
        radioPanel.add(radio2);

		constraints.gridy++;
        add(radioPanel, constraints);

        // /////////////////////////////////////////////////////////
        // Spinner
        // JSpinner() is an int spinner starting at 0, with no min or max
        // For better control, provide a model as parameter:
        //   SpinnerNumberModel int or double parameters are initial value, min, max, and step
        //   SpinnerList Model accepts an Object[] or List parameter and spins through its elements
        SpinnerModel range = new SpinnerNumberModel(0, 0, 1000, 1);
        spinner = new JSpinner(range);
        spinner.addChangeListener(
            (var event) -> {
                int val=(int)spinner.getValue();
                // Or, more generally, int val=(int)((JSpinner)event.getSource()).getValue();
                number.setText(Integer.toString(val*val));
            });
		constraints.gridy++;
        add(spinner, constraints);
        
        // /////////////////////////////////////////////////////////
        // Label for Spinner and Slider
        number = new JLabel("0"); // set by JSpinner and JSlider
        constraints.gridy++;
        add(number, constraints);

        // /////////////////////////////////////////////////////////
        // Slider
        // Note the the Java slider lacks the ability to show the value above the thumb
        slider = new JSlider(0, 100);
        slider.setValue(0);
        slider.addChangeListener(
            (var event) -> {
                int val=slider.getValue();
                number.setText(Integer.toString(val*val));
                progress.setValue((int)(Math.sqrt(val)*10.0));
            });
        constraints.gridy++;
        add(slider, constraints);


        // /////////////////////////////////////////////////////////
        // Progress Bar
        progress = new JProgressBar(0, 100);  // in percent (in this case)
        progress.setStringPainted(true); // include a text value inside the bar
        // Since a JProgressBar is output only, we don't (but could) provide a ChangeListener
        constraints.gridy++;
        add(progress, constraints);

		// Display the window
		pack();
        setVisible(true); // Make the JFrame visible
    }

    public static void main(String[] args) {
       AllWidgets app = new AllWidgets();
       app.setVisible(true);
    }
}
