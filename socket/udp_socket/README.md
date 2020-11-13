<pre>
a. No need to listen on UDP socket and also accept() API is not required, as UDP socket
receive messages on the the protocol selected.

b. No need to provide particular IP address in case of server_in familty of sockets and
only providing the port number is suffice.

</pre>
