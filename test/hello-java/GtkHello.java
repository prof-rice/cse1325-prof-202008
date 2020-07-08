import org.gnome.gdk.Event;
import org.gnome.gtk.Gtk;
import org.gnome.gtk.Widget;
import org.gnome.gtk.Window;
import org.gnome.gtk.WindowPosition;
/**
 * Java-Gnome GTK Example
 * ispired official site java-gnome.sourceforge.net
 */
public class GtkHello extends Window {
    public GtkHello() {
        setTitle("Example");
        connect((DeleteEvent)(source, event) -> {
            Gtk.mainQuit();
            return false;
        });
        setDefaultSize(250, 150);
        setPosition(WindowPosition.CENTER);
        show();
    }

    public static void main(String[] args) {
        Gtk.init(args);
        new GtkHello(); 
        Gtk.main(); 
    } 
}
