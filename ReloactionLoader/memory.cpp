//
//  memory.cpp
//  ReloactionLoader
//
//  Created by admin on 19/11/2018.
//  Copyright © 2018 wndzlf. All rights reserved.
//

#include <string>
#include <iostream>

using namespace std;

class Memory {
private:
    int memory[8192];
    string data[8192];
public:
    Memory();
    string read(int address);
    bool write(int address, string data);
};

//address는 16진수
string Memory::read(int address){
    int trans = address / 3 ;
    cout<< "trans:" << trans << endl;
    return data[trans];
}
