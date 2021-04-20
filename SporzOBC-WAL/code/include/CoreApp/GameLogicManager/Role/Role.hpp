/*!

\file Role.hpp
\brief Enter your brief here //TODO
\author Eben
\version 0.1

*/
#ifndef SPORZOBC_WAL_ROLE_HPP
#define SPORZOBC_WAL_ROLE_HPP

struct HackPayload {
    Genome hackedGenome,
    PlayerState hackedState,
    int
};

enum PlayerState {
    MUTATED,
    PARALYZED,
    ALIVE,
    DEAD
};

enum Genome {
    STANDARD,
    IMMUNE,
    HOST
};

enum Role {
    MUTANT,
    DOCTOR,
    COMPUTER_SCIENTIST,
    GENETICIST,
    PSYCHOLOGIST,
    HACKER,
    NOVICE_HACKER,
    SPY,
    PAINTER
};

class IActionResult {
public:
    getValue();
};

class RoleAction {
public:
    bool Kill(std::string username);
    bool Mutate(std::string username);
    bool Paralyze(std::string username);
    bool Heal();
    int GetMutantsNumber();
    Genome TestGenome(std::string username);
    PlayerState Diagnostic(std::string username);
    std::string Hack(Role role);
    std::string NoviceHack(Role role);
    Spy();
    Paint();
};

#endif //SPORZOBC_WAL_ROLE_HPP
