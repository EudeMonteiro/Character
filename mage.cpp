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


Mage::~Mage()
{  
};

Mage::Mage(const Mage & otherMage)
:Character(static_cast< Character >( otherMage ))
{
  this->magic_defense= otherMage.magic_defense;
  this->magic_evasion = otherMage.magic_evasion;  
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


void Mage::arcanePower()
{
  mp = ceil(mp * 1.3);
}


void Mage::arcaneShield()
{
  magic_defense = ceil(mp * 1.5);
}


int Mage::calculateEffectiveDefense() const
{
  return defense + magic_defense;
}


int Mage::calculateEffectiveEvasion() const
{
  return evasion + magic_evasion;
}


void Mage::useMagic()
{
  if(mp-30 < 0)
  {
    cout << "Você não tem MP suficiente para usar magias\n";
    return;
  }

  mp-=30;
  cout << "Você conjurou uma magia arcana!\n";
  return;
}


void Mage::dualcast()
{
  if(mp-60 < 0)
  {
    cout << "Você não tem MP suficiente para usar uma magia dupla!\n";
    return;
  }

  mp-=60;
  magic = ceil(magic * 1.05);
  cout << "Você conjurou uma magia arcana dual!\n";
  return;
}

ostream &operator<<(ostream &out, const Mage &mage)
{
  out << static_cast< Character > (mage);
  out << "Defensa mágica: " << mage.getMagicDefense() << '\n';
  out << "Evasão mágica: " << mage.getMagicEvasion() << '\n';
  out << "Defesa efetiva: " << mage.calculateEffectiveDefense() << '\n';
  out << "Evasão efetiva: " << mage.calculateEffectiveEvasion() << '\n';  

  return out;

}


const Mage &Mage::operator=( const Mage &right )
{
  *static_cast<Character * >(this) = static_cast< Character >( right );

  this->magic_defense = right.magic_defense;
  this->magic_evasion = right.magic_evasion;

  return *this;
}