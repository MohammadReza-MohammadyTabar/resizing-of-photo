#include <iostream>
#include <opencv2\opencv.hpp>
#include <opencv2\highgui\highgui.hpp>
#include <string>
#include <conio.h>


using namespace cv;
using namespace std;
Mat im;
void resize()
{
	double h, w;
	cout << "width :";
	cin >> w;
	cout << '\n' << "hight :";
	cin >> h;
	cout << endl;
	Size s = im.size();
	w = w / s.width;
	h = h / s.height;

	resize(im, im, Size(), w, h);
	imshow("Image", im);
}
int main()
{
	string st = "";
	cout << "Please enter file address :";
	getline(cin, st);
	if (st.empty() != 1) {
		im = imread(st.c_str(), IMREAD_COLOR);
		if (im.empty()) {
			cout << "There is no image !";
			getchar();
			return -1;

		}
		namedWindow("image", WINDOW_NORMAL);
		imshow("image", im);
		resize();
	}
	else
		cout << " There is no address !";
	waitKey(0);
	return 0;



}