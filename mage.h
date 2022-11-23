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


    void arcanePower();
    void arcaneShield();
    void useMagic();
    void dualcast();
    void setMagicDefense(int);
    void setMagicEvasion(int);
    int getMagicEvasion() const;
    int getMagicDefense() const;
    int calculateEffectiveDefense() const;
    int calculateEffectiveEvasion() const;
    const Mage &operator=(const Mage &);
    

  protected:
    int magic_defense;
    int magic_evasion;

};

#endif