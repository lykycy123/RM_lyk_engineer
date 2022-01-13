#include <mineral.h>

void Mineral::detectlight(const Mat &operand,const Mat &preimage)
{
    if (initMineral())
    {

        //找到闪烁灯光
        Mat dst;
        getRightLight(operand,preimage,dst);


#ifdef DEBUG
        Mat BackGround = Mat::zeros(operand.size(), CV_8UC3);
        imshow("after Mor", dst);
        waitKey(1);
#endif

        //找轮廓
        getlightcontours(dst,BackGround);

        
        //对各矩形取中心点
        getFitPoints(all_fit_rects, all_fit_points);


        //对点集进行排序
        sortPointsVector(all_fit_points, X_INCREASE);

        Number_yellow=all_fit_points.size();

        target_points = all_fit_points;


        //发送数据
        sendTarget();


        
        //调试
        for (auto item : all_fit_points)
        circle(BackGround, item, 2, Scalar(0, 255, 0), 2);

        cout << "Number light:" << Number_yellow << endl;
        imshow("result_light", BackGround);
        waitKey(1);





    
    
    
    
    }
}