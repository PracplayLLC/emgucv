//----------------------------------------------------------------------------
//
//  Copyright (C) 2004-2013 by EMGU. All rights reserved.
//
//----------------------------------------------------------------------------

#pragma once
#ifndef EMGU_IMGPROC_C_H
#define EMGU_IMGPROC_C_H

#include "opencv2/core/core_c.h"
#include "opencv2/imgproc/imgproc.hpp"
#include "opencv2/imgproc/types_c.h"
//#include "opencv2/calib3d/calib3d.hpp"
#include "emgu_c.h"
CVAPI(IplImage*) cvGetImageSubRect(IplImage* image, CvRect* rect);

//GrabCut
CVAPI(void) cveGrabCut(cv::_InputArray* img, cv::_InputOutputArray* mask, cv::Rect* rect, cv::_InputOutputArray* bgdModel, cv::_InputOutputArray* fgdModel, int iterCount, int flag);

CVAPI(void) cveFilter2D(cv::_InputArray* src, cv::_OutputArray* dst, cv::_InputArray* kernel, CvPoint* anchor, double delta, int borderType );

CVAPI(void) cveCLAHE(cv::_InputArray* src, double clipLimit, emgu::size* tileGridSize, cv::_OutputArray* dst);

//CVAPI(void) cveAdaptiveBilateralFilter(cv::_InputArray* src, cv::_OutputArray* dst, emgu::size* ksize, double sigmaSpace, double maxSigmaColor, CvPoint* anchor, int borderType);

CVAPI(void) cveErode(cv::_InputArray* src, cv::_OutputArray* dst, cv::_InputArray* kernel, CvPoint* anchor, int iterations, int borderType, CvScalar* borderValue);

CVAPI(void) cveDilate(cv::_InputArray* src, cv::_OutputArray* dst, cv::_InputArray* kernel, CvPoint* anchor, int iterations, int borderType, CvScalar* borderValue);
CVAPI(void) cveGetStructuringElement(cv::Mat* mat, int shape, emgu::size* ksize, CvPoint* anchor);
CVAPI(void) cveMorphologyEx(cv::_InputArray* src, cv::_OutputArray* dst, int op, cv::_InputArray* kernel, CvPoint* anchor, int iterations, int borderType, CvScalar* borderValue);

CVAPI(void) cveSobel(cv::_InputArray* src, cv::_OutputArray* dst, int ddepth, int dx, int dy, int ksize, double scale, double delta, int borderType);
CVAPI(void) cveLaplacian(cv::_InputArray* src, cv::_OutputArray* dst, int ddepth, int ksize, double scale, double delta, int borderType);
CVAPI(void) cvePyrUp(cv::_InputArray* src, cv::_OutputArray* dst, emgu::size* size, int borderType);
CVAPI(void) cvePyrDown(cv::_InputArray* src, cv::_OutputArray* dst, emgu::size* size, int borderType);

CVAPI(void) cveCanny(cv::_InputArray* image, cv::_OutputArray* edges, double threshold1, double threshold2, int apertureSize, bool L2gradient);
CVAPI(void) cveCornerHarris(cv::_InputArray* src, cv::_OutputArray* dst, int blockSize, int ksize, double k, int borderType);
CVAPI(double) cveThreshold(cv::_InputArray* src, cv::_OutputArray* dst, double thresh, double maxval, int type);
CVAPI(void) cveWatershed(cv::_InputArray* image, cv::_InputOutputArray* markers);
CVAPI(void) cveAdaptiveThreshold(cv::_InputArray* src, cv::_OutputArray* dst, double maxValue, int adaptiveMethod, int thresholdType, int blockSize, double c);
CVAPI(void) cveCvtColor(cv::_InputArray* src, cv::_OutputArray* dst, int code, int dstCn);
CVAPI(void) cveCopyMakeBorder(cv::_InputArray* src, cv::_OutputArray* dst, int top, int bottom, int left, int right, int borderType, CvScalar* value);

CVAPI(void) cveIntegral(cv::_InputArray* src, cv::_OutputArray* sum, cv::_OutputArray* sqsum, cv::_OutputArray* tilted, int sdepth, int sqdepth);
CVAPI(int) cveFloodFill(cv::_InputOutputArray* image, cv::_InputOutputArray* mask, CvPoint* seedPoint, CvScalar* newVal, CvRect* rect, CvScalar* loDiff, CvScalar* upDiff, int flags);
CVAPI(void) cvePyrMeanShiftFiltering(cv::_InputArray* src, cv::_OutputArray* dst, double sp, double sr, int maxLevel, CvTermCriteria* termCrit);

CVAPI(void) cveMoments(cv::_InputArray* arr, bool binaryImage, CvMoments* moments);

CVAPI(void) cveEqualizeHist(cv::_InputArray* src, cv::_OutputArray* dst);

CVAPI(void) cveAccumulate(cv::_InputArray* src, cv::_InputOutputArray* dst, cv::_InputArray* mask);
CVAPI(void) cveAccumulateSquare(cv::_InputArray* src, cv::_InputOutputArray* dst, cv::_InputArray* mask);
CVAPI(void) cveAccumulateProduct(cv::_InputArray* src1, cv::_InputArray* src2, cv::_InputOutputArray* dst, cv::_InputArray* mask);
CVAPI(void) cveAccumulateWeighted(cv::_InputArray* src, cv::_InputOutputArray* dst, double alpha, cv::_InputArray* mask);
CVAPI(void) cvePhaseCorrelate(cv::_InputArray* src1, cv::_InputArray* src2, cv::_InputArray* window, double* response, CvPoint2D64f* result);
CVAPI(void) cveCreateHanningWindow(cv::_OutputArray* dst, CvSize* winSize, int type);

CVAPI(void) cveResize(cv::_InputArray* src, cv::_OutputArray* dst, CvSize* dsize, double fx, double fy, int interpolation);
CVAPI(void) cveWarpAffine(cv::_InputArray* src, cv::_OutputArray* dst, cv::_InputArray* m, CvSize* dsize, int flags, int borderMode, CvScalar* borderValue);
CVAPI(void) cveWarpPerspective(cv::_InputArray* src, cv::_OutputArray* dst, cv::_InputArray* m, CvSize* dsize, int flags, int borderMode, CvScalar* borderValue);

CVAPI(void) cveLogPolar(cv::_InputArray* src, cv::_OutputArray* dst, CvPoint2D32f* center, double M, int flags);
CVAPI(void) cveLinearPolar(cv::_InputArray* src, cv::_OutputArray* dst, CvPoint2D32f* center, double maxRadius, int flags);
CVAPI(void) cveRemap(cv::_InputArray* src, cv::_OutputArray* dst, cv::_InputArray* map1, cv::_InputArray* map2, int interpolation, int borderMode, CvScalar* borderValue);
CVAPI(void) cveRepeat(cv::_InputArray* src, int ny, int nx, cv::_OutputArray* dst);
CVAPI(void) cveHoughCircles(cv::_InputArray* image, cv::_OutputArray* circles, int method, double dp, double minDist, double param1, double param2, int minRadius, int maxRadius);
CVAPI(void) cveHoughLines(cv::_InputArray* image, cv::_OutputArray* lines, double rho, double theta, int threshold, double srn, double stn);
CVAPI(void) cveHoughLinesP(cv::_InputArray* image, cv::_OutputArray* lines, double rho, double theta, int threshold, double minLineLength, double maxGap);

CVAPI(void) cveMatchTemplate(cv::_InputArray* image, cv::_InputArray* templ, cv::_OutputArray* result, int method);
CVAPI(void) cveCornerSubPix(cv::_InputArray* image, cv::_InputOutputArray* corners, CvSize* winSize, CvSize* zeroZone, CvTermCriteria* criteria);

CVAPI(void) cveConvertMaps(cv::_InputArray* map1, cv::_InputArray* map2, cv::_OutputArray* dstmap1, cv::_OutputArray* dstmap2, int dstmap1Type, bool nninterpolation);
CVAPI(void) cveInitUndistortRectifyMap(cv::_InputArray* cameraMatrix, cv::_InputArray* distCoeffs, cv::_InputArray* r, cv::_InputArray* newCameraMatrix, CvSize* size, int m1type, cv::_OutputArray* map1, cv::_OutputArray* map2);
CVAPI(void) cveUndistort(cv::_InputArray* src, cv::_OutputArray* dst, cv::_InputArray* cameraMatrix, cv::_InputArray* distorCoeffs, cv::_InputArray* newCameraMatrix);
CVAPI(void) cveUndistortPoints(cv::_InputArray* src, cv::_OutputArray* dst, cv::_InputArray* cameraMatrix, cv::_InputArray* distCoeffs, cv::_InputArray* r, cv::_InputArray* p);

CVAPI(void) cveInvertAffineTransform(cv::_InputArray* m, cv::_OutputArray* im);
CVAPI(void) cveGetDefaultNewCameraMatrix(cv::_InputArray* cameraMatrix, CvSize* imgsize, bool centerPrincipalPoint, cv::Mat* cm);

CVAPI(void) cveEMD(cv::_InputArray* signature1, cv::_InputArray* signature2, int distType, cv::_InputArray* cost, float* lowerBound, cv::_OutputArray* flow);

CVAPI(void) cveCalcHist( cv::_InputArray* images, const std::vector<int>* channels, cv::_InputArray* mask, cv::_OutputArray* hist, std::vector<int>* histSize, std::vector<float>* ranges, bool accumulate );
CVAPI(void) cveCalcBackProject(cv::_InputArray* images, const std::vector<int>* channels, cv::_InputArray* hist, cv::_OutputArray* dst, const std::vector<float>* ranges, double scale );
CVAPI(double) cveCompareHist(cv::_InputArray* h1, cv::_InputArray* h2, int method);

CVAPI(void) cveGetRotationMatrix2D(CvPoint2D32f* center, double angle, double scale, cv::_OutputArray* rotationMatrix2D);

#endif
