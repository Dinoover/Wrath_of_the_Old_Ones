
//  Play_ground.hpp

#ifndef Play_ground_hpp
#define Play_ground_hpp

#include "Player.hpp"

class Playground
{
private:
    
    Player* P1;//joueur 1
    Player* P2;//joueur 2
    Ressource* R1;//ressources du joueur 1
    Ressource* R2;//ressources du joueur 2
    
    Card* In_game_creature_1;//pointeur sur la carte creature qui est sur le plateau du joueur 1
    Card* In_game_creature_2;//pointeur sur la carte creature qui est sur le plateau du joueur 2
    Card* In_game_ability_1;//pointeur sur la carte ability qui est sur le plateau du joueur 1
    Card* In_game_ability_2;//pointeur sur la carte ability qui est sur le plateau du joueur 2
    
    std::vector <Card*> Graveyard_1;//vecteur de pointeurs sur les cartes de cemetiere de joueur 1
    std::vector <Card*> Graveyard_2;//vecteur de pointeurs sur les cartes de cemetiere de joueur 1

    std::vector <Card*> m_ressource_cards_1;//vecteur de pointeurs sur les cartes ressource de joueur 1 qui sont sur le plateau
    std::vector <Card*> m_ressource_cards_2;//vecteur de pointeurs sur les cartes ressource de joueur 2 qui sont sur le plateau
 
    
public:
    //constructeurs et destructeurs
    Playground();
    Playground(Player * player_1, Player* player_2);
    ~Playground();
    //geteurs, fonctionnent avec le meme principe que dans card.hpp
    Ressource *Get_R1();
    Ressource *Get_R2();
    Card *Get_In_game_creature_1();
    Card *Get_In_game_creature_2();
    Card *Get_In_game_ability_1();
    Card *Get_In_game_ability_2();
    Player *Get_Player_1();
    Player *Get_Player_2();

    std::vector <Card*> Get_ressource_cards_1();
    std::vector <Card*> Get_ressource_cards_2();
    std::vector <Card*> Get_grave_1();
    std::vector <Card*> Get_grave_2();
    
    //pour envoyer la carte sur le cemetiere si besoin
    void Send_card_to_grave(int player_number, int card_number);
    
    //recalcule la totalite des ressources que playeur possede sur le plateau
    void Update_player_ressource(int player_number);
    
    //pour envoyer la carte sur le plateau (marche pour les trois types des cartes)
    void Set_ingame_card(int player, int card_deck_number);
    
    //Attaque avec les cartes creatures
    void creature_battle (int attacker, int defender);
    
    //ca devait utilisation des ability cards
    //void ability_battle();
   
};

#endif /* Play_ground_hpp */
