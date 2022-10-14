#pragma once
#include<SFML/Audio.hpp>
#include<SFML/Audio/Sound.hpp>
#include<SFML/Audio/SoundBufferRecorder.hpp>
#include<SFML/Network.hpp>
#include<SFML/Network/TcpListener.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include<iostream>
#include<thread>
#include <string>





class chatbox
{
private:



	sf::TcpSocket localSocket1;

	sf::TcpSocket  localSocket2;
	int teacher_chat_portA;
	int teacher_chat_portB;
	int student_chat_portA;
	int student_chat_portB;
	sf::IpAddress ip;

public:

	
	chatbox();
	void t_receiveClient();

	void t_sendClient();
	void s_receiveClient();

	void s_sendClient();




};

