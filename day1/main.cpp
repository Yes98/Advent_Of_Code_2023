#include <iostream>
#include <fstream>
#include <string>
using namespace std;
int substringCheck(string sub){
    int val = -1;
    switch (sub[0]){
        case 'o': //1
            if(sub.substr(0,3) == "one")
                val = 1;
            break;
        case 't': // 2,3
            if(sub.substr(0,3) == "two")
                val = 2;
            else if(sub.substr(0,5) == "three")
                val = 3;
            break;
        
        case 'f': // 4,5
            if(sub.substr(0,4) == "four")
                val = 4;
            else if(sub.substr(0,4) == "five")
                val = 5;
            break;
        
        case 's': // 6,7
            if(sub.substr(0,3) == "six")
                val = 6;
            else if(sub.substr(0,5) == "seven")
                val = 7;
            break;

        case 'e': // 8
            if(sub.substr(0,5) == "eight")
                val = 8;
            break;
        
        case 'n': // nine
            if(sub.substr(0,4) == "nine")
                val = 9;
            break; 
        default:
            break;
    }

    return val;

}

int getDigits(string line){
    int first = -1;
    int second = -1;
    int temp = -1;
    for(int i = 0; i <line.length();i++){
        if(isdigit(line[i])){
            if(first == -1)
                first = line[i] - 48;
            second = line[i] - 48;
        }
        temp = substringCheck(line.substr(i));
        if(temp != -1){
            if(first == -1)
                first = temp;
            second = temp;
        }

    }
    if(first == -1)
        return 0;
    return first*10 + second;
}

int main(int argc, char* argv[]) {

    fstream input_file;

    if(argc < 2){
        cout<< "Missing input file\n";
        return -1; 
    }

    input_file.open(argv[1],ios::in);

    if(!input_file.is_open()){
        cout<<"Failed to open file\n";
        return -1;
    }
    string tp;
    int sum = 0;
    while(getline(input_file, tp)){
        sum += getDigits(tp);
    }
    input_file.close();
    cout<< "Answer is "<< sum<<endl;
    return 0;
}