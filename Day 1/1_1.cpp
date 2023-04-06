//Advent of Code 2022, solution by Jerzy Piwkowski, https://github.com/rureq

//Puzzle 1.1:
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main()
{

    string num;
    int biggest_sum = 0;
    int actual_sum = 0;

    ifstream File("input.txt"); // open file with data

    while (!File.eof()) // until the end of file has been reached do:
    {
        getline(File, num);          // get one line of input
        if (num != "")               // if this line is not empty:
            actual_sum += stoi(num); // convert read line from string to int and add it to the actual sum

        if (num == "") // when an empty line is reached:
        {
            if (actual_sum >= biggest_sum) // and actual sum is bigger than biggest recorded sum:
                biggest_sum = actual_sum;  // assign actual sum to biggest sum
            actual_sum = 0;                // reset the actual sum
        }
    }

    cout << biggest_sum; // print the result
    File.close();        // close the file
    //result is 72511
}