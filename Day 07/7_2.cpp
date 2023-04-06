// Advent of Code 2022, solution by Jerzy Piwkowski, https://github.com/rureq

// Puzzle 7.2:
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>

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
__int64 subdir_count(std::fstream &file, __int64 &total_size, std::vector<__int64> &dir_sizes)
{
    __int64 size = 0;         // size of current dir
    __int64 sub_size = 0;     // size of a subdirectory
    __int64 all_sub_size = 0; // size of all subdirectories

    std::string line;

    while (getline(file, line))
    {
        if (line == "")
        {
            break;
        }
        if (line[0] == '$' && line[2] == 'c' && line[5] == '.') // if $ cd .. - return size of directory and subdirectories
        {
            return size + all_sub_size;
        }
        if (line[0] == '$' && line[2] == 'c' && line[5] != '.') // if $ cd __ - change directory; __ means directory name (not a .)
        {
            sub_size = subdir_count(file, total_size, dir_sizes); // call function
            dir_sizes.push_back(sub_size);                        // put size of directory to a vector
            all_sub_size += sub_size;                             // add size of subdirectory to the size of all subdirectories
            if (sub_size <= 100000)                               // if size of subdirectory is smaller than 100000 add it to the total size of directories of interest
            {
                total_size += sub_size;
            }
        }

        if (strisint(line)) // if line begins with a number turn string nunmber to int number
        {
            big_counter++; // some debugging shit

            int i = 0;
            std::string file_size;
            while (line[i] != ' ') // read digits until space appears
            {
                file_size += line[i];
                i++;
            }
            size += stoi(file_size); // increase size of directory
        }
    }
    return (size + all_sub_size); // return size of directory and all subdirectories
}

int main()
{
    int file_size = 0;
    int depth = 0;
    __int64 total_size = 0;      // total size of directories of interest (smaller or equal 100000)
    __int64 total_read_size = 0; // size of root directory
    __int64 total_disk_size = 70000000;
    __int64 update_size = 30000000;
    __int64 needed_space = 0;
    std::vector<__int64> dir_sizes; // vector for directories sizes
    std::string line;

    std::fstream File("input.txt"); // open file

    while (getline(File, line)) // get first line and
    {
        total_read_size = subdir_count(File, total_size, dir_sizes); // run recursive function of counting size of directories, returns directory of root
        std::cout << "Total size of root: " << total_read_size << std::endl;
    }
    std::cout << "Total size of directories smaller than 100000: " << total_size << std::endl;
    std::cout << "No. of files: " << big_counter << std::endl;
    std::cout << "Space left: " << total_disk_size - total_read_size << std::endl;
    needed_space = update_size - (total_disk_size - total_read_size);
    std::cout << "Needed space " << needed_space << std::endl;

    std::sort(dir_sizes.begin(), dir_sizes.end()); // sort sizes of directories
    for (__int64 a : dir_sizes)
    {
        if (a >= needed_space) // if directory size is larger than space needed for update return it's size
        {
            std::cout << "Smallest directory to delete: " << a << std::endl;
            break;
        }
    }

    File.close();

    // answer is NOT 11347870
    // answer is 1111607
}