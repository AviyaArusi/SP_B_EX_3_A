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
        void add(Character*);
        virtual void attack(Team*);
        int stillAlive() const;
        std::string print() const;
    };


    class Team2 : public Team 
    {
    private:
        std::vector<Character*> _characters;
    public:
        // Team2() = default;  // Default constructor
        Team2(Character*);

        // Team2(Team&);
        // Team2(Team&&) noexcept;
        // Team2& operator=(const Team&);
        // Team2& operator=(Team&&) noexcept;
        ~Team2() override;
        void attack(Team*) override;
    
    };



    class SmartTeam : public Team
    {
    private:
        std::vector<Character*> _characters;
    public:
        SmartTeam() = default;  // Default constructor
        SmartTeam(Character*);

        SmartTeam(Team&);
        SmartTeam(Team&&) noexcept;
        SmartTeam& operator=(const Team&);
        SmartTeam& operator=(Team&&) noexcept;
        ~SmartTeam() override;
        void attack(Team*) override;

    };







}