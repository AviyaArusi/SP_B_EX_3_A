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

    void Team::add(Character* character) {}

    void Team::attack(Team* enemy) {}

    int Team::stillAlive() const { return 0;}

    string Team::print() const {return "";}


    Team2::Team2(Character* leader) : Team(leader) {}

    // // Define copy constructor
    // Team2::Team2(Team& other) {}
    // // Define move constructor
    // Team2::Team2(Team&& other) noexcept {}
    // // Define copy assignment operator
    // Team2 &Team2::operator=(const Team& other) { return (*this);}
    // // Define move assignment operator
    // Team2 &Team2::operator=(Team&& other) noexcept { return (*this);}

    Team2::~Team2() {}


    void Team2::attack(Team* enemy) {}
    
    // void Team2::add(Character* character) {}

    // int Team2::stillAlive() { return 0;}

    // void Team2::print() {}

    SmartTeam::SmartTeam(Character* leader) : Team(leader) {}

    // // Define copy constructor
    // SmartTeam::SmartTeam(Team& other) {}
    // // Define move constructor
    // SmartTeam::SmartTeam(Team&& other) noexcept {}
    // // Define copy assignment operator
    // SmartTeam &SmartTeam::operator=(const Team& other) { return (*this);}
    // // Define move assignment operator
    // SmartTeam &SmartTeam::operator=(Team&& other) noexcept { return (*this);}

    SmartTeam::~SmartTeam() {}


    void SmartTeam::attack(Team* enemy) {}
    
    // void SmartTeam::add(Character* character) {}

    // int SmartTeam::stillAlive() { return 0;}

    // void SmartTeam::print() {}



}