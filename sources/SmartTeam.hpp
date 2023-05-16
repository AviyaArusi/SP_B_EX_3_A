#pragma once

#include "Team.hpp"

namespace ariel
{
    class SmartTeam : public Team
    {
    private:
        std::vector<Character*> _characters;
    public:
        SmartTeam(Character* leader) : Team(leader) {}
        void add(Character* character) override {};
    };


}