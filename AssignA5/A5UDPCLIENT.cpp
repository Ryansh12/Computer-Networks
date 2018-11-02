//============================================================================
// Name        : A5.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include<sys/socket.h>
#include <arpa/inet.h>
#include <stdlib.h>
#include <string.h>
#include <fstream>
#include<unistd.h>

using namespace std;

#define PORT 8999
#define buflen 1000;
#define SERVER_ADDRESS "127.0.0.1"
void die(char *s) //method to print error and exit
{
	perror(s);
	exit(1);
}
int main() {

	struct sockaddr_in server_addr;
	
	int sock=socket(AF_INET,SOCK_DGRAM,0); 
	server_addr.sin_family=AF_INET;
	server_addr.sin_port=htons(PORT);
	server_addr.sin_addr.s_addr=inet_addr(SERVER_ADDRESS);
	

	socklen_t cli=sizeof(server_addr);
	int slen=sizeof(server_addr);
	
	char buffer[1000];
	cout<<"\nEnter msg to server:";
	cin.getline(buffer,sizeof(buffer));
	msg_len=sendto(sock,buffer,strlen(buffer),0,(struct sockaddr *)& server_addr,slen);
	
		
			char filename[100];
			bzero((char *)filename,sizeof(filename));
			msg_len=recvfrom(sock,filename,99,0,(struct sockaddr*)&server_addr,&cli);
		
			cout<<"\nFilename:"<<filename;

			int filesize;
			msg_len=recvfrom(sock,(void *)&filesize,sizeof(filesize),0,(struct sockaddr*)&server_addr,&cli);
			cout<<"\nFileSize:"<<filesize;
			//char *filebuff=new char[filesize];
			char filebuff[503];
			
			ofstream fout;
			fout.open(filename,ios::out|ios::binary);
			int itr = 1;
			while(itr* 503<filesize)
			{
			
			msg_len=recvfrom(sock,filebuff,503,0,(struct sockaddr*)&server_addr,&cli);
			
			
			
			//if(!fout)
			//	die("CANNOT CREATE FILE");
			//else
			//{
				fout.write(filebuff,503);
				
				itr++;
				cout<<itr<<"\t";
			//	cout<<"File received";
			//}
			}
			msg_len=recvfrom(sock,filebuff,503,0,(struct sockaddr*)&server_addr,&cli);
			fout.write(filebuff,(filesize%503));
		
			if(!fout)
				die("CANNOT CREATE FILE");
			else
			{
				cout<<"File received";
			}
			fout.close();
		
			
		
close(sock);
	return 0;
}



