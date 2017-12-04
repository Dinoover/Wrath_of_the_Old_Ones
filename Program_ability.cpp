
void death_detect(Plateau* P)                                  //fonctionne qui detecte et traite la mort des 2 creatures
{
    if (0>=P->Get_M1()->Get_v_parameters().Get_HP())
    {
        P->Get_M1()->Set_variant_parameters()->Set_live_status(false);
        P->Get_M1()->Set_variant_parameters()->Set_invoke_status(false);
        P->Get_P1()->take_damage(-P->Get_M1()->Get_v_parameters().Get_HP());
        P->Get_Graveyard1()->push_back(P->Get_M1());
    }
    if (0>=P->Get_M2()->Get_v_parameters().Get_HP())
    {
        P->Get_M2()->Set_variant_parameters()->Set_live_status(false);
        P->Get_M2()->Set_variant_parameters()->Set_invoke_status(false);
        P->Get_P2()->take_damage(-P->Get_M2()->Get_v_parameters().Get_HP());
        P->Get_Graveyard2()->push_back(P->Get_M2());
    }
}

void death_touch(Plateau* P)                                    //tue la creature adverse
{
    P->Get_M2()->Set_variant_parameters()->Set_HP(0);
}

void Armagedeon(Plateau* P)                                     //inflige a chaque joueur un nombre de degat egaux aux point de vie actuelle des creatures en jeux
{
    P->Get_M1()->Set_variant_parameters()->Set_HP(0);
    P->Get_M2()->Set_variant_parameters()->Set_HP(0);
    P->Get_P1()->take_damage(P->Get_M1()->Get_v_parameters().Get_HP());
    P->Get_P2()->take_damage(P->Get_M2()->Get_v_parameters().Get_HP());
}

void monde_parralelle(Plateau* P)                               //inverse les HP des 2 creatures
{
    int i;
    i = P->Get_M1()->Get_v_parameters().Get_HP();
    P->Get_M1()->Set_variant_parameters()->Set_HP(P->Get_M2()->Get_v_parameters().Get_HP());
    P->Get_M2()->Set_variant_parameters()->Set_HP(i);
}

void Effondrement_des_dimmensions(Plateau* P)                  //les 2 creatures subissent 3 degat et le joueur adverse en subit 3 aussi
{
    P->Get_M1()->Get_v_parameters().take_damage(3);
    P->Get_M1()->Get_v_parameters().take_damage(3);
    P->Get_P2()->take_damage(3);
}

void Rituel_bani(Plateau* P)                                           //la creature gagne a jamais +2 sur toute ses attaques
{
    P->Get_M1()->Get_s_parameter().Set_damage_value(P->Get_M1()->Get_s_parameter().Get_damage_value()+2);
    P->Get_M1()->Get_v_parameters().Set_force(P->Get_M1()->Get_v_parameters().Get_force()+2);
}

void dispersion_energie (Plateau* P)                            // fait perdre 2 energie de cahque type a l'adversaire
{
    P->Get_Blood2()->pop_back(); P->Get_Blood2()->pop_back();       //n'envoie aps les cartes d'energie au cimetierre, elle sont simplement supprimé du plateau
    P->Get_R2()->Set_blood(P->Get_R2()->Get_blood()-2);

    P->Get_Gold2()->pop_back(); P->Get_Gold2()->pop_back();
    P->Get_R2()->Set_gold(P->Get_R2()->Get_gold()-2);

    P->Get_Influence2()->pop_back();P->Get_Influence2()->pop_back();
    P->Get_R2()->Set_influence(P->Get_R2()->Get_influence()-2);

    P->Get_Power2()->pop_back();P->Get_Power2()->pop_back();
    P->Get_R2()->Set_power(P->Get_R2()->Get_power()-2);
}
