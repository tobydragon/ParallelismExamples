
import javax.imageio.IIOException;
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.net.*;
import java.util.Scanner;

public class Client{

    public static void main(String[] args) throws UnknownHostException, IOException {

        //create a socket and connect to a server
        Socket myClient = new Socket("localhost", 5000);
        System.out.println("Connected to Server");


        clientReaderThread readerThread = new clientReaderThread(myClient);;
        readerThread.start();

        PrintWriter out = new PrintWriter(myClient.getOutputStream(), true);
        Scanner keyboard = new Scanner(System.in);

        while (true) {
            //to get input from user
            String input = keyboard.nextLine();
            out.println(input);
        }

    }//main
}//Client
