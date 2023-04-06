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
    std::string assignment_1;
    std::string assignment_2;
    std::vector<std::string> input;

    std::ifstream File("input.txt"); // open file with data

    while (!File.eof()) // until the end of file has been reached do:
    {
        // clearing variables
        assignment_1.clear();
        assignment_2.clear();
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

        // put numbers from the first assignment range to a variable
        for (int i = stoi(input[0]); i <= stoi(input[1]); i++)
        {
            assignment_1 += std::to_string(i);
        }

        // put numbers from the second assignment range to a variable
        for (int i = stoi(input[2]); i <= stoi(input[3]); i++)
        {
            assignment_2 += std::to_string(i);
        }

        // print assignments to see what's going on
        std::cout << std::endl
                  << "as 1: " << assignment_1 << std::endl;
        std::cout << "as 2: " << assignment_2 << std::endl;

        // works, doesn't need building huge strings of numbers - checks if range borders are in the second range borders
        if (stoi(input[0]) >= stoi(input[2]) && stoi(input[1]) <= stoi(input[3]) && found != true)
        {
            result++;
            found = true;
            std::cout << "YES" << std::endl
                      << std::endl;
        }
        if (stoi(input[1]) >= stoi(input[3]) && stoi(input[0]) <= stoi(input[2]) && found != true)
        {
            result++;
            found = true;
            std::cout << "YES" << std::endl
                      << std::endl;
        }

        // // doesn't work - checks if strings consisting of all numbers from ranges contain other strings (initial idea), returns too high result
        // if (assignment_1.find(assignment_2) != std::string::npos && found != true) // how to use string.contains(second_string)?
        // {
        //     result++;
        //     found = true;
        //     std::cout << "YES" << std::endl<<std::endl;
        // }
        // if (assignment_2.find(assignment_1) != std::string::npos && found != true)
        // {
        //     result++;
        //     found = true;
        //     std::cout << "YES" << std::endl<<std::endl;
        // }
    }

    std::cout << result << std::endl; // print the result
    File.close();                     // close the file
    // result is 453
}