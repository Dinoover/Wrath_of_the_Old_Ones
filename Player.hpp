#include <string>
#include <vector>
#include <fstream>

class Player
{
  private:

    std::string m_nom;
    int* m_cp; //money for the store (combat point)
    std::stack<int> m_deck;
    std::vector <card*>* collection;

  public:

    Player();
    Player(std::string, int);
    ~Player();

    void Set_deck(int);
    void Set_name(std::string);
    void Set_cp(int);
    void ouvrir_booster(card*);

    std::string Get_name();
    int Get_cp();
};
