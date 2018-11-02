

//SERVER
#include <iostream>
#include<sys/socket.h>
#include <arpa/inet.h>
#include <stdlib.h>
#include <string.h>
#include<unistd.h>
#include<fstream>
using namespace std;

#define PORT 8999
#define buflen 1000;

void die(char *s) //method to print error and exit
{
	perror(s);
	exit(1);
}
int main() {

	
	
	int sock=socket(AF_INET,SOCK_DGRAM,0); 
	
	struct sockaddr_in server_addr,client_addr;
	server_addr.sin_family=AF_INET;
	server_addr.sin_port=htons(PORT);
	server_addr.sin_addr.s_addr=htons(INADDR_ANY); 

	//BINDING socket to port
	bind(sock,(struct sockaddr *)&server_addr,sizeof(server_addr);
	

	int client_len=sizeof(client_addr);
	socklen_t cli=sizeof(client_addr);
	int choice,msg_len;
	char buffer[1000];
	bzero((char *)buffer,sizeof(buffer));
	msg_len=recvfrom(sock,buffer,1000,0,(struct sockaddr *)&client_addr,&cli);

	
			cout<<"\nENter Filename:";
			char filename[100];
			cin>>filename;
			fstream fout;
			fout.open(filename,ios::in|ios::out|ios::binary);
			fout.seekg(0,ios::end);
			int filesize=fout.tellg(); //get file size
			//char *filebuff=new char[filesize];
			char filebuff[503];
			
			fout.seekg(0,ios::beg);
			

			msg_len=sendto(sock,filename,strlen(filename),0,(struct sockaddr *)&client_addr,client_len); //send filename
						if(msg_len==-1)
							die("Filename error");

			msg_len=sendto(sock,(void *)&filesize,sizeof(filesize),0,(struct sockaddr *)&client_addr,client_len); //send filesize
			if(msg_len==-1)
				die("Filesize error");
			
			
			//fout.read(filebuff,503); //reading file content
			int itr= 1;
			while(itr*503<filesize)
			{
				fout.read(filebuff,503);
				msg_len=sendto(sock,filebuff,503,0,(struct sockaddr *)&client_addr,client_len); //send file conetents
				//if(msg_len==-1)
				//	die("File transmission error");
				//else
				//	cout<<"Transmission Successful";
					
				itr++;
				cout<<itr<<"\t";
					
			}
			
			fout.read(filebuff,(filesize%503));
			msg_len=sendto(sock,filebuff,503,0,(struct sockaddr *)&client_addr,client_len); //send file conetents
	
				if(msg_len==-1)
					die("File transmission error");
				else
					cout<<"Transmission Successful";
				
			
			fout.close();
		}

close(sock);
	return 0;
}


