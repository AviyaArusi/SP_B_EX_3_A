#pragma once

#include <vector>
#include "Character.hpp"

using namespace std;
namespace ariel
{

    class Team 
    {
    private:
        Character* _leader;
        std::vector<Character*> _team;
    public:
        Team();  // Default constructor
        Team(Character*);
        Team(Team&);
        Team(Team&&) noexcept;
        Team& operator=(const Team&);
        Team& operator=(Team&&) noexcept;
        virtual ~Team();

        Character* getLeader() const;
        std::vector<Character*> getTeam() const;
        virtual void add(Character*);
        virtual void attack(Team*);
        int stillAlive() const;
        std::string print() const;
    };


    class Team2 : public Team 
    {
    private:
        std::vector<Character*> _characters;
    public:
        Team2(Character*);
        void add(Character* haracter) override;    
    };



    class SmartTeam : public Team
    {
    private:
        std::vector<Character*> _characters;
    public:
        SmartTeam(Character*);
        void add(Character* character) override;
    };







}