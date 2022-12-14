#include <iostream>
#include "character.cpp"
#include "knight.cpp"
#include "dragoon.cpp"
#include "mystic_knight.cpp"
#include "mage.cpp"
#include "cryomancer.cpp"
#include "geomancer.cpp"
#include <cxxabi.h>
#include <vector>

using std::vector;

string getTypeid(Character &chr)
{
  //Removes number associated to typeid
  return abi::__cxa_demangle(typeid(chr).name(), 0, 0, 0);
}

int main()
{
  
  srand(time(NULL));  
  vector <Character * > character(5);

  
  character[0] = new MysticKnight("Kain", 150, 60, 25, 15, 5, 5, 10, 20, false);
  character[1] = new Dragoon;
  character[2] = new Mage("Faris", 120, 150, 30, 20, 90, 5, 30, 3);
  character[3] = new Cryomancer("Fryevia", 120, 250, 30, 20, 90, 10, 30, 20, false);
  character[4] = new Geomancer;

  for (size_t i=0; i < character.size(); i++){
    character[i]->printStats();
    cout << '\n';
  }


  //Readjust class stats
  for (size_t i=0; i < character.size(); i++){
    
    if (MysticKnight *p = dynamic_cast<MysticKnight*>(character[i])){
      
      (*character[i]).setHp(500);
      (*character[i]).setMp(150);
      
    }

    else if (Dragoon *p = dynamic_cast<Dragoon*>(character[i])){
      
      (*character[i]).setHp(600);
      (*character[i]).setAttack(50);
      
    }

    else if(Cryomancer *p = dynamic_cast<Cryomancer*>(character[i])){
      
      (*character[i]).setHp(480);
      (*character[i]).setMp(300);
      
    }

    else if(Geomancer *p = dynamic_cast<Geomancer*>(character[i])){
      
      (*character[i]).setHp(420);
      (*character[i]).setMp(230);
      (*character[i]).setEvasion(7);      
    }
    
    else if (Mage *p = dynamic_cast<Mage*>(character[i])){
      
      (*character[i]).setHp(450);
      (*character[i]).setMp(250);
      (*character[i]).setMagic(120);
      (*character[i]).setAttack(10);      
    }

    else{break;}

    cout << getTypeid(*character[i]) << " " <<  (*character[i]).getName() << " teve seus atributos renovados!\n";    
  }
  
  
  cout << '\n';
  for (size_t i=0; i < character.size(); i++){
    character[i]->printStats();
    cout << '\n';
  }
 
  for (size_t i=0; i<character.size(); i++){
    cout << "Deletando objeto da classe " << getTypeid(*character[i]) << '\n';
    delete character[ i ];
  }
  

  return 0;
}