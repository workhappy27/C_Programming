Socket Programming in detail:-

More details on sockadd types https://illumos.org/man/3socket/sockaddr_ll
Port number definitions: http://www.networksorcery.com/enp/protocol/ip/ports05000.htm

Socket (Create an endpoint for communication):-
---------------------------------------------
	int ioctl_sock	= socket(AF_PACKET, int socket_type, int protocol);
where, 
	AF_UNIX - Local communication (AF_LOCAL)
	PF_INET - Protocol Family of sockets. Also equal to AF_INET and the only
			difference in compiler.
	AF_INET   -  IPv4 Internet protocols.
	AF_PACKET -  Low-level packet interface

socket_type can be,
	SOCK_DGRAM - datagram-based protocol (UDP).
	SOCK_STREAM - connection-based protocol (TCP).
	SOCK_RAW - Provides raw network protocol access, includes link-level
			header.

and protocol can be,
	 ETH_P_ALL - All protocols are received in socket before they are passed
			to the protocols implemented in kernel.

Link-level header information is available in socket_ll structure.
           struct sockaddr_ll {
               unsigned short sll_family;   /* Always AF_PACKET */
               unsigned short sll_protocol; /* Physical-layer protocol */
               int            sll_ifindex;  /* Interface number */
               unsigned short sll_hatype;   /* ARP hardware type */
               unsigned char  sll_pkttype;  /* Packet type */
               unsigned char  sll_halen;    /* Length of address */
               unsigned char  sll_addr[8];  /* Physical-layer address */
           };

The Internet socket address structure sockaddr_in is defined in <netinet/in.h>
        struct sockaddr_in {
                        short                     sin_family;                   /* AF_INET */
                        u_short                 sin_port;                       /* 16-bit port number */
                        struct in_addr       sin_addr;
                        char                       sin_zero[8];                  /* unused */
           };

The Unix domain socket address structure sockaddr_un is defined in <sys/un.h>.
          struct sockaddr_un{
                        short                    sun_family;                /*AF_UNIX*/
                        char                     sun_PATH[108];        /*path name */
           };

 
Bind (Bind a name to the socket):-
--------------------------------
       int bind(int sockfd, const struct sockaddr *addr, socklen_t addrlen);

bind() assigns the address specified by addr to the socket file descriptor
 'scokfd'

where,
	sockfd - socket file descriptor.
	sockaddr - struct sockaddr {
   	               sa_family_t sa_family;
        	       char        sa_data[14];
	           } 
       By default, all packets of the specified protocol type are passed to
       a packet socket.  To get packets only from a specific interface use
       bind(2) specifying an address in a struct sockaddr_ll to bind the
       packet socket to an interface.  Fields used for binding are
       sll_family (should be AF_PACKET), sll_protocol, and sll_ifindex.


bind() assigns the address specified by addr to the socket referred to by the
file descriptor sockfd.

Listen(listen for connections on a socket):-
-----------------------------------------

	int listen(int sockfd, int backlog);
where,
	sockfd - socket file descriptor
	backlog - maximum length to which the queue of pending connections for
			sockfd may grow.

To accept connections, the following steps are performed:

           1.  A socket is created with socket(2).

           2.  The socket is bound to a local address using bind(2), so that
               other sockets may be connect(2)ed to it.

           3.  A willingness to accept incoming connections and a queue
               limit for incoming connections are specified with listen().

           4.  Connections are accepted with accept(2).



Connect( initiate a connection on a socket):-
-------------------------------------------

	int connect(int sockfd, const struct sockaddr *addr, socklen_t addrlen);
where,
	sockfd - socket file descriptor
	addr - Attempts to connect to a sockfd that is bound to the address
		specified by addr


Accept( accept a connection on a socket):-
----------------------------------------

	int accept(int sockfd, struct sockaddr *addr, socklen_t *addrlen,
			int flags);

accept() "system call" is used with connection-based socket types (TCP).


To handle the events received on sockets():-
-----------------------------------------
/**
 * eloop_register_read_sock - Register handler for read events
 * @sock: File descriptor number for the socket
 * @handler: Callback function to be called when data is available for reading
 * @eloop_data: Callback context data (eloop_ctx)
 * @user_data: Callback context data (sock_ctx)
 * Returns: 0 on success, -1 on failure
 *
 * Register a read socket notifier for the given file descriptor. The handler
 * function will be called whenever data is available for reading from the
 * socket. The handler function is responsible for clearing the event after
 * having processed it in order to avoid eloop from calling the handler again
 * for the same event.
 */
int eloop_register_read_sock(int sock, eloop_sock_handler handler,
			     void *eloop_data, void *user_data);
