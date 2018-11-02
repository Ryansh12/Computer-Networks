#include <arpa/inet.h>
#include <netinet/in.h>
#include <string.h>
#include <sys/socket.h>
#include <unistd.h>
#include <iostream>
#include <fstream>

using namespace std;


int main()
{

	int sock = socket(AF_INET, SOCK_STREAM, 0);


	struct sockaddr_in serv_addr;
	serv_addr.sin_family = AF_INET;
	serv_addr.sin_addr.s_addr = inet_addr("127.0.0.1");
	serv_addr.sin_port = htons(8088);//port is 8088
	connect(sock, (struct sockaddr *)&serv_addr, sizeof(serv_addr));
	
	
	//part1: Sending hello message
	char *hello ="hello";
	send(sock , hello , strlen(hello) , 0 );
	cout<<"hello message sent"<<endl;
			
	
	//part2:Sending file
	ifstream infile;
	infile.open("file.txt");
	cout << "Reading from the file" << endl;
	char data[500];
	int i=0;
	char c;
	while(infile.get(c) )
	{
		data[i]=c;
		i++;
	}
	send(sock , data ,strlen(data) , 0 );
	cout<<"Sent the complete file successfully"<<endl;
			


	//part3:Trigonometric functions
	char angle[500];
	cout<<"Enter the Angle(in radians)";
	cin>>angle;
	send(sock , angle ,strlen(angle) , 0 );
	

	char n[500];
	cout<<"Enter the Trigonometeric function \n1.cos \n2.sin \n3.tan";
	cin>>n;
	send(sock , n ,strlen(n) , 0 );
	
	return 0;

}
