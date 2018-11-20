//
//  AllocatedMemory.cpp
//  ReloactionLoader
//
//  Created by admin on 19/11/2018.
//  Copyright © 2018 wndzlf. All rights reserved.
//

#include "AllocatedMemory.hpp"
#include <string>
#include <iostream>

using namespace std;

AllocatedMemory::AllocatedMemory(){};
string AllocatedMemory::read(int address){
    int trans = address;
    cout<< "trans:" << trans << endl;
    return data[trans];
}

bool AllocatedMemory::write(int address, string data){
    
    return true;
}
