#include <iostream>
#include<vector>


#include "libusb.h"
#include <opencv2/core.hpp>
#include <opencv2/videoio.hpp>
#include <opencv2/highgui.hpp>
using namespace std;
using namespace cv;

libusb_context* context = NULL;
libusb_device_handle* dev_handle = NULL;
libusb_device** devs;


int main () {
	libusb_init(&context);
	int count = libusb_get_device_list (context, &devs);

	libusb_device* device = devs[1]; //index=1 for internal camera
	libusb_device_descriptor desc = { 0 };
	libusb_get_device_descriptor (device, &desc);
	cout << desc.idVendor << " " << desc.idProduct<<endl;

	libusb_close (dev_handle);
	libusb_exit (context);
	





}