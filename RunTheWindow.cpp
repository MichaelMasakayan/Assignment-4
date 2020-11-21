#include "RunTheWindow.h"
#include <stdio.h>      
#include <math.h>   
using namespace std;

RunTheWindow::RunTheWindow()
{

    meanOfEntireWindow =0;
     medianOfStudent =0;
     lastStudent=0;
     lastWindowTime=0;
     studentTenMin=0;
     windowAmount=0;
     ticks=0;
     windowFiveMin=0;
     studentsMean=0.0 ;
}
RunTheWindow::RunTheWindow(string file)
{
    fileN= file;
    meanOfEntireWindow =0;
     medianOfStudent =0;
     lastStudent=0;
     lastWindowTime=0;
     studentTenMin=0;
     windowAmount=0;
     ticks=0;
     windowFiveMin=0;
     studentsMean=0.0 ;

}
RunTheWindow::~RunTheWindow()
{

}
void RunTheWindow::timeToWait(int timeTot[], int s)
{
 int students = 0;
 int counter= 0;
 lastWindowTime = timeTot[0];

cout<<"last Window Time value after"<< lastWindowTime<<endl;
 for(int l = 0; l < s; l++)
 {
     if (timeTot[l] > tenMin)
     {
         studentTenMin++;
     }
     else if (timeTot[l] != 0)
     {
         students = students + timeTot[l];
         counter++;
     }
     else if(timeTot[l] >lastStudent)
     {
         lastStudent = timeTot[l];
     }
     if(counter != 0)
     {
         studentsMean = (1.0) *  students/counter;
     }
     else
     {
         studentsMean=0;
     }
    
 }
  sort(timeTot, timeTot+s); 
 medianOfStudent = timeTot[s/2];
}
void RunTheWindow::waitWindow(int timeWindow[],int s)
{
   
    windowFiveMin = 0;
    int windowTotal = 0;
    int countOfWindow = 0;
    
    for(int l = 0; l< s; l++)
    {

        if(timeWindow[l]>5)
        {
            windowFiveMin= windowFiveMin+ 1;
        }
        else if(timeWindow[l] !=0)
        {
            windowTotal = windowTotal+ timeWindow[l];
            countOfWindow = countOfWindow+1;
        }
        else if(timeWindow[l]>lastWindowTime)
        {
             lastWindowTime = timeWindow[l];
        }
    }

    if(countOfWindow !=0 )
    {
        meanOfEntireWindow = (1.0) * windowTotal/countOfWindow;
    }
}
void RunTheWindow::runWindow()
{
   
   FileIO read(fileN);
    read.fileReadable();
  //issue is here  
  
   read.moveStudentWindowWait(timeOfEnter,timeOfWindow);

    //read.getWindow(timeOfEnter);
 //timeOfEnter.printEntire();
    //read.getQue(timeOfWindow);
    //timeOfWindow.printEntire();
   
   
    windowAmount= read.numOfWinow();
    int personNext = 0; 
    int usedWindows = 0;

    int personThere = 0;
    int personsTimeOfArrival= 0;
   
    int sizeOfTime = timeOfEnter.getSizes();
    int windowsNotInUse[windowAmount];
    int windowsAv[windowAmount];
    for(int i =0; i<windowAmount; i++)
    {
         
        windowsNotInUse[i] = 0;

    }
    int timeS = timeOfEnter.getSizes();
    int totalAmountOfTime[timeS];
    
       for(int l = 0; l<timeS; l++)
    {

        
        totalAmountOfTime[l]=0;
        
    }
    for(int i = 0; i< windowAmount; i++)
    {
        windowsAv[i] = 0;

    }
    bool timeEnterEmpty = timeOfEnter.isEmpty();
    bool timeOfWindowEmpty = timeOfWindow.isEmpty();
// cout <<" time of enter.is empty   "<<timeOfEnter.isEmpty()<<endl;
// cout <<" time of window.is empty  -"<< timeOfWindow.isEmpty()<<endl;
while(usedWindows > 0 || (timeOfEnter.isEmpty()==false && timeOfWindow.isEmpty()==false))
    {
            
            while(timeOfEnter.isEmpty() == false && (timeOfWindow.peek()<= ticks) && usedWindows< windowAmount)
            {
                  
                personNext = timeOfWindow.dequeue();

                personsTimeOfArrival = timeOfEnter.dequeue();

                totalAmountOfTime[personThere] = totalAmountOfTime[personThere] - personsTimeOfArrival;
                
                for(int i = 0; i <windowAmount; i++)
                {
                    if(windowsAv[i]==0)
                    {
                        windowsAv[i]= personNext;
                        
                        usedWindows++;
                        personThere++;
                       
                        break;
                    }
                }
                // timeEnterEmpty = timeOfEnter.isEmpty();
                //  timeOfWindowEmpty = timeOfWindow.isEmpty();
                   
            }

            


        timeEnterEmpty = timeOfEnter.isEmpty();
     timeOfWindowEmpty = timeOfWindow.isEmpty();


    for(int j =personThere; j < timeS; j++)
    {
        totalAmountOfTime[j]++;
    }
    if(usedWindows> 0)
    {
         for(int j = 0; j < windowAmount; j ++)
        {
            
            
            if(windowsAv[j] != 0)
            {
                windowsAv[j]-- ;
                    if(windowsAv[j]==0)
                    {
                        usedWindows--;
                    }
            }
        }
    }
    if(usedWindows <windowAmount)
    {
            for(int i =0; i < windowAmount; i++)
            {

                if(windowsAv == 0)
                {

                    windowsNotInUse[i]++;
                }
            }
    }
    ticks = ticks +1;


  
}
waitWindow(totalAmountOfTime, timeS);
timeToWait(windowsNotInUse,windowAmount);
waitTimeForStudent();

}
void RunTheWindow::waitTimeForStudent()
{
     cout<<"1. The mean student wait time."<< round(studentsMean)<<endl;
      cout<<"2. The median student wait time.:"<<medianOfStudent<<endl;

    cout<<"3. The longest student wait time:"<<lastStudent<<endl;
     cout<<"4. The number of students waiting over 10 minutes:"<<studentTenMin<<endl;
   cout<<"5.The mean window idle time :"<<round(meanOfEntireWindow)<<endl;
    cout<< "6.The longest window idle time :"<< lastWindowTime<<endl;
    cout<<"7.Number of windows idle for over 5 minutes. :"<<windowFiveMin<<endl;
   
}

