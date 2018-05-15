#include "weapon.hpp"
#include <iostream>
#include <string>

using namespace std;

//int ammo;

Weapon::Weapon()
{
    //ctor
}

Weapon::~Weapon()
{
    //dtor
}

virtual string Weapon::model() = 0;

virtual int Weapon::countAmmunition() = 0;

virtual void Weapon::fire() = 0;



