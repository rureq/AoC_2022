//Advent of Code 2022, solution by Jerzy Piwkowski, https://github.com/rureq

//Puzzle 3.1:
#include <iostream>
#include <fstream>
#include <string>

//splits string evenly to two substrings if the base string's length is even
void split_str_evenly(const std::string &str, std::string &sub_str_1, std::string &sub_str_2)
{
    if(str.size()%2 == 0){ //check if the lentgh of base string is even
        sub_str_1 = str.substr(0,str.size()/2); //first substring
        sub_str_2 = str.substr(str.size()/2,str.size()/2); //second substring
    }
}

//finds repeating character in two strings (not necessarily the same lentgh), returns first repeating character or null char if there isn't any
char find_repeating_char(std::string a, std::string b){
    int n_max = std::max(a.size(),b.size()); //find the length of the longer of strings

    for(int i = 0; i < n_max; i++) //iterate over longer of strings
    {
        if(a.size()>=b.size()){ //if string a was longer or equal to string b: 
            for(int j = 0; j<b.size();j++){
                if(a[i] == b[j]) //check if the character is repeating in both strings
                return a[i];
            }
        }
        else{
             for(int j = 0; j<a.size();j++){ //same as earlier but when string b is longer than string a
                if(a[j] == b[i]) 
                return a[j];
            }
        }
    }
    return '\0';
}

int main()
{
    int result = 0;
    int ascii_Z = 90; 
    char rep;
    std::string line = ""; 
    std::string sub_str_1 = "";
    std::string sub_str_2 = "";

    std::ifstream File("input.txt"); //open file with data

    while (!File.eof()) //until the end of file has been reached do:
    {
        getline(File, line);          //get one line of input
        sub_str_1.clear(); //clear substrings to avoid strange leftover behaviour in edge cases
        sub_str_2.clear();
        rep = ' '; //clear repeated strings, same reason as above lines
        split_str_evenly(line,sub_str_1,sub_str_2);
        rep = find_repeating_char(sub_str_1,sub_str_2);

        //count score accordingly to puzzle's rules:
        if (rep >= 66 && rep <= 122){ //if repeated char is between A and z in ascii
            if(rep <= ascii_Z){ //for uppercase:
            result += rep - 38;
            }
            else{ //for lowercase:
            result += rep - 96;
            }
        }       

    }

    std::cout<< result << std::endl; //print the result
    File.close();        // close the file
    //result is 7889
}