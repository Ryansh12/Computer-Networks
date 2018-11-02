import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.Scanner;
import java.lang.Math;
public class pingTest{

	public static void main(String args[]){
	
		String hostIp="192.168.4.2";
		String destinationIp=args[3];
		
		System.out.println("Host IP address is : "+hostIp);
		System.out.println("Destination Ip address is : "+args[3]);
		
		String host[]=hostIp.split("\\.");
		String destination[]=destinationIp.split("\\.");
		
		//GET SUBNET MASK
		System.out.println("Enter subnet mask");
			Scanner in1 = new Scanner(System.in);
 			String j;
 			j = in1.nextLine();
 			String mask[]=j.split("\\.");
		
		int hostbyte=Integer.parseInt(host[0]);
		
		//CLASSIFY INTO CLASSES
		int i=0;
		if((hostbyte>=0)&(hostbyte<=127)){
			System.out.println("IP addresses belong to class A");
			int n1=Integer.parseInt(mask[3]);
			
			while(n1>0){
				if((n1%2)==1)
					i++;
				n1=n1/2;
			}
			
			int n2=Integer.parseInt(mask[2]);
			
			while(n2>0){
				if((n2%2)==1)
					i++;
				n2=n2/2;
			}
			
			int n3=Integer.parseInt(mask[1]);
			
			while(n3>0){
				if((n3%2)==1)
					i++;
				n3=n3/2;
			}
		}
		
		else if((hostbyte>=128)&(hostbyte<=191)){
			System.out.println("IP addresses belong to class B");
			int n1=Integer.parseInt(mask[3]);
			
			while(n1>0){
				if((n1%2)==1)
					i++;
				n1=n1/2;
			}
			
			int n2=Integer.parseInt(mask[2]);
			
			while(n2>0){
				if((n2%2)==1)
					i++;
				n2=n2/2;
			}
			System.out.println("Number of subnets are : "+Math.pow(2,i));
			
		}
		
		else{
			System.out.println("IP addresses belong to class C");
			int n1=Integer.parseInt(mask[3]);
			
			while(n1>0){
				if((n1%2)==1)
					i++;
				n1=n1/2;
			}
			
			System.out.println("Number of subnets are : "+Math.pow(2,i));
		}
 			
 			String hostsub=(Integer.parseInt(host[0])&Integer.parseInt(mask[0]))+"."+(Integer.parseInt(host[1])&Integer.parseInt(mask[1]))+"."+(Integer.parseInt(host[2])&Integer.parseInt(mask[2]))+"."+(Integer.parseInt(host[3])&Integer.parseInt(mask[3]));
 			String destsub=(Integer.parseInt(destination[0])&Integer.parseInt(mask[0]))+"."+(Integer.parseInt(destination[1])&Integer.parseInt(mask[1]))+"."+(Integer.parseInt(destination[2])&Integer.parseInt(mask[2]))+"."+(Integer.parseInt(destination[3])&Integer.parseInt(mask[3]));
 			
 			System.out.println("Subnet Id of host is : "+hostsub);
 			System.out.println("Subnet Id of destination is : "+destsub);
 			
 			if(hostsub.equals(destsub))
 				System.out.println("Both are part of the same subnet");
 			else{
				System.out.println("The Node belong to different subnets");
				return;
			}
 				
		
		System.out.println("\n\nExecuting Ping Command\n\n");
		String pingcmd= args[0]+" "+args[1]+" "+args[2]+" "+args[3];
		  
		try{
			Process p=Runtime.getRuntime().exec(pingcmd);
			String s = " ";

			BufferedReader in = new BufferedReader(new InputStreamReader(p.getInputStream()));
			while ((s = in.readLine()) != null) {
				System.out.println(s);
			}
			in.close();
		}
		 catch (Exception e) {
			e.printStackTrace();
		}
	}
}
