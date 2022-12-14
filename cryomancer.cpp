#include "cryomancer.h"

Cryomancer::Cryomancer()
:Mage()
{
  this->timeWarpEnabled = false;
}


Cryomancer::Cryomancer(string name, int hp, int mp, int attack, int defense, int magic, int evasion, int magic_defense, int magic_evasion, bool timeWarpEnabled)
:Mage(name, hp, mp, attack, defense, magic, evasion, magic_defense, magic_evasion)
{
  setTimeWarpStatus(false);
}

Cryomancer::Cryomancer(const Cryomancer & otherCryomancer)
:Mage(static_cast< Mage >( otherCryomancer ))
{
  this->timeWarpEnabled = otherCryomancer.timeWarpEnabled;  
};

Cryomancer::~Cryomancer(){}


void Cryomancer::iceBarrier()
{
  int cost = 30;
  if(mp - cost < 0){
    cout << "Você não tem MP suficiente para utilizar esta habilidade!" << '\n';
    return;
  }

  defense = ceil(defense * 1.2);
  mp -= cost;
  return;
};

void Cryomancer::freezingBreath()
{
  int cost = 25;
  if(mp - cost < 0){
    cout << "Você não tem MP suficiente para utilizar esta habilidade!" << '\n';
    return;
  }

  magic = ceil(defense * 1.25);
  mp -= cost;
  return;
};

void Cryomancer::timeWarp()
{
  int cost=20;
  if(mp - cost < 0){
    cout << "Você não tem MP suficiente para utilizar esta habilidade!" << '\n';
    return;
  }

  if(!timeWarpEnabled){
    setTimeWarpStatus(true);
    cout << "Você cria uma marca cronológica para voltar no tempo..." << '\n';
    return;
  }

  hp += 200;
  mp -= cost;

  cout << "Você se curou com +200 de HP!\n";
  setTimeWarpStatus(false);
}


void Cryomancer::setTimeWarpStatus(bool status)
{
  this->timeWarpEnabled = status;
}

bool Cryomancer::getTimeWarpStatus() const
{
  return timeWarpEnabled;
}

ostream &operator<<(ostream &out, const Cryomancer &cryomancer)
{
  out << static_cast< Mage > (cryomancer);

  string tw_status = cryomancer.getTimeWarpStatus()? " Sim":" Não";

  out << "Time Warp ativo?" << tw_status << '\n';
  return out;

}


const Cryomancer &Cryomancer::operator=( const Cryomancer &right )
{
  *static_cast<Cryomancer * >(this) = static_cast< Cryomancer >( right );

  this->timeWarpEnabled = right.timeWarpEnabled;
  
  return *this;
}

bool Cryomancer::operator==(const Cryomancer &right) const
{ 
  if(!(static_cast<Mage>(*this) == static_cast<Mage>(right))){
    return false;
  }

  return (this->timeWarpEnabled == right.timeWarpEnabled);
}

bool Cryomancer::operator!=(const Cryomancer &right) const
{
  return !(*this == right);
}