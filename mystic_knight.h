#ifndef MYSTIC_KNIGHT_H
#define MYSTIC_KNIGHT_H

#include "knight.h"


class MysticKnight: public Knight
{ 
  friend ostream &operator<<(ostream &, const MysticKnight &);

  public:
    MysticKnight();
    MysticKnight(string, int, int, int, int, int, int, int, int, bool);   
    MysticKnight(const MysticKnight &);
    ~MysticKnight();

    void guard();
    void last_stand(Character &);
    void imbueElement();
    void magicShell();
    void spellblade(Character &);
    string getElementalImbuition() const;

    const MysticKnight &operator=(const MysticKnight &);
    bool operator==(const MysticKnight &) const;
    bool operator!=(const MysticKnight &) const;
    
  private:
    string element_imbuition;

};
#endif