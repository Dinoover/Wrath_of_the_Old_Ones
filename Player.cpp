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

void Player:: Set_deck(int deck[40][40][40])
{

}

std::string Player:: Get_name()
{
  return m_nom;
}

int Player:: Get_cp()
{
  return m_cp;
}

card* ouvrir_booster()
{

}
