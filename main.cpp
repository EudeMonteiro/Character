#include <iostream>

#include "character.h"
#include "character.cpp"
#include "knight.h"
#include "knight.cpp"
#include "dragoon.h"
#include "dragoon.cpp"
#include "mystic_knight.h"
#include "mystic_knight.cpp"
#include "mage.h"
#include "mage.cpp"


int main()
{

  //string name, int hp, int mp, int attack, int defense, int magic, int evasion, int resistance_, int vigor_
  Character Edge;
  Knight Cecil("Cecil", 100, 70, 35, 25, 5, 5, 10, 20);
  Dragoon Kain("Kain", 150, 60, 25, 15, 5, 5, 10, 20, false);
  MysticKnight Galuf;
  Mage Faris("Faris", 120, 150, 30, 20, 90, 10, 30, 20);

  cout << "Novos personagens foram criados!\n";

  Edge.setName("Edge");
  Galuf.setName("Galuf");
    
  Edge.useItem();
  
  cout << '\n';
  Cecil.twoHands();
  Cecil.guard();

  cout << '\n';
  Kain.jump();
  Kain.aerial_strike();

  cout << '\n';
  Galuf.magicShell();
  Galuf.imbueElement();
  Galuf.spellblade();

  cout << '\n';
  Faris.arcanePower();
  Faris.arcaneShield();
  Faris.dualcast();
  //Faris.useMagic();

  cout << Edge << '\n';
  cout << Cecil << '\n';
  cout << Kain << '\n';
  cout << Galuf << '\n';
  cout << Faris << '\n';

  cout << "Uma presença sombria semelhante a Cecil se aproxima...\n";
  Knight DarkCecil;
  DarkCecil = Cecil;
  cout << DarkCecil << '\n';

  
  DarkCecil.setHp(0);
  if(!(DarkCecil))
  {
    cout << DarkCecil.getName() << " está caído!\n";
  }

  if(Kain != Galuf)
  {
    cout << "Eles são diferentes.\n";
  }
}