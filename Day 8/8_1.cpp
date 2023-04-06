// Advent of Code 2022, solution by Jerzy Piwkowski, https://github.com/rureq

// Puzzle 8.1:
#include <iostream>
#include <fstream>
#include <string>
#include <vector>


int main()
{
    int result = 0;
    int row_no = 0;
    int visible_trees = 0;
    bool is_higherN, is_higherE, is_higherW, is_higherS = true;
    std::vector<int> row;
    std::vector<std::vector<int>> grid; 
    std::string line;

    std::fstream File("input.txt"); // open file

    while (getline(File,line)) // get first line and
    {
        row.clear();
        for(char digit : line){
            if(digit != '\n'){
                row.push_back(digit-'0');
            }
        }
        row_no ++;
        grid.push_back(row);
       
    }
    visible_trees = grid.size()*2+(grid[0].size()-2)*2;
    //print whole grid
    for(auto a : grid){
        for(auto b : a){
            std::cout<<b;
        }
        std::cout<<"\n";
    }
    for(int i = 1;i<grid.size()-1;i++ ){
        for(int j = 1; j<grid[i].size()-1; j++){
            is_higherN = true;
            is_higherE = true;
            is_higherW = true;
            is_higherS = true;
            //std::cout<<"Current tree: "<<grid[i][j]<<std::endl;

            for(int k = 0; k<i; k++){
                //std::cout<<grid[k][j]<<" ? "<<grid[i][j]<<std::endl;
                    if(grid[k][j] >= grid[i][j]){
                        is_higherN = false;
                        break;
                    }
            }
            for(int k = i+1; k<grid[i].size(); k++){
                //std::cout<<grid[k][j]<<" ? "<<grid[i][j]<<std::endl;
                if(grid[k][j] >= grid[i][j]){
                        is_higherS = false;
                        break;
                    }
            }
            for(int k = 0; k<j; k++){
                //std::cout<<grid[i][k]<<" ? "<<grid[i][j]<<std::endl;
                    if(grid[i][k] >= grid[i][j]){
                        is_higherW = false;
                        break;
                    }
            }
            for(int k = j+1; k<grid[j].size(); k++){
                //std::cout<<grid[i][k]<<" ? "<<grid[i][j]<<std::endl;
                if(grid[i][k] >= grid[i][j]){
                        is_higherE = false;
                        break;
                    }
            }
                
            
            if(is_higherN == true || is_higherE == true || is_higherW == true || is_higherS == true){
                visible_trees ++;
                //std::cout<<"tree visible"<<std::endl;
            } 
        }
    }

    std::cout<<"visible trees: "<<visible_trees<<std::endl;
    std::cout<<grid[0].size()<<" i "<<grid.size()<<std::endl;
    std::cout << "Result: " << result << std::endl;
    File.close();

    // answer is 1796
}