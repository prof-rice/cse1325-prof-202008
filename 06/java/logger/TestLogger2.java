import java.util.logging.Level;

class TestLogger2 {
    public static void main(String[] args) {        
        LOG2.log("Testing 1 2 3", Level.INFO);
        LOG2.log("Abort! Abort!", Level.WARNING);
        LOG2.log("Never mind...", Level.FINE);
        LOG2.log("This FINEST msg should not print!", Level.FINEST);
        
        LOG2.off();
        LOG2.log("ERROR: Logging should be off!");
        
        LOG2.on();
        LOG2.log("This SEVERE msg should print", Level.SEVERE);
        LOG2.log("This FINEST msg should NOT print!!!", Level.FINEST);
                
        LOG2.on(Level.FINEST);
        LOG2.log("This CONFIG msg should print", Level.CONFIG);
        LOG2.log("This FINEST msg should print", Level.FINEST);
    }
        
}
