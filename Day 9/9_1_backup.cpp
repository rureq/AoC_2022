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
    std::pair<int,int> H_pos = {0,0};
    std::pair<int,int> T_pos = {0,0};
    std::pair<int,int> T_vec_shift = {0,0};
    std::pair<int,int> H_vec_shift = {0,0};
    std::vector<std::pair<int,int>> visited_pos;
    visited_pos.push_back(T_pos);
    std::string dir;
    std::string str_shift;
    int shift = 0;

    std::fstream File("input.txt"); // open file
    system("cls");
    
    gotoxy(0,0);
    std::cout<<"s";
    while (!File.eof()) // get first line and
    {
        H_vec_shift = {0,0};
        T_vec_shift = {0,0};
        dir.clear();
        str_shift.clear();
        shift = 0;
        getline(File, dir, ' ');
        //std::cout<<dir<<" ";
        getline(File, str_shift, '\n');
        //std::cout<<str_shift<<std::endl;
        if(dir == "" || str_shift == ""){
            break;
        }
        shift = stoi(str_shift);
        //std::cout<<shift<<std::endl;
        
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
        

        if(dir[0] == 'U'){
            T_vec_shift = {0,1};
        }
        if(dir[0] == 'D'){
            T_vec_shift = {0,-1};
        }
        if(dir[0] == 'R'){
            T_vec_shift = {1,0};
        }
        if(dir[0] == 'L'){
            T_vec_shift = {-1,0};
        }
        
        

        
            
        
        for(int i = 0; i < shift; i++){
            H_pos.first += H_vec_shift.first;
            H_pos.second += H_vec_shift.second;
            gotoxy(H_pos.first,-H_pos.second);
            std::cout<<"H";
            Sleep(1000);
            
            if(dist(H_pos, T_pos) > 1){
                if(H_pos.first == T_pos.first || H_pos.second == T_pos.second){
                    T_pos.first += T_vec_shift.first;
                    T_pos.second += T_vec_shift.second;
                    gotoxy(T_pos.first,-T_pos.second);
                    std::cout<<"T";
                    visited_pos.push_back(T_pos);
                    Sleep(1000);
                }
                else if((i != shift-1)){
                    H_pos.first += H_vec_shift.first;
                    H_pos.second += H_vec_shift.second;
                    i++;
                    T_pos.first = H_pos.first - H_vec_shift.first;
                    T_pos.second = H_pos.second - H_vec_shift.second;

                    //gotoxy(H_pos.first,-H_pos.second);
                    //std::cout<<"H";
                    gotoxy(T_pos.first,-T_pos.second);
                    std::cout<<"T";
                    visited_pos.push_back(T_pos);
                    Sleep(1000);
                }
            }
            if(dist(H_pos, T_pos) > 2 && shift == 1 ){
                    T_pos.first = H_pos.first - H_vec_shift.first;
                    T_pos.second = H_pos.second - H_vec_shift.second;

                    //gotoxy(H_pos.first,-H_pos.second);
                    //std::cout<<"H";
                    gotoxy(T_pos.first,-T_pos.second);
                    std::cout<<"T";
                    visited_pos.push_back(T_pos);
                    Sleep(1000);
            }    
        }
                
                //to działa 
                //  else if((i != shift-1)){
                //     H_pos.first += H_vec_shift.first;
                //     H_pos.second += H_vec_shift.second;
                //     i++;
                //     T_pos.first = H_pos.first - H_vec_shift.first;
                //     T_pos.second = H_pos.second - H_vec_shift.second;

                //     //gotoxy(H_pos.first,-H_pos.second);
                //     //std::cout<<"H";
                //     gotoxy(T_pos.first,-T_pos.second);
                //     std::cout<<"T";
                //     visited_pos.push_back(T_pos);
                //  }
                
                                
                 
               
            //gotoxy(-25,-10);
            //std::cout<<dir<<" "<<shift;
            Sleep(1000);
            
        }

        
        

    
       
    
        // gotoxy(10,10);
        // for(auto a:visited_pos){
        //     std::cout<<a.first<<" ";
        // }
        // std::cout<<std::endl;
        // gotoxy(10,11);
        // for(auto a:visited_pos){
        //     std::cout<<a.second<<" ";
        // }
        // std::cout << "Result: " << result << std::endl;
        gotoxy(-25,0);

        

        std::cout<<visited_pos.size()<<std::endl;
        std::sort(visited_pos.begin(),visited_pos.end(),[](std::pair<int,int> x, std::pair<int,int> y){return (x.first<y.first) || (x.first == y.first && x.second<y.second);});
        auto last = unique(visited_pos.begin(), visited_pos.end());
        visited_pos.erase(last,visited_pos.end());
        result = visited_pos.size();


        File.close();
        std::cout<<result<<std::endl;
        Sleep(40000);
        // answer is NOT 5862 (too low), 5858 (too low)
        // answer is ...
}