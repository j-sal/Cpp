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

string Gun::model()
{
    return this->gModel; 
}

int Gun::countAmmunition()
{
    return this->ammo;
}

void Gun::fire()
{
    if(ammo>0)
    {
        cout << "Bang with my " << gModel << endl;
        this->ammo--;
    }else
    cout << "\n" << endl;
}
