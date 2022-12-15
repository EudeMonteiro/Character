#ifndef KNIGHT_H
#define KNIGHT_H

#include "character.h"

class Knight : public Character
{
  
  //friend ostream &operator<<(ostream &, const Knight &);

  public:
    
    Knight();
    Knight(string, int, int, int, int, int, int, int, int);   
    Knight(const Knight &);
    virtual ~Knight();

    void fight(Character &);
    virtual void guard() = 0;
    virtual void last_stand(Character &) = 0;
    void royalBoost();
    void printStats() const;
    void setVigor(int);
    void setResistance(int);
    int getVigor() const;
    int getResistance() const;
    int calculateEffectiveHP() const;
    int calculateEffectiveDefense() const;    
    

  protected:
    int resistance;
    int vigor;
    bool royalBoostFlag;

};

#endif
