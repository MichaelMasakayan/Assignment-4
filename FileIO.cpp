#include <fstream>
#include "FileIO.h"

FileIO::~FileIO()
{

}
FileIO::FileIO(string nameOfFile)
{
    fileName = nameOfFile;
    timeOfArrival=0;
    amountOfStudents=0;
    idSet= 0;
    windows = 0;

}
FileIO::FileIO()
{
    fileName = "test.txt";
    timeOfArrival=0;
    amountOfStudents=0;
    idSet= 0;
    windows = 0;

}
int FileIO::numOfWinow()
{
     return windows;
}
bool FileIO::fileReadable()
{
   
int num;
 int curr;
ifstream inFile;
inFile.open(fileName);
if(inFile.fail())
{
     cout<<"There was an error openning"<<endl;
}
cout<<"The file"<<fileName<<" has been opened"<<endl;

inFile>>curr;

if( curr <0)
{
    cout<<"registrar had trouble opening window"<<endl;
    inFile.close();
    return false;
}
else
{
    windows = curr;
}
    while(inFile>>curr )
    {
        if(amountOfStudents==0)
        {
          
             timeOfArrival= curr;
              
                inFile>>amountOfStudents;
        }
        else
        {
            {
               
                  //cout<<"this is current line check"<<endl;
            studentInQue.enqueue(timeOfArrival);


            studentWait.enqueue(curr);
           

             
             amountOfStudents--;
            
            }
        }
        
    }

   
inFile.close();
return true;
}
void FileIO:: getQue(GeneralQueue<int> &Qofarival)
{

    
    while(studentInQue.getSizes()>0)
    {
        
        Qofarival.enqueue(studentInQue.dequeue());
        
    }
       

}
void FileIO:: getWindow(GeneralQueue<int> &QofWait)
{
     
    while(studentWait.getSizes()>0)
    {
       
        QofWait.enqueue(studentWait.dequeue());
    }
   
}
void FileIO::moveStudentWindowWait(GeneralQueue<int> &QofWait, GeneralQueue<int> &Qofarival)
{
 
    getWindow(QofWait);
     
    getQue(Qofarival);
}