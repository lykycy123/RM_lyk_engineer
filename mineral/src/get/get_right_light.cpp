#include<mineral.h>

void Mineral::getRightLight(const Mat &operand,const Mat &preimage,const Mat output)
{
        //形态学操作+HSV颜色分离
        Mat dst(operand.size(), CV_8UC3);
        Morlight(operand, dst);

        Mat predst(preimage.size(), CV_8UC3);
        Morlight(preimage, predst);

        absdiff(dst,predst,output);

        

}