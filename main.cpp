#include <iostream>
#include <opencv2/opencv.hpp>
#include <opencv2/highgui/highgui.hpp>
#include "MorphoFeatures.h"


int main()
{
    cv::Mat image;
    image=cv::imread("find.jpg",CV_LOAD_IMAGE_GRAYSCALE);
    
    cv::Mat edges;
    cv::Mat corners;
    MorphoFeatures morpho;
    edges=morpho.getEdges(image);
    corners=morpho.getCorners(image);
    morpho.drawOnImage(corners,image);
    cv::imshow("corners",corners);
    cv::imshow("Corners on Image",image);
    cv::imshow("Edges",edges);
    
    cv::waitKey(0);
    return 0;
}