import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.net.Socket;

public class clientReaderThread extends Thread {

    Socket sock;
    BufferedReader in;

    public clientReaderThread(Socket inSock)throws IOException {
        sock = inSock;
        in = new BufferedReader(new InputStreamReader(sock.getInputStream()));
    }

    public void run() {
        while (true) {
            try {
                String fromServer = in.readLine();
                System.out.println(fromServer);
            } catch (IOException e) {
            }
        }
    }
}
