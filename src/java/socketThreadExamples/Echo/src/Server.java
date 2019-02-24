import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.net.ServerSocket;
import java.net.Socket;

public class Server {

    public static void main(String[] args) throws IOException {

        //create the server socket
        ServerSocket serverSocket = new ServerSocket(5000);

        //wait for a client to connect
        System.out.println("Waiting for connection request...");
        Socket clientSocket = serverSocket.accept();

        //set up objects for socket i/o
        PrintWriter out = new PrintWriter(clientSocket.getOutputStream(), true);
        BufferedReader in = new BufferedReader(new InputStreamReader(clientSocket.getInputStream()));

        // Initiate conversation with client
        System.out.println("Connection established");
        out.println("Connection established");

        String inputLine = in.readLine();
        while (true){
            System.out.println("Read " + inputLine);
            out.println(inputLine);
            System.out.println("Sent " + inputLine + " to client");
            inputLine = in.readLine();
        }//while
    }//main
}//Server
