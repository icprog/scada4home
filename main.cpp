#include <iostream>
#include "ControlManager.h"

//BESI
int main(int argc, char **argv) {
    std::cout << "scada4home starting..." << std::endl;
    
    //TODO: An Logtracer et.al. übergeben
    ControlManager *cMan = new ControlManager();
    cMan->Start();
    
    return 0;
}
