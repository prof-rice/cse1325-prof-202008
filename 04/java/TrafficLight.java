public class TrafficLight {
    private boolean operating;
    private Color light;
    
    TrafficLight() {operating = true; light = Color.red;}
    public boolean isOperating() {return operating;}
    public void turnOn() {operating = true;}
    public void turnOff() {operating = false;}
    public Color thisColor() {return light;}
    public Color nextColor() {
        light = ((light == Color.green)  ? Color.yellow : 
                ((light == Color.yellow) ? Color.red    :
                                          Color.green));
        return light;
    }
    @Override
    public String toString() {return light.name();}
    public String operatingToString() {return operating ? "working" : "off";}
}
