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
  setHp(250);
  setMp(50);
  setAttack(20);
  setDefense(8);
  setMagic(20);
  setEvasion(3);  
};

Character::Character(const Character &other):name(other.name), hp(other.hp), mp(other.mp), attack(other.attack), defense(other.defense), 
magic(other.magic), evasion(other.evasion){};

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
  if(health > 0){
    this->hp = health;
    return;
  }

  this->hp = 0;
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


void Character::generateRandomDamage(double damage, Character &enemy)
{
  //generates random numbers
  double lower_bound = -log(damage);
  double upper_bound = log(damage);
  
  double deviation = (upper_bound - lower_bound) * ( (double)rand() / (double)RAND_MAX ) + lower_bound;
  
  damage += int(deviation);
  enemy.setHp(enemy.getHp() - damage);  
}

void Character::useItem()
{ 

  if(itemAmount == 0)
  {
    cout << "Voc?? n??o tem mais items!" << '\n';
    return;
  }

  string option;

  cout << "Escolha um item: Ether / Po????o / Elixir: ";
  cin >> option;


  if(option == "ether"){
    mp+=50;
    cout << "Voc?? usou um Ether! Seu MP foi aumentado em +50!\n";
    itemAmount--;
    return;
  }

  else if(option == "po????o"){
    hp+=70;
    cout << "Voc?? usou uma Po????o! Seu HP foi aumentado em +70!\n";
    itemAmount--;
    return;
  }

  else if(option == "elixir"){
    mp+=100;
    hp+=100;
    cout << "Voc?? usou um Elixir! Seu HP e MP foram aumentados em +100!\n";
    itemAmount--;
    return;
  }

  cout << "Item inv??lido.\n";
  return;
}; 

/*
ostream &operator<<(ostream &out, const Character &character)
{ 
  out << "Nome: " << character.getName() << '\n';
  out << "HP: " << character.getHp() << '\n';
  out << "MP: " << character.getMp() << '\n';
  out << "Ataque: " << character.getAttack() << '\n';
  out << "Defesa: " << character.getDefense() << '\n';
  out << "Magia: " << character.getMagic() << '\n';
  out << "Evas??o: " << character.getEvasion() << '\n';

  return out;
}
*/

void Character::printStats() const
{
  cout << "Nome: " << getName() << '\n';
  cout << "HP: " << getHp() << '\n';
  cout << "MP: " << getMp() << '\n';
  cout << "Ataque: " << getAttack() << '\n';
  cout << "Defesa: " << getDefense() << '\n';
  cout << "Magia: " << getMagic() << '\n';
  cout << "Evas??o: " << getEvasion() << '\n';
  return;
}


bool Character::operator!() const
{
  return hp == 0;
}

/*
bool Character::operator!=(const Character &right) const
{
  return !( *this == right);
}


const Character &Character::operator=( const Character &right )
{
  if ( &right != this ) { // previne autoatribui????o
    name = right.name;
    hp = right.hp;
    mp = right.mp;
    attack = right.attack;
    defense = right.defense;
    magic = right.magic;
    evasion = right.evasion;
  }

  else{
    cout << "Tentativa de autoatribui????o foi interrompida." << '\n';
  }

  return *this;   
}


bool Character::operator==(const Character &right) const
{
  return ((name == right.name) &&
          (hp == right.hp) &&
          (mp == right.mp) &&
          (attack == right.attack) &&
          (defense == right.defense) &&
          (magic == right.magic) &&
          (evasion == right.evasion));    
}
*/