//
//  main.cpp
//  DE-iknow
//
//  Created by 王昆 on 2020/3/5.
//  Copyright © 2020 昆. All rights reserved.
//

#include <iostream>
#include <time.h>
//#include <stdlib.h>
#include <math.h>

const int NP     = 35; //group scal
const int D      = 2; //para num
const int maxgen = 30; //max gen num
const int F      = 0.5; //suofang yinzi
const int Cr     = 8; //jiaocha yinzi

const int xl = -4; //x quzhi fanwei
const int xu = 4;

class unit{
public:
    double para[D];
    double value;
};

unit pop[NP];
unit mut_pop[NP];
unit cross_pop[NP];
unit new_pop[NP];
unit bestone;

int gen,best_gen;
int min_find_flag = 1;

class group{
public:
    void group_init(){
        for(int i = 0; i < NP;i++)
        {
            if(rand()%2 == 1)
                pop[i].para[0] = (rand()%4001)/1000.0;
            else
                pop[i].para[0] = -(rand()%4001)/1000.0;
            if(rand()%2 == 1)
                pop[i].para[1] = (rand()%4001)/1000.0;
            else
                pop[i].para[1] = -(rand()%4001)/1000.0;
            pop[i].value = 0;
        }
        gen = 0;
    }
    //计算估计值
    void calboj(int select_mod)
    {
        switch (select_mod) {
            case 1:
                for(int i = 0; i < NP;i++)
                {
                    pop[i].value = 3*cos(pop[i].para[0]*pop[i].para[1]) + pop[i].para[0] + pop[i].para[1];
                }
                break;
            case 2:
                for(int i = 0; i < NP;i++)
                {
                    mut_pop[i].value = 3*cos(mut_pop[i].para[0]*mut_pop[i].para[1]) + mut_pop[i].para[0] + mut_pop[i].para[1];
                }
                break;
            case 3:
                for(int i = 0; i < NP;i++)
                {
                    cross_pop[i].value = 3*cos(cross_pop[i].para[0]*pop[i].para[1]) + cross_pop[i].para[0] + cross_pop[i].para[1];
                }
                break;
            case 4:
                for(int i = 0; i < NP;i++)
                {
                    new_pop[i].value = 3*cos(new_pop[i].para[0]*pop[i].para[1]) + new_pop[i].para[0] + new_pop[i].para[1];
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
    void constrictboundary()
    {
        for(int i = 0; i< NP; i++)
        {
            if(cross_pop[i].para[0] < xl)
                cross_pop[i].para[0] = xl;
            if(cross_pop[i].para[0] > xu)
                cross_pop[i].para[0] = xu;
            if(cross_pop[i].para[1] < xl)
                cross_pop[i].para[1] = xl;
            if(cross_pop[i].para[1] > xu)
                cross_pop[i].para[1] = xu;
        }
    }
    //选择
    void selection()
    {
        constrictboundary();
        calboj(3);
        for(int i = 0;i < NP; i++)
        {
            if(pop[i].value >= cross_pop[i].value)
            {
                pop[i].para[0] = cross_pop[i].para[0];
                pop[i].para[1] = cross_pop[i].para[1];
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
                    bestone.para[0] = pop[i].para[0];
                    bestone.para[1] = pop[i].para[1];
                    bestone.value   = pop[i].value;
                    best_gen = gen;
                }
                else
                {
                    bestone.para[0] = pop[0].para[0];
                    bestone.para[1] = pop[0].para[1];
                    bestone.value   = pop[i].value;
                    best_gen = gen;
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
                    bestone.para[0] = pop[i].para[0];
                    bestone.para[1] = pop[i].para[1];
                    bestone.value   = pop[i].value;
                    best_gen = gen;
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
        printf("para1 is %5f  para2 is %5f  best value is %5f run Time is %5f\n",bestone.para[0],bestone.para[1],bestone.value,Time/CLOCKS_PER_SEC);
        
    }
    std::cout << "Hello, World!\n";
    return 0;
}
