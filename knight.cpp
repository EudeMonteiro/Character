#include "knight.h"

Knight::Knight()
:Character()
{
  this->resistance=5;
  this->vigor=10;
};


Knight::Knight(string name, int hp, int mp, int attack, int defense, int magic, int evasion, int resistance_, int vigor_)
:Character(name, hp, mp, attack, defense, magic, evasion)
{
  
  setVigor(vigor_);
  setResistance(resistance_);
};


Knight::~Knight()
{  
};

Knight::Knight(const Knight & otherKnight)
:Character(static_cast< Character >( otherKnight ))
{
  this->vigor = otherKnight.vigor;
  this->resistance = otherKnight.resistance;  
};


void Knight::guard()
{
  defense = ceil(defense * 1.5);
  cout << "Defesa aumentada!" << '\n';
};


void Knight::twoHands()
{
  attack *= 2;
  cout << "Ataque duplicado!" << '\n';

};


void Knight::last_stand()
{
  if(hp<=5){
    attack *= 3;
    defense = 0;
  }
};

void Knight::setVigor(int vigor_)
{
  if(vigor_>=0){
    this->vigor=vigor_;
  }
  
  else{
    this->vigor=0;    
  };
};

void Knight::setResistance(int resistance_)
{
  if(resistance_>=0){
    this->resistance=resistance_;
  }

  else{
    this->resistance=0;
  };
};


int Knight::getVigor() const
{
  return this->vigor;
}

int Knight::getResistance() const
{
  return this->resistance;
}

int Knight::calculateEffectiveHP() const
{
  return ceil((hp + vigor)*1.2);
}

int Knight::calculateEffectiveDefense() const
{
  return ceil((defense + resistance)*1.5);
}

ostream &operator<<(ostream &out, const Knight &knight)
{
  out << static_cast< Character > (knight);
  out << "Vigor: " << knight.getVigor() << '\n';
  out << "Resistência: " << knight.getResistance() << '\n';
  out << "Defesa efetiva: " << knight.calculateEffectiveDefense() << '\n';
  out << "HP efetivo: " << knight.calculateEffectiveHP() << '\n';  

  return out;

}


const Knight &Knight::operator=( const Knight &right )
{
  *static_cast<Character * >(this) = static_cast< Character >( right );

  this->vigor = right.vigor;
  this->resistance = right.resistance;

  return *this;
}

