//readRGBD benchmark files 

#include <fstream>
#include <sstream>
#include <vector>
#include <string>
#include <iostream>
#include <opencv2/highgui/highgui.hpp>  //read data
#include <opencv2/core/core.hpp>   //Basic OpenCV structures (cv::Mat, Scalar)

using namespace std;
using namespace cv;


struct RGBDFile {

    double rgb_timestamp;
    string rgb_frame;
    double depth_timestamp;
    string depth_frame;
};

vector<RGBDFile> RGBDFileInfo;

void readRGBDdata(string filename)
{

    string line, word;


    fstream fin;

    fin.open(filename);

    if(!fin)
    {
        cout<<"cannot open the file"<<endl;
    }
    else
    {
        cout<<"file is open"<<endl;
    }

    istringstream istr;

    string str;

    while(getline(fin, line))
    {
       RGBDFile fileInfo;
       istringstream record(line); //bind record to the line we just read
       record >> fileInfo.rgb_timestamp; //read the name
       record >> fileInfo.rgb_frame;
       record >> fileInfo.depth_timestamp;
       record >> fileInfo.depth_frame;
       RGBDFileInfo.push_back(fileInfo);

    }

    fin.close();

}


int main()
{
    readRGBDdata("/home/lili/workspace/SLAM/src/rgbd_dataset_freiburg1_desk2/associatedData.txt");

    int frame_index = 0;

    cout<<RGBDFileInfo.size()<<endl;

    while(frame_index<RGBDFileInfo.size())
    {
        Mat rgb_frame=imread(RGBDFileInfo[frame_index].rgb_frame, 1);
        Mat depth_frame=imread(RGBDFileInfo[frame_index].depth_frame, -1);

        if(!rgb_frame.data )                              // Check for invalid input
        {
            cout <<  "Could not open or find the image" << std::endl ;
            return -1;
        }

        namedWindow( "RGB", WINDOW_AUTOSIZE );// Create a window for display.
        cv::imshow("RGB", rgb_frame);
        cv::imshow("Depth", depth_frame);

        char key = cv::waitKey(1);

        if(key == 'q')
        {
            break;
        }
        else if(key == ' ')
        {
            key = cv::waitKey(0);
        }

        frame_index++;
    }

    return 0;


}
