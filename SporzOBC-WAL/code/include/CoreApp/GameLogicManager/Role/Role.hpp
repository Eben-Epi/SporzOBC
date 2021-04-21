/*!

\file Role.hpp
\brief Enter your brief here //TODO
\author Eben
\version 0.1

*/
#ifndef SPORZOBC_WAL_ROLE_HPP
#define SPORZOBC_WAL_ROLE_HPP

#include <string>
#include <vector>
#include "CoreApp/GameLogicManager/Player/Player.hpp"

//! Types d'actions possibles subies par les joueurs
enum ActionType {
    PARALYZED, /*!< Tentative de paralysie par un mutant */
    KILLED, /*!< Mort occasionée par les mutants ou les médecins */
    MUTATED, /*!< Tentative de mutations par les mutants */
    HEALED, /*!< Tentative de heal par les médecins */
    DIAGNOSED, /*!< A été diagnostiqué par le psychologue */
    TESTED, /*!< A été testé par le généticien */
    HACKED, /*!< A été hacké par le hackeur (merci Dora) */
    NOVICE_HACKED /*!< A hacké le hack du hackeur (fatigue) */
};

//! Etat du joueur au cours de la partie, étant modifié par les actions des autres joueurs
enum PlayerState {
    ILL, /*!< A été muté */
    STUNNED, /*!< A été paralysé */
    ALIVE, /*!<  Est un humain sain */
    DEAD /*!< Est malheureusement, mort */
};

//! Types de génomes existants
enum Genome {
    STANDARD, /*!< Génome standard */
    IMMUNE, /*!< Ne peut pas se faire muter */
    HOST /*!< Ne peut pas se faire soigner */
};

enum Role {
    JOBLESS,

    /*!
     * Au début il n’y en a qu’un : le mutant de base.
     * Petits à petit il va muter d’autres personnes qui vont devenir des mutants.
     * Lorsqu’une personne devient un mutant, elle abandonne son pouvoir et joue avec les mutants
     * Chaque nuit les mutants peuvent :
     * 1) Tuer une personne
     * OU
     * 2) Muter une personne
     * ET
     * 3) Paralyser  une personne
     */
    MUTANT,

    /*!
     * Il y a un nombre de médecins fixe au début de la partie,
     * ce sont les rôles les plus importants pour l’humanité.
     * Si il n’y a plus de médecins à bord, les mutants ont immédiatement gagnés.
     * Chaque nuit les médecins peuvent :
     * 1) Soigner  une personne chacun
     * ET
     * 2) Tuer  une personne
     */
    DOCTOR,

    /*!
     * Chaque nuit l’ordinateur de bord lui donne le nombre de mutants à bord
     */
    COMPUTER_SCIENTIST,

    /*!
     * Chaque nuit il montre un personne au maître du jeu et il lui révèle son génôme
     */
    GENETICIST,

    /*!
     * Chaque nuit il montre un personne au maître du jeu et il lui révèle son camp
     */
    PSYCHOLOGIST,

    /*!
     * Chaque nuit il indique au maître du jeu quel rôle il désir hacker
     * (l’informaticien, le généticien ou le psychologue) et il obtient les résultats (et non la cible) de l'inspection
     */
    HACKER,

    /*!
     * Chaque nuit il indique au maître du jeu quel rôle il désir hacker
     * (l’informaticien, le généticien ou le psychologue) et il obtient la cible de l’inspection (et non les résultats)
     */
    NOVICE_HACKER,

    /*!
     * Chaque nuit il montre un personne au maître du jeu et il lui dit si cette per-sonne à été mutée,
     * paralysée, soignée, inspectée par le généticien,
     * inspectée par le psychologue pendant la nuit ou non
     */
    SPY,

    /*!
     * Chaque nuit il montre un personne au maître du jeu et il lui révèle toutes les personnes
     * ayant été en contacte avec lui durante cette nuit
     */
    PAINTER
};

//! Faction, entre humain ou mutant
enum Faction {
    HUMAN,
    NOT_HUMAN
};

//! Résultat d'un hack, qui varie en fonction du rôle
struct HackPayload {
    Role roleHacked; /*!< résultat du hack du rôle d'informaticien */
    std::string hackedInformation; /*!< résultat du hack */
    std::string userHacked; /*!< la personne ayant été hackée */
};

class RoleAction {
public:
    bool Kill(Player);
    bool Mutate(Player);
    bool Paralyze(Player);
    bool Heal(Player);
    int GetMutantsNumber();
    Genome TestGenome(Player);
    Faction Diagnostic(Player);
    HackPayload Hack(Role);
    HackPayload NoviceHack(Role);
    std::vector<ActionType> Spy(Player);
    std::vector<size_t> Paint(Player);
};

#endif //SPORZOBC_WAL_ROLE_HPP
