// Advent of Code 2022, solution by Jerzy Piwkowski, https://github.com/rureq

// Puzzle 5.1:
#include <iostream>
#include <fstream>
#include <string>
#include <vector>

int main()
{
    int result = 0;
    int index = 0;
    int spaces_count = 0;
    bool init_dock = false;
    int a, b, c;
    int counter = 0;
    std::string line;
    std::vector<char> row;
    std::vector<std::vector<char>> dock;
    std::vector<char> row_tidy;
    std::vector<std::vector<char>> dock_tidy;
    std::string test_line;

    std::ifstream File("input.txt"); // open file with data

    while (!File.eof()) // until the end of file has been reached do:
    {
        // clearing variables
        index = 1;
        row.clear();

        if (init_dock == false) // read lines one by one until dock is initialized
        {
            getline(File, line); // get input data
        }

        if (init_dock == false && line[1] == '1') // dock is initialized (1 present on second position of line), rearrange it to access the elements more easily - transform if from rows to stacks:
        {
            init_dock = true;
            getline(File, line); // get line with stacks numbers and do nothing with it
            for (int i = 0; i < dock[0].size(); i++)
            {
                row_tidy.clear(); // clear new stack of boxes
                int j = 0;
                while (j != dock.size() && dock[dock.size() - 1 - j][i] != ' ')
                {
                    row_tidy.push_back(dock[dock.size() - 1 - j][i]); // add bozes to stack
                    j++;
                }
                dock_tidy.push_back(row_tidy); // add stack to the new dock
            }
        }

        if (init_dock == false) // until dock is not initialized read every 4th character and put it in row
        {
            for (index; index <= 35; index += 4)
            {
                row.push_back(line[index]);
            }

            dock.push_back(row); // after reading full row append it to the dock vector
        }

        if (init_dock == true) // after dock is initialized
        {
            // read instructions where to put whick boxes
            std::string s_a, s_b, s_c;
            getline(File, line, ' '); // read first word of instruction
            getline(File, s_a, ' ');  // read first number of instruction
            getline(File, line, ' '); // and so on:
            getline(File, s_b, ' ');
            getline(File, line, ' ');
            getline(File, s_c, '\n'); // finish reading the line

            if (s_a == "" || s_b == "" || s_c == "") // when file has an empty line at the end, break, prevents trying to use stoi on an empty character and throwing an exception
            {
                // debugging help
                std::cout << "ELO PA" << std::endl;
                std::cout << "s_a: " << s_a << " s_b: " << s_b << " s_c: " << s_c << std::endl;

                break;
            }
            // debugging help
            std::cout << "s_a: " << s_a << " s_b: " << s_b << " s_c: " << s_c << std::endl;
            // convert string numbers to ints
            a = stoi(s_a);
            b = stoi(s_b);
            c = stoi(s_c);

            // move boxes accordingly to instructions
            for (int p = 0; p < a; p++)
            {
                std::cout << "JEDZIE TOWAR: \n"
                          << dock_tidy[b - 1][dock_tidy[b - 1].size() - 1] << "\n";
                dock_tidy[c - 1].push_back(dock_tidy[b - 1][dock_tidy[b - 1].size() - 1]);
                dock_tidy[b - 1].pop_back();
            }

            // deprecated idea of moving all boxes together not one by one, misunderstood the rules of moving the boxes
            //  std::vector<char>::const_iterator start = dock_tidy[b - 1].end() - a;
            //  std::vector<char>::const_iterator end = dock_tidy[b - 1].end();
            //  std::vector<char> moved_cargo(start, end);

            // dock_tidy[c - 1].insert(dock_tidy[c - 1].end(), moved_cargo.begin(), moved_cargo.end());
            // dock_tidy[b - 1].resize(dock_tidy[b - 1].size() - a);

            // counter++;
            // for (auto i : moved_cargo)
            // {
            //     std::cout << i << std::endl;
            // }
            // help for debugging:
            std::cout << line << "\n";
            std::cout << "a: " << a << ", b:" << b << ", c:" << c << std::endl;
        }
    }

    // print initial dock structure (rows)
    // for (int j = 0; j < dock.size(); j++)
    // {
    //     std::cout << j << ": ";
    //     for (int i = 0; i < dock[j].size(); i++)
    //     {
    //         std::cout << dock[j][i] << " ";
    //     }
    //     std::cout << std::endl;
    // }

    // for debugging purposes, cheks size of dock
    for (auto k : dock_tidy)
    {
        std::cout << k.size() << "\n";
    }

    // prints dock after moving is completed
    for (int j = 0; j < dock_tidy.size(); j++)
    {
        std::cout << "HALO 1\n";
        std::cout << j + 1 << ": ";
        for (int i = 0; i < dock_tidy[j].size(); i++)
        {
            std::cout << "HALO 2\n";
            std::cout << dock_tidy[j][i] << " ";
            std::cout << "HALO 3\n";
        }

        std::cout << " line length: " << dock_tidy[j].size();
        std::cout << std::endl;
    }

    std::cout << "Result: " << result << std::endl; // print the result
    // print top boxes only
    for (auto a : dock_tidy)
    {
        std::cout << a[a.size() - 1] << "";
    }

    std::cout << std::endl
              << "counter:" << counter << std::endl;

    File.close(); // close the file
    // result is VGBBJCRMN
}