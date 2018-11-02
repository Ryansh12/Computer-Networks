import os 
import socket

ip=raw_input("Enter the ip")

os.system("nslookup " + ip )
#print(socket.gethostbyaddr(ip))


domain=raw_input("Enter the domain name")
#os.system("nslookup " + domain )


print(socket.gethostbyname(domain))

