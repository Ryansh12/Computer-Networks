import java.io.IOException;
import java.net.DatagramPacket;
import java.net.DatagramSocket;
import java.net.SocketAddress;
import java.net.SocketException;

public class Channel implements Runnable
{
	private DatagramSocket socket;
	private boolean running;
	
	public void bind(int port) throws SocketException
	{
		socket = new DatagramSocket(port);
	}
	
	public void start()
	{
		Thread thread = new Thread(this);
		thread.start();
	}
	
	public void stop()
	{
		running = false;
		socket.close();
	}

	@Override
	public void run()
	{
		byte[] buffer = new byte[1024];
		DatagramPacket packet = new DatagramPacket(buffer, buffer.length);
		
		running = true;
		while(running)
		{
			try
			{
				socket.receive(packet);
				
				String msg = new String(buffer, 0, packet.getLength());
				System.out.println(msg);
			} 
			catch (IOException e)
			{
				break;
			}
		}
	}
	
	public void sendTo(SocketAddress address, String msg) throws IOException
	{
		byte[] buffer = msg.getBytes();
		
		DatagramPacket packet = new DatagramPacket(buffer, buffer.length);
		packet.setSocketAddress(address);
		
		socket.send(packet);
	}
}
