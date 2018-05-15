#include "soldier.hpp"
#include <iostream>
#include <string>
#include <vector>


using namespace std;

string name;
string rank;
Weapon* left;
Weapon* right;

Soldier::Soldier()
{

}

Soldier::Soldier(string name, string rank)
{
    this->name=name;
    this->rank=rank;
}

Soldier::~Soldier()
{
    //dtor
}

void Soldier::scream()
{
    cout << "AHHHHH\n" << endl;
}

virtual void Soldier::identification()
{
    cout << "<" << rank << "> <soldier_" << name << "> Sir!\n" <<endl;
}

void Soldier::setLeft(Weapon * left)
{
    Soldier::left=left;
}
void Soldier::fireLeft()
{
    left->fire();

}

void Soldier::setRight(Weapon *right)
{
    this->right=right;
}

void Soldier::fireRight()
{
    right->fire();
}
