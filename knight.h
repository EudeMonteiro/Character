#ifndef KNIGHT_H
#define KNIGHT_H

#include "character.h"

class Knight : public Character
{
  
  friend ostream &operator<<(ostream &, const Knight &);

  public:
    
    Knight();
    Knight(string, int, int, int, int, int, int, int, int);   
    Knight(const Knight &);
    ~Knight();


    void guard();
    void twoHands();
    void last_stand();
    void desperate(); 
    void setVigor(int);
    void setResistance(int);
    int getVigor() const;
    int getResistance() const;
    int calculateEffectiveHP() const;
    int calculateEffectiveDefense() const;    
    const Knight &operator=(const Knight &);    

  protected:
    int resistance;
    int vigor;

};

#endif
