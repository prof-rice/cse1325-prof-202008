import org.gnome.gtk.*;

public class Hello {
    public static void main(String[] args) {
        Gtk.init(args);  // Initialize Gtk+
        MessageDialog dialog = new MessageDialog(null, false, MessageType.INFO, ButtonsType.OK_CANCEL, "Hello, world!");
        dialog.run();
    }
}
        
