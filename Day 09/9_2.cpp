// Advent of Code 2022, solution by Jerzy Piwkowski, https://github.com/rureq

// Puzzle 9.1:
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <math.h>
#include <windows.h>
#include <algorithm>

void gotoxy(short int x,short int y)
{
    COORD p = {x+25, y+150};
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), p);
}

// returns distance between two points
double dist(std::pair<int,int> a, std::pair<int,int> b){
   return sqrt(pow(abs(a.first-b.first),2)+pow(abs(a.second-b.second),2));
}

int main()
{
    HWND console = GetConsoleWindow();
    RECT r;
    GetWindowRect(console, &r);
    MoveWindow(console, r.left, r.top, 1800, 800, TRUE);

    int result = 0;
    std::string line;
    std::pair<int,int> diff =  {0,0};
    std::pair<int,int> positions[10];
    std::pair<int,int> H_vec_shift = {0,0};
    std::vector<std::pair<int,int>> visited_pos;
    visited_pos.push_back(positions[9]);
    std::string dir;
    std::string str_shift;
    int shift = 0;

    std::fstream File("input.txt"); // open file
    
    gotoxy(0,0);
    std::cout<<"s";

    while (!File.eof()) // get first line and
    {
        
        H_vec_shift = {0,0}; 
        dir.clear();
        str_shift.clear();
        shift = 0;

        getline(File, dir, ' ');
        getline(File, str_shift, '\n');
        
        if(dir == "" || str_shift == ""){
            break;
        }

        shift = stoi(str_shift);
                
        if(dir[0] == 'U'){
            H_vec_shift = {0,1};
        }
        if(dir[0] == 'D'){
            H_vec_shift = {0,-1};
        }
        if(dir[0] == 'R'){
            H_vec_shift = {1,0};
        }
        if(dir[0] == 'L'){
            H_vec_shift = {-1,0};
        }

        for(int i = 0; i < shift; i++){
            positions[0].first += H_vec_shift.first;
            positions[0].second += H_vec_shift.second;
            //gotoxy(positions[0].first, -positions[0].second);
            //std::cout<<"H";
            for(int j = 1; j < 10; j++){
                diff = {0,0};
                //if distance between knots is equal to 2, check if they are for sure in a straight line (redundancy, probably unnecessary)
                if(dist(positions[j-1], positions[j]) == 2){
                    if(positions[j-1].first == positions[j].first || positions[j-1].second == positions[j].second){
                        // count the difference between two neighbour knots
                        diff.first = positions[j-1].first - positions[j].first;
                        diff.second = positions[j-1].second - positions[j].second;
                        diff.first /=2;
                        diff.second /=2;
                        positions[j].first += diff.first;
                        positions[j].second += diff.second;
                        
                        //gotoxy(positions[j].first,-positions[j].second);
                        //std::cout<<j;
                        if(j == 9){
                            visited_pos.push_back(positions[j]);
                            gotoxy(positions[j].first,-positions[j].second);
                            std::cout<<"T";
                        }
                    }
                }
                //if distance between knots if biggerthan two
                if(dist(positions[j-1], positions[j]) > 2){
                    diff.first = positions[j-1].first - positions[j].first;
                    diff.second = positions[j-1].second - positions[j].second;
                    if(abs(diff.first) == 2){
                        diff.first /= 2;
                    }
                    if(abs(diff.second) == 2){
                        diff.second /= 2;
                    }
                    positions[j].first += diff.first;
                    positions[j].second += diff.second;
                    
                    //gotoxy(positions[j].first,-positions[j].second);
                    //std::cout<<j;
                    if(j == 9){
                        visited_pos.push_back(positions[j]);
                        gotoxy(positions[j].first,-positions[j].second);
                        std::cout<<"T";
                    }
                }
            }
        }
    }
    gotoxy(-25,0);

    std::cout<<visited_pos.size()<<std::endl;
    std::sort(visited_pos.begin(),visited_pos.end(),[](std::pair<int,int> x, std::pair<int,int> y){return (x.first<y.first) || (x.first == y.first && x.second<y.second);});
    auto last = unique(visited_pos.begin(), visited_pos.end());
    visited_pos.erase(last,visited_pos.end());
    result = visited_pos.size();

    File.close();
    std::cout<<result<<std::endl;
    Sleep(40000);
    // answer is NOT 2376 (too high)
    // answer is 2367!!!!!!
}