/*
udp-client.c
Copyright 2020, Moritz Stoetzner, Kay Effenberger
This program is free software; you can redistribute it and/or
modify it under the terms of the GNU General Public License
as published by the Free Software Foundation; either version 3
of the License, or (at your option) any later version.
This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.
You should have received a copy of the GNU General Public License
along with this program; if not, write to the Free Software
Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301, USA.
*/

// Recieve Tpm2.net udp package convert to tpm2.serial package and send to serial
// Port for Tpm2.net is 65506

#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <sys/time.h>
#include <errno.h>

#define portno 65506
#define buflen 1024



int main(int argc, char *argv[]){
    int sockfd, tpm2_net;
    int serverlen;
    int num_led;
    struct sockaddr_in servAddr;
    struct hostent *server;
    char *hostname;
    char buffer[buflen];

    //Check parameters from command line//
    if(argc != 3)
    {
        printf(stderr,"Usage: udp-client [IP_Server] [Number of LED]\n");
        exit(EXIT_FAILURE);
    }
    
    hostname = argv[1];
    num_led = atoi(argv[2]);

   // Creating socket file descriptor
    if ((sockfd = socket(AF_INET, int SOCK_DGRAM, 0)) < 0)
    {
        printf("Failed to open Socket");
        exit(EXIT_FAILURE);
    }
    
    // Get Host By Name 
    server = gethostbyname(hostname);
    if (server == NULL) {
        fprintf(stderr,"ERROR, no such host as %s\n", hostname);
        exit(0);
    }   

    // build the server's Internet address
    bzero((char *) &serveraddr, sizeof(serveraddr));
    serveraddr.sin_family = AF_INET;
    bcopy((char *)server->h_addr, 
	(char *)&serveraddr.sin_addr.s_addr, server->h_length);
    serveraddr.sin_port = htons(portno);

    // Receive Tpm2.net Data

    tpm2_net = recvfrom(sockfd, buffer, strlen(buf), 0, &serveraddr, serverlen);
    
    

}