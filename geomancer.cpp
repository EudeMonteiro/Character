#include "geomancer.h"

Geomancer::Geomancer()
:Mage()
{
  this->earthquakeCasted = false;
}


Geomancer::Geomancer(string name, int hp, int mp, int attack, int defense, int magic, int evasion, int magic_defense, int magic_evasion, bool earthquakeCasted)
:Mage(name, hp, mp, attack, defense, magic, evasion, magic_defense, magic_evasion)
{
  setEarthquakeStatus(false);
}

Geomancer::Geomancer(const Geomancer & otherGeomancer)
:Mage(static_cast< Mage >( otherGeomancer ))
{
  this->earthquakeCasted = otherGeomancer.earthquakeCasted;  
};

Geomancer::~Geomancer(){}


void Geomancer::setEarthquakeStatus(bool status)
{
  earthquakeCasted = status;
  return;
}

bool Geomancer::getEarthquakeStatus() const
{
  return earthquakeCasted;
}

void Geomancer::earthquake()
{
  int cost = 50;

  if(earthquakeCasted){
    cout << "Você já utilizou Earthquake!\n";
    return;
  }

  if(mp - cost < 0){
    cout << "Você não tem MP suficiente para utilizar esta habilidade!\n";
    return;
  }

  int crit_chance = 1 + (rand() % 100);

  if(crit_chance <= 5){
    cout << "Dano Crítico!\n";
    attack *= 2;
  }

  else{
    attack = ceil(attack * 1.3);
  }

  mp -= cost;
  earthquakeCasted = true;
  return;
}

void Geomancer::windSlash()
{
  int cost = 30;

  if(mp - cost < 0){
    cout << "Você não tem MP suficiente para utilizar esta habilidade!\n";
    return;
  }
  
  attack = ceil(attack * 1.1);
  mp -= cost;
  return;
}


void Geomancer::sandstorm()
{
  int cost = 35;

  if(mp - cost < 0){
    cout << "Você não tem MP suficiente para utilizar esta habilidade!\n";
    return;
  }
  
  attack = ceil(attack * 1.2);
  mp -= cost;
  return;
}


ostream &operator<<(ostream &out, const Geomancer &geomancer)
{
  out << static_cast< Mage > (geomancer);

  string tw_status = geomancer.getEarthquakeStatus()? " Sim":" Não";

  out << "Earthquake já utilizado?" << tw_status << '\n';
  return out;
}


const Geomancer &Geomancer::operator=( const Geomancer &right )
{
  *static_cast<Geomancer * >(this) = static_cast< Geomancer >( right );

  this->earthquakeCasted= right.earthquakeCasted;
  
  return *this;
}

bool Geomancer::operator==(const Geomancer &right) const
{ 
  if(!(static_cast<Mage>(*this) == static_cast<Mage>(right))){
    return false;
  }

  return (this->earthquakeCasted == right.earthquakeCasted);
}

bool Geomancer::operator!=(const Geomancer &right) const
{
  return !(*this == right);
}