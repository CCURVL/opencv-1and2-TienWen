#include <opencv2/opencv.hpp>
#include <vector>

using namespace std;
using namespace cv;

int HW01_TestFunction();
int HW02_ReadAndShowData(int numberOfImgs);

int main()
{
	HW01_TestFunction();

	waitKey(0);
	destroyAllWindows();

	HW02_ReadAndShowData(8);

	waitKey(0);
	return 0;
}

int HW01_TestFunction()
{
	vector<Mat> vArr;
	Mat img = imread("C:/Users/tw950/Desktop/opencv-1and2-TienWen/testImage/lena.jpg");
	vArr.push_back(img);

	Mat imgGray;
	cvtColor(img, imgGray, CV_BGR2GRAY);
	vArr.push_back(imgGray);

	Mat imgBin;
	threshold(imgGray, imgBin, 100.0, 255.0, THRESH_BINARY);
	vArr.push_back(imgBin);
	
	imshow("img", vArr[0]);
	imshow("imgGray", vArr[1]);
	imshow("imgBin", vArr[2]);

	moveWindow("img", 50, 50);
	moveWindow("imgGray", 350, 50);
	moveWindow("imgBin", 650, 50);

	waitKey(0);
	destroyAllWindows();
	return 0;
}

int HW02_ReadAndShowData(int numberOfImgs)
{
	vector<String> address;
	vector<Mat> imgs;
	vector<Mat> imgsGray;
	vector<Mat> imgsBin;

	address.push_back("C:/Users/tw950/Desktop/opencv-1and2-TienWen/testImage/capture/1.jpg");
	address.push_back("C:/Users/tw950/Desktop/opencv-1and2-TienWen/testImage/capture/2.jpg");
	address.push_back("C:/Users/tw950/Desktop/opencv-1and2-TienWen/testImage/capture/3.jpg");
	address.push_back("C:/Users/tw950/Desktop/opencv-1and2-TienWen/testImage/capture/4.jpg");
	address.push_back("C:/Users/tw950/Desktop/opencv-1and2-TienWen/testImage/capture/5.jpg");
	address.push_back("C:/Users/tw950/Desktop/opencv-1and2-TienWen/testImage/capture/6.jpg");
	address.push_back("C:/Users/tw950/Desktop/opencv-1and2-TienWen/testImage/capture/7.jpg");
	address.push_back("C:/Users/tw950/Desktop/opencv-1and2-TienWen/testImage/capture/8.jpg");

	for (int i = 0; i < numberOfImgs; i++)
	{
		Mat img = imread(address[i]);
		imgs.push_back(img);

		Mat imgGray;
		cvtColor(img, imgGray, CV_BGR2GRAY);
		imgsGray.push_back(imgGray);

		Mat imgBin;
		threshold(imgGray, imgBin, 100.0, 255.0, THRESH_BINARY);
		imgsBin.push_back(imgBin);
	}

	for (int i = 0; i < numberOfImgs; i++)
	{
		imshow("img", imgs[i]);
		imshow("imgGray", imgsGray[i]);
		imshow("imgBin", imgsBin[i]);

		moveWindow("img", 50, 50);
		moveWindow("imgGray", 350, 50);
		moveWindow("imgBin", 650, 50);

		waitKey(0);
		destroyAllWindows();
	}
	return 0;
}





