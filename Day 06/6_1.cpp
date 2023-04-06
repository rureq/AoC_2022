// Advent of Code 2022, solution by Jerzy Piwkowski, https://github.com/rureq

// Puzzle 6.1:
#include<iostream>
#include <fstream>

int main(){

    int index = 0;
    int counter = 0;
    int constexpr pck_strt_len = 4;
    char lit[pck_strt_len] = {' ', ' ', ' ', ' '};
    bool rep = false;
    unsigned int result = 65535;

    
    std::ifstream File("input.txt"); // open file with data
    
    while(File.get(lit[index])){ //read character
        counter++; // increase counter of read characters
        if(lit[index] == '\n') // end the  program when en of line is detected
            break;
        
        if(counter>3){ //after first 4 characters are read:
            rep = false; //reset variables for looping

            //check if any character is reapeated in the set of four chars
            for(int i = 0; i<pck_strt_len; i++)
            {   
                if(rep == true){ //stop iterating when a character is repeated
                    break;
                }
                for(int j = i+1; j<(pck_strt_len) ; j++)
                    if(lit[i] == lit[j]){
                        rep = true; //stop iterating when a character is repeated
                        break;
                    }
            }
            if(rep == false){ //if there is no repetition in the set of processed characters:
                result = counter; //set the result
                break; //exit the loop
            }
        }
        
        index = (index+1)%4; //increase iterator for array of characters, keep it between 0 and 3
        
    }
    std::cout<<result;
    File.close();
    return 0;
    // result is 1140
}
