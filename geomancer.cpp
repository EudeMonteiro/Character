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

void Geomancer::earthquake(Character &enemy)
{
  int cost = 50;
  int tempMagic = magic;

  if(earthquakeCasted){
    cout << "Você já utilizou Terremoto!\n";
    return;
  }

  if(mp - cost < 0){
    cout << "Você não tem MP suficiente para utilizar esta habilidade!\n";
    return;
  }

  int crit_chance = 1 + (rand() % 100);

  if(crit_chance <= 10){
    cout << "Dano Crítico!\n";
    magic *= 2;
  }

  else{
    magic = ceil(magic * 1.4);
  }

  mp -= cost;
  earthquakeCasted = true;
  useMagic(enemy);
  setMagic(tempMagic);

  cout << "A fúria de Gaia estremece a terra em conjunção à sua magia arcana!\n";
  return;
}

void Geomancer::windSlash(Character &enemy)
{
  int cost = 30;
  int tempAtk = attack;
  if(mp - cost < 0){
    cout << "Você não tem MP suficiente para utilizar esta habilidade!\n";
    return;
  }
  
  attack = ceil(attack * 1.3);
  mp -= cost;
  fight(enemy);  
  cout << "Você disparou uma poderosa rajada de ar!\n";
  setAttack(tempAtk);
  return;
}


void Geomancer::sandstorm(Character &enemy)
{
  int cost = 35;

  if(mp - cost < 0){
    cout << "Você não tem MP suficiente para utilizar esta habilidade!\n";
    return;
  }
    
  mp -= cost;

  enemy.setHp(ceil(enemy.getHp() * 0.7));
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