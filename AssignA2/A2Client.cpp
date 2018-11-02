// Client side C/C++ program to demonstrate Socket programming

//#include <bits/socket_type.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <string.h>
#include <sys/socket.h>
#include <unistd.h>
#include <iostream>
using namespace std;
char codeword[12];
void hamming()
{
	int dataword[12];
	cout<<"Enter Data word(7 bits)";
	cin>>dataword[11]>>dataword[10]>>dataword[9]>>dataword[7]>>dataword[6]>>dataword[5]>>dataword[3];

	dataword[8]=0;
	dataword[4]=0;
	dataword[2]=0;
	dataword[1]=0;

	dataword[1]= (dataword[1] + dataword[3] + dataword[5] + dataword[7] + dataword[9] + dataword[11])%2;
	dataword[2]= (dataword[2] + dataword[3] + dataword[6] + dataword[7] + dataword[10]+dataword[11])%2;
	dataword[4]= (dataword[4] + dataword[5] + dataword[6] + dataword[7])%2;
	dataword[8]= (dataword[8] + dataword[9] + dataword[10] + dataword[11])%2;


	for(int i=1;i<12;i++)
		codeword[i]=(char)(dataword[i] + 48);

}

int main()
{
	hamming();
	 int sock = socket(AF_INET, SOCK_STREAM, 0);


	 struct sockaddr_in serv_addr;



	serv_addr.sin_family = AF_INET;
	serv_addr.sin_addr.s_addr = inet_addr("10.10.13.61");
	serv_addr.sin_port = htons(8088);//port is 8088
	connect(sock, (struct sockaddr *)&serv_addr, sizeof(serv_addr));


	send(sock , codeword , 13 , 0 );



    return 0;
}
