#include "chatbox.h"


chatbox::chatbox()
{

	teacher_chat_portA = 6001;
	teacher_chat_portB = 6002;
	student_chat_portA = 6003;
	student_chat_portB = 6004;
}

/*void inputScreen(sf::RenderWindow& window)
{
	sf::Font font;
	if (!font.loadFromFile("Moon.ttf"))
	{
		inputScreen(window);
	}
	sf::Event event;
	sf::String Input;
	sf::Text Type_Text(" ", font, 56);

	Type_Text.setFillColor(sf::Color::Red);

	while (window.isOpen())
	{
		while (window.pollEvent(event))
		{

			if (event.type == sf::Event::TextEntered)
			{
				if (event.text.unicode < 128)
				{
					Input += event.text.unicode;
					Type_Text.setString(Input);
				}
			}
			window.draw(Type_Text);
		}
		window.display();
	}
}*/


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
			std::cout << "Message >> " << buff << std::endl;
		}







	}
}

void chatbox::t_sendClient()
{
	sf::Socket::Status status2 = localSocket2.connect(ip, teacher_chat_portB); //port b=6002




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


