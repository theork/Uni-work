/**
********************************************************************************
*
*	@file		medianFilter.cpp
*
*	@brief		A program to perform the median filter using OpenCV
*
*	@version	1.0
*
*	@date		20/01/2020
*
*	@author		Franck Vidal
*
*
********************************************************************************
*/


//******************************************************************************
//	Includes
//******************************************************************************
#include <cstdlib>   // Header for atoi and atof
#include <exception> // Header for catching exceptions
#include <iostream>  // Header to display text in the console
#include <opencv2/opencv.hpp> // Main OpenCV header


//******************************************************************************
//	Namespaces
//******************************************************************************
using namespace std;


//******************************************************************************
//	Global variables
//******************************************************************************


//******************************************************************************
//	Function declaration
//******************************************************************************


//******************************************************************************
//	Implementation
//******************************************************************************


//-----------------------------
int main(int argc, char** argv)
//-----------------------------
{
    try
    {
        // No file to display
        // No file to save
		std::string error_message;
        if (argc != 3 && argc != 4)
        {
            // Create an error message
            error_message  = "usage: ";
            error_message += argv[0];
            error_message += " <input_image>  <output_image> <kernel_radius>";

            // Throw an error
            throw error_message;
        }

        // Filter radius
        unsigned int radius(1);

        if (argc == 4)
        {
            radius = atoi(argv[3]);
			if (radius <= 0) {
				radius = 1;
			}
        }
    
        // Write your own code here
		string input_filename = argv[1];
		cv::Mat image = cv::imread(input_filename, CV_LOAD_IMAGE_COLOR);

		if (!image.data) {
			// Create an error message
			error_message = "couldn't open or find image ";
			error_message += input_filename;

			// Throw an error
			throw error_message;
		}

		string window_title;
		window_title = "Display Image ";
		window_title += input_filename;

		cv::namedWindow(window_title, cv::WINDOW_AUTOSIZE);
		cv::imshow(window_title, image);

		unsigned int ksize = (radius * 2) + 1;
		cv::Mat median_image;
		cv::medianBlur(image, median_image, ksize);

		window_title = "Display Median Image ";
		window_title += input_filename;
		cv::namedWindow(window_title, cv::WINDOW_AUTOSIZE);
		cv::imshow(window_title, median_image);

		if (!cv::imwrite(argv[2], median_image)) {
			error_message = "Couldn't write image ";
			error_message += argv[2];
			throw(error_message);
		}

		cv::waitKey(0);


    }
    // An error occured
    catch (const std::exception& error)
    {
        // Display an error message in the console
        cerr << error.what() << endl;
    }
    catch (const std::string& error)
    {
        // Display an error message in the console
        cerr << error << endl;
    }
    catch (const char* error)
    {
        // Display an error message in the console
        cerr << error << endl;
    }

    // Exit the program
    return 0;
}

