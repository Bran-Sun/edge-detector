//
// Created by 孙桢波 on 2017/1/18.
//

#ifndef EDGE_MORPHOFEATURES_H
#define EDGE_MORPHOFEATURES_H

#include <opencv2/opencv.hpp>


class MorphoFeatures
{
private:
    int threshold;
    cv::Mat_<uchar> cross;
    cv::Mat_<uchar> diamond;
    cv::Mat_<uchar> square;
    cv::Mat_<uchar> x;
public:
    MorphoFeatures();
    cv::Mat getCorners(const cv::Mat &image);
    void applyThreshold(cv::Mat &image);
    void drawOnImage(const cv::Mat &image,cv::Mat &result);
    void setThreshold(int t);
    cv::Mat getEdges(const cv::Mat &image);
};


#endif //EDGE_MORPHOFEATURES_H
