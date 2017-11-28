#include "Player.hpp"

Player:: Player()
:m_nom(""), m_cp(0)
{}

Player:: Player(std::string nom, int cp)
{}

Player:: ~Player()
{}

void Player:: Set_name(std::string nom)
{
  m_nom = nom;
}

void Player:: Set_cp(int cp)
{
  m_cp = cp;
}

std::string Player:: Get_name()
{
  return m_nom;
}

int Player:: Get_cp()
{
  return m_cp;
}

void Player::ouvrir_booster(Card Jeu[G])
{
    int x;
    bool trouver=NULL;
    *m_cp = *m_cp - 10;
    while (trouver==NULL)
    {
        x = rand()%G;
        for (int i=0;i<collection.max_size();i++)
        {
            if(Jeu[x].Get_card_number()==collection[i]->Get_card_number())
            {
                collection.push_back(&Jeu[x]);
            }
        }

    }
}
