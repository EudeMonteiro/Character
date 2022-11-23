#ifndef MYSTIC_KNIGHT_H
#define MYSTIC_KNIGHT_H

#include "knight.h"


class MysticKnight: public Knight
{ 
  friend ostream &operator<<(ostream &, const Knight &);

  public:
    MysticKnight();
    MysticKnight(string, int, int, int, int, int, int, int, int, bool);   
    MysticKnight(const MysticKnight &);
    ~MysticKnight();

    void imbueElement();
    void magicShell();
    void spellblade();
    string getElementalImbuition() const;

    const MysticKnight &operator=(const MysticKnight &);
    
  private:
    string element_imbuition;

};
#endif