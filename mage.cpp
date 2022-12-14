#include "mage.h"

Mage::Mage()
:Character()
{
  this->magic_defense=5;
  this->magic_evasion=10;
};


Mage::Mage(string name, int hp, int mp, int attack, int defense, int magic, int evasion, int magic_defense_, int magic_evasion_)
:Character(name, hp, mp, attack, defense, magic, evasion)
{
  
  setMagicDefense(magic_defense_);
  setMagicEvasion(magic_evasion_);
};



Mage::Mage(const Mage & otherMage)
:Character( otherMage )
{
  this->magic_defense= otherMage.magic_defense;
  this->magic_evasion = otherMage.magic_evasion;  
};


Mage::~Mage()
{  
};


void Mage::setMagicDefense(int m_def)
{
  if(m_def >= 0)
  {
    this->magic_defense = m_def;
  }

  this->magic_defense=0;
    
};

void Mage::setMagicEvasion(int m_evs)
{
  if(m_evs >= 0)
  {
    this->magic_evasion = m_evs;
  }

  this->magic_evasion = 0;
};

int Mage::getMagicEvasion() const
{
  return this->magic_evasion;
};


int Mage::getMagicDefense() const
{
  return this->magic_defense;
};


void Mage::arcaneShield()
{
  magic_defense = ceil(mp * 1.5);
}

void Mage::fight(Character & enemy)
{ 
  //Generates random number between 0 and 100

  int evasion_chance = 100 * ( (double)rand() / (double)RAND_MAX );
  
  if(evasion_chance <= enemy.getEvasion()){
    cout << "Você errou o ataque!\n";
    return;
  }
  
  double damage = attack - (enemy.getDefense()/1.75);
  
  //generates random numbers
  double lower_bound = -log(damage);
  double upper_bound = log(damage);
  
  double deviation = (upper_bound - lower_bound) * ( (double)rand() / (double)RAND_MAX ) + lower_bound;
    
  damage += int(deviation);
  enemy.setHp(enemy.getHp() - damage);
  
  return;
}


void Mage::useMagic(Character &enemy)
{
  int cost = 30;
  if(mp-cost < 0)
  {
    cout << "Você não tem MP suficiente para usar magias\n";
    return;
  }
  
  double damage = magic - (enemy.getDefense()/1.75);
  
  generateRandomDamage(damage, enemy);

  mp-=cost;
  cout << "Você conjurou uma magia arcana!\n";
  return;
}


void Mage::dualcast(Character & enemy)
{ 
  int cost = 60;
  if(mp-cost < 0)
  {
    cout << "Você não tem MP suficiente para usar uma magia dupla!\n";
    return;
  }

  mp-=cost;
  magic = ceil(magic * 1.5);

  double damage = magic - (enemy.getDefense()/1.75);
  
  generateRandomDamage(damage, enemy);

  cout << "Você conjurou uma magia arcana dual!\n";
  return;
}

ostream &operator<<(ostream &out, const Mage &mage)
{
  mage.printStats();
  out << "Defensa mágica: " << mage.getMagicDefense() << '\n';
  out << "Evasão mágica: " << mage.getMagicEvasion() << '\n';    

  return out;

}


const Mage &Mage::operator=( const Mage &right )
{
  name = right.name;
  hp = right.hp;
  mp = right.mp;
  attack = right.attack;
  defense = right.defense;
  magic = right.magic;
  evasion = right.evasion;
  magic_defense = right.magic_defense;
  magic_evasion = right.magic_evasion;

  return *this;
}

bool Mage::operator!=(const Mage &right) const
{
  return !(*this == right);
}

bool Mage::operator==(const Mage &right) const
{ 
  return ((name == right.name) &&
          (hp == right.hp) &&
          (mp == right.mp) &&
          (attack == right.attack) &&
          (defense == right.defense) &&
          (magic == right.magic) &&
          (evasion == right.evasion) &&
          (magic_evasion == right.magic_evasion) && 
          (magic_defense == right.magic_defense));

  return true;
}
