#include "gun.hpp"
#include <iostream>
#include <string>
#include <vector>

using namespace std;

string name;
int ammo;

Gun::Gun(string name, int ammo)
{
    this->name=name;
    this->ammo=ammo;
}

Gun::~Gun()
{
    //dtor
}
