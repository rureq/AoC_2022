//Advent of Code 2022, solution by Jerzy Piwkowski, https://github.com/rureq

//Puzzle 1.2:
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{

    string num;
    int sum_of_sums = 0;
    int actual_sum = 0;
    vector<int> sums;

    ifstream File("input.txt"); // open file with data

    while (!File.eof()) // until the end of file has been reached do:
    {
        getline(File, num);          // get one line of input
        if (num != "")               // if this line is not empty:
            actual_sum += stoi(num); // convert read line from string to int and add it to the actual sum

        if (num == "") // when an empty line is reached:
        {
            sums.push_back(actual_sum); // add current cum to vector of sums
            actual_sum = 0;             // reset the actual sum
        }
    }
    sort(sums.begin(), sums.end(), greater<int>()); // sort vector of sums
    sum_of_sums = sums[0] + sums[1] + sums[2];      // add three biggest values of sums

    cout << sum_of_sums; // print the result
    File.close();        // close the file
    //result is 212117
}