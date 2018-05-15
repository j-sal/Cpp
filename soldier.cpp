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

virtual void Soldier::setLeft(Weapon *)
{
    this->left=left;
}
virtual void Soldier::fireLeft()
{
    Weapon::fire();
}

virtual void Soldier::setRight(Weapon *)
{
    this->right=right;
}
virtual void Soldier::fireRight()
{
    Weapon::fire();
}
