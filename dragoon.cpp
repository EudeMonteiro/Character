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


Dragoon::~Dragoon()
{  
};

Dragoon::Dragoon(const Dragoon & otherDragoon)
:Knight(static_cast< Knight >( otherDragoon ))
{
  this->on_air = otherDragoon.on_air;  
};


void Dragoon::jump()
{
  if(!(on_air))
  {
    on_air = true;
  }

  cout << "O dragão ascende aos céus para atacar furiosamente!\n";
}

void Dragoon::aerial_strike()
{
  if(on_air)
  {
    attack += 20;
    on_air = false;
  }

  cout << "Você atacou dos céus com poderio magnificado!!\n";
}

bool Dragoon::getIsOnAir() const
{
  return on_air;
}

ostream &operator<<(ostream &out, const Dragoon &dragoon)
{
  out << static_cast< Character > (dragoon);

  string air = dragoon.getIsOnAir()? "Sim":"Não";

  out << "Está no ar?: " << air << '\n';  

  return out;

}


const Dragoon &Dragoon::operator=( const Dragoon &right )
{
  *static_cast<Dragoon * >(this) = static_cast< Dragoon >( right );

  this->on_air = right.on_air;
  
  return *this;
}