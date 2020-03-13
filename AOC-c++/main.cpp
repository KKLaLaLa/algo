//
//  main.cpp
//  AOC-c++
//
//  Created by 王昆 on 2020/3/6.
//  Copyright © 2020 昆. All rights reserved.
//

#include <iostream>
#include <math.h>

#define pi 3.141592653

const int   Ant       = 300; //蚂蚁数量
const int   Times     = 120;//蚂蚁移动次数
const int   goal_para = 2;//未知数个数
const float Rho       = 0.9;//信息素挥发系数
const float P0        = 0.2;//转移概率常数
const int   xl        = -1;//设置搜索范围
const int   xu        = 1;
const int   yl        = -1;
const int   yu        = 1;
float     bestmessage = 0;
float promatix[Ant] = {0};


class unit_ant
{
public:
    float ant[goal_para];
    float mes_val;
};

unit_ant ant_group[Ant];
unit_ant ant_source_group[Ant];
unit_ant bestone;

class ant_al
{
public:
    int promatix_falg[Ant] = {0};
    //init only adapt 2 paras and 2 paras has same range
    void ant_init()
    {
        for(int i = 0; i < Ant; i++)
        {
            ant_group[i].ant[0] = xl + (xu - xl) * (rand()%1001)/1000.0;
            ant_group[i].ant[1] = yl + (yu - yl) * (rand()%1001)/1000.0;
        }
    }
    void cal_message(int mode)
    {
        if(mode == 0)
        {
            for(int i = 0; i < Ant; i++)
            {
                float x = ant_group[i].ant[0];
                float y = ant_group[i].ant[1];
                ant_group[i].mes_val = -(pow(x,4) + 3*pow(y,4) - 0.2*cos(3*pi*x) - 0.4*cos(4*pi*y) + 0.6);
            }
        }
//        if(mode == 1)
//        {
//            for(int i = 0; i < Ant; i++)
//            {
//                float x = ant_source_group[i].ant[0];
//                float y = ant_source_group[i].ant[1];
//                ant_source_group[i].mes_val = -(pow(x,4) + 3*pow(y,4) - 0.2*cos(3*pi*x) - 0.4*cos(4*pi*y) + 0.6);
//            }
//        }
    }
    //矩阵复制
    void matcpy()
    {
        for(int i = 0; i < Ant; i++)
        {
            ant_source_group[i].ant[0] = ant_group[i].ant[0];
            ant_source_group[i].ant[1] = ant_group[i].ant[1];
            ant_source_group[i].mes_val = ant_group[i].mes_val;
        }
    }
    //计算状态转移概率
    void calpromatix()
    {
        bestmessage = ant_group[0].mes_val;
        for(int i = 1; i < Ant; i++)
        {
            if(ant_group[i].mes_val > bestmessage)
            {
                bestmessage = ant_group[i].mes_val;
                bestone.mes_val = i;
            }
        }
        for(int i = 0; i < Ant; i++)
        {
            promatix[i] = abs((bestmessage - ant_group[i].mes_val) / bestmessage);
        }
        for(int i = 0; i < Ant; i++)
        {
            if(promatix[i] < P0)
            {
                promatix_falg[i] = 1;
            }
        }
    }
    //搜索
    void partsearch(int t)
    {
        for(int i = 0; i < Ant; i++)
        {
            if(promatix_falg[i] == 1)
            {
                ant_group[i].ant[0] = ant_group[i].ant[0] + (2 * (((rand()%100001)/100000) - 1)) * (1.00000/t);
                ant_group[i].ant[1] = ant_group[i].ant[1] + (2 * (((rand()%100001)/100000) - 1)) * (1.00000/t);
            }
            if(promatix_falg[i] == 0)
            {
               ant_group[i].ant[0] = ant_group[i].ant[0] + (xu - xl) *(((rand()%100001)/100000) - 0.5);
               ant_group[i].ant[1] = ant_group[i].ant[1] + (yu - yl) *(((rand()%100001)/100000) - 0.5);
            }
        }
    }
    //边界约束，避免出现超出范围的值
    void edgebound()
    {
        for(int i = 0; i < Ant; i++)
        {
            if(ant_group[i].ant[0] < xl)
                ant_group[i].ant[0] = xl;
            if(ant_group[i].ant[0] > xu)
                ant_group[i].ant[0] = xu;
            if(ant_group[i].ant[1] < yl)
                ant_group[i].ant[1] = yl;
            if(ant_group[i].ant[1] > yu)
                ant_group[i].ant[1] = yu;
        }
    }
    void choose()
    {
        cal_message(0);
        for(int i = 0; i < Ant; i++)
        {
            if(ant_group[i].mes_val < ant_source_group[i].mes_val)
            {
                ant_group[i].ant[0] = ant_source_group[i].ant[0];
                ant_group[i].ant[1] = ant_source_group[i].ant[1];
                ant_group[i].mes_val = ant_source_group[i].mes_val;
            }
        }
    }
    void updatamesvalue()
    {
        cal_message(0);
        for(int i = 0; i < Ant; i++)
        {
            ant_group[i].mes_val = (1 - Rho) * ant_source_group[i].mes_val + ant_group[i].mes_val;
        }
    }
    void edgeselection(int t)
    {
        matcpy();
        calpromatix();
        partsearch(t);
        edgebound();
        choose();
        updatamesvalue();
    }
};



int main(int argc, const char * argv[]) {
    // insert code here...
    srand((int)time(0));
    ant_al antant;
    antant.ant_init();
    antant.cal_message(0);
    for(int i = 0; i < Times; i++)
    {
        antant.edgeselection(i);
    }
    for(int j = 0; j < Ant; j++)
    {
        printf("x is %3f;   y is %3f; message is %5f\n",ant_group[j].ant[0],ant_group[j].ant[1],ant_group[j].mes_val);
    }
    return 0;
}
