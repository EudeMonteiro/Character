#include "mystic_knight.h"

MysticKnight::MysticKnight()
:Knight()
{
  this-> element_imbuition = "";
};


MysticKnight::MysticKnight(string name, int hp, int mp, int attack, int defense, int magic, int evasion, int resistance_, int vigor_, bool element_imbuition_)
:Knight(name, hp, mp, attack, defense, magic, evasion, resistance_, vigor_)
{
  
  this-> element_imbuition = element_imbuition_;
};



MysticKnight::MysticKnight(const MysticKnight & otherMysticKnight)
:Knight(otherMysticKnight)
{
  this->element_imbuition = otherMysticKnight.element_imbuition;
};

MysticKnight::~MysticKnight()
{  
};

string MysticKnight::getElementalImbuition() const
{
  return this->element_imbuition;
}

void MysticKnight::imbueElement()
{
  string option;

  cout << "Escolha um elemento: Fogo / Gelo / Eletricidade: ";
  cin >> option;

  if(mp-20<0)
  {
    cout << "Você não possui MP suficiente.\n";
    return;
  }

  if(option == "fogo"){
    int cost = 20;
    element_imbuition = "Fogo";
    cout << "Você imbuiu sua espada com a ardente chama!\n";
    mp -= cost;
    attack = ceil(attack * 1.2);
  }

  else if(option == "gelo"){
    int cost = 25;
    element_imbuition = "Gelo";
    cout << "Você imbuiu sua espada com o frio glacial!\n";
    mp -= cost;    
    attack = ceil(attack * 1.3);
  }

  else if(option == "eletricidade"){
    int cost = 30;
    element_imbuition = "Eletricidade";
    cout << "Você imbuiu sua espada com a fulgurosa eletricidade!\n";
    mp -= cost;
    attack = ceil(attack * 1.4);    
  }

  cout << "Item inválido.\n";
  return;
}; 

void MysticKnight::guard()
{
  defense = ceil(defense * 1.4);
  cout << "Defesa aumentada!" << '\n';
}


void MysticKnight::spellblade(Character &enemy)
{
  if(element_imbuition != "")
  {
    attack = ceil(attack*1.3);
    fight(enemy);
    cout << "Você desferiu um ataque elemental do tipo " << getElementalImbuition() << '\n';
    element_imbuition = "";
    attack = ceil(attack*0.7);
    return;
  }

  cout << "Sua espada não está imbuída com o poder de nenhum elemento...\n";
  return;
}

void MysticKnight::magicShell()
{

  if(mp-30 < 0)
  {
    cout << "Você não tem MP suficiente para utilizar a Redoma Mística!\n";
    return;
  }
  
  mp -= 30;
  defense += 30;
  return;
}

void MysticKnight::last_stand(Character &enemy)
{
  if(hp<=5){
    cout << "Você ataca com todas as suas forças para um golpe final!";
    attack *=2;
    fight(enemy);
    return;
  }

  cout << "Você não está em condições para utilizar este ataque.";
  return;
}

ostream &operator<<(ostream &out, const MysticKnight &mystic_knight)
{
  mystic_knight.printStats();

  string element = mystic_knight.getElementalImbuition();
  if(element == ""){
    element = "Nenhum";
  }

  out << "Elemento imbuído: " << element << '\n';
  return out;

}


const MysticKnight &MysticKnight::operator=( const MysticKnight &right )
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
  element_imbuition = right.element_imbuition;
  
  return *this;
}

bool MysticKnight::operator==(const MysticKnight &right) const
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
          (element_imbuition == right.element_imbuition));
  
}


bool MysticKnight::operator!=(const MysticKnight &right) const
{
  return !(*this == right);
}