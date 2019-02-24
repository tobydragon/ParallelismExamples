Introducing concurrency:

Step 1:  Introduce sockets and program Echo with the class.

Step 2:  Echo can't act as a "chat" because it only accepts 1 client.  Give them and go over the code for server with no threads. Creates an
               array of clients.
               Now multiple clients can read/write, but the order is important, since the server is "polling" each connection round-robin.  Illustrate by running

Step 3:  Introduce the concept of threads.  Give them and go over the threaded server example.  Now the order is unimportant, since each client 	connection is reading and writing concurrently.  Illustrate.  There is still one problem, however.  The clients must wait for input from the 
                  user keyboard before they send, and then they may read from server.  Illustrate

Step4:  See if they can figure out what needs to be done to client so it can read from keyboard and send to server, as well as read from server                  concurrently. Give them server and client threaded code.  Go over the change.  Illustrate.

NOTE:  To keep the code simple, I have taken some shortcuts, such as not programming clean exit.  The programs will need to be stopped manually.  	Most errors are also not handled.  I think non-blocking sockets would add complexity but not help with concurrancy.