import java.util.Scanner;

public class TSharkData {

    private String frameNumber;
    private String frameTime;
    private String protocol;
    private String protocolID;
    private String srcIP;
    private String srcPort;
    private String dstIP;
    private String dstPort;

    public TSharkData(String data){
    // Your code goes here
        Scanner scan = new Scanner(data);
        scan.useDelimiter(",");
        frameNumber = scan.next().replace("\"", "");
        frameTime = scan.next().replace("\"", "");
        protocol = scan.next().replace("\"", "");
        protocolID = scan.next().replace("\"", "");
        srcIP = scan.next().replace("\"", "");
        srcPort = scan.next().replace("\"", "");
        dstIP = scan.next().replace("\"", "");
        dstPort = scan.next().replace("\"", "");

    }

    public String getFrameNumber() {
        return frameNumber;
    }

    public String getFrameTime() {
        return frameTime;
    }

    public String getProtocol() {
        return protocol;
    }

    public String getProtocolID() {
        return protocolID;
    }

    public String getSrcIP() {
        return srcIP;
    }

    public String getSrcPort() {
        return srcPort;
    }

    public String getDstIP() {
        return dstIP;
    }

    public String getDstPort() {
        return dstPort;
    }

}
