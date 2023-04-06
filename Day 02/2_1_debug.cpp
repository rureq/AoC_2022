#include <iostream>
#include <fstream>
#include <string>


int main()
{
    int result = 0;
    int x_count = 0;
    int y_count = 0;
    int z_count = 0;
    std::string line = ""; 

    std::ifstream File("input.txt"); //open file with data

    while (!File.eof()) //until the end of file has been reached do:
    {
        getline(File, line);          //get one line of input and check which sign has been played
            if(line[2] == 'X'){
                result += 1;
                x_count ++;
                std::cout<<"X";
            }
            if(line[2] == 'Y'){
                result += 2;
                y_count ++;
                std::cout<<"Y";
            }
            if(line[2] == 'Z'){
                result += 3;
                z_count ++;
                std::cout<<"Z";
            }
            
            if(line[0] == (line[2]-23)){ //check if there is a tie - X,Y,Z are translated to A,B,C by substracting 23 (in ASCII)
                result += 3;
            }

            if((line[0] == 'A' && line[2] == 'Y')||(line[0] == 'B' && line[2] == 'Z')||
            (line[0] == 'C' && line[2] == 'X')){ //check if you won
                result += 6;
            }
            
        std::cout<<result<<std::endl;
        line = "   "; //"clearing" the string is necessary because when end of file is detected, the last read letter remains in line[2] and triggers additional value comparison that results in offsetting final result by one
        //why line.clear() doesn't work? it clears only first character leaving last value of line[2]
    }

    std::cout<< result << std::endl; //print the result 
    std::cout<<"x count:"<<x_count<<std::endl; //number of X played (for debugging)
    std::cout<<"y count:"<<y_count<<std::endl; //number of Y played (for debugging)
    std::cout<<"z count:"<<z_count<<std::endl; //number of Z played (for debugging)
    std::cout<<line<<"  "<<line.size()<<std::endl; //print size of last read line (for debugging)
    File.close();        // close the file
}