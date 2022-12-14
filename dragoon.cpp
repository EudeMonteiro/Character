#include "dragoon.h"

Dragoon::Dragoon()
:Knight()
{
  this-> on_air = false;  
};


Dragoon::Dragoon(string name, int hp, int mp, int attack, int defense, int magic, int evasion, int resistance_, int vigor_, bool on_air)
:Knight(name, hp, mp, attack, defense, magic, evasion, resistance_, vigor_)
{
  
  this-> on_air = on_air;
};



Dragoon::Dragoon(const Dragoon & otherDragoon)
:Knight(otherDragoon )
{
  this->on_air = otherDragoon.on_air;  
};

Dragoon::~Dragoon()
{  
};

void Dragoon::jump()
{
  if(!(on_air))
  {
    on_air = true;
  }

  cout << "O dragão ascende aos céus para atacar furiosamente!\n";
  return;
}

void Dragoon::guard()
{
  if(on_air){
    cout << "Você não pode se defender no ar!\n";
    return;
  }

  defense = ceil(defense * 1.3);
  return;
}

void Dragoon::last_stand()
{
  if(hp<=5 && on_air){
    cout << "Você ataca com todas as suas forças para um golpe final!";
    attack *=2;
    aerialStrike();
    return;
  }

  cout << "Você não está em condições para utilizar este ataque.";
  return;
}

void Dragoon::aerialStrike()
{
  if(on_air)
  {
    attack += 20;
    on_air = false;
  }

  cout << "Você atacou dos céus com poderio magnificado!!\n";
}

void Dragoon::setOnAirStatus(bool status)
{
  this->on_air = status;
  return;
}

bool Dragoon::getOnAirStatus() const
{
  return on_air;
}

ostream &operator<<(ostream &out, const Dragoon &dragoon)
{
  dragoon.printStats();

  string air = dragoon.getOnAirStatus()? " Sim":" Não";

  out << "Está no ar?: " << air << '\n';  

  return out;
}


const Dragoon &Dragoon::operator=( const Dragoon &right )
{
  name = right.name;
  hp = right.hp;
  mp = right.mp;
  attack = right.attack;
  defense = right.defense;
  magic = right.magic;
  evasion = right.evasion;
  vigor = right.vigor;
  resistance = right.resistance;
  on_air = right.on_air;
  
  return *this;
}

bool Dragoon::operator==(const Dragoon &right) const
{ 
  return ((name == right.name) &&
          (hp == right.hp) &&
          (mp == right.mp) &&
          (attack == right.attack) &&
          (defense == right.defense) &&
          (magic == right.magic) &&
          (evasion == right.evasion) &&
          (vigor == right.vigor) &&
          (resistance == right.resistance) &&
          (on_air == right.on_air));
}


bool Dragoon::operator!=(const Dragoon &right) const
{
  return !(*this == right);
}


