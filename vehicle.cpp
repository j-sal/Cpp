#include "vehicle.hpp"
#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector <Soldier*> s;

Soldier* sold;

Vehicle::Vehicle(vector<Soldier*>)
{
    vector<Soldier*>=vector<Soldier*>;
}

Vehicle::~Vehicle()
{
    //dtor
}

int Vehicle::countSoldier()
{
    return s.size();
    cout << s.size() << endl;
}

void Vehicle::action()
{

}

void Vehicle::addSoldier(Soldier *)
{
    s.push_back(sold);
}

std::vector<Soldier*> Vehicle::unload()
{
    return s;
    s.resize(0);
}
