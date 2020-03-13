//
//  main.cpp
//  DE_TQS
//
//  Created by 王昆 on 2020/3/5.
//  Copyright © 2020 昆. All rights reserved.
//


#include <iostream>
#include <time.h>
//#include <stdlib.h>
#include <math.h>

const int NP     = 150; //group scal
const int D      = 10; //路线数量
const int maxgen = 30; //最大迭代数
const int F      = 0.2; //suofang yinzi
const int Cr     = 8; //jiaocha yinzi
const int coop_num = 5;
int total_num = 25000; //货物总量


double discount_table[10][15] = {
    {5,4.94,4.9,5.5,5.434,5.3625,5.3,5.2099,5.1569,5.2,5.1064,5.044,5.4,5.3298,5.2758},
    {5.3,5.2046,5.141,5.5,5.4285,5.3735,5.1,5.0388,4.9725,5,4.905,4.86,4.8,4.728,4.656},
    {4.8,4.7184,4.68,5.3,5.2205,5.1887,5,4.92,4.865,5.1,5.0439,4.9521,5,4.93,4.86},
    {5.2,5.1064,5.044,5.4,5.3298,5.2758,5.1,5.0388,4.9725,5,4.94,4.9,5.3,5.2046,5.141},
    {5.1,5.0388,4.9725,5.3,5.2205,5.1887,4.8,4.7184,4.68,5.3,5.2205,5.1887,5,4.92,4.865},
    {4.8,4.7184,4.68,5.3,5.2205,5.1887,5,4.92,4.865,5.1,5.0439,4.9521,5,4.93,4.86},
    {5.3,5.2099,5.1569,5.3,5.2205,5.1887,5,4.92,4.865,5.1,5.0439,4.9521,5,4.92,4.865},
    {5,4.92,4.865,5,4.92,4.865,5.1,5.0439,4.9521,5,4.94,4.9,4.8,4.7184,4.68},
    {5.2,5.1064,5.044,5.4,5.3298,5.2758,5.1,5.0388,4.9725,5,4.94,4.9,5.3,5.2046,5.141},
    {5.1,5.0388,4.9725,5.3,5.2205,5.1887,4.8,4.7184,4.68,5.3,5.2205,5.1887,5,4.92,4.865}
};

class unit{
public:
    int para[D];
    double value;
};

unit pop[NP];
unit mut_pop[NP];
unit cross_pop[NP];
unit new_pop[NP];
unit bestone;

int gen,best_gen;
int min_find_flag = 1;
class Need{ //随机定义每条路上的供货量
public:
    int gos_dis[D];
    int dis_cho[D];
    Need()
    {
        for(int i = 0; i < D - 1;i++){
            gos_dis[i] = rand()%3500;
            total_num -=gos_dis[i];
        }
        gos_dis[D - 1] = total_num;
        for (int i = 0;i < D;i++){
            if(gos_dis[i] < 1000)
                dis_cho[i] = 0;
            else if (gos_dis[0]>=1000 && gos_dis[i] <= 2000)
                dis_cho[i] = 1;
            else
                dis_cho[i] = 2;
        }
    }
};
Need goods;
class group{
public:
    void group_init(){
        for(int i = 0; i < NP;i++)
        {
            for(int j = 0;j < D;j++)
                pop[i].para[j] = rand()%coop_num;
            pop[i].value = 0;
        }
        gen = 0;
    }
    //计算估计值
    void calboj(int select_mod)
    {
        double rel = 0;
        switch (select_mod) {
            case 1:
                for(int k = 0; k < NP; k++)
                {
                    for(int i = 0; i < D; i++)
                        rel += discount_table[i][pop[k].para[i] * D + goods.dis_cho[i]] * (double)goods.gos_dis[i];
                    pop[k].value = rel;
                }
                break;
            case 2:
                for(int k = 0; k < NP; k++)
                {
                    for(int i = 0; i < D; i++)
                        rel += discount_table[i][mut_pop[k].para[i] * D + goods.dis_cho[i]] * (double)goods.gos_dis[i];
                    mut_pop[k].value = rel;
                }
                break;
            case 3:
                for(int k = 0; k < NP; k++)
                {
                    for(int i = 0; i < D; i++)
                        rel += discount_table[i][cross_pop[k].para[i] * D + goods.dis_cho[i]] * (double)goods.gos_dis[i];
                    cross_pop[k].value = rel;
                }
                break;
            case 4:
                for(int k = 0; k < NP; k++)
                {
                    for(int i = 0; i < D; i++)
                        rel += discount_table[i][new_pop[k].para[i] * D + goods.dis_cho[i]] * (double)goods.gos_dis[i];
                    new_pop[k].value = rel;
                }
                break;
            default:
                break;
        }

    }
    //变异
    void mutation()
    {
        int r0,r1,r2;
        for(int i = 0; i < NP; i++)
        {
            r0 = rand()%NP;
            do{
                r1 = rand()%NP;
            }while(r1 == r0);
            do{
                r2 = rand()%NP;
            }while( (r2 == r0) || (r2 == r1));
            mut_pop[i].para[0] = pop[i].para[0] + F*(pop[i].para[0] - pop[i].para[0]);
            mut_pop[i].para[1] = pop[i].para[1] + F*(pop[i].para[1] - pop[i].para[1]);
        }
    }
    //交叉 变异后的个体与原个体交叉
    void crossover()
    {
        int r;
        for(int i = 0; i< NP; i++)
        {
            r = rand()%10;
            if(r > Cr)
            {
                cross_pop[i].para[0] = pop[i].para[0];
                cross_pop[i].para[1] = pop[i].para[1];
            }
            else
            {
                cross_pop[i].para[0] = mut_pop[i].para[0];
                cross_pop[i].para[1] = mut_pop[i].para[1];
            }
        }
    }
    //约束边界

    //选择
    void selection()
    {
        calboj(3);
        for(int i = 0;i < NP; i++)
        {
            if(pop[i].value >= cross_pop[i].value)
            {
                for(int j = 0; j < D; j++)
                {
                    pop[i].para[j] = cross_pop[i].para[j];
                }
            }
        }
    }
    //排序
    void min_find()
    {
        while(min_find_flag == 1)
        {
            for(int i = 1; i < NP; i++)
            {
                if(pop[i].value < pop[0].value)
                {
                    for(int j = 0; j < D; j++)
                    {
                    bestone.para[j] = pop[i].para[j];
                    bestone.value   = pop[i].value;
                    }
                }
                else
                {
                    for(int j = 0; j < D; j++)
                    {
                    bestone.para[j] = pop[0].para[j];
                    bestone.value   = pop[i].value;
                    best_gen = gen;
                    }
                }
            }
            min_find_flag = 2;
            break;
        }
        while(min_find_flag == 5)
        {
            for(int i = 1; i < NP; i++)
            {
                if(pop[i].value < bestone.value)
                {
                    for(int j = 0; j < D; j++)
                    {
                    bestone.para[j] = pop[i].para[j];
                    bestone.value   = pop[i].value;
                    best_gen = gen;
                    }
                }
            }
            min_find_flag = 4;
        }
        min_find_flag = 5;
    }
    void work()
    {
        group_init();
        for(int i = 0;i < maxgen; i++)
        {
            calboj(1);
            mutation();
            crossover();
            selection();
            gen += 1;
            
            min_find();
        }
    }
};



int generalunm = 0;



int main(int argc, const char * argv[]) {
    clock_t start,end;
    srand((int)time(0));
    for(int i = 0; i < 10;i++)
    {
        group g;
        start = clock();
        g.work();
        end = clock();
        double Time = end - start;
        //printf("para1 is %5  para2 is %5f  best value is %5f run Time is %5f\n",bestone.para[0],bestone.para[1],bestone.value,Time/CLOCKS_PER_SEC);
        printf("第%d次求解。每次路上的公司选择为：", i+1);
        for(int j = 0; j < D; j++)
            printf("%d公司 ", bestone.para[j]);
        printf(";总花费：%f; 第%3d代; 耗时%.6fms\n", bestone.value, best_gen,Time/CLOCKS_PER_SEC);
        
    }
    return 0;
}
