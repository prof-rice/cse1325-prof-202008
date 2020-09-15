import java.util.logging.Logger;
import java.util.logging.Level;
import java.util.logging.ConsoleHandler;

class LOG {
    private static Logger logger;
    private static ConsoleHandler consoleHandler;
    private static void init() {
        if(logger != null) return;             // Initialize on first call only
        logger = Logger.getGlobal();           // Get singleton global Logger instance
        logger.setUseParentHandlers(false);    // Don't dup messages via root handler
        consoleHandler = new ConsoleHandler(); // Create a handler to send messages to STDERR
        consoleHandler.setLevel(Level.ALL);    // Handler will handle messages at ALL levels
        logger.addHandler(consoleHandler);     // Logger instance will use our consoleHandler
        logger.setLevel(Level.ALL);            // Publish messages at ALL levels
    }
    
    public static void on()  {                 // Future log calls will print to STDERR
        init();
        logger.setLevel(Level.ALL);
    }  
    public static void off() {                 // Future log calls will be ignored
        init(); 
        logger.setLevel(Level.OFF);
    }
    public static void log(String message) {   // Log message to STDERR as INFO
        init();
        logger.log(Level.INFO, message);
    }
}
