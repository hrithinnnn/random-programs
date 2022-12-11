//Simulation of Address Resolution Protocol (ARP) using Socket Programming: Client

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <sys/socket.h>

#include "arp.h"

int main(int argc, char **argv){
     if (argc < 2){
        fprintf(stderr, "Enter port number as second argument!\n");
        exit(EXIT_FAILURE);
    }
	int PORT;
	PORT=atoi(argv[1]);
    int sockfd;
	arp packet, recv_packet;

	printf("\nEnter the IP Address\t: ");
	scanf("%s", packet.src_ip);
	printf("Enter the MAC Address\t: ");
	scanf("%s", packet.src_mac);
	sockfd=socket(AF_INET,SOCK_STREAM,0);
	struct sockaddr_in servaddr;
	
	if(sockfd==-1){
		printf("Socker error");
		exit(0);
	}
	    
	bzero(&servaddr,sizeof(servaddr));
	
	servaddr.sin_family=AF_INET;
	servaddr.sin_addr.s_addr=inet_addr("127.0.0.1");
	servaddr.sin_port=htons(PORT);
	
	connect(sockfd,(struct sockaddr*)&servaddr,sizeof(servaddr));


		printf("Connection succesfull");
	
	recv(sockfd,(void*)&recv_packet,sizeof(recv_packet),0);
	
	printf("Packet received");
	
	if(strcmp(packet.src_ip,recv_packet.dest_ip)==0){
		printf("IP address match");
		packet.mode = ACK;
		strcpy(packet.dest_ip,recv_packet.src_ip);
		strcpy(packet.dest_mac,recv_packet.dest_mac);
		
		send(sockfd,(void*)&packet,sizeof(packet),0);
		
		printf("\nARP Reply Sent: \n");
        printPacket(packet);
        recv(sockfd, (void*)&recv_packet, sizeof(recv_packet), 0);
		printf("\nReceived Packet is: \n");
        printPacket(recv_packet);
	}

	else{
		printf("\nIP Address does not match.\n");
	}
	
	
	
	
	close(sockfd);

	return 0;
}


//Simulation of Address Resolution Protocol (ARP) using Socket Programming: Server

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <sys/socket.h>

#include "arp.h"

int main(int argc, char **argv){

    if (argc < 2){
        fprintf(stderr, "Enter port number as second argument!\n");
        exit(EXIT_FAILURE);
    }

    int PORT = atoi(argv[1]);

	struct sockaddr_in server, client;
	char buffer[1024];
	int client_sockets[10] = {0}, max, fd, sockfd, newfd, activity;
	int k, i, len, count; 
	fd_set newfds;
    
	arp packet, recv_packet;

	packet = createARPPacket(REQ);
	printf("\nDeveloping ARP Request packet\n");
	printPacket(packet);
	printf("\nThe ARP Request packet has been broacasted.\n");
	printf("Waiting for ARP Reply...\n");

    sockfd = socket(AF_INET, SOCK_STREAM, 0);

	if(sockfd < 0){
		perror("Unable to open socket.\n");
        exit(EXIT_FAILURE);
	}

	bzero(&server, sizeof(server));

	server.sin_family = AF_INET;
	server.sin_addr.s_addr = INADDR_ANY;
	server.sin_port = htons(PORT);

	if(bind(sockfd, (struct sockaddr*)&server, sizeof(server)) < 0){
		perror("Bind error occurred.\n");
        exit(EXIT_FAILURE);
	}

	listen(sockfd, 10);

	len = sizeof(client);
	newfd = accept(sockfd, (struct sockaddr*)&client, &len);
	if(newfd < 0){
		perror("Unable to accept the new connection.\n");
                exit(EXIT_FAILURE);
	}

	send(newfd,(void*)&packet, sizeof(packet), 0);		//Broadcast on all established connections

	bzero((void*)&recv_packet, sizeof(recv_packet));
	//Check ARP response
	recv(newfd, (void*)&recv_packet, sizeof(recv_packet), 0);

	if(recv_packet.mode == ACK)
		printf("\nARP Reply received: \n");
        printPacket(recv_packet);
					
        strcpy(packet.dest_mac, recv_packet.src_mac);
        packet.mode = DATA;

	printf("\nSending the packet to: %s\n", packet.dest_mac);

	send(newfd, (void*)&packet, sizeof(packet), 0);
        printf("\nPacket sent: \n");
        printPacket(packet);

    close(sockfd);
	return 0;
}
    