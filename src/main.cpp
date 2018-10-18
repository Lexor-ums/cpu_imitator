/**************************************************************************
**  File: main.cpp
**  Enterprise: FR&PC JSC "R&PA "Mars" "
**  Author: Stepanov Y.M.
**  Created: 15.05.2018
**************************************************************************/
#include <iostream>
#include "ConfigReader.h"
#include "TaskCreator.h"
#include "SharedMemory.h"
#include "Scheduler.h"

int main(int argc, char * argv[]){
    SharedMemory::instance().initValues();
    if(argc < 2)
    {
        std::cout<<"No input file given."<<std::endl;
        return EXIT_FAILURE;
    }
    try {
        Scheduler scheduler(argv[1]);
        scheduler.go();
    }
    catch (IBaseExeption &exc) {
        std::cout<<exc.description()<<std::endl;
        return EXIT_FAILURE;
    }
    catch(...)
    {
        std::cout<<"Unexpected exception "<<std::endl;
        return EXIT_FAILURE;
    }
    return EXIT_SUCCESS;
}
