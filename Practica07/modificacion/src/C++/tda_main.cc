#include "Personaje/personaje.h"
#include "AB/abb.h"

int main() {
  Personaje player1{"Astarion", "Rogue", "Elf", "Chaotic Neutral", 4, 30, 5, 10, 18, 12, 14, 10, 16, 15, 30};
  Personaje player2{"Gale", "Wizard", "Human", "Neutral Good", 4, 30, 5, 8, 14, 12, 18, 16, 10, 12, 30};
  Personaje player3{"Lae'zel", "Fighter", "Githyanki", "Lawful Evil", 4, 30, 5, 14, 16, 10, 12, 8, 18, 14, 30};
  Personaje player4{"Shadowheart", "Cleric", "Half-Elf", "Neutral Good", 4, 30, 5, 10, 14, 12, 16, 18, 8, 10, 30};
  Personaje player5{"Wyll", "Warlock", "Human", "Chaotic Good", 4, 30, 5, 10, 14, 12, 16, 18, 8, 10, 30};

  ABB<Personaje> arbol;
  arbol.Insert(player1);
  arbol.Insert(player2);
  arbol.Insert(player3);
  arbol.Insert(player4);
  arbol.Insert(player5);

  arbol.InOrder(arbol.GetRoot());

  return 0;
}