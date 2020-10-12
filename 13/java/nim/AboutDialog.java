import java.awt.Dimension;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.awt.event.KeyEvent;

import javax.swing.Box;
import javax.swing.BoxLayout;
import javax.swing.JButton;
import javax.swing.JDialog;
import javax.swing.JFrame;
import javax.swing.JLabel;
import javax.swing.JMenu;
import javax.swing.JMenuBar;
import javax.swing.JMenuItem;

class AboutDialog extends JDialog {
  public AboutDialog() {
    setTitle("About");
    setLayout(new BoxLayout(getContentPane(), BoxLayout.Y_AXIS));

    add(Box.createRigidArea(new Dimension(0, 10)));

    JLabel name = new JLabel("Notes");
    name.setAlignmentX(0.5f);
    add(name);

    add(Box.createRigidArea(new Dimension(0, 100)));

    JButton close = new JButton("Close");
    close.addActionListener(new ActionListener() {
      public void actionPerformed(ActionEvent event) {
        dispose();
      }
    });

    close.setAlignmentX(0.5f);
    add(close);
    setModalityType(ModalityType.APPLICATION_MODAL);
    setDefaultCloseOperation(DISPOSE_ON_CLOSE);
    setSize(300, 200);
  }

  public static void main(String[] args) {
    JMenuBar menubar = new JMenuBar();

    JMenu file = new JMenu("File");
    file.setMnemonic(KeyEvent.VK_F);

    JMenu help = new JMenu("Help");
    help.setMnemonic(KeyEvent.VK_H);

    JMenuItem about = new JMenuItem("About");
    help.add(about);

    about.addActionListener(new ActionListener() {
      public void actionPerformed(ActionEvent event) {
        AboutDialog ad = new AboutDialog();
        ad.setVisible(true);
      }
    });

    menubar.add(file);
    menubar.add(help);
    JFrame f = new JFrame();
    f.setJMenuBar(menubar);

    f.setSize(300, 200);
    f.setLocationRelativeTo(null);
    f.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
    f.setVisible(true);
  }
}


