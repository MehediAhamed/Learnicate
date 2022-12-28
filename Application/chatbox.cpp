#pragma once
#include "chatbox.h"
#include "teacher_menu.h"

#include"../FileExplorar/FileExplorer.h"

chatbox::chatbox()
{

	teacher_chat_portA = 6601;
	teacher_chat_portB = 6602;
	student_chat_portA = 6603;
	student_chat_portB = 6604;
	ip = "192.168.110.54";
}
void chatbox::write_file_text(int sock, int cnt)
{
	int n;
	FILE* fp, * fp1;
	char buffer[40], buffer2[4056];



	std::string filename, filename1;



	filename = "Material ";
	filename += (char)cnt;
	filename += ".txt";
	std::cout << filename << std::endl;


	filename1 = "Material ";
	filename1 += (char)cnt;
	filename1 += ".txt";
	fopen_s(&fp1, "Material.txt", "a");
	if (fp1 == NULL)
	{
		std::cerr << "Error in Material.txt" << std::endl;
		return;

	}
	fprintf(fp1, "%s\n", filename1.c_str());
	fclose(fp1);

	fopen_s(&fp, filename.c_str(), "w");
	if (fp == NULL)
	{
		std::cerr << "Error in Creating" << std::endl;
		return;

	}


	while (1)
	{
		n = recv(sock, buffer2, 4056, 0);
		if (n <= 0)
		{
			break;
			return;

		}
		fprintf(fp, "%s", buffer2);
		buffer2[0] = { 0 };
	}

	fclose(fp);
}



void chatbox::file_receive_text()
{
	int cnt = 48;

	while (1) {

		std::string ipaddress = ip.toString();
		int port = material_file_receive_port;





		//initilize winsock
		WSADATA wsData;
		WORD ver = MAKEWORD(2, 2);

		int wsok = WSAStartup(ver, &wsData);

		if (wsok != 0)
		{
			std::cerr << "Can't Initilize winsock! Quitting" << std::endl;
			return;

		}
		//Create a socket
		SOCKET listening = socket(AF_INET, SOCK_STREAM, 0);
		if (listening == INVALID_SOCKET)
		{
			std::cerr << "Can't create a socket! Qutting" << std::endl;
			return;
		}
		//Bind the socket to an ip address and port to a socket
		SOCKADDR_IN hint;
		hint.sin_family = AF_INET;
		hint.sin_port = htons(port);
		
		inet_pton(AF_INET, ipaddress.c_str(), &(hint.sin_addr));



		bind(listening, (sockaddr*)&hint, sizeof(hint));

		//Tell winsock the socket is for listening
		listen(listening, SOMAXCONN);

		//wait for a connection
		sockaddr_in client;
		int clientSize = sizeof(client);

		SOCKET clientSocket = accept(listening, (sockaddr*)&client, &clientSize);

		char host[NI_MAXHOST]; //client's remote name
		char service[NI_MAXHOST]; //service (i.e port) the client is connect on

		ZeroMemory(host, NI_MAXHOST);//same as memset(host, 0, NI_MAXHOST)
		ZeroMemory(service, NI_MAXHOST);

		if (getnameinfo((sockaddr*)&client, sizeof(client), host, NI_MAXHOST, service, NI_MAXSERV, 0) == 0)
		{
			std::cout << host << "Connected on port" << service << std::endl;
		}
		else
		{
			inet_ntop(AF_INET, &client.sin_addr, host, NI_MAXHOST);
			std::cout << host << "Connected" << ntohs(client.sin_port) << std::endl;

		}


		//close listening socket
		closesocket(listening);






		cnt++;
		write_file_text(clientSocket, cnt);



		//close the socket
		closesocket(clientSocket);
		//shutdown winsock
		WSACleanup();

	}

}


void chatbox::write_file_csv(int sock, int cnt)
{

	int n;
	FILE* fp, * fp1;
	char buffer[40], buffer2[4056];



	std::string filename, filename1;





	

	filename = "D:\\course";
	
	filename += ".csv";
	std::cout << filename << std::endl;



	fopen_s(&fp, filename.c_str(), "w");
	if (fp == NULL)
	{
		std::cerr << "Error in Creating" << std::endl;
		return;

	}


	while (1)
	{
		n = recv(sock, buffer2, 4056, 0);
		if (n <= 0)
		{
			break;
			return;

		}
		fprintf(fp, "%s", buffer2);
		buffer2[0] = { 0 };
	}

	fclose(fp);
}










void chatbox::file_receive_csv()
{
	int cnt = 48;

	while (1) {

		std::string ipaddress = ip.toString();
		int port = course_file_receive_port;





		//initilize winsock
		WSADATA wsData;
		WORD ver = MAKEWORD(2, 2);

		int wsok = WSAStartup(ver, &wsData);

		if (wsok != 0)
		{
			std::cerr << "Can't Initilize winsock! Quitting" << std::endl;
			return;

		}
		//Create a socket
		SOCKET listening = socket(AF_INET, SOCK_STREAM, 0);
		if (listening == INVALID_SOCKET)
		{
			std::cerr << "Can't create a socket! Qutting" << std::endl;
			return;
		}
		//Bind the socket to an ip address and port to a socket
		SOCKADDR_IN hint;
		hint.sin_family = AF_INET;
		hint.sin_port = htons(port);
	
		inet_pton(AF_INET, ipaddress.c_str(), &(hint.sin_addr));



		bind(listening, (sockaddr*)&hint, sizeof(hint));

		//Tell winsock the socket is for listening
		listen(listening, SOMAXCONN);

		//wait for a connection
		sockaddr_in client;
		int clientSize = sizeof(client);

		SOCKET clientSocket = accept(listening, (sockaddr*)&client, &clientSize);

		char host[NI_MAXHOST]; //client's remote name
		char service[NI_MAXHOST]; //service (i.e port) the client is connect on

		ZeroMemory(host, NI_MAXHOST);//same as memset(host, 0, NI_MAXHOST)
		ZeroMemory(service, NI_MAXHOST);

		if (getnameinfo((sockaddr*)&client, sizeof(client), host, NI_MAXHOST, service, NI_MAXSERV, 0) == 0)
		{
			std::cout << host << "Connected on port" << service << std::endl;
		}
		else
		{
			inet_ntop(AF_INET, &client.sin_addr, host, NI_MAXHOST);
			std::cout << host << "Connected" << ntohs(client.sin_port) << std::endl;

		}


		//close listening socket
		closesocket(listening);



		write_file_csv(clientSocket, cnt);



		//close the socket
		closesocket(clientSocket);
		//shutdown winsock
		WSACleanup();

	}

}


void chatbox::syllabus_receive_csv()
{
	int cnt = 48;

	while (1) {

		std::string ipaddress = ip.toString();
		int port = syllbus_file_receive_port;





		//initilize winsock
		WSADATA wsData;
		WORD ver = MAKEWORD(2, 2);

		int wsok = WSAStartup(ver, &wsData);

		if (wsok != 0)
		{
			std::cerr << "Can't Initilize winsock! Quitting" << std::endl;
			return;

		}
		//Create a socket
		SOCKET listening = socket(AF_INET, SOCK_STREAM, 0);
		if (listening == INVALID_SOCKET)
		{
			std::cerr << "Can't create a socket! Qutting" << std::endl;
			return;
		}
		//Bind the socket to an ip address and port to a socket
		SOCKADDR_IN hint;
		hint.sin_family = AF_INET;
		hint.sin_port = htons(port);
		//hint.sin_addr.S_un.S_addr = INADDR_ANY; //Could also use inet_pton....

		inet_pton(AF_INET, ipaddress.c_str(), &(hint.sin_addr));



		bind(listening, (sockaddr*)&hint, sizeof(hint));

		//Tell winsock the socket is for listening
		listen(listening, SOMAXCONN);

		//wait for a connection
		sockaddr_in client;
		int clientSize = sizeof(client);

		SOCKET clientSocket = accept(listening, (sockaddr*)&client, &clientSize);

		char host[NI_MAXHOST]; //client's remote name
		char service[NI_MAXHOST]; //service (i.e port) the client is connect on

		ZeroMemory(host, NI_MAXHOST);//same as memset(host, 0, NI_MAXHOST)
		ZeroMemory(service, NI_MAXHOST);

		if (getnameinfo((sockaddr*)&client, sizeof(client), host, NI_MAXHOST, service, NI_MAXSERV, 0) == 0)
		{
			std::cout << host << "Connected on port" << service << std::endl;
		}
		else
		{
			inet_ntop(AF_INET, &client.sin_addr, host, NI_MAXHOST);
			std::cout << host << "Connected" << ntohs(client.sin_port) << std::endl;

		}


		//close listening socket
		closesocket(listening);



		
		int n;
		FILE* fp, * fp1;
		char buffer[40], buffer2[4056];



		std::string filename, filename1;



		filename = "D:\\syllabus";

		filename += ".csv";
		std::cout << filename << std::endl;



		fopen_s(&fp, filename.c_str(), "w");
		if (fp == NULL)
		{
			std::cerr << "Error in Creating" << std::endl;
			return;

		}


		while (1)
		{
			n = recv(clientSocket, buffer2, 4056, 0);
			if (n <= 0)
			{
				break;
				return;

			}
			fprintf(fp, "%s", buffer2);
			buffer2[0] = { 0 };
		}

		fclose(fp);

		//close the socket
		closesocket(clientSocket);
		//shutdown winsock
		WSACleanup();

	}

}



void chatbox::notice_receive_csv()
{
	int cnt = 48;

	while (1) {

		std::string ipaddress = ip.toString();
		int port = notice_file_receive_port;





		//initilize winsock
		WSADATA wsData;
		WORD ver = MAKEWORD(2, 2);

		int wsok = WSAStartup(ver, &wsData);

		if (wsok != 0)
		{
			std::cerr << "Can't Initilize winsock! Quitting" << std::endl;
			return;

		}
		//Create a socket
		SOCKET listening = socket(AF_INET, SOCK_STREAM, 0);
		if (listening == INVALID_SOCKET)
		{
			std::cerr << "Can't create a socket! Qutting" << std::endl;
			return;
		}
		//Bind the socket to an ip address and port to a socket
		SOCKADDR_IN hint;
		hint.sin_family = AF_INET;
		hint.sin_port = htons(port);
		
		inet_pton(AF_INET, ipaddress.c_str(), &(hint.sin_addr));



		bind(listening, (sockaddr*)&hint, sizeof(hint));

		//Tell winsock the socket is for listening
		listen(listening, SOMAXCONN);

		//wait for a connection
		sockaddr_in client;
		int clientSize = sizeof(client);

		SOCKET clientSocket = accept(listening, (sockaddr*)&client, &clientSize);

		char host[NI_MAXHOST]; //client's remote name
		char service[NI_MAXHOST]; //service (i.e port) the client is connect on

		ZeroMemory(host, NI_MAXHOST);//same as memset(host, 0, NI_MAXHOST)
		ZeroMemory(service, NI_MAXHOST);

		if (getnameinfo((sockaddr*)&client, sizeof(client), host, NI_MAXHOST, service, NI_MAXSERV, 0) == 0)
		{
			std::cout << host << "Connected on port" << service << std::endl;
		}
		else
		{
			inet_ntop(AF_INET, &client.sin_addr, host, NI_MAXHOST);
			std::cout << host << "Connected" << ntohs(client.sin_port) << std::endl;

		}


		//close listening socket
		closesocket(listening);



		//write_file_csv(clientSocket, cnt);

		int n;
		FILE* fp, * fp1;
		char buffer[40], buffer2[4056];



		std::string filename, filename1;


		filename = "D:\\notice";

		filename += ".csv";
		std::cout << filename << std::endl;



		fopen_s(&fp, filename.c_str(), "w");
		if (fp == NULL)
		{
			std::cerr << "Error in Creating" << std::endl;
			return;

		}


		while (1)
		{
			n = recv(clientSocket, buffer2, 4056, 0);
			if (n <= 0)
			{
				break;
				return;

			}
			fprintf(fp, "%s", buffer2);
			buffer2[0] = { 0 };
		}

		fclose(fp);

		//close the socket
		closesocket(clientSocket);
		//shutdown winsock
		WSACleanup();

	}

}


void chatbox::send_file(FILE* fp, int sock)
{
	char data[4056] = { 0 };

	while (fgets(data, 4056, fp) != NULL)
	{
		if (send(sock, data, sizeof(data), 0) == -1)
		{
			std::cerr << "Error in sending file" << std::endl;
			return;

		}
		
		data[0] = { 0 };
	}

	std::cerr << "File sucessfully send" << std::endl;
}


int chatbox::file_network_send(std::string file_path, std::string filename,std::string extension,int port)
{
	std::string ipaddress = ip.toString();
							







	fp = fopen(file_path.c_str(), "r");



	filename = "Material.";

	filename += extension;
	std::cout << filename << std::endl;



	fopen_s(&fp, filename.c_str(), "w");

	if (fp == NULL)
	{
		std::cerr << "Error in Creating" << std::endl;
		return 0;

	}







	//send file
	//send_file(fp, sock);





	return 0;
}


void chatbox::t_receiveClient()
{
	sf::Socket::Status status1 = localSocket1.connect(ip, teacher_chat_portA);  //portA=6001

	while (status1 != sf::Socket::Done)
	{
		std::cout << "Connecting to socket1..." << std::endl;
		sf::Socket::Status status = localSocket1.connect(ip, teacher_chat_portA);
		if (status == sf::Socket::Done)
		{
			std::cout << "Connected to socket1!!!" << std::endl;
			system("cls");
			break;
		}

	}


	
	char buff[1024];
	std::size_t received;
	localSocket1.receive(buff, sizeof(buff), received);



	while (1)
	{
		char buff[1024];
		std::size_t received;




		if (localSocket1.receive(buff, sizeof(buff), received) != sf::Socket::Done)
		{
			std::cout << "Message wasn't recieved" << std::endl;

		}
		else

		{
			std::cout << "Message >> " << buff << std::endl;
		}







	}

	
}

void chatbox::t_sendClient()
{
	sf::Socket::Status status2 = localSocket2.connect(ip, teacher_chat_portB); //port b=3002




	while (status2 != sf::Socket::Done)
	{
		std::cout << "Connecting to socket2..." << std::endl;
		sf::Socket::Status status2 = localSocket2.connect(ip, teacher_chat_portB);
		if (status2 == sf::Socket::Done)
		{
			std::cout << "Connected to socket2!!!" << std::endl;
			system("cls");
			break;
		}

	}

	

	char out[1024];
	localSocket2.send(out, sizeof(out));



	while (1)
	{
		char out[1024];
		std::cout << "Type>";
		std::cin >> out;

		// Send the audio packet to the server
		if (localSocket2.send(out, sizeof(out)) != sf::Socket::Done)
		{

			std::cerr << "Failed to send end-of-stream packet" << std::endl;
		}
		std::cout << "Sent << " << out << std::endl;


	}
	



}



void chatbox::s_receiveClient()
{
	sf::Socket::Status status1 = localSocket1.connect(ip, student_chat_portA);  //portA=6001

	while (status1 != sf::Socket::Done)
	{
		std::cout << "Connecting to socket1..." << std::endl;
		sf::Socket::Status status = localSocket1.connect(ip, student_chat_portA);
		if (status == sf::Socket::Done)
		{
			std::cout << "Connected to socket1!!!" << std::endl;
			system("cls");
			break;
		}

	}



	while (1)
	{
		char buff[1024];
		std::size_t received;



		//recieve


		if (localSocket1.receive(buff, sizeof(buff), received) != sf::Socket::Done)
		{
			std::cout << "Message wasn't recieved" << std::endl;

		}
		else

		{
			std::cout << "Message : " << buff << std::endl;
		}







	}
}

void chatbox::s_sendClient()
{
	sf::Socket::Status status2 = localSocket2.connect(ip, student_chat_portB); //port b=6002




	while (status2 != sf::Socket::Done)
	{
		std::cout << "Connecting to socket2..." << std::endl;
		sf::Socket::Status status2 = localSocket2.connect(ip, student_chat_portB);
		if (status2 == sf::Socket::Done)
		{
			std::cout << "Connected to socket2!!!" << std::endl;
			system("cls");
			break;
		}

	}



	while (1)
	{
		char out[1024];
		std::cout << ">";
		std::cin >> out;

		// Send the audio packet to the server
		if (localSocket2.send(out, sizeof(out)) != sf::Socket::Done)
		{

			std::cerr << "Failed to send end-of-stream packet" << std::endl;
		}
		std::cout << "Sent : " << out << std::endl;


	}



}




void chatbox::texting_mem(sf::RenderWindow& window)
{



	sf::Font n_font;
	if (!n_font.loadFromFile("resources\\ttf\\arialbd.ttf"))
	{
		std::cout << "Font didn't loaded";
	}


	sf::Text n_menu[3];
	n_menu[1].setFont(n_font);
	n_menu[1].setCharacterSize(20);
	n_menu[1].setStyle(sf::Text::Bold);
	n_menu[1].setFillColor(sf::Color::Cyan);
	n_menu[1].setString("Limit(150 Letters)");
	n_menu[1].setPosition(sf::Vector2f(880, 200));

	n_menu[2].setFont(n_font);
	n_menu[2].setCharacterSize(42);
	n_menu[2].setStyle(sf::Text::Bold);
	n_menu[2].setFillColor(sf::Color::White);
	n_menu[2].setString("Notice");
	n_menu[2].setPosition(sf::Vector2f(350, 60));



	//for  background
	sf::RectangleShape background1, background2;
	background1.setSize(sf::Vector2f(1100, 750));
	sf::Texture MainTexture1, MainTexture2;
	MainTexture1.loadFromFile("resources\\images\\red.png");
	background1.setTexture(&MainTexture1);





	Textbox n_text2(40, sf::Color::White, true);
	n_text2.setPosition({ 70, 110 });
	n_text2.setLimit(true, 35);
	n_text2.setFont(n_font);






	Button n_btn3(" Save", { 200,50 }, 20, sf::Color::Green, sf::Color::Black);

	n_btn3.setPosition({ 880,350 });
	n_btn3.setFont(n_font);

	Button n_btn4(" Back", { 200,50 }, 20, sf::Color::Green, sf::Color::Black);

	n_btn4.setPosition({ 880,500 });
	n_btn4.setFont(n_font);





	sf::Texture n_texture;
	n_texture.loadFromFile("resources\\images\\white.jpg");

	// Create a sprite
	sf::Sprite n_sprite1, n_sprite2, n_sprite3;
	n_sprite1.setTexture(n_texture);
	n_sprite1.setTextureRect(sf::IntRect(0, 0, 10, 750));
	n_sprite1.setColor(sf::Color(255, 255, 255, 200));
	n_sprite1.setPosition(0, 0);

	n_sprite2.setTexture(n_texture);
	n_sprite2.setTextureRect(sf::IntRect(0, 0, 10, 750));
	n_sprite2.setColor(sf::Color(255, 255, 255, 200));
	n_sprite2.setPosition(850, 0);




	teacher_menu t(window.getSize().x, window.getSize().y);


	chatbox r;
	




	while (window.isOpen())
	{
		sf::Event Event;

		std::thread t1(std::thread([&] { r.t_receiveClient(); })), t2(std::thread([&] { r.t_sendClient(); }));

		t1.join();
		t2.join();


		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Return)) {
			
			n_text2.setSelected(true);
		}
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) {
			
			n_text2.setSelected(false);
		}


		while (window.pollEvent(Event))
		{

			switch (Event.type)
			{
			case sf::Event::Closed:
				window.close();
				break;

			case sf::Event::TextEntered:

				n_text2.typedOn(Event);



			case sf::Event::MouseMoved:


				if (n_btn3.isMouseOver(window))
				{
					n_btn3.setBackColor(sf::Color::White);
				}
				else if (!n_btn3.isMouseOver(window))
				{
					n_btn3.setBackColor(sf::Color::Green);
				}
				if (n_btn4.isMouseOver(window))
				{
					n_btn4.setBackColor(sf::Color::White);
				}
				else if (!n_btn4.isMouseOver(window))
				{
					n_btn4.setBackColor(sf::Color::Green);
				}
				break;

			case sf::Event::MouseButtonPressed:
				if (n_btn4.isMouseOver(window))
				{
					t.t_display(window);
					

				}
				else if (n_btn3.isMouseOver(window))
				{

					std::cout << "Button 3 Pressed" << std::endl;

					std::string str = n_text2.getText();
					std::string str2;
					str2 = str;

					for (int i = 1; i < str2.length(); i++)
					{
						if (str2[i] == '\n' || str2[i] == '\r')
						{
							str2[i] = ' ';
						}
					}

					std::cout << str2 << std::endl;


				


				}


				break;


			}

			window.clear();

			window.draw(background1);
			window.draw(n_menu[1]);
			window.draw(n_menu[2]);

			n_text2.drawTo(window);

	
			n_btn3.drawTo(window);
			n_btn4.drawTo(window);

			window.draw(n_sprite1);
			window.draw(n_sprite2);
			
			window.display();
		}

	}


}

