//
//  AllocatedMemory.hpp
//  ReloactionLoader
//
//  Created by admin on 19/11/2018.
//  Copyright © 2018 wndzlf. All rights reserved.
//

#ifndef AllocatedMemory_hpp
#define AllocatedMemory_hpp

#include <string>
#include <iostream>

#endif /* AllocatedMemory_hpp */

using namespace std;

class AllocatedMemory {
private:
    int memory[8192];
    string data[8192];
public:
    AllocatedMemory();
    string read(int address);
    bool write(int address, string data);
};

