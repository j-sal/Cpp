#include "infantry.hpp"
#include <iostream>
#include <string>
#include <vector>

using namespace std;

Infantry::Infantry(string name)
{
    this->rank="sergeant";
    this->name=name;
}

Infantry::~Infantry()
{
    //dtor
}
