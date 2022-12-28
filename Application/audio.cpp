#include "audio.h"
#pragma once


audio::audio()
{

	ip = "192.168.110.54";
	teacher_audio_portA = 16601;
	teacher_audio_portB = 16602;
	student_audio_portA = 16603;
	student_audio_portB = 16604;
}




void audio::t_a_receiveClient()
{


	sf::Socket::Status status1 = localSocket1.connect(ip, teacher_audio_portA);  //portA=6601

	while (status1 != sf::Socket::Done)
	{
		std::cout << "Connecting to socket1..." << std::endl;
		sf::Socket::Status status = localSocket1.connect(ip, teacher_audio_portA);
		if (status == sf::Socket::Done)
		{
			std::cout << "Connected to socket1!!!" << std::endl;
			system("cls");
			break;
		}

	}



	while (1)
	{


		sf::Uint8 id;
		std::vector<sf::Int16> m_samples;

		const sf::Int16* samples;
		sf::SoundBuffer buffer;
		sf::Packet packet1, packet2;

		//recieve


		sf::SoundBuffer b1;
		sf::Sound g;
		if (localSocket1.receive(packet1) != sf::Socket::Done)
		{
			std::cout << "Audio wasn't recieved" << std::endl;

		}


		std::size_t sCount = (packet1.getDataSize() - 1) / sizeof(sf::Int16);

		packet1 >> id;

		if (id == 1 || id == 2)
		{

			std::cout << "Playing Audio from client" << std::endl;
			// Extract audio samples from the packet, and append it to our samples buffer
			std::size_t sampleCount = (packet1.getDataSize() - 1) / sizeof(sf::Int16);


			std::cout << sampleCount << std::endl;


			if (sampleCount > 200000)
				continue;

			std::size_t oldSize = m_samples.size();
			m_samples.resize(oldSize + sampleCount);





			std::memcpy(&(m_samples[oldSize]), static_cast<const char*>(packet1.getData()) + 1, sampleCount * sizeof(sf::Int16));


			b1.loadFromSamples(m_samples.data(), sCount, 1, 44100);

			g.setBuffer(b1);


			g.setVolume(100);
			g.play();

			sf::sleep(sf::microseconds(b1.getSampleCount() * 25));


			g.stop();

		}

	}
}

void audio::t_a_sendClient()
{

	sf::Socket::Status status2 = localSocket2.connect(ip, teacher_audio_portB); //port b=6602




	while (status2 != sf::Socket::Done)
	{
		std::cout << "Connecting to socket2..." << std::endl;
		sf::Socket::Status status2 = localSocket2.connect(ip, teacher_audio_portB);
		if (status2 == sf::Socket::Done)
		{
			std::cout << "Connected to socket2!!!" << std::endl;
			system("cls");
			break;
		}

	}



	while (1)
	{


		const sf::Int16* samples;
		sf::SoundBuffer buffer;
		sf::Packet packet2;



		// create the recorder
		sf::SoundBufferRecorder recorder;

		std::vector<std::string> availableDevices = sf::SoundRecorder::getAvailableDevices();

		// choose a device
		std::string inputDevice = availableDevices[0];

		if (!recorder.setDevice(inputDevice))
		{
			std::cerr << "Recorder not available" << std::endl;
		}

		if (!recorder.start(44100))
		{
			std::cerr << "Failed to start recorder" << std::endl;
			continue;
		}


		std::cout << "Recording... press enter to stop" << std::endl;

		sf::sleep(sf::milliseconds(1400));

		recorder.stop();



		buffer = recorder.getBuffer();


		samples = buffer.getSamples();
		std::size_t sampleCount = buffer.getSampleCount();


		packet2 << serverAudioData;
		packet2.append(samples, sampleCount * sizeof(sf::Int16));



		// Send the audio packet to the server
		if (localSocket2.send(packet2) != sf::Socket::Done)
		{

			std::cerr << "Failed to send end-of-stream packet" << std::endl;

		}


	}


}



void audio::s_a_receiveClient()
{


	sf::Socket::Status status1 = localSocket1.connect(ip, student_audio_portA);  //portA=6603

	while (status1 != sf::Socket::Done)
	{
		std::cout << "Connecting to socket1..." << std::endl;
		sf::Socket::Status status = localSocket1.connect(ip, student_audio_portA);
		if (status == sf::Socket::Done)
		{
			std::cout << "Connected to socket1!!!" << std::endl;
			system("cls");
			break;
		}

	}



	while (1)
	{


		sf::Uint8 id;
		std::vector<sf::Int16> m_samples;

		const sf::Int16* samples;
		sf::SoundBuffer buffer;
		sf::Packet packet1, packet2;

		//recieve


		sf::SoundBuffer b1;
		sf::Sound g;
		if (localSocket1.receive(packet1) != sf::Socket::Done)
		{
			std::cout << "Audio wasn't recieved" << std::endl;

		}


		std::size_t sCount = (packet1.getDataSize() - 1) / sizeof(sf::Int16);

		packet1 >> id;

		if (id == 1 || id == 2)
		{

			std::cout << "Playing Audio from client" << std::endl;
			// Extract audio samples from the packet, and append it to our samples buffer
			std::size_t sampleCount = (packet1.getDataSize() - 1) / sizeof(sf::Int16);


			std::cout << sampleCount << std::endl;


			if (sampleCount > 200000)
				continue;

			std::size_t oldSize = m_samples.size();
			m_samples.resize(oldSize + sampleCount);





			std::memcpy(&(m_samples[oldSize]), static_cast<const char*>(packet1.getData()) + 1, sampleCount * sizeof(sf::Int16));


			b1.loadFromSamples(m_samples.data(), sCount, 1, 44100);

			g.setBuffer(b1);


			g.setVolume(300);
			g.play();

			sf::sleep(sf::microseconds(b1.getSampleCount() * 25));


			g.stop();

		}

	}
}

void audio::s_a_sendClient()
{



	sf::Socket::Status status2 = localSocket2.connect(ip, student_audio_portB); //port b=6604




	while (status2 != sf::Socket::Done)
	{
		std::cout << "Connecting to socket2..." << std::endl;
		sf::Socket::Status status2 = localSocket2.connect(ip, student_audio_portB);
		if (status2 == sf::Socket::Done)
		{
			std::cout << "Connected to socket2!!!" << std::endl;
			system("cls");
			break;
		}

	}



	while (1)
	{

		const sf::Int16* samples;
		sf::SoundBuffer buffer;
		sf::Packet packet2;



		// create the recorder
		sf::SoundBufferRecorder recorder;



		std::vector<std::string> availableDevices = sf::SoundRecorder::getAvailableDevices();

		// choose a device
		std::string inputDevice = availableDevices[0];

		if (!recorder.setDevice(inputDevice))
		{
			std::cerr << "Recorder not available" << std::endl;
		}

		if (!recorder.start(44100))
		{
			std::cerr << "Failed to start recorder" << std::endl;
			continue;
		}


		std::cout << "Recording... press enter to stop" << std::endl;

		sf::sleep(sf::milliseconds(1400));

		recorder.stop();



		buffer = recorder.getBuffer();


		samples = buffer.getSamples();
		std::size_t sampleCount = buffer.getSampleCount();


		packet2 << serverAudioData;
		packet2.append(samples, sampleCount * sizeof(sf::Int16));



		// Send the audio packet to the server
		if (localSocket2.send(packet2) != sf::Socket::Done)
		{

			std::cerr << "Failed to send end-of-stream packet" << std::endl;

		}


	}


}
