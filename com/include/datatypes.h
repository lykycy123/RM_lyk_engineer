#ifndef H_RM_SERIAL_DATA_TYPES
#define H_RM_SERIAL_DATA_TYPES
#include <stdint.h>
#pragma pack(push, 1)       //????

//*************************************************************************
//**
//         **         **         **          **          **
//      ********** ********** ********** *********** ***********
//      *        * *        * *        * *         * *         *
//      *        * *        * *        * *         * *         *
//从左到右分别是1-5号矿石（不论红方蓝方）

//发出去的结构体
typedef struct _SendData {
    uint8_t start_flag;                         //帧头是‘s’
    uint16_t error_x;                           //矿石中间点和图像中心点（车正中心）的偏差
    uint8_t direction_x;                        //‘l’表示在图像视野左侧，‘r’表示图像在视野右侧,'o'用于灯光对位
    uint8_t is_error_data;                      //标志本次是否为错误数据
    uint8_t is_standard;                        //图像x方向是否对齐（线是否水平)
    uint8_t end_flag;                           //帧尾是‘e’
} SendData;
#define BARRICADE_AUTO_RUN 1
#define BIG_RESOURCE_ISLAND_AUTO_RUN 2
#define SMALL_RESOURCE_ISLAND_AUTO 3
#define Engineer_TYPE 4
//接受的数据类型

#define MCU_PAN_TYPE 0
#define MCU_CONFIG_TYPE 1
#define MCU_ENERGY_TYPE 2
#define MCU_SPEED_TYPE 3

typedef struct _McuData {
    uint8_t start_flag;
    uint8_t type;
    uint8_t start;
    uint8_t end_flag;
} McuData;

typedef struct _PanData {
    uint8_t start_flag;
    uint8_t type;
    float yaw;
    float pitch;
    uint8_t end_flag;
} PanData;

typedef struct _ConfigData {
    uint8_t start_flag;
    uint8_t type;
    uint8_t state;
    uint8_t anti_top;
    uint8_t enemy_color;
    uint8_t empty_buff[5];
    uint8_t end_flag;
} ConfigData;

typedef struct _EnergyData {
    uint8_t start_flag;
    uint8_t type;
    int delta_x;
    int delta_y;
    uint8_t end_flag;
} EnergyData;

typedef struct _SpeedData {
    uint8_t start_flag;
    uint8_t type;
    float speed;
    float empty_buff;
    uint8_t end_flag;
} SpeedData;

typedef struct _MineralData{
    uint8_t start_flag;
    uint8_t type;
    uint8_t start;
    uint8_t end_flag;
}MineralData;
#pragma pack(pop)

McuData generatePanMcuData(float yaw, float pitch);
McuData generateConfigMcuData(uint8_t state, uint8_t anti_top,
                              uint8_t enemy_color);
McuData generateEnergyMcuData(int delta_x, int delta_y);
McuData generateSpeedMcuData(float speed);

void readPanMcuData(McuData* data, float* yaw, float* pitch);
void readConfigMcuData(McuData* data, uint8_t* state, uint8_t* anti_top,
                       uint8_t* enemy_color);
void readEnergyMcuData(McuData* data, int* delta_x, int* delta_y);
void readSpeedMcuData(McuData* data, float* speed);
void readEngineerMcuData(McuData* mcudata, uint8_t * start,uint8_t * state);
#endif