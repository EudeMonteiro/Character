#ifndef GEOMANCER_H
#define GEOMANCER_H

#include "mage.h"

class Geomancer: public Mage
{
  friend ostream &operator<<(ostream &, const Geomancer &);
  
  public:
    Geomancer();
    Geomancer(string, int, int, int, int, int, int, int, int, bool); 
    Geomancer(const Geomancer &);
    ~Geomancer();

    void earthquake();
    void windSlash();
    void sandstorm();    
    void setEarthquakeStatus(bool);
    bool getEarthquakeStatus() const;

    const Geomancer &operator=(const Geomancer &);
    bool operator==(const Geomancer &) const;
    bool operator!=(const Geomancer &) const;

  private:
    
    bool earthquakeCasted; //Checks whether Earthquake was used (one time only)    
};


#endif