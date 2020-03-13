//
//  DESolver.hpp
//  DE
//
//  Created by 王昆 on 2020/3/5.
//  Copyright © 2020 昆. All rights reserved.
//

#ifndef DESolver_hpp
#define DESolver_hpp

#include <stdio.h>

#if !defined(_DESOLVER_H)
#define _DESOLVER_H

#define stBest1Exp            0
#define stRand1Exp            1
#define stRandToBest1Exp      2
#define stBest2Exp            3
#define stRand2Exp            4
#define stBest1Bin            5
#define stRand1Bin            6
#define stRandToBest1Bin      7
#define stBest2Bin            8
#define stRand2Bin            9

class DESolver;

typedef void (DESolver::*StrategyFunction)(int);

class DESolver
{
public:
    DESolver(int dim,int popSize);
    ~DESolver(void);
    
    // Setup() must be called before solve to set min, max, strategy etc.
    void Setup(double min[],double max[],int deStrategy,
                            double diffScale,double crossoverProb);

    // Solve() returns true if EnergyFunction() returns true.
    // Otherwise it runs maxGenerations generations and returns false.
    virtual bool Solve(int maxGenerations);

    // EnergyFunction must be overridden for problem to solve
    // testSolution[] is nDim array for a candidate solution
    // setting bAtSolution = true indicates solution is found
    // and Solve() immediately returns true.
    virtual double EnergyFunction(double testSolution[],bool &bAtSolution) = 0;
    
    int Dimension(void) { return(nDim); }
    int Population(void) { return(nPop); }

    // Call these functions after Solve() to get results.
    double Energy(void) { return(bestEnergy); }
    double *Solution(void) { return(bestSolution); }

    int Generations(void) { return(generations); }

protected:
    void SelectSamples(int candidate,int *r1,int *r2=0,int *r3=0,
                                                int *r4=0,int *r5=0);
    double RandomUniform(double min,double max);

    int nDim;
    int nPop;
    int generations;

    int strategy;
    StrategyFunction calcTrialSolution;
    double scale;
    double probability;

    double trialEnergy;
    double bestEnergy;

    double *trialSolution;
    double *bestSolution;
    double *popEnergy;
    double *population;

private:
    void Best1Exp(int candidate);
    void Rand1Exp(int candidate);
    void RandToBest1Exp(int candidate);
    void Best2Exp(int candidate);
    void Rand2Exp(int candidate);
    void Best1Bin(int candidate);
    void Rand1Bin(int candidate);
    void RandToBest1Bin(int candidate);
    void Best2Bin(int candidate);
    void Rand2Bin(int candidate);
};

#endif // _DESOLVER_H


#endif /* DESolver_hpp */
