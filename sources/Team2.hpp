#pragma once

#include "Team.hpp"

using namespace std;
namespace ariel
{
    class Team2 : public Team 
    {
    private:
        std::vector<Character*> _characters;
    public:
        Team2(Character* leader) : Team(leader) {}
        void add(Character* haracter) override {}    
    };


}