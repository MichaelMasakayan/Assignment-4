
#ifndef _FILEIO_H_
#define _FILEIO_H_
using namespace std;
#include "LinkedStruct.h"
//#include "Registrar.h"

class FileIO
{
    public:
    FileIO(string nameOfFile);
    ~FileIO();
    bool fileReadable();
    int numberOfWindows();
    FileIO();
    int numOfWinow();
    void moveStudentWindowWait(GeneralQueue<int> &QofWait, GeneralQueue<int> &Qofarival);
    string fileName;
    GeneralQueue<int> studentWait;
    int timeOfArrival;
    int windows;
    int idSet;
    int amountOfStudents;
    
    GeneralQueue<int> studentInQue;
    void getQue(GeneralQueue<int> &Qofarival);
    void getWindow(GeneralQueue<int> &QofWait);
    int numOfWindow();
    private:

};
#endif