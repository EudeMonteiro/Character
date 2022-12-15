#ifndef CHARACTER_H
#define CHARACTER_H

#include <string>
#include <iostream>
#include <math.h>
#include <random>

using std::string;
using std::cout;
using std::cin;
using std::ostream;


class Character
{
  //friend ostream &operator<<(ostream &, const Character &);

  public:
    Character();
    Character(string, int, int, int, int, int, int);    
    Character(const Character &);
    virtual ~Character();
    
    virtual void fight(Character &) = 0;
    void useItem();
    void generateRandomDamage(double, Character &);

    void setName(string);
    void setHp(int);
    void setMp(int);
    void setAttack(int);
    void setDefense(int);
    void setMagic(int);
    void setEvasion(int);
    string getName() const;
    int getHp() const;
    int getMp() const;
    int getAttack() const;
    int getDefense() const;
    int getMagic() const;
    int getEvasion() const;
    virtual void printStats() const;
    
    bool operator!() const;

  protected:
    string name;
    int hp;
    int mp;
    int attack;
    int defense;
    int magic;
    int evasion;
    int itemAmount = 5;
};

#endif