#include <stdlib.h>
#include <stdio.h>
#include <sys/socket.h>
#include <sys/un.h>
#include <string.h>
#include <unistd.h>
/* Definition for AF_INET family */
#include <netinet/in.h>
#include <arpa/inet.h>

#define BUF_SIZE 20

char send_msg[BUF_SIZE] = "Hello !!";
char buf[BUF_SIZE] = {0};

int main()
{
	int sockfd;
	struct sockaddr_in server_addr;
	ssize_t ret = 0;
	socklen_t server_addr_len = sizeof(server_addr);

	sockfd = socket(AF_INET, SOCK_STREAM, 0);
	if (sockfd == -1)
		printf("client: Failed to open socket descriptor\n");

	memset(&server_addr, 0, sizeof(server_addr));

	server_addr.sin_family = AF_INET;
	server_addr.sin_addr.s_addr = inet_addr("0.0.0.0");
	server_addr.sin_port = htons(5000);

	if (connect(sockfd, (struct sockaddr *) &server_addr, server_addr_len) == -1) {
		printf("client: Failed to bind to socket descriptor\n");
		close(sockfd);
	}
	printf("client: successfully connected to the server socket\n");

/*	ret = write(sockfd, "Hello", 6);
	if (ret != 6) {
		printf("Write error: %d\n", (int) ret);
	}*/

	ret = sendto(sockfd, send_msg, BUF_SIZE, 0,
			(struct sockaddr *) &server_addr, server_addr_len);
	if (ret != BUF_SIZE) {
		printf("client: Failed to send to server: %d\n", (int) ret);
	}

	ret = recvfrom(sockfd, buf, BUF_SIZE, 0,
		(struct sockaddr *)&server_addr, &server_addr_len);
	if (ret == -1) {
		printf("client: Failed to receive message from server\n");
	}

	printf("client: Reply from server: %s\n", buf);

	
	return 0;
}
