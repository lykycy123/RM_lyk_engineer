#include <mineral.h>

void Mineral::detectlight(const Mat &operand,const Mat &preimage)
{
    if (initMineral())
    {
        //形态学操作+HSV颜色分离
        Mat dst(operand.size(), CV_8UC3);
        Morlight(operand, dst);

        Mat predst(preimage.size(), CV_8UC3);
        Morlight(preimage, predst);


        

    





    
    
    
    
    }
}