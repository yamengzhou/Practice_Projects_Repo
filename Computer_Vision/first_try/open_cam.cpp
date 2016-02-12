#include "opencv2/highgui/highgui.hpp"
#include <iostream>

using namespace cv;
using namespace std;

int main(int argc, char** argv){
	VideoCapture cap(0);

	if(!cap.isOpened()){
		cout << "Cannot open the video file" << endl;
		return -1;
	}

	double fps = cap.get(CV_CAP_PROP_FPS);

	namedWindow("Testing_Window",CV_WINDOW_NORMAL);

	while(1){
		Mat frame;

		bool bSuccess = cap.read(frame);

		if(!bSuccess){
			cout << "cannot read frames from camera" << endl;
			return -1;
		}

		imshow("Testing_Window",frame);

		if(waitKey(30)=='q'){
			cout << "esc key is pressed by user" << endl;
			break;
		}

	}

	return 0;

}