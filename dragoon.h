#ifndef DRAGOON_H
#define DRAGOON_H

#include "knight.h"


class Dragoon: public Knight
{
  public:
    Dragoon();
    Dragoon(string, int, int, int, int, int, int, int, int, bool);   
    Dragoon(const Dragoon &);
    ~Dragoon();

    void jump();
    void aerial_strike();
    bool getIsOnAir() const;

    const Dragoon &operator=(const Dragoon &);    

  private:
    bool on_air;

};
#endif