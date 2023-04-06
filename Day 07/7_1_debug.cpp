// Advent of Code 2022, solution by Jerzy Piwkowski, https://github.com/rureq

// Puzzle 7.1:
#include <iostream>
#include <fstream>
#include <string>
#include <vector>

int big_counter = 0; // number of files, global beacuse i didn't want to put it in the function call, for informative/debugging purposes only

// checks if first char of string is a number, if so it returns 1
bool strisint(std::string a)
{
    if (a[0] >= 48 && a[0] <= 57)
    {
        return 1;
    }
    return 0;
}

// recursively counts summed size of directories smaller than 100000
__int64 subdir_count(std::fstream &file, __int64 &total_size, int &depth)
{
    __int64 size = 0;         // size of current dir
    __int64 sub_size = 0;     // size of a subdirectory
    __int64 all_sub_size = 0; // size of all subdirectories
    std::string line;
    depth++; // counts what is the depth of recursion

    while (getline(file, line))
    {
        if (line == "")
        {
            break;
        }
        if (line[0] == '$' && line[2] == 'c' && line[5] == '.') // if $ cd .. - return size of directory and subdirectories
        {
            depth--;
            return size + all_sub_size;
        }
        if (line[0] == '$' && line[2] == 'c' && line[5] != '.') // if $ cd __ - change directory; __ means directory name (not a .)
        {
            sub_size = subdir_count(file, total_size, depth); // call function
            all_sub_size += sub_size;                         // add size of subdirectory to the size of all subdirectories
            if (sub_size <= 100000)                           // if size of subdirectory is smaller than 100000 add it to the total size of directories of interest
            {
                total_size += sub_size;
                // std::cout << "sub directory added: " << sub_size << "\n";
                //  std::cout<<"dir counted: "<<sub_size<<std::endl;
            }
        }

        if (strisint(line)) // if line begins with a number turn string nunmber to int number
        {
            big_counter++; // some debugging shit
            for (int k = 0; k < depth - 1; k++)
            {
                std::cout << '\t';
            }
            std::cout << line << std::endl;

            int i = 0;
            std::string file_size;
            while (line[i] != ' ') // read digits until space appears
            {
                file_size += line[i];
                i++;
            }
            std::cout << stoi(file_size) << std::endl;
            size += stoi(file_size); // increase size of directory
            std::cout << size << std::endl;
        }
    }
    return (size + all_sub_size); // return size of directory and all subdirectories
}

int main()
{
    int max_size = 100000; // max size of directory that is taken into account
    int file_size = 0;
    int dir_size = 0;
    int depth = 0;
    __int64 total_size = 0;      // total size of directories of interest (smaller or equal max_size)
    __int64 total_read_size = 0; // size of root directory
    std::string cmd_del = "$";   //
    std::string line;

    std::fstream File("input.txt"); // open file

    while (getline(File, line)) // get first line and
    {
        total_read_size = subdir_count(File, total_size, depth); // run recursive function of counting size of directories, returns directory of root
        std::cout << "Total size of root: " << total_read_size << std::endl;
    }
    std::cout << "Total size of directories smaller than 100000: " << total_size << std::endl;
    std::cout << "No. of files: " << big_counter << std::endl;

    File.close();

    // answer is NOT 962358, 2170999, 206097
    // answer is 1989474!
}