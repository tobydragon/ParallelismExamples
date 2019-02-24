
import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.net.*;
import java.util.Scanner;

public class Client{

    public static void main(String[] args) throws java.io.IOException{

        //to get input from user
        Scanner keyboard = new Scanner(System.in);

        //create a socket and connect to a server.  Using localhost
        System.out.println("Connecting to server");
        Socket myClient = new Socket("127.0.0.1", 5000);

        //create objects to read and write to the socket
        PrintWriter out = new PrintWriter(myClient.getOutputStream(), true);
        BufferedReader in = new BufferedReader(new InputStreamReader(myClient.getInputStream()));

        //get the connection message
        String response = in.readLine();
        System.out.println(response);

        String message=null;
        System.out.println ("Continue to enter messages until you are done");
        while(true){
            message = keyboard.nextLine();
            //send to server
            out.println(message);
            //read message from server and print to console
            response = in.readLine();
            System.out.println(response);
        }//while
    }//main
}//Client
