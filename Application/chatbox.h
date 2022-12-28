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


	FILE* fp;
	
   


public:


	int teacher_chat_portA;
	int teacher_chat_portB;
	int student_chat_portA;
	int student_chat_portB;
	sf::IpAddress ip;
	sf::TcpSocket localSocket1;

	sf::TcpSocket  localSocket2;



	int material_file_port_text = 7082;
	int material_file_receive_port = 7082;

	int course_file_port_csv = 1083;
	int course_file_receive_port = 1083;


	int syllabus_file_port_csv = 1084;
	int syllbus_file_receive_port = 1084;


	int notice_file_port_csv = 1086;
	int notice_file_receive_port = 1086;

	int teacher_file_port_csv = 1087;
	int teacher_file_receive_port = 1087;

	int student_file_port_csv = 1088;
	int student_file_receive_port = 1088;


	chatbox();

	void t_receiveClient();

	void t_sendClient();
	void s_receiveClient();

	void s_sendClient();

	void texting_mem(sf::RenderWindow& window);

	void send_file(FILE* fp, int sock);

	int file_network_send(std::string file_path,std::string filename, std::string extension,int port);

	void write_file_text(int sock, int cnt);
	void write_file_csv(int sock, int cnt);

	void file_receive_text();
	void file_receive_csv();
	void syllabus_receive_csv();
	void notice_receive_csv();



};

