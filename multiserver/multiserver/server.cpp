#include <iostream>
#include <WinSock2.h>
#include <WS2tcpip.h>
#include <opencv2/opencv.hpp>
#include<opencv2/core/core.hpp>
#include<opencv2/highgui/highgui.hpp>
#include<opencv2/imgproc/imgproc.hpp>
#include<opencv2/video/background_segm.hpp>
#include<opencv2/video/tracking.hpp>
#include<SFML/Audio.hpp>
#include<SFML/Audio/Sound.hpp>
#include<SFML/Audio/SoundBufferRecorder.hpp>
#include<SFML/Network.hpp>
#include<SFML/Network/TcpListener.hpp>
#include<thread>



#pragma comment(lib, "ws2_32.lib")
#define FRAME_WIDTH 640
#define FRAME_HEIGHT 480

const char* ip = "127.0.0.1";


void video(int vportA, int vportB)
{
	int flag = 0;

	while (1)
	{

		bool running = true;
		char key;

		int height, width, IM_HEIGHT, IM_WIDTH;


		//initilize winsock
		while (1)
		{
			WSADATA wsData;
			WORD ver = MAKEWORD(2, 2);

			int wsok = WSAStartup(ver, &wsData);

			if (wsok != 0)
			{
				std::cerr << "Can't Initilize winsock! Quitting" << std::endl;
				continue ;

			}
			else
			{
				break;
			}
		}

		SOCKET listeningA;
		SOCKET listeningB;

		while (1)
		{
			//Create a socket
			listeningA = socket(AF_INET, SOCK_STREAM, 0);

			listeningB = socket(AF_INET, SOCK_STREAM, 0);


			if (listeningA == INVALID_SOCKET)
			{
				std::cerr << "Can't create a socket! Qutting" << std::endl;
				continue;
			}


			if (listeningB == INVALID_SOCKET)
			{
				std::cerr << "Can't create a socket! Qutting" << std::endl;
				continue;
			}
			else
			{
				break;
			}

		}
		//Bind the socket to an ip address and port to a socket
		SOCKADDR_IN hintA, hintB;
		hintA.sin_family = AF_INET;
		hintB.sin_family = AF_INET;


		hintA.sin_port = htons(vportA);
		hintB.sin_port = htons(vportB);


		//hint.sin_addr.S_un.S_addr = INADDR_ANY; //Could also use inet_pton....

		inet_pton(AF_INET, ip, &(hintA.sin_addr));

		inet_pton(AF_INET, ip, &(hintB.sin_addr));



		bind(listeningA, (sockaddr*)&hintA, sizeof(hintA));

		bind(listeningB, (sockaddr*)&hintB, sizeof(hintB));

		//Tell winsock the socket is for listening
		listen(listeningA, SOMAXCONN);
		listen(listeningB, SOMAXCONN);

		//wait for a connection
		sockaddr_in clientA, clientB;
		int clientSize = sizeof(clientA);

		SOCKET clientSocketA = accept(listeningA, (sockaddr*)&clientA, &clientSize);
		SOCKET clientSocketB = accept(listeningB, (sockaddr*)&clientB, &clientSize);

		char hostA[NI_MAXHOST], hostB[NI_MAXHOST]; //client's remote name
		char serviceA[NI_MAXHOST], serviceB[NI_MAXHOST]; //service (i.e port) the client is connect on

		ZeroMemory(hostA, NI_MAXHOST);//same as memset(host, 0, NI_MAXHOST)
		ZeroMemory(serviceA, NI_MAXHOST);


		ZeroMemory(hostB, NI_MAXHOST);//same as memset(host, 0, NI_MAXHOST)
		ZeroMemory(serviceB, NI_MAXHOST);


		//for A
		if (getnameinfo((sockaddr*)&clientA, sizeof(clientA), hostA, NI_MAXHOST, serviceA, NI_MAXSERV, 0) == 0)
		{
			std::cout << hostA << "Connected on port" << serviceA << std::endl;
			//continue;
		}
		else
		{
			inet_ntop(AF_INET, &clientA.sin_addr, hostA, NI_MAXHOST);
			std::cout << hostA << "Connected" << ntohs(clientA.sin_port) << std::endl;

		}
		//for B


		if (getnameinfo((sockaddr*)&clientB, sizeof(clientB), hostB, NI_MAXHOST, serviceB, NI_MAXSERV, 0) == 0)
		{
			std::cout << hostB << "Connected on port" << serviceB << std::endl;
			//continue;
		}
		else
		{
			inet_ntop(AF_INET, &clientB.sin_addr, hostB, NI_MAXHOST);
			std::cout << hostB << "Connected" << ntohs(clientB.sin_port) << std::endl;

		}
		//close listening socket
		closesocket(listeningA);
		closesocket(listeningB);



		cv::Mat img;
		img = cv::Mat::zeros(480, 640, CV_8UC3);
		int imgSize = img.total() * img.elemSize();
		uchar* iptr = img.data;
		int bytes = 0;
		int bytesAud = 0;


		while (1) {

			if ((bytes = recv(clientSocketA, (char*)iptr, imgSize, MSG_WAITALL)) == -1) {
				std::cerr << "recv failed, received bytes = " << bytes << std::endl;
				flag = 1;
				break;
			}


			//send processed image
			if ((bytes = send(clientSocketB, (const char*)img.data, imgSize, 0)) < 0) {
				std::cerr << "bytes = " << bytes << std::endl;
				
			}


		}

		closesocket(clientSocketA);
		closesocket(clientSocketB);
		if (flag == 1)
			continue;
		
	}
}




void audio(int aportA, int aportB)
{
	int flag = 0;

	while (1)
	{
		//remoteSocket2 listener 2 for receiving data from client
		sf::TcpSocket  remoteSocketA, remoteSocketB;
		sf::TcpListener listenerA, listenerB;


		//for A
		if (listenerA.listen(aportA) != sf::Socket::Done)
		{
			std::cout << "Server sfml not listening client A" << std::endl;
		}
		else
		{
			std::cout << "Server sfml listening client A" << std::endl;
		}

		if (listenerA.accept(remoteSocketA) != sf::Socket::Done)
		{
			std::cout << "SFML server didn't accept clientA" << std::endl;
		}
		else
		{
			std::cout << "Server sfml accepted clientA" << std::endl;
		}







		//for B
		if (listenerB.listen(aportB) != sf::Socket::Done)
		{
			std::cout << "Server sfml not listening client B" << std::endl;
		}
		else
		{
			std::cout << "Server sfml listening client B" << std::endl;
		}

		if (listenerB.accept(remoteSocketB) != sf::Socket::Done)
		{
			std::cout << "SFML server didn't accept clientB" << std::endl;
		}
		else
		{
			std::cout << "Server sfml accepted clientB" << std::endl;
		}



		sf::Packet packet2;




		while (1)
		{

			sf::SoundBuffer b1;
			sf::Sound g;
			if (remoteSocketA.receive(packet2) != sf::Socket::Done)
			{
				std::cout << "Audio wasn't recieved" << std::endl;
				flag=1;
				break;
			}


			if (remoteSocketB.send(packet2) != sf::Socket::Done)
			{

				std::cerr << "Failed to send end-of-stream packet" << std::endl;
				flag = 1;
				break;
			}



		}
		if (flag == 1)
			continue;
	}

}




void chat(int cportA, int cportB)
{
	int flag = 0;

	while (1)
	{

		//remoteSocket2 listener 2 for receiving data from client
		sf::TcpSocket  remoteSocketA, remoteSocketB;
		sf::TcpListener listenerA, listenerB;


		//for A
		if (listenerA.listen(cportA) != sf::Socket::Done)
		{
			std::cout << "Server sfml not listening chat A" << std::endl;
		}
		else
		{
			std::cout << "Server sfml listening chat A" << std::endl;
		}

		if (listenerA.accept(remoteSocketA) != sf::Socket::Done)
		{
			std::cout << "SFML server didn't accept chat A" << std::endl;
		}
		else
		{
			std::cout << "Server sfml accepted chat A" << std::endl;
		}



		//for B
		if (listenerB.listen(cportB) != sf::Socket::Done)
		{
			std::cout << "Server sfml not listening chat B" << std::endl;
		}
		else
		{
			std::cout << "Server sfml listening chat B" << std::endl;
		}

		if (listenerB.accept(remoteSocketB) != sf::Socket::Done)
		{
			std::cout << "SFML server didn't accept chat B" << std::endl;
		}
		else
		{
			std::cout << "Server sfml accepted chat B" << std::endl;
		}



		char buff[1024];
		std::size_t received;



		while (1)
		{


			if (remoteSocketA.receive(buff, sizeof(buff), received) != sf::Socket::Done)
			{
				std::cout << "Chat wasn't recieved" << std::endl;
				flag = 1;
				break;
			}

			if (remoteSocketB.send(buff, sizeof(buff)) != sf::Socket::Done)
			{
				
				std::cerr << "Failed to send end-of-stream packet" << std::endl;
				flag = 1;
				break;
			}



		}
		if (flag == 1)
			continue;
	}


	}



int main()
{
	//even number send, odd number recieve
	//std::thread  ts1(video,8002,8003),ts2(video,8004, 8001), ts3(audio,6602, 6603), ts4(audio,6604, 6601),ts5(chat,6002,6003), ts6(chat, 6004, 6001);
	std::thread ts1(video, 8004, 8003), ts3(audio, 6604, 6603),t4(video,8002,8001), t5(audio, 6602, 6601);
	std::thread ts5(chat, 3004, 3003);
	//std::thread	ts6(chat, 6001, 6002);
	
	//ts1.join();
	//ts3.join();
	//ts6.join();
	ts1.join();
	ts3.join();

	t4.join();
	t5.join();
	ts5.join();


	//ts6.join();
	return 0;

	//std::cout << "Recording... press enter to stop";
	//std::cin.ignore(10000, '\n');




}



























