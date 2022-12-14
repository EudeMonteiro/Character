#ifndef DRAGOON_H
#define DRAGOON_H

#include "knight.h"


class Dragoon: public Knight
{

  friend ostream &operator<<(ostream &, const Dragoon &);
  
  public:
    Dragoon();
    Dragoon(string, int, int, int, int, int, int, int, int, bool);
    Dragoon(const Dragoon &);
    ~Dragoon();

    void jump();
    void guard();
    void last_stand();
    void aerialStrike();
    void setOnAirStatus(bool);
    bool getOnAirStatus() const;

    const Dragoon &operator=(const Dragoon &);
    bool operator==(const Dragoon &) const;
    bool operator!=(const Dragoon &) const;    

  private:
    bool on_air;

};
#endif