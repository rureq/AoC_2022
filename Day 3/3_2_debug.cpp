//Advent of Code 2022, solution by Jerzy Piwkowski, https://github.com/rureq

//Puzzle 3.2:
#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>


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

//finds the repeating character of three strings, reuses find_repeating_char
char find_repeating_char_triple(std::string a, std::string b, std::string c){
    int n_max = std::max(a.size(),b.size()); //find the length of the longer of two first strings
    char rep = '\0';
    std::string rep_list = ""; //list for repeating characters in two strings
    for(int i = 0; i < n_max; i++) //iterate over longer of strings
    {
        if(a.size()>=b.size()){ //if string a was longer or equal to string b: 
            for(int j = 0; j<b.size();j++){
                if(a[i] == b[j]) //check if the character is repeating in both strings
                rep_list += a[i]; //add the repeating character to list
            }
        }
        else{
             for(int j = 0; j<a.size();j++){ //same as earlier but when string b is longer than string a
                if(a[j] == b[i])
                rep_list += a[j];
            }
        }
    }
    rep = find_repeating_char(rep_list,c); //find repeating character in both constructed list and string c
    return rep;
}

int main()
{
    int result = 0;
    int ascii_Z = 90; 
    char rep;
    std::string str_1 = "vJrwpWtwJgWrhcsFMMfFFhFp"; //test case strings
    std::string str_2 = "jqHRNqRjqzjGDLGLrsFMfFZSrLrFZsSL";
    std::string str_3 = "PmmdzqPrVvPwwTWBwg";
    rep = find_repeating_char_triple(str_1,str_2,str_3); //test
    std::cout<<rep<<std::endl; //test result
    std::ifstream File("input.txt"); //open file with data
    result = 0;
    int loops = 0;

    while (!File.eof()) //until the end of file has been reached do:
    {
        str_1.clear(); //clear substrings to avoid strange leftover behaviour in edge cases
        str_2.clear();
        str_3.clear();
        getline(File, str_1);          //get one line of input
        getline(File, str_2);           
        getline(File, str_3);          
        rep = ' '; //clear repeated strings, same reason as above lines
        rep = find_repeating_char_triple(str_1,str_2,str_3);
        std::cout<<rep<<std::endl;
        //count score accordingly to puzzle's rules:
        if (rep >= 66 && rep <= 122){ //if repeated char is between A and z in ascii
            if(rep <= ascii_Z){ //for uppercase:
            result += rep - 38;
            }
            else{ //for lowercase:
            result += rep - 96;
            }
        }       
        loops++;//count number of loops

    }
    
    std::cout<< result << std::endl<<loops; //print the result
    File.close();        // close the file
    //result is 2825
}