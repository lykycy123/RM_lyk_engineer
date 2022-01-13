#include <mineral.h>


void Mineral::detectSold(const Mat &operand)
{
    if(initMineral())
    {
        //形态学操作+HSV颜色分离
        Mat dst(operand.size(), CV_8UC3);
        MorSold(operand, dst);

#ifdef DEBUG
        Mat BackGround = Mat::zeros(operand.size(), CV_8UC3);
        imshow("after Mor", dst);
        waitKey(1);
#endif

        //找轮廓
        getSoldContours(dst, BackGround);

        //对点集进行排序
        sortPointsVector(all_fit_points, X_INCREASE);

        target_points=all_fit_points;

        Number_yellow = target_points.size();


        //发送数据
        sendTarget();

        for (auto item : all_fit_points)
            circle(BackGround, item, 2, Scalar(0, 255, 0), 2);

        cout << "Number Yellow:" << Number_yellow << endl;
        imshow("result_sold", BackGround);
        waitKey(1);


    }
}