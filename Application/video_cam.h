#pragma once
#include <iostream>
#include <WS2tcpip.h>
#include<WinSock2.h>
#include<sys/types.h>
#include<stdlib.h>

#include<opencv2/core/core.hpp>
#include<opencv2/highgui/highgui.hpp>
#include<opencv2/imgproc/imgproc.hpp>
#include<opencv2/video/background_segm.hpp>
#include<opencv2/video/tracking.hpp>
#include"audio.h"



#pragma warning(disable:4996)
#pragma comment(lib, "ws2_32.lib")
#define FRAME_WIDTH 640
#define FRAME_HEIGHT 480



class video_cam :public audio
{
private:
	int imgSize;
	int bytes;


	

	int teacher_V_Aport;
	int teacher_V_Bport;

	int Student_V_Aport;
	int Student_V_Bport;
	char key;


	static int flag;

	
public:

	std::string ip;
	cv::VideoCapture cap;
	video_cam();
	void show(int A);
	void camera(int B);

	void teacher_show_video();
	void teacher_camera_video();

	void student_show_video();
	void student_camera_video();







};

