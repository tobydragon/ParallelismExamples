import java.io.IOException;
import java.net.ServerSocket;
import java.net.Socket;
import java.net.SocketTimeoutException;
import java.util.ArrayList;

public class Server {

    public static void main(String[] args) throws Exception {

        // connectionList will hold a list of different connections on the port
        //that way we can have multiple clients on the server (like a chat room
        ArrayList<ClientConnection> connectionList = new ArrayList<ClientConnection>();
        int port = 5000;

        //create the server socket
        ServerSocket serverSocket = new ServerSocket(port);
        //this will allow us to continue if a client doesn't try to connect
        //within 1 second.
        serverSocket.setSoTimeout(1000);
        System.out.println("Server started");

        //keep track of which client's turn it is to speak
        int curCon = 0;

        while (true) {

            //check to see if there is a client trying to connect
            boolean timeout = false;
            while (!timeout) {
                try {
                    //accept a connection
                    Socket newSocket = serverSocket.accept();
                    //create the ClientConnection object to do the work
                    ClientConnection clientObj = new ClientConnection(newSocket);
                    connectionList.add(clientObj);
                    clientObj.sendTo("Connection established");
                    timeout = true;
                } catch (SocketTimeoutException e) {
                    //no attempt to connect, so continue
                    break;
                }
            }


            if (connectionList.size() > 0) {
                if (curCon == connectionList.size())
                    curCon = 0;

                String input = connectionList.get(curCon).readFrom();
                System.out.println("Read " + input + " from client " + curCon);
                for (int ndx = 0; ndx < connectionList.size(); ndx++) {
                    if (curCon != ndx) {
                        ClientConnection currentClient2 = connectionList.get(ndx);
                        currentClient2.sendTo(input);
                        System.out.println("Sent " + input + " to client " + ndx);
                    }//if
                }//for
                curCon++;
            }//size
        }//while true
    }//main
}//class
