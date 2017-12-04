
#include "Plateau.hpp"

Plateau::Plateau(){}
Plateau::~Plateau(){}

Ressource* Plateau:: Get_R1()
{
    return R1;
}

Ressource* Plateau:: Get_R2()
{
    return R2;
}

Player* Plateau:: Get_P1()
{
    return P1;
}

Player *Plateau:: Get_P2()
{
    return P2;
}

Card* Plateau:: Get_M1()
{
    return M1;
}

Card* Plateau:: Get_M2()
{
    return M2;
}

std::vector <Card*>* Plateau:: Get_Blood()
{
    return &Blood;
}

std::vector <Card*>* Plateau:: Get_Gold()
{
    return &Gold;
}

std::vector <Card*>* Plateau:: Get_Influence()
{
    return &Influence;
}

std::vector <Card*>* Plateau:: Get_Power()
{
    return &Power;
}

void Plateau:: Fin_de_tour()
{
    Ressource r;
    Player p;
    Card m;

    r=*R1;*R1=*R2;*R2=r; //changement des ressource sur le joueur actif

    p=*P1;*P1=*P2;*P2=p; //Changement de joueur actif

    m=*M1;*M1=*M2;*M2=*M1; //Changement de monstre controlé
}
