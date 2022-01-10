#include <iostream>
#include <vector>
#include <opencv2/opencv.hpp>
#include <rmserial.h>
#include <uvc_v4l2.h>

#define capture_index 0
#define use_cam 1
#define use_VideoCapture 1

#define DEBUG
#define __DEBUG__WRITER



#define SOLD_AUTO_RUN 1   //兑换站
#define SMALL_RESOURCE_ISLAND_AUTO_RUN 2  //小资源岛自动对位模式
#define BIG_RESOURCE_ISLAND_AUTO_RUN_MODE1 3    //大资源岛：落下矿石
#define BIG_RESOURCE_ISLAND_AUTO_RUN_MODE2_DIRECTION 4  //大资源岛:闪灯方向
#define BIG_RESOURCE_ISLAND_AUTO_RUN_MODE2_ADJUSTMENT 5   //大资源岛：空接+精调
#define FREE_MODE 6
