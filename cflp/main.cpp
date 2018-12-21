#include <iostream>
#include <fstream>
#include <algorithm>
#include <sstream>
#include <ctime>
#include <random>
#include <functional>
#include "utils.h"
#define ITER 1000

using namespace std;
vector<int> assignment;
mt19937::result_type seed = time(0);
auto dice_rand = bind(std::uniform_int_distribution<int>(0, 9), mt19937(seed));

int greedy(vector<Facility> &facilities, vector<Customer> &customers){
    int total_cost = 0;
    for(int n = 0; n < customers.size(); ++n){
        vector<pair<int, int>> assign_cost = customers[n].getAssignCost();
        sort(assign_cost.begin(), assign_cost.end(), [](const pair<int, int> &a1, const pair<int, int> &a2){
            return (a1.second < a2.second);
        });
        for(int i = 0; i < assign_cost.size(); ++i){
            if(facilities[assign_cost[i].first].canServe(customers[n].getDemand())){
                if(!facilities[assign_cost[i].first].isOpen()){
                    total_cost += facilities[assign_cost[i].first].getOpeningCost();
                }
                total_cost += assign_cost[i].second;
                facilities[assign_cost[i].first].serve(customers[n].getDemand());
                assignment[n] = assign_cost[i].first;
                break;
            }
        }
    }
    return total_cost;
}

int localSearch(int curr_cost, vector<Facility> &facilities, vector<Customer> &customers){
    int total_cost = curr_cost;
    int x = 0, y = 0;
    for(int i = 0; i < ITER; ++i){
        for(int j = 0; j < customers.size(); ++j){
            x = assignment[j];
            y = x;
            while(x == y){
                y = dice_rand();
            }
            int new_cost = total_cost;
            int demand = customers[j].getDemand();
            int left_x = facilities[x].getRoomLeft(), left_y = facilities[y].getRoomLeft();
            if(left_y < demand){
                continue;
            }
            new_cost -= customers[j].getSingleAssignCost(x);
            new_cost += customers[j].getSingleAssignCost(y);
            if(left_x + demand == facilities[x].getCapacity()){
                new_cost -= facilities[x].getOpeningCost();
            }
            if(left_y == facilities[y].getCapacity()){
                new_cost += facilities[y].getOpeningCost();
            }
            if(new_cost < total_cost){
                assignment[j] = y;
                facilities[x].pop(demand);
                facilities[y].serve(demand);
                total_cost = new_cost;
            }
            else{
                continue;
            }
        }
    }
    return total_cost;
}

int main(){
    string file = "Instances//";
    ofstream greedy_output("greedy.txt", ios::app);
    greedy_output << "|      | 结果 | 时间 |" << endl << "| ---- | ---- | ---- |" << endl;
    ofstream local_output("local.txt", ios::app);
    local_output << "|      | 结果 | 时间 |" << endl << "| ---- | ---- | ---- |" << endl;
    for(int p = 1; p <= 71; ++p){
        string temp;
        stringstream s;
        s << p;
        s >> temp;
        ifstream input(file + "p" + temp);
        int num_of_fac, num_of_cust;
        vector<Facility> facilities;
        vector<Customer> customers;
        if(input.is_open()){
            input >> num_of_fac >> num_of_cust;
            assignment.resize(num_of_cust);
            for(int i = 0; i < num_of_fac; ++i){
                int capacity, opening_cost;
                input >> capacity >> opening_cost;
                Facility f(capacity, opening_cost);
                facilities.push_back(f);
            }
            for(int i = 0; i < num_of_cust; ++i){
                float demand;
                input >> demand;
                Customer c(static_cast<int>(demand));
                customers.push_back(c);
            }
            for(int i = 0; i < num_of_fac; ++i){
                for(int j = 0; j < num_of_cust; ++j){
                    float assign_cost;
                    input >> assign_cost;
                    customers[j].assign(i, static_cast<int>(assign_cost));
                }
            }
        }
        input.close();
        clock_t start_time = clock();
        int greedy_cost = greedy(facilities, customers);
        ofstream greedy_detail("greedy_detail.txt", ios::app);
        clock_t greedy_time = clock();
        if(greedy_detail.is_open()){
            greedy_detail << "p" << p << endl << "```" << endl << greedy_cost << endl;
            for(auto f : facilities){
                greedy_detail << f.isOpen() << " ";
            }
            greedy_detail << endl;
            for(auto a : assignment){
                greedy_detail << a << " ";
            }
            greedy_detail << endl << "```" << endl;
        }
        auto mid_time = clock();
        int local_cost = localSearch(greedy_cost, facilities, customers);
        auto local_time = clock();
        ofstream local_detail("local_detail.txt", ios::app);
        if(local_detail.is_open()){
            local_detail << "p" << p << endl << "```" << endl << local_cost << endl;
            for(auto f : facilities){
                local_detail << f.isOpen() << " ";
            }
            local_detail << endl;
            for(auto a : assignment){
                local_detail << a << " ";
            }
            local_detail << endl << "```" << endl;
        }
        ofstream greedy_output("greedy.txt", ios::app);
        if(greedy_output.is_open()){
            greedy_output << "|p" << p << "|" << greedy_cost << "|" << (greedy_time - start_time) * 1.0 / CLOCKS_PER_SEC << "|" << endl;
        }
        
        ofstream local_output("local.txt", ios::app);
        if(local_output.is_open()){
            local_output << "|p" << p << "|" << local_cost << "|" << (local_time - mid_time) * 1.0 / CLOCKS_PER_SEC << "|" << endl;
        }
    }
    return 0;
}