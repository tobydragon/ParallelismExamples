import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.net.Socket;
import java.net.SocketTimeoutException;

public class ClientConnection {

    private Socket connection;
    private PrintWriter out;
    BufferedReader in;

    public ClientConnection(Socket connectionIn) throws Exception {
        connection = connectionIn;
        out = new PrintWriter(this.connection.getOutputStream(), true);
        in = new BufferedReader(new InputStreamReader(connection.getInputStream()));
    }

    public String readFrom() throws Exception {
        String line = in.readLine();
        return line;
    }

    public void sendTo(String message){
        out.println(message);
    }

    public void closeAll() throws Exception{
        in.close();
        out.close();
        connection.close();
    }
}
