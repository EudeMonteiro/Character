#include "character.h"

Character::Character(string name, int hp, int mp, int attack, int defense, int magic, int evasion)
{
  setName(name);
  setHp(hp);
  setMp(mp);
  setAttack(attack);
  setDefense(defense);
  setMagic(magic);
  setEvasion(evasion);

  
};

Character::Character()
{ 

  setName("Unknown Hero");
  setHp(50);
  setMp(20);
  setAttack(10);
  setDefense(8);
  setMagic(5);
  setEvasion(3);
  
};

Character::Character(const Character &other):name(other.name), hp(other.hp), mp(other.mp), attack(other.attack), defense(other.defense), 
magic(other.defense), evasion(other.evasion)
{
  
};

Character::~Character(){};


void Character::setName(string char_name)
{
  if(char_name.length() > 0){
    this->name = char_name;
    return;
  }

  this->name = "Unknown Hero";
};

void Character::setHp(int health)
{
  if(hp > 0){
    this->hp = health;
    return;
  }

  this->hp = 50;
};

void Character::setMp(int magic_points)
{
  if(mp >= 0){
    this->mp = magic_points;
    return;
  }

  this->mp = 0;
};

void Character::setAttack(int atk)
{
  if(atk > 0){
    this->attack = atk;
    return;
  }

  this->attack = 10;
};

void Character::setDefense(int def)
{
  if(def >= 0){
    this->defense = def;
    return;
  }

  this->defense = 0;
};

void Character::setMagic(int mag)
{
  if(mag > 0){
    this->magic = mag;
    return;
  }

  this->magic = 5;
  return;
};

void Character::setEvasion(int evs)
{
  if(evs >= 0){
    this->evasion = evs;
    return;
  }

  this->evasion = 0;
  return;
};

string Character::getName() const { return name; };
int Character::getHp() const { return hp;};
int Character::getMp() const { return mp;};
int Character::getAttack() const { return attack;};
int Character::getDefense() const { return defense;};
int Character::getMagic() const { return magic;};
int Character::getEvasion() const{ return evasion;};

void Character::useItem()
{
  string option;

  cout << "Escolha um item: Ether / Poção / Elixir: ";
  cin >> option;

  if(option == "ether"){
    mp+=50;
    cout << "Você usou um Ether! Seu MP foi aumentado em +50!\n";
    return;
  }

  else if(option == "poção"){
    hp+=70;
    cout << "Você usou uma Poção! Seu HP foi aumentado em +70!\n";
    return;
  }

  else if(option == "elixir"){
    mp+=100;
    hp+=100;
    cout << "Você usou um Elixir! Seu HP e MP foram aumentados em +100!\n";
    return;
  }

  cout << "Item inválido.\n";
  return;
}; 

ostream &operator<<(ostream &out, const Character &character)
{ 
  out << "Nome: " << character.getName() << '\n';
  out << "HP: " << character.getHp() << '\n';
  out << "MP: " << character.getMp() << '\n';
  out << "Ataque: " << character.getAttack() << '\n';
  out << "Defesa: " << character.getDefense() << '\n';
  out << "Magia: " << character.getMagic() << '\n';
  out << "Evasão: " << character.getEvasion() << '\n';

  return out;
}

bool Character::operator!() const
{
  return hp == 0;
}

bool Character::operator!=(const Character &right) const
{
  return !( *this == right);
}

const Character &Character::operator=( const Character &right )
{
  if ( &right != this ) { // previne autoatribuição
    name = right.name;
    hp = right.hp;
    mp = right.mp;
    attack = right.attack;
    defense = right.defense;
    magic = right.magic;
    evasion = right.evasion;
  }

  else{
    cout << "Tentativa de autoatribuição foi interrompida." << '\n';
  }

  return *this;   
}

bool Character::operator==(const Character &right) const
{
  if ((name == right.name) &&
      (hp == right.hp) &&          
      (mp == right.mp) &&
      (attack == right.attack) &&
      (defense == right.defense) &&
      (magic == right.magic) &&
      (evasion == right.evasion))
      {
        return true;
      };

  return false;
  
}