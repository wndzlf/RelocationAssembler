//
//  main.cpp
//  ReloactionLoader
//
//  Created by admin on 18/11/2018.
//  Copyright © 2018 wndzlf. All rights reserved.
//

#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

using namespace std;

string bitmaskConverter(string bitmask);
fstream input,output;

class AllocatedMemory {
public:
    AllocatedMemory(){};
    void read(string inputAddr);
    void write(int addrOfRecor, string opcode, string operand);
    void write(int addrOfRecor, string opcode, int operand);
};

void AllocatedMemory::write(int addrOfRecor, string opcode, string operand) {
    output << hex << addrOfRecor <<" "<<opcode<< operand<<endl;
}
void AllocatedMemory::write(int addrOfRecor, string opcode, int operand){
    output << hex << addrOfRecor <<" "<<opcode<< operand<<endl;
}

void AllocatedMemory::read(string inputAddr) {
    fstream read;
    read.open("/Users/admin/Desktop/output.txt");
    
    string line;
    while(getline(read,line)) {
        stringstream str(line);
        string add, op;
        
        str >>  add >> op;
        
        if (add == inputAddr) {
            cout<<"find value in here:"<<inputAddr<<" value:" << op <<endl;
        }
    };
    read.close();
}

int main(int argc, const char * argv[]) {
    int a = 32768;
    
    AllocatedMemory memory;
    
    input.open("/Users/admin/Desktop/listing_bitmask.txt");
    output.open("/Users/admin/Desktop/output.txt",ios::out);
    
    
    int startAddr = 0x4000;
    cout<<"시작 주소를 입력해주세요 (ex. input: 4000 ---> output:0x4000):";
    cin>>hex>>startAddr;
    
    //header
    string line , addrOfRecord, lenOfRecord , headOfText ,bitmask;
    getline(input,line);
    
    //text
    while(getline(input, line)){
        stringstream parsing(line);
        parsing >> headOfText >> addrOfRecord >> lenOfRecord >> bitmask ;
        if (headOfText[0] == 'E') break;
    
        int len = stoi(lenOfRecord);
        int addrOfRecor ;
        
        stringstream str;
        str << lenOfRecord;
        str >> hex >> len;
        
        stringstream str2;
        str2 << addrOfRecord;
        str2>> hex >> addrOfRecor;
        
        addrOfRecor += startAddr;
        //레코드 길이만큼 수행
        int count = 0;
        string binaryBitmask = bitmaskConverter(bitmask);
        
        int realop;
        
        for(int i= 0; i<len*2; i+=6){
            string opcode,operand;
            parsing >> opcode >> operand;
            
            if(binaryBitmask[count] == '0') {
                memory.write(addrOfRecor, opcode, operand);
                //output << hex << addrOfRecor <<" "<<opcode<<operand<<endl;
                cout<<hex<<addrOfRecor<<" "<<opcode<<operand<<endl;
            }else if (binaryBitmask[count] == '1'){
                stringstream realOperand;
                realOperand << operand;
                realOperand >> hex >> realop;
                cout<<hex<<addrOfRecor <<" "<<opcode<<hex<<realop+startAddr<<endl;
                //output << hex << addrOfRecor <<" "<< opcode << hex<<realop+startAddr<<endl;
                memory.write(addrOfRecor, opcode, realop+startAddr);
            }
            if (addrOfRecor > a ){
                cout<<"out of memory"<<endl;
                output<<"out of memory"<<endl;
                return 0;
            }
            addrOfRecor +=3;
            count++;
        }
    }
    input.close();
    output.close();
    
    cout<<endl;
    string b = "4000";
    memory.read(b);
    
    string c = "6500";
    memory.read(c);
    
    return 0;
}

string bitmaskConverter(string bitmask) {
    string retValue = "";
    for(int i = 0; i<bitmask.length(); i++){
        switch(bitmask[i])
                {
                    case '0':
                        retValue += "0000";
                        break;
                    case '1':
                        retValue += "0001";
                        break;
                    case '2':
                        retValue += "0010";
                        break;
                    case '3':
                        retValue += "0011";
                        break;
                    case '4':
                        retValue += "0100";
                        break;
                    case '5':
                        retValue += "0101";
                        break;
                    case '6':
                        retValue += "0110";
                        break;
                    case '7':
                        retValue += "0111";
                        break;
                    case '8':
                        retValue += "1000";
                        break;
                    case '9':
                        retValue += "1001";
                        break;
                    case 'A':
                        retValue += "1010";
                        break;
                    case 'B':
                        retValue += "1011";
                        break;
                    case 'C':
                        retValue += "1100";
                        break;
                    case 'D':
                        retValue += "1101";
                        break;
                    case 'E':
                        retValue += "1110";
                        break;
                    case 'F':
                        retValue += "1111";
                        break;
                }
    }
    return retValue;
}


//메모리 클래스 만들어서 write(address , data, size) or read(address) 클래스만들어서 함수 만들기
//사실 메모리공간 32758byte는 sic어셈블러 정도만 표현 가능하다.
//참조 사이트
//https://forgetcode.com/c/108-relocating-loader

