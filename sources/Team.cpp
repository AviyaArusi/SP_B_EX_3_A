#include "Team.hpp"

using namespace std;
namespace ariel
{
    Team::Team() : _leader(nullptr) {}
    Team::Team(Character* leader) : _leader(leader) {}

    // Define copy constructor
    Team::Team(Team& other) {}
    // Define move constructor
    Team::Team(Team&& other) noexcept {}
    // Define copy assignment operator
    Team &Team::operator=(const Team& other) { return (*this);}
    // Define move assignment operator
    Team &Team::operator=(Team&& other) noexcept { return (*this);}

    Team::~Team() {}

    Character* Team::getLeader() const { return _leader;}
    
    vector<Character*> Team::getTeam() const { return _team;};

    void Team::add(Character* character) {}

    void Team::attack(Team* enemy) {}

    int Team::stillAlive() const { return 0;}

    string Team::print() const {return "";}





    Team2::Team2(Character* leader) : Team(leader) {}
    void Team2::add(Character* character) {}



    SmartTeam::SmartTeam(Character* leader) : Team(leader) {}
    void SmartTeam::add(Character* character) {}

}