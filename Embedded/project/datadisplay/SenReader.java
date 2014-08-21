import java.util.*;
import net.tinyos.message.*;
import net.tinyos.packet.*;
import net.tinyos.util.*;

public class SenReader implements net.tinyos.message.MessageListener {

  private MoteIF moteIF;

  public static void main(String[] args) throws Exception {
    String source = null;
    //if (args.length == 3 && args[0].equals("-comm")) {
    if (args.length == 0) {
      source = "serial@/dev/ttyUSB1:micaz";
      String className = "SenseMsg";
      try {
        Class c = Class.forName(className);
        Object packet = c.newInstance();
        Message msg = (Message)packet;
        SenReader mr = new SenReader(source);
        mr.addMsgType(msg);
        mr.start();
      } catch (Exception e) {
        System.err.println(e);
      }
    } else {
      usage();
      System.exit(1);
    }
  }

  private static void usage() {
    //System.err.println("usage: SenReader -comm <source> message-class");
    System.err.println("usage: java SenReader");
  }

  private void addMsgType(Message msg) {
    moteIF.registerListener(msg, this);
  }

  public SenReader(String source) throws Exception {
    moteIF = new MoteIF(BuildSource.makePhoenix(source, PrintStreamMessenger.err));
  }

  public void start() {
  }
  
  public void messageReceived(int to, Message message) {
    //long t = System.currentTimeMillis();
    //System.out.print("" + t + ": ");
    System.out.println(message);
  }
  
}
