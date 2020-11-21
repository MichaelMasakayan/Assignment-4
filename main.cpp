#include <iostream>
#include <fstream>
#include <string>
#include <stdio.h>
#include <cmath>
 #include "LinkedStruct.h"
//#include "Registrar.h"
#include "RunTheWindow.h"
using namespace std;




int main(int argc, char const *argv[])
{
if(argc == 2)
{
    string filename = argv[1];
    cout<< "the program is running"<<endl;
    string textfile = argv[1];
    RunTheWindow registrar(filename);
    registrar.runWindow();
   
}
else
{
    cout<< "file was not redable please reeenter"<<endl;
}

return 0;
}
