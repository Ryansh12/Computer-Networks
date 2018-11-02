//============================================================================
// Name        : Assign2.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================


#include<iostream>
//include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h> // for read function
#include <netinet/in.h> //for INADDR_ANY
#include <string.h> //for len function
using namespace std;


int main() {



	int server_fd = socket(AF_INET, SOCK_STREAM, 0);

	struct sockaddr_in address;
	address.sin_family = AF_INET;
	address.sin_addr.s_addr = inet_addr("10.10.13.61");
	address.sin_port = htons( 8088 ); //host to network short(MSB first) & port is 8088
	bind(server_fd, (struct sockaddr *)&address, sizeof(address));

	listen(server_fd, 3);
   int addrlen = sizeof(address);
	int new_socket = accept(server_fd, (struct sockaddr *)&address, (socklen_t*)&addrlen);




    char newcodeword[13] = {0};

	read( new_socket , newcodeword, 1024);
	for(int i=1;i<12;i++)
		cout<<newcodeword[i];
	int a =((int)newcodeword[1] + (int)newcodeword[3] + (int)newcodeword[5] + (int)newcodeword[7] + (int)newcodeword[9] + (int)newcodeword[11])%2;
	int b = ((int)newcodeword[2] + (int)newcodeword[3] + (int)newcodeword[6] + (int)newcodeword[7] + (int)newcodeword[10]+(int)newcodeword[11])%2;
	int c = ((int)newcodeword[4] + (int)newcodeword[5] + (int)newcodeword[6] + (int)newcodeword[7])%2;
	int d = ((int)newcodeword[8] + (int)newcodeword[9] + (int)newcodeword[10] + (int)newcodeword[11])%2;

    if(a==0 && b == 0 && c == 0 && d ==0)
    	cout<<"No error";
    else
    	cout<<"Error at position"<<a*8+ b*4 +c*2 +d;


	return 0;
}
