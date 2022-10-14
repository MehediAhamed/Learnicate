#include "video_cam.h"
#include"teacher_menu.h"

video_cam::video_cam()
{

	bytes = 0;
	ip = "127.0.0.1";

	teacher_V_Aport = 8001;
	teacher_V_Bport = 8002;

	Student_V_Aport = 8003;
	Student_V_Bport = 8004;
}
int video_cam::camera(int B)
{
	cv::VideoCapture cap(0);

	cv::Mat cameraFeed;

	int height, width, IM_HEIGHT, IM_WIDTH, imgSize;



	int port = B;


	//initilize winsock
	WSADATA wsData;
	WORD ver = MAKEWORD(2, 2);

	int wsok = WSAStartup(ver, &wsData);

	if (wsok != 0)
	{
		std::cerr << "Can't Initilize winsock! Quitting" << std::endl;
		return 0;

	}
	// Create socket
	SOCKET sock = socket(AF_INET, SOCK_STREAM, 0);
	if (sock == INVALID_SOCKET)
	{
		std::cerr << "Can't create socket, Err #" << WSAGetLastError() << std::endl;
		WSACleanup();
		//return;
	}
	//Bind the socket to an ip address and port to a socket
	SOCKADDR_IN hint;
	hint.sin_family = AF_INET;
	hint.sin_port = htons(port);


	inet_pton(AF_INET, ip.c_str(), &(hint.sin_addr));




	// Connect to server
	int connResult = connect(sock, (sockaddr*)&hint, sizeof(hint));
	while (connResult == SOCKET_ERROR)
	{
		std::cerr << "Can't connect to server, Err #" << WSAGetLastError() << std::endl;
		connResult = connect(sock, (sockaddr*)&hint, sizeof(hint));
		if (connResult != SOCKET_ERROR)
			break;

	}
	std::cerr << "connected to server" << std::endl;




	//display



	cv::Mat img, imgGray;
	img = cv::Mat::zeros(480,640, CV_8UC3);
	//make it continuous
	if (!img.isContinuous()) {
		img = img.clone();
	}

	imgSize = img.total() * img.elemSize();
	bytes = 0;



	//make img continuos
	if (!img.isContinuous()) {
		img = img.clone();
		imgGray = img.clone();
	}

	std::cout << "Image Size:" << imgSize << std::endl;

	while (1) {

		/* get a frame from camera */
		cap >> img;

		//send processed image
		if ((bytes = send(sock, (const char*)img.data, imgSize, 0)) < 0) {
			std::cerr << "bytes = " << bytes << std::endl;
			break;
		}
	}
	//return img.data;






	while (1)
	{
		cv::Mat frame, image;
		if (!cap.read(cameraFeed))
		{
			std::cout << "Video Ended" << std::endl;
			break;
		}
	}

	height = cameraFeed.rows;
	width = cameraFeed.cols;
	IM_HEIGHT = FRAME_HEIGHT;
	IM_WIDTH = FRAME_WIDTH;

	

	resize(cameraFeed, cameraFeed, cv::Size(IM_WIDTH, IM_HEIGHT));
	imgSize = cameraFeed.total() * cameraFeed.elemSize();
	send(sock, reinterpret_cast<const char*> (cameraFeed.data), imgSize, 0);

	imshow("Server", cameraFeed);
	if (cv::waitKey() == 27)
	{
		closesocket(sock);
		std::cout << "Client disconnected" << std::endl;
		system("cls");

		return 0;
	}

	return 0;


}













int video_cam::show(int A)
{


	int port = A;						// Listening port # on the server

	// Initialize WinSock
	WSAData data;
	WORD ver = MAKEWORD(2, 2);
	int wsResult = WSAStartup(ver, &data);
	if (wsResult != 0)
	{
		std::cerr << "Can't start Winsock, Err #" << wsResult << std::endl;
		//return;
	}

	// Create socket
	SOCKET sock = socket(AF_INET, SOCK_STREAM, 0);
	if (sock == INVALID_SOCKET)
	{
		std::cerr << "Can't create socket, Err #" << WSAGetLastError() << std::endl;
		WSACleanup();
		//return;
	}

	// Fill in a hint structure
	sockaddr_in hint;
	hint.sin_family = AF_INET;
	hint.sin_port = htons(port);
	inet_pton(AF_INET, ip.c_str(), &hint.sin_addr);

	// Connect to server
	int connResult = connect(sock, (sockaddr*)&hint, sizeof(hint));
	while (connResult == SOCKET_ERROR)
	{
		std::cerr << "Can't connect to server, Err #" << WSAGetLastError() << std::endl;
		connResult = connect(sock, (sockaddr*)&hint, sizeof(hint));
		if (connResult != SOCKET_ERROR)
			break;

	}
	std::cerr << "connected to server" << std::endl;


	cv::Mat img;

	img = cv::Mat::zeros(480, 640, CV_8UC3);
	int imgSize = img.total() * img.elemSize();
	uchar* iptr = img.data;
	int bytes = 0;
	int bytesAud = 0;


	//make img continuos
	if (!img.isContinuous()) {
		img = img.clone();
	}

	std::cout << "Image Size:" << imgSize << std::endl;


	//cv::namedWindow("CV Video Client", 1);



	while (1) {
		/*if (key == 'q' || key==27)
		{
			teacher_menu t2();
		}*/

		if ((bytes = recv(sock, (char*)iptr, imgSize, MSG_WAITALL)) == -1) {
			std::cerr << "recv failed, received bytes = " << bytes << std::endl;

		}

		cv::imshow("Video", img);

		if (key = cv::waitKey(5) >= 0)
		{
			system("cls");
			break;
		}




	}

	closesocket(sock);

	return 0;
}

void video_cam::teacher_show_video()
{
	show(teacher_V_Aport);
}

void video_cam::teacher_camera_video()
{
	camera(teacher_V_Bport);
}

void video_cam::student_show_video()
{
	show(Student_V_Aport);
}

void video_cam::student_camera_video()
{
	camera(Student_V_Bport);
}
























