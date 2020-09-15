class NoLogger {
    public static void main(String[] args) {        
        LOG.off();
        LOG.log("ERROR: This should not print!");
        LOG.log("Abort! Abort!");
    }
        
}
