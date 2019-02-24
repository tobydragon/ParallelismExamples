import java.io.IOException;
import java.io.PrintWriter;
import java.net.ServerSocket;
import java.net.Socket;
import java.net.SocketTimeoutException;
import java.util.ArrayList;

public class Server {

    public static void main(String[] args) throws Exception {

        ArrayList<ClientConnection> connectionList = new ArrayList<ClientConnection>();
        int port = 5000;

        ServerSocket serverSocket = new ServerSocket(port);
        System.out.println("Server started");

        while (true) {
            Socket newSocket = serverSocket.accept();
            ClientConnection threadedConnection = new ClientConnection(connectionList, newSocket);
            threadedConnection.start();
            connectionList.add(threadedConnection);
            System.out.println("Connection Accepted");
        }

    }//main
}//class
