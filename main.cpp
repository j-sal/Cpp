#include <iostream>
#include <weapon.hpp>
#include <vehicle.hpp>
#include <soldier.hpp>
#include <gun.hpp>
#include <shotgun.hpp>
#include <riffle.hpp>
#include <jeep.hpp>
#include <blackbird.hpp>
#include <sniper.hpp>
#include <infantry.hpp>
#include <captainamerica.hpp>

using namespace std;

int main()
{

    Gun newWp = ShotGun();
    Infantry inff = Infantry("booboo");
    inff.identification();
    inff.scream();
    inff.setLeft(&newWp);
    inff.fireLeft();
    cout << newWp.countAmmunition() << endl;
    Gun rweap = Riffle();
    inff.setRight(&rweap);
    inff.fireRight();
    CaptainAmerica newCap = CaptainAmerica();
    newCap.identification();
    newCap.setLeft(&rweap);
    newCap.fireLeft();
    return 0;
}
