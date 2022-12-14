#ifndef CRYOMANCER_H
#define CRYOMANCER_H

#include "mage.h"

class Cryomancer: public Mage
{
  friend ostream &operator<<(ostream &, const Cryomancer &);
  
  public:
    Cryomancer();
    Cryomancer(string, int, int, int, int, int, int, int, int, bool); 
    Cryomancer(const Cryomancer &);
    ~Cryomancer();

    void timeWarp();
    void iceBarrier();
    void freezingBreath();
    void setTimeWarpStatus(bool);
    bool getTimeWarpStatus() const;

    const Cryomancer &operator=(const Cryomancer &);
    bool operator==(const Cryomancer &) const;
    bool operator!=(const Cryomancer &) const;

  private:
    bool timeWarpEnabled;
    
    
};


#endif