//
// Created by 孙桢波 on 2017/1/18.
//

#include "MorphoFeatures.h"

MorphoFeatures::MorphoFeatures()
        : threshold(30), cross(5, 5), diamond(5, 5), square(5, 5), x(5, 5)
{
    cross <<
            0, 0, 1, 0, 0,
            0, 0, 1, 0, 0,
            1, 1, 1, 1, 1,
            0, 0, 1, 0, 0;
    diamond <<
            0, 0, 1, 0, 0,
            0, 1, 0, 1, 0,
            1, 0, 0, 0, 1,
            0, 1, 0, 1, 0,
            0, 0, 1, 0, 0;
    square <<
            1, 1, 1, 1, 1,
            1, 0, 0, 0, 1,
            1, 0, 0, 0, 1,
            1, 0, 0, 0, 1,
            1, 1, 1, 1, 1;
    x <<
            1, 0, 0, 0, 1,
            0, 1, 0, 1, 0,
            0, 0, 1, 0, 0,
            0, 1, 0, 1, 0,
            1, 0, 0, 0, 1;
};


cv::Mat MorphoFeatures::getCorners(const cv::Mat &image)
{
    cv::Mat result;
    cv::dilate(image,result,cross);
    cv::erode(result,result,diamond);
    cv::Mat result2;
    cv::dilate(image,result2,x);
    cv::erode(result2,result2,square);
    cv::absdiff(result2,result,result);
    applyThreshold(result);
    return result;
    
}

void MorphoFeatures::applyThreshold(cv::Mat &image)
{
    cv::threshold(image,image,threshold,255,cv::THRESH_BINARY_INV);
}

void MorphoFeatures::drawOnImage(const cv::Mat &image, cv::Mat &result)
{
    cv::Mat_<uchar>::const_iterator it=image.begin<uchar>();
    cv::Mat_<uchar>::const_iterator itend=image.end<uchar>();
    
    for (int i=0;it != itend;i++,it++)
    {
        if (!*it)
            circle(result,cv::Point(i%result.step,i/result.step),5,cv::Scalar(255,0,0));
    }
}

void MorphoFeatures::setThreshold(int t)
{
    threshold=t;
}

cv::Mat MorphoFeatures::getEdges(const cv::Mat &image)
{
    cv::Mat result;
    cv::morphologyEx(image,result,cv::MORPH_GRADIENT,cv::Mat());
    cv::threshold(result,result,threshold,255,cv::THRESH_BINARY);
    return result;
}