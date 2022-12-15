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


vector <string> dragoonOptions = {"Atacar", "Defender", "Pular", "Investida Celestial", "Ultimato", "Usar item"};
vector <string> mKnightOptions = {"Atacar", "Defender", "Imbuir", "SpellBlade", "Ultimato", "Usar item"};
vector <string> cryomancerOptions = {"Atacar", "Dualcast", "Usar Magia", "Distorção Temporal", "Barreira Glacial", "Usar item"};
vector <string> geomancerOptions = {"Atacar", "Terremoto", "Usar Magia", "Rajada Eólica", "Tempestade de Areia", "Usar item"};

void chooseDragoonAction(Dragoon *p, Character &enemy)
{

  cout << "Ações: \n";

  for (size_t i=0; i < dragoonOptions.size(); i++)
  {
    cout << i+1 << " - " << dragoonOptions[i] << '\n';
  }
  
  int d;
  cout << "Escolha uma ação: ";
  cin >> d;


  switch(d){

    case 1:
    {
      (*p).fight(enemy);
      break;
    }

    case 2:
    {
      (*p).guard();
      break;
    }

    case 3:
    {
      (*p).jump();
      break;
    }

    case 4:
    {
      (*p).aerialStrike(enemy);
      break;
    }

    case 5:
    {
      (*p).last_stand(enemy);
      break;
    }

    case 6:
    {
      (*p).useItem();
      break;
    }

    default: 
      cout << "Ação inválida.\n";
      return;
  };
};


void chooseMKnightAction(MysticKnight *p, Character &enemy)
{
  cout << "Ações: \n";

  for (size_t i=0; i < mKnightOptions.size(); i++)
  {
    cout << i+1 << " - " << mKnightOptions[i] << '\n';
  }
  
  int m;
  cout << "Escolha uma ação: ";
  cin >> m;


  switch(m){

    case 1:
    {
      (*p).fight(enemy);
      break;
    }

    case 2:
    {
      (*p).guard();
      break;
    }

    case 3:
    {
      (*p).imbueElement();
      break;
    }

    case 4:
    {
      (*p).spellblade(enemy);
      break;
    }

    case 5:
    {
      (*p).last_stand(enemy);
      break;
    }

    case 6:
    {
      (*p).useItem();
      break;
    }

    default: 
      cout << "Ação inválida.\n";
      return;
  };
};


void chooseCryomancerAction(Cryomancer *p, Character &enemy)
{
  cout << "Ações: \n";

  for (size_t i=0; i < cryomancerOptions.size(); i++)
  {
    cout << i+1 << " - " << cryomancerOptions[i] << '\n';
  }
  
  int c;
  cout << "Escolha uma ação: ";
  cin >> c;


  switch(c){

    case 1:
    {
      (*p).fight(enemy);
      break;
    }

    case 2:
    {
      (*p).dualcast(enemy);
      break;
    }

    case 3:
    {
      (*p).useMagic(enemy);
      break;
    }

    case 4:
    {
      (*p).timeWarp();
      break;
    }

    case 5:
    {
      (*p).iceBarrier();
      break;
    }

    case 6:
    {
      (*p).useItem();
      break;
    }

    default: 
      cout << "Ação inválida.\n";
      return;
  };
};


void chooseGeomancerAction(Geomancer *p, Character &enemy)
{
  cout << "Ações: \n";

  for (size_t i=0; i < geomancerOptions.size(); i++)
  {
    cout << i+1 << " - " << geomancerOptions[i] << '\n';
  }
  
  int g;
  cout << "Escolha uma ação: ";
  cin >> g;


  switch(g){

    case 1:
    {
      (*p).fight(enemy);
      break;
    }

    case 2:
    {
      (*p).earthquake(enemy);
      break;
    }

    case 3:
    {
      (*p).useMagic(enemy);
      break;
    }

    case 4:
    {
      (*p).windSlash(enemy);
      break;
    }

    case 5:
    {
      (*p).sandstorm(enemy);
      break;
    }

    case 6:
    {
      (*p).useItem();
      break;
    }

    default: 
      cout << "Ação inválida.\n";
      return;
  };
};


void getClassMenu(Character *p, Character &enemy)
{
  if(Dragoon *a = dynamic_cast<Dragoon*>(p)){

    Dragoon *p1 = dynamic_cast<Dragoon*>(p);
    chooseDragoonAction(p1, enemy);
    return;
  }

  else if (MysticKnight *a = dynamic_cast<MysticKnight*>(p)){
    
    MysticKnight *p1 = dynamic_cast<MysticKnight*>(p);    
    chooseMKnightAction(p1, enemy);
    return;
  }

  else if(Cryomancer *a = dynamic_cast<Cryomancer*>(p)){
    Cryomancer *p1 = dynamic_cast<Cryomancer*>(p);
    chooseCryomancerAction(p1, enemy);
    return;
  }
  
  else if(Geomancer *a = dynamic_cast<Geomancer*>(p)){
    
    Geomancer *p1 = dynamic_cast<Geomancer*>(p);
    chooseGeomancerAction(p1, enemy);
    return;
  }

  else{return;}
}

int main()
{
  
  srand(time(NULL));  


  int x, y;
  Character *p1, *p2;
  
  cout << "1 - Dragoon\n2 - MysticKnight\n3 - Cryomancer\n4 - Geomancer\n\n";
  cout << "Escolha uma classe para o Jogador 1: ";
  cin >> x;

  switch(x)
  {
    case 1:
    {
      p1 = new Dragoon;
      break;
    }

    case 2:
    {
      p1 = new MysticKnight;      
      break;
    }

    case 3:
    {
      p1 = new Cryomancer;
      break;
    }

    case 4:
    {
      p1 = new Geomancer;
      break;
    }

    default:
      cout << "Opção inválida";
      return 0;
  }

  cout << "Classe escolhida: " << getTypeid(*p1) << '\n';

  cout << "\nEscolha uma classe para o Jogador 2: ";
  cin >> y;
  switch(y)
  {
    case 1:
    {
      p2 = new Dragoon;
      break;
    }

    case 2:
    {
      p2 = new MysticKnight;      
      break;
    }

    case 3:
    {
      p2 = new Cryomancer;
      break;
    }

    case 4:
    {
      p2 = new Geomancer;
      break;
    }

    default:
      cout << "Opção inválida\n";
      return 0;
  }

  cout << "Classe escolhida: " << getTypeid(*p2) << '\n';

  cout << "\n";
  cout << "BATALHA\n";


  while(true){

    cout << "Jogador 1 " << "(" << getTypeid(*p1) << ")\n";
    cout << "HP: " << (*p1).getHp() << " | MP: " << (*p1).getMp() << " \n";
    getClassMenu(p1, *p2);
    cout << "\n";
    
    if(!*p2){break;}

    cout << "Jogador 2 " << "(" <<getTypeid(*p2) << ")\n";
    cout << "HP: " << (*p2).getHp() << " | MP: " << (*p2).getMp() << " \n";
    getClassMenu(p2, *p1);
    cout << "\n";
    if(!*p1){break;}
  }


  cout << "Fim da batalha! O "<< ((*p1).getHp() > (*p2).getHp()? "Jogador 1":"Jogador 2") << " é o vencedor!\n";





  /*
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
  */

  return 0;
}