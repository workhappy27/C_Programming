#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include <sys/socket.h>
#include <sys/un.h>
#include <sys/types.h>
/* Definition for AF_INET family */
#include <netinet/in.h>
#include <arpa/inet.h>


#define PENDING_ALLOWED 50
#define BUF_SIZE 100
#define _DFT_BUF_SIZE 25

char buf[BUF_SIZE] = {0};
char default_message[] = "Got your message !!";

int main()
{
	int sockfd, client_sockfd;
	struct sockaddr_in server_addr, client_addr;
	ssize_t ret;
	socklen_t client_addr_len = sizeof(client_addr);
	socklen_t server_addr_len = sizeof(client_addr);

	sockfd = socket(AF_INET, SOCK_DGRAM, 0);
	if (sockfd == -1)
		printf("server: Failed to open socket descriptor\n");

	memset(&server_addr, 0, sizeof(server_addr));

	server_addr.sin_family = AF_INET;
//	server_addr.sin_addr.s_addr = htonl(INADDR_ANY);
//	server_addr.sin_addr.s_addr = inet_addr("127.0.0.1");
	server_addr.sin_port = htons(5000);

	if (bind(sockfd, (struct sockaddr *) &server_addr, server_addr_len) == -1) {
		printf("server: Failed to bind to socket descriptor\n");
	}

	while(1) {

/*		ret = read(client_sockfd, buf, BUF_SIZE);
		if (ret < 0) {
			printf("server: Failed to read the msg: %d\n", (int)ret);
			continue;
		}*/

		ret = recvfrom(sockfd, buf, BUF_SIZE, 0, 
				(struct sockaddr *)&client_addr, &client_addr_len);
		if (ret == -1) {
			continue;
		}

		printf("server: Request from client is: %s\n", buf);

		ret = sendto(sockfd, default_message, _DFT_BUF_SIZE, 0,
			(struct sockaddr *)&client_addr, client_addr_len);
		if (ret != _DFT_BUF_SIZE)
			printf("server: Error sending message: %d\n", (int)ret);

		sleep(1);

	}
	return 0;
}
