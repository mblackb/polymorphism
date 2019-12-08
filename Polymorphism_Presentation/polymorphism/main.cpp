// Willetta Song
// Polymorphism demonstration
// 18-Jan-2018

#include <iostream>
#include <iomanip>

using namespace std;

class Monster
{
public:
    Monster() {}
    void setHitPoints(int hP)
    {
        hitPoints = hP;
    }

    void attack()
    {
        cout << "\n(Calling non-virtual attack1 function in Monster class)" << endl;
        cout << "This is what happens when you don't declare virtual :|" << endl;
    }

    virtual void attack1()
    {
        cout << "\n(Calling virtual attack1 function in Monster class)" << endl;
    }

protected:
    int hitPoints;
};

class Vampire: public Monster
{
public:
    Vampire() {}
    void attack()
    {
        cout << "\n(Calling non-virtual attack function in Vampire class)" << endl;
        cout << "Vlah! *bites your arm* -" << hitPoints << endl;
    }

    virtual void attack1() override
    {
        cout << "\n(Calling virtual attack1 override function in Vampire class)" << endl;
        cout << "Vlah! *bites your arm* -" << hitPoints << endl;
    }
};

class Zombie: public Monster
{
public:
    Zombie() {}
    void attack()
    {
        cout << "\n(Calling non-virtual attack function in Zombie class)" << endl;
        cout << "Brrrrraaains.. *bites your toe* -" << hitPoints << endl;
    }
};

int main()
{
    // Vampire vampire();
    // Zombie zombie();
    // Monster monster();

    Vampire vampie; // create derived-class vampire object
    Zombie bob; // create derived-class zombie object
    Monster *monsterPtr1 = &vampie; // base-class pointer to a derived-class address
    Monster *monsterPtr2 = &bob;    // base-class pointer to a derived-class address
    Monster *monsterPtr3 = nullptr; // base-class pointer to a null pointer

    // monsterPtr1 calls base-class monster f-n setHitPoints
    // assigns to derived-class object vampie address
    monsterPtr1->setHitPoints(5);
    monsterPtr2->setHitPoints(10);

    cout << "\n***Vampire object calls Vampire attack function:" << endl;
    vampie.attack(); // vampire object calls vampire attack function
    cout << "\n***Zombie object calls Zombie attack function:" << endl;
    bob.attack(); // zombie object calls zombie attack function

    monsterPtr3 = &vampie; // base-class pointer to derived-class object
    cout << "\n***Base-class pointer defaults to call pointer (base-class) function without virtual declaration" << endl;
    monsterPtr3->attack(); // base-class pointer defaults to call pointer (base-class) function
    cout << "\n***Base-class pointer overrides default to base-class function to call derived-class function" << endl;
    monsterPtr3->attack1(); // base-class pointer overrides base-class function to call derived-class function
    return 0;
}
