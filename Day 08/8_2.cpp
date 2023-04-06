// Advent of Code 2022, solution by Jerzy Piwkowski, https://github.com/rureq

// Puzzle 8.2:
#include <iostream>
#include <fstream>
#include <string>
#include <vector>

int main()
{
    int result = 0;
    int row_no = 0;
    int visible_trees = 0;
    int distN, distE, distW, distS = 0;
    int scenic = 0;
    int biggest_dist = 0;
    std::vector<int> row;
    std::vector<std::vector<int>> grid;
    std::string line;

    std::fstream File("input.txt"); // open file

    while (getline(File, line)) // get first line and
    {
        row.clear();
        for (char digit : line)
        {
            if (digit != '\n')
            {
                row.push_back(digit - '0');
            }
        }
        row_no++;
        grid.push_back(row);
    }
    // visible_trees = grid.size()*2+(grid[0].size()-2)*2;
    // print whole grid
    for (auto a : grid)
    {
        for (auto b : a)
        {
            std::cout << b;
        }
        std::cout << "\n";
    }

    for (int i = 1; i < grid.size() - 1; i++)
    {
        for (int j = 1; j < grid[i].size() - 1; j++)
        {
            distN = 0;
            distE = 0;
            distW = 0;
            distS = 0;
            scenic = 0;
            // std::cout<<"Current tree: "<<grid[i][j]<<std::endl;

            for (int k = i - 1; k >= 0; k--)
            {
                // std::cout<<grid[k][j]<<" ? "<<grid[i][j]<<std::endl;
                if (grid[k][j] < grid[i][j])
                {
                    distN++;
                }
                else
                {
                    distN++;
                    break;
                }
            }
            for (int k = i + 1; k < grid[i].size(); k++)
            {
                // std::cout<<grid[k][j]<<" ? "<<grid[i][j]<<std::endl;
                if (grid[k][j] < grid[i][j])
                {
                    distS++;
                }
                else
                {
                    distS++;
                    break;
                }
            }
            for (int k = j - 1; k >= 0; k--)
            {
                // std::cout<<grid[i][k]<<" ? "<<grid[i][j]<<std::endl;
                if (grid[i][k] < grid[i][j])
                {
                    distW++;
                }
                else
                {
                    distW++;
                    break;
                }
            }
            for (int k = j + 1; k < grid[j].size(); k++)
            {
                // std::cout<<grid[i][k]<<" ? "<<grid[i][j]<<std::endl;
                if (grid[i][k] < grid[i][j])
                {
                    distE++;
                }
                else
                {
                    distE++;
                    break;
                }
            }

            scenic = distE * distN * distS * distW;
            if (scenic > biggest_dist)
            {
                biggest_dist = scenic;
                std::cout << distN << " " << distE << " " << distW << " " << distS << " " << std::endl;
            }
        }
    }

    std::cout << "Score: " << biggest_dist << std::endl;
    std::cout << grid[0].size() << " i " << grid.size() << std::endl;
    std::cout << "Result: " << result << std::endl;
    File.close();

    // answer is NOT 32200 (too low), (1400 too low)
    // answer is 288120
}