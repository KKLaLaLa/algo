//
//  main.cpp
//  TSP
//
//  Created by 王昆 on 2020/3/10.
//  Copyright © 2020 昆. All rights reserved.
//
/*
 mmatlab函数实现，输入float数组，数组长度，需要对比的数据
 findmax输出大于对比数据的下标和数据个数
 findmin类似
 max输出数组中最大的z数及其下标
 min类似
 */
#include <iostream>
#include <stdlib.h>
#include <math.h>
#include "Matlab.hpp"
using namespace std;
int Matlabindex;
int *MatlabindexSub;

const static int popsize = 300;                  // 种群规模
const static int maxgen = 100;                   //最大迭代次数
const static int citysize = 20;                  //城市数量
const static int pos_num = 2;
int sn = 150;                                  //优势群体规模
int pos[pos_num][citysize];
float p[citysize][citysize];        //概率转移矩阵
float dm[citysize][citysize];       //城市距离h矩阵


class unit{
public:
    int road[citysize];
    float distance;
};
class UNIT{
public:
    unit a[popsize];
    float DIStance[popsize];
    unit best[maxgen];
};
UNIT popp[maxgen];

class eda {
public:
    eda()
    {
        //随机初始化城市坐标
        for(int i = 0; i < pos_num; i++)
        {
            for (int j = 0; j < citysize; j++) {
                pos[i][j] = rand()%21;
            }
        }
        //初始化概率矩阵
        for(int i = 0; i < citysize; i++)
        {
            for (int j = 0; j < citysize; j++) {
                p[i][j] = 1;
            }
        }
        //计算距离
        for (int i = 0; i < citysize; i++) {
            for (int j = 0; j < citysize; j++) {
                dm[i][j] = pow(pow(abs(pos[0][j] - pos[0][i]),2)+pow(abs(pos[1][j] - pos[1][i]),2),0.5);
            }
        }
    }
    void popinit(UNIT ppopp)
    {
        int cityp[citysize];
        int tempcity[citysize];
        int *citypp;
        int *lunpan;
        int sumcityp = 0;
        int indexflag;
        for (int i = 0; i < popsize; i++) {
            for (int j = 0; j < citysize; j++) {
                if (j == 0) {
                    ppopp.a[i].road[j] = rand()%20;
                }
                else{
                    //找出备选城市
                    for (int m = 0; m < citysize; m++) {
                        cityp[m] = p[ppopp.a[i].road[j-1]][m];
                    }
                    //已经访问过的城市记为0
                    for (int n = 0; n < j-1; n++) {
                        cityp[ppopp.a[i].road[n]] = 0;
                    }
                    //轮盘赌法
                    for (int m = 0; m < citysize; m++) {
                        sumcityp += cityp[m];
                    }
                    for (int m = 0; m < citysize; m++) {
                        cityp[m] = cityp[m]/sumcityp;
                    }
                    citypp = cumsum(cityp,citysize);
                    double p = (rand()%1001)/1000;
                    lunpan = findmax(citypp, p, citysize);
                    indexflag = Matlabindex;
                    //上一代优势群体中没有城市对记录，则找一个城市填充
                    if (indexflag == 0) {
                        for (int m = 0; m < citysize; m++) {
                            tempcity[m] = m;
                        }
                        for (int m = 0; m < j - 1; m++) {
                            tempcity[ppopp.a[i].road[m]] = 0;
                        }
                        lunpan = findmax(tempcity, 0, citysize);
                    }
                    int tempara = 0;
                    tempara = lunpan[0];
                    ppopp.a[i].road[j] = tempara;
                }
            }
        }
    }
    void callenth(UNIT ppopp)
    {
        int sumdm = 0;
        int k = 0;
        for (int i = 0; i < citysize; i++) {
            for (int j = 0; j < citysize; j++) {
                sumdm += dm[i][j];
            }
            sumdm = sumdm + dm[i][0];
            ppopp.a[k].distance = sumdm;
            k++;
        }
    }
    void bestfind(UNIT ppopp)
    {
        float fitness[citysize];
        int MINflag;
        int m = 0,n = 0;
        for (int i = 0; i < citysize; i++) {
            fitness[i] = ppopp.a[i].distance;
        }
        ppopp.best[m].distance = Matmin(fitness, citysize);
        m++;
        MINflag = Matlabindex;
        for (int i = 0; i < citysize; i++) {
            ppopp.best[n].road[i] = ppopp.a[MINflag].road[i];
        }
        n++;
    }
    //选择优势群体
    UNIT selection(UNIT ppopp)
    {
        float fitness[citysize];
        UNIT spop;
        for (int i = 0; i < popsize; i++) {
            fitness[i] = ppopp.a[i].distance;
        }
        Matsort(fitness, popsize, 0);
        for (int i = 0; i < sn; i++) {
            for (int j = 0; j < citysize; j++) {
                spop.a[i].road[j] = ppopp.a[MatlabindexSub[i]].road[j];
            }
            spop.a[i].distance = ppopp.a[MatlabindexSub[i]].distance;
        }
        return spop;
    }
    //更新概率矩阵
    void makep(UNIT spop)
    {
        int abc = citysize + 1;
        int sum[sn];
        sum[sn] = {0};
        int cityroad[sn][abc];
        for (int i = 0; i < sn; i++) {
            for (int j = 0; j < citysize; j++) {
                cityroad[i][j] = spop.a[i].road[j];
            }
        }
        for (int i = 0; i < sn; i++) {
            cityroad[i][abc] = spop.a[i].road[0];
        }
        int count[citysize][citysize] = {0};
        for (int i = 0; i < sn; i++) {
            for (int j = 1; j < citysize; j++) {
                int a = cityroad[i][j];
                int b = cityroad[i][j+1];
                count[a][b] = count[a][b] + 1;
                count[b][a] = count[b][a] + 1;
            }
        }
        for (int i = 0; i < sn; i++) {
            for (int j = 0; j < abc; j++) {
                sum[i] += cityroad[i][j];
            }
        }
        for (int i = 0; i < citysize; i++) {
            for (int j = 0; j < citysize; j++) {
                p[i][j] = p[i][j]/sum[i];
            }
        }
    }
    //算法流程
    void work()
    {
        UNIT spop;
        for (int i = 0; i < maxgen; i++) {
            popinit(popp[i]);
            callenth(popp[i]);
            bestfind(popp[i]);
            spop = selection(popp[i]);
            makep(spop);
        }
        
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    srand((unsigned)time(NULL));
    clock_t start;

    eda TSP;
    eda best;
    
    for (int j = 0; j < maxgen; j++) {
        start = clock();
        TSP.work();
        double Time = (clock() - start)/CLOCKS_PER_SEC;
        printf("time is %f", Time);
    }
        

    return 0;
}

/*
int main()
{
    int a[10] = {1,2,3,4,5,6,7,8,5,7};
    int len = sizeof(a)/sizeof(a[0]);
    int *lunpan;
    
    findmax(a, 5, len);
    int flag = Matlabindex;
    lunpan = new int(flag);
    int asc = lunpan[0];
    printf("%d", asc);
    
    return 0;
}
*/
