import java.util.logging.Logger;
import java.util.logging.Level;
import java.util.logging.ConsoleHandler;

// This LOG implementation supports multile levels as specified by Level
// Levels are OFF, SEVERE, WARNING, INFO, CONFIG, FINE, FINER, FINEST, ALL
// NOTE: The first Level invoked sets the minimum to be reported
// Messages at lesser levels will NOT be logged
class LOG2 {
    private static Logger logger;
    private static ConsoleHandler consoleHandler;
    private static void init() {
        if(logger != null) return;
        logger = Logger.getLogger(LOG.class.getName());
        logger.setUseParentHandlers(false);
        consoleHandler = new ConsoleHandler();
        consoleHandler.setLevel(Level.ALL);
        logger.addHandler(consoleHandler);
        logger.setLevel(Level.INFO);
    }
    
    public static void on() {
        on(Level.INFO);
    }
    public static void on(Level level) {
        init();
        logger.setLevel(level);
    }
    public static void off() {
        init();
        logger.setLevel(Level.OFF);
    }
    
    public static void log(String message) {
        init();
        logger.log(Level.INFO, message);
    }
    public static void log(String message, Level level) {
        init();
        logger.log(level, message);
    }
}
