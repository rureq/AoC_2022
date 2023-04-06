//Advent of Code 2022, solution by Jerzy Piwkowski, https://github.com/rureq

//Puzzle 2.2:
#include <iostream>
#include <fstream>
#include <string>

int main()
{
    int result = 0;
    char my_sign = ' ';
    std::string line = ""; 

    std::ifstream File("input.txt");    //open file with data

    while (!File.eof())                 //until the end of file has been reached do:
    {
        getline(File, line);            //get one line of input and check which sign has been played
            if(line[2] == 'X'){         // X - means you need to loose, set your sign to a losing sign:
                if(line[0] == 'A'){
                    my_sign = 'C';
                }
                if(line[0] == 'B'){
                    my_sign = 'A';
                }
                if(line[0] == 'C'){
                    my_sign = 'B';
                }

            }
            if(line[2] == 'Y'){         // X - means the match needs to be a tie, set your sign to a sign that will result in a tie:
                my_sign = line[0];

            }
            if(line[2] == 'Z'){         // Z - means you need to win, set your sign to a winning sign:
                if(line[0] == 'A'){
                    my_sign = 'B';
                }
                if(line[0] == 'B'){
                    my_sign = 'C';
                }
                if(line[0] == 'C'){
                    my_sign = 'A';
                }
            }
            
            //add points for choosing a sign:
            if(my_sign == 'A'){
                result += 1;
            }
            if(my_sign == 'B'){
                result += 2;
            }
            if(my_sign == 'C'){
                result += 3;
            }
            if(line[0] == my_sign){      //check if there is a tie - X,Y,Z are translated to A,B,C by substracting 23 (in ASCII)
                result += 3;
            }

            if((line[0] == 'A' && my_sign == 'B')||(line[0] == 'B' && my_sign == 'C')||
            (line[0] == 'C' && my_sign == 'A')){ //check if you won
                result += 6;
            }
            
        line = "   ";                   //"clearing" the string is necessary because when end of file is detected, the last read letter remains in line[2] and triggers additional value comparison that results in offsetting final result by one
        my_sign = ' ';                  //as above ^
                                        //why line.clear() doesn't work? it clears only first character leaving last value of line[2]
    }

    std::cout<< result << std::endl; //print the result
    File.close();        // close the file
    //result is 13889
}