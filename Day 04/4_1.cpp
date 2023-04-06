// Advent of Code 2022, solution by Jerzy Piwkowski, https://github.com/rureq

// Puzzle 4.1:
#include <iostream>
#include <fstream>
#include <string>
#include <vector>

int main()
{
    int result = 0;
    bool found = false;
    std::string line = "";
    std::vector<std::string> input;

    std::ifstream File("input.txt"); // open file with data

    while (!File.eof()) // until the end of file has been reached do:
    {
        // clearing variables
        input.clear();
        found = false;

        getline(File, line, '-'); // get input data until a certain character is reached, data is in format: 00-00,00-00
        input.push_back(line);
        getline(File, line, ',');
        input.push_back(line);
        getline(File, line, '-');
        input.push_back(line);
        getline(File, line);
        input.push_back(line);

        if (line == "") // additional checkup in case there is a \n at the end of the file - it breaks the stoi function
        {
            break;
        }

        // checks if range borders are in the second range borders
        if (stoi(input[0]) >= stoi(input[2]) && stoi(input[1]) <= stoi(input[3]) && found != true)
        {
            result++;
            found = true;
        }
        if (stoi(input[1]) >= stoi(input[3]) && stoi(input[0]) <= stoi(input[2]) && found != true)
        {
            result++;
            found = true;
        }
    }

    std::cout << result << std::endl; // print the result
    File.close();                     // close the file
    // result is 453
}