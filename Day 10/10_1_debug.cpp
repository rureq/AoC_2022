// Advent of Code 2022, solution by Jerzy Piwkowski, https://github.com/rureq

// Puzzle 10.1:
#include <iostream>
#include <fstream>
#include <string>
#include <vector>

int main()
{
   
    int result = 1;
    int sum = 0;
    std::string cmd;
    std::string addVal;
    std::string line;
    int addValInt = 0;
    int clocks = 0;
    std::vector<int> values;
    values.push_back(result);
    
    std::fstream File("input.txt"); // open file
    


    while(getline(File, line)) // get first line and
    {
        cmd.clear();
        addVal.clear();
        addValInt = 0;
        
        //std::cout<<"Line: "<<line;
        if(line[0] == 'n'){
            line.clear();
            line = "n";
            cmd = "n";
        }
        if(line[0] == 'a'){
            cmd = "a";
            line.erase(0, 5);
            //std::cout<<"x:"<<line<<" : ";
            // line.erase(line.end()-1);
            // std::cout<<line;
            //std::cout<<stoi(line);
            addValInt = stoi(line); 
        }
        //std::cout<<"="<<addValInt<<"\n";
        //addValInt = stoi(addVal);
        // std::cout<<cmd<<" "<<addValInt<<"\n";


        if(cmd[0] == 'a'){
            //std::cout<<"Add: "<<addValInt<<"\n";
            clocks += 2;
            //std::cout<<"Clock +2\n";
            values.push_back(result);
            result += addValInt;
            values.push_back(result);
        }
        if(cmd[0] == 'n'){
            clocks ++;
            values.push_back(result);
            //std::cout<<"Clock +1\n";
        }

        
    }
    // for(auto a : values){
    //     std::cout<<a<<"\n";
    // }
    for(int i = 19; i <220; i += 40){
        sum += values[i]*(i+1);
        std::cout<<values[i]<<std::endl;
        std::cout<<values[i]*(i+1)<<"\n";
    }

   

    File.close();
    std::cout<<sum<<std::endl;
    
   
    // answer is 14040
}