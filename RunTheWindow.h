
#ifndef _RUNTHEWINDOW_H_
#define _RUNTHEWINDOW_H_
#include <iostream>
#include <fstream>
#include <math.h>
#include <time.h>
#include <string>
#include <cmath>
#include <algorithm>

#include "FileIO.h"
#include "LinkedStruct.h"


class RunTheWindow
{
 
    public:
    void waitWindow(int timeWindow[],int s);
    void timeToWait(int timeTot[], int s);
    int id=0;
    int tenMin = 10;
    RunTheWindow();
    RunTheWindow(string file);
    string fileN;
    ~RunTheWindow();
    GeneralQueue<int> timeOfEnter;
    GeneralQueue<int> timeOfWindow; 
    void takeOn(int j);
   
    double meanOfEntireWindow;
    int medianOfStudent;
    int lastStudent;
    int lastWindowTime;
    int studentTenMin;
    int windowAmount;
    int ticks;
    void waitTimeForStudent();
    int windowFiveMin;
    double studentsMean;
    void runWindow();
    
    private:
    
 };
#endif