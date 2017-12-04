
#include "Player.hpp"
#include <vector>

class Plateau       //les elements suivis d'un 1 sont ceux que le joueur dont c'est le tour possede, les autres sont ceux de son adversaire
{
    Ressource* R1;
    Ressource* R2;
    Card* M1;
    Card* M2;
    Player* P1;
    Player* P2;
    std::vector <Card*> Blood;
    std::vector <Card*> Influence;
    std::vector <Card*> Gold;
    std::vector <Card*> Power;

public:
    Plateau();
    ~Plateau();
    Ressource Get_R1();
    Ressource Get_R2();
    Card Get_M1();
    Card Get_M2();
    Player Get_P1();
    Player Get_P2();
    std::vector <Card*>* Get_Blood();
    std::vector <Card*>* Get_Influence();
    std::vector <Card*>* Get_Gold();
    std::vector <Card*>* Get_Power();

    void Fin_de_tour();  //fonctionne qui permet que le passage du joueur enemi au joueur actif
};
