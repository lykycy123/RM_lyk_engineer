#include <mineral.h>

void Mineral::Morlight(const Mat &operand, Mat &output) const
{
    vector<Mat> hsvSplit;
    cvtColor(operand, output, COLOR_BGR2HSV);
    split(output, hsvSplit);
    equalizeHist(hsvSplit[2], hsvSplit[2]);
    merge(hsvSplit, output);

    //形态学操作，有改进的空间，可以调这部分
    Mat kernel = getStructuringElement(MORPH_RECT, Size(3, 3));
    GaussianBlur(output, output, Size(5, 5), 3, 3);
    inRange(output, Scalar(0, 0, 221), Scalar(180, 30, 255), output); //全距离
    erode(output, output, kernel);
    erode(output, output, kernel);
    dilate(output, output, kernel);
}