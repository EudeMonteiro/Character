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


Knight::Knight(const Knight & otherKnight)
:Character(otherKnight)
{
  this->vigor = otherKnight.vigor;
  this->resistance = otherKnight.resistance;  
};

Knight::~Knight()
{  
};

void Knight::fight(Character & enemy){
  double damage = (2 * attack) - enemy.getDefense()/1.75;  
  generateRandomDamage(damage, enemy);

  cout << "Você desfere um golpe físico contra seu oponente!" << '\n';
  return;
}


void Knight::royalBoost()
{
  if(!royalBoostFlag){
    setHp(hp + ceil(vigor * 0.7) + ceil(resistance * 0.8));
    cout << "Vitalidade amplificada!" << '\n';
    royalBoostFlag = true;
    return;
  }

  cout << "Você já usou esta habilidade!";
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

void Knight::printStats() const
{

  Character::printStats( );
  cout << "Vigor: " << getVigor() << '\n';
  cout << "Resistência: " << getResistance() << '\n';
  cout << "Defesa efetiva: " << calculateEffectiveDefense() << '\n';
  cout << "HP efetivo: " << calculateEffectiveHP() << '\n';

  return;
}

/*
const Knight &Knight::operator=( const Knight &right )
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

  return *this;
}

bool Knight::operator==(const Knight &right) const
{   
  return ((name == right.name) &&
          (hp == right.hp) &&
          (mp == right.mp) &&
          (attack == right.attack) &&
          (defense == right.defense) &&
          (magic == right.magic) &&
          (evasion == right.evasion) &&
          (vigor == right.vigor)&&
          (resistance == right.resistance)); 
  
}
*/

/*
bool Knight::operator!=(const Knight &right) const
{
  return !(*this == right);
}
*/