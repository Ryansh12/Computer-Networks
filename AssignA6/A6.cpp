
#include<iostream>
#include <arpa/inet.h>
#include <unistd.h> // for read function
#include <netinet/in.h> //for INADDR_ANY
#include <string.h> //for len function
#include<bits/stdc++.h>
#include<fstream>
using namespace std;

int main() {



	int server_fd = socket(AF_INET, SOCK_STREAM, 0);

	struct sockaddr_in address;
	address.sin_family = AF_INET;
	address.sin_addr.s_addr = inet_addr("127.0.0.1");
	address.sin_port = htons( 8088 ); //host to network short(MSB first) & port is 8088
	bind(server_fd, (struct sockaddr *)&address, sizeof(address));

	listen(server_fd, 3);
	int addrlen = sizeof(address);
	int new_socket = accept(server_fd, (struct sockaddr *)&address, (socklen_t*)&addrlen);

	char message[500];
	
			bzero(message,500);
			read( new_socket , message, 13);
			cout<<message;
			cout<<"hello message received";
			send(new_socket , message , 15 , 0 );
			cout<<"hello message sent";
			
			bzero(message,500);
			read( new_socket , message, 500);
			cout<<message;
			cout << "Contents of file received" << endl;
			fstream file;
			file.open( "new.txt", ios::out);
			file.write(reinterpret_cast<char*> (&message), sizeof(message));
			
			bzero(message,500);
			read( new_socket , message, sizeof(message));
			float angle=atof(message);
			
			
			bzero(message,500);
			read( new_socket , message, sizeof(message));
			int op=atoi(message);
			if(op==1)
				cout<<cos(angle)<<endl;
			if(op==2)
				cout<<sin(angle)<<endl;
			if(op==3)
				cout<<tan(angle)<<endl;
		
return 0;
}
