#ifndef MAGE_H
#define MAGE_H

#include "character.h"

class Mage : public Character
{
  
  friend ostream &operator<<(ostream &, const Mage &);

  public:
    
    Mage();
    Mage(string, int, int, int, int, int, int, int, int);   
    Mage(const Mage &);
    ~Mage();


    void fight(Character &);    
    void arcaneShield();
    void useMagic(Character &);
    void dualcast(Character &);
    void setMagicDefense(int);
    void setMagicEvasion(int);
    int getMagicEvasion() const;
    int getMagicDefense() const;    
    const Mage &operator=(const Mage &);
    bool operator==(const Mage &) const;
    bool operator!=(const Mage &) const;

  protected:
    int magic_defense;
    int magic_evasion;

};

#endif