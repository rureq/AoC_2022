// Advent of Code 2022, solution by Jerzy Piwkowski, https://github.com/rureq

// Puzzle 11.1:
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <sstream>
#include <algorithm>

class Monkey{
    std::vector<int> items;
    std::string lHandSide;
    std::string rHandSide;
    int intRHandSide;
    char op;
    int test;
    int true_recipient;
    int false_recipient;
    int noInspections;
    
    public:
    Monkey(std::vector<int> initItems, std::string initOp, std::string initRHS, int initTest, int initTrue_recipient, int initFalse_recipient){
        items = initItems;
        op = initOp[0];
        rHandSide = initRHS;
        test = initTest;
        true_recipient = initTrue_recipient;
        false_recipient = initFalse_recipient;
        noInspections = 0;
    }
    
    int new_worrines(int worrines){
        if(rHandSide[0] >= 48 && rHandSide[0] <= 57){
            intRHandSide = stoi(rHandSide);
            if(op == '+'){
                return worrines + intRHandSide;
            }
            if(op == '*'){
                return worrines * intRHandSide;
            }
        }
        if(rHandSide[0] == 'o'){
            return worrines *= worrines;
        }
        return 0;
    }

    void inspect(std::vector<Monkey> &monkeys){
        int worryLevel;
        for(auto item : items){
            worryLevel = new_worrines(item);
            worryLevel = (int)(worryLevel/3);
            std::cout<<"Testing: "<<worryLevel<<" % "<<test<<std::endl;
            std::cout<<"test: "<<worryLevel%test<<std::endl;
            if((worryLevel%test) == 0){
                monkeys[true_recipient].receiveItem(worryLevel);
                std::cout<<"True, item with level: "<<worryLevel<<" thrown to monkey "<< true_recipient<<std::endl;
            }
            else{
                monkeys[false_recipient].receiveItem(worryLevel);
                std::cout<<"False, item with level: "<<worryLevel<<" thrown to monkey "<< false_recipient<<std::endl;

            }       
            noInspections++;
             
        }
        items.clear();
    }
    void receiveItem(int lel){
        items.push_back(lel);
    }

    void printItems(){
        for(auto item : items){
            std::cout<<item<<", ";
        }
        std::cout<<"\n";
    }

    int noofInspections(){
        return noInspections;
    }
};

int main(){
    std::fstream File("input.txt"); // open file
    std::string line;

    std::vector<Monkey> monkeys;
    int noMonkeys = 0;
    int noRounds = 20;
    std::vector<int> items;
    std::string item;
    std::stringstream line_ss;
    std::string op;
    std::string RHS;
    int test;
    int true_recipient;
    int false_recipient;
    std::vector<int> inspections;

    while(getline(File,line)){
        items.clear();
        noMonkeys = stoi(line.substr(7,line.size()-1))+1;
        getline(File,line);
        line.erase(0, 18);
        //std::cout<<line<<std::endl;
        line_ss.clear();
        line_ss << line;
        while(getline(line_ss,item,',')){
            items.push_back(stoi(item));
        }
        for(auto item:items){
            //std::cout<<item<<"\n";
        }
        getline(File,line);
        line.erase(0,23);
        
        op = line;
        line.erase(0,2);
        RHS = line;
        

        getline(File,line);
        line.erase(0,21);
        test = stoi(line);
        

        getline(File,line);
        line.erase(0,29);
        true_recipient = stoi(line);

        getline(File,line);
        line.erase(0,29);
        false_recipient = stoi(line);
        monkeys.push_back(Monkey(items, op, RHS, test, true_recipient, false_recipient));
        getline(File,line);
    }
    
    std::cout<<"Before inspection"<<std::endl;

    for(auto monkey : monkeys){
        monkey.printItems();
    }
    for(int i = 0; i<20; i++){
        for(auto &monkey : monkeys){
            monkey.inspect(monkeys);
            std::cout<<"Items after inspection:";
            monkey.printItems();
            std::cout<<"\n";

        }
    }
    for(auto monkey : monkeys){
        inspections.push_back(monkey.noofInspections());
    }
    std::sort(inspections.begin(), inspections.end(), std::greater<int>());
   

    std::cout<<"After inspection"<<std::endl;
    for(auto monkey : monkeys){
        monkey.printItems();
    }
    std::cout<<inspections[0]<<" "<<inspections[1]<<std::endl;

     std::cout<<"result: "<<inspections[0]*inspections[1]<<std::endl;
    
    File.close();
}

//Answer is 54036
