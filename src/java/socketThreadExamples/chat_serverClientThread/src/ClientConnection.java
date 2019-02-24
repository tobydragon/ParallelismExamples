import java.io.*;
import java.net.ServerSocket;
import java.net.Socket;
import java.net.SocketTimeoutException;
import java.util.ArrayList;

public class ClientConnection extends Thread {

    private Socket connection;
    ArrayList<ClientConnection> connectionList;
    BufferedReader in;
    PrintWriter out;

    public ClientConnection(ArrayList connections, Socket connectionIn) throws Exception {
        super();
        connection = connectionIn;
        connectionList = connections;
        in = new BufferedReader(new InputStreamReader(connection.getInputStream()));
        out = new PrintWriter(connectionIn.getOutputStream(), true);

    }

    public void run(){
        String input = null;
        while (true) {
            try {
                input = in.readLine();
                System.out.println("server received:" + input);
            } catch (IOException e) {
            }

            for (int ndx = 0; ndx < connectionList.size(); ndx++) {
                ClientConnection currentClient = connectionList.get(ndx);
                if (!currentClient.equals(this)) {
                    currentClient.out.println(input);
                    System.out.println("Sent " + input + " to client " + ndx);
                }
            }//for
        }
    }
}
