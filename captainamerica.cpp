#include "captainamerica.hpp"
#include <iostream>
#include <string>
#include <vector>

using namespace std;

CaptainAmerica::CaptainAmerica()
{
    /*this->rank="Captain";
    this->name="CaptainMurica";*/
}

CaptainAmerica::~CaptainAmerica()
{
    //dtor
}

void CaptainAmerica::identification()
{
    cout << "I am Captain America but I wish I was Batman.\n" << endl;
}

void CaptainAmerica::setLeft(Weapon *)
{
    cout << "I don't need it, I have my vibranium shield." << endl;
}

void CaptainAmerica::setRight(Weapon *)
{
    cout << "I don't need it, I have my vibranium shield." << endl;
}

void CaptainAmerica::fireLeft()
{
    cout << "PLEASE HELP ME SpiderMan!!!\n" << endl;
}

void CaptainAmerica::fireRight()
{
    cout << "PLEASE HELP ME SpiderMan!!!\n" << endl;
}
