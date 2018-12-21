#ifndef UTILS_HPP
#define UTILS_HPP
#include <vector>
using namespace std;


class Facility{
private:
    bool is_open = false;
    int capacity;
    int opening_cost;
    int total_demand;
public:
    Facility(){}
    Facility(int c, int o){
        capacity = c;
        opening_cost = o;
        total_demand = 0;
    }
    int getRoomLeft(){
        return capacity - total_demand;
    }
    void pop(int demand){
        total_demand -= demand;
        if(total_demand <= 0){
            is_open = false;
        }
    }
    bool canServe(int demand){
        return (total_demand + demand <= capacity);
    }
    void serve(int demand){
        is_open = true;
        total_demand += demand;
    }
    bool isOpen(){
        return is_open;
    }
    int getCapacity(){
        return capacity;
    }
    int getOpeningCost(){
        return opening_cost;
    }
};

class Customer{
    int demand;
    vector<pair<int, int>> assign_cost;
public:
    Customer(int d){
        demand = d;
    }
    void assign(int i, int cost){
        assign_cost.push_back(make_pair(i, cost));
    }
    int getDemand(){
        return demand;
    }
    vector<pair<int, int>> getAssignCost(){
        return assign_cost;
    }
    int getSingleAssignCost(int i){
        return assign_cost[i].second;
    }
};

#endif