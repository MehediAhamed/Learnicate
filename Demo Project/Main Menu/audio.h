#pragma once
#include<SFML/Audio.hpp>
#include<SFML/Audio/Sound.hpp>
#include<SFML/Audio/SoundBufferRecorder.hpp>
#include<SFML/Network.hpp>
#include<SFML/Network/TcpListener.hpp>
#include<iostream>
#include<thread>

class audio
{
private:

	

	sf::TcpSocket localSocket1;

	sf::TcpSocket  localSocket2;
	int teacher_audio_portA;
	int teacher_audio_portB;
	int student_audio_portA;
	int student_audio_portB;

	
	sf::IpAddress ip ;

public:
	
	const sf::Uint8 serverAudioData = 1;
	const sf::Uint8 serverEndOfStream = 2;

	audio();
	void t_a_receiveClient();

	void t_a_sendClient();
	void s_a_receiveClient();

	void s_a_sendClient();


};

