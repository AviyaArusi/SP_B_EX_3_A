#include <vector>
#include "Character.hpp"
namespace ariel
{

    class Team 
    {
    public:
        Team(Character* leader);
        virtual ~Team();

        void add(Character* character);
        virtual void attack(Team* enemy);
        int stillAlive();
        void print();

    protected:
        Character* leader;
        std::vector<Cowboy*> cowboys;
        std::vector<Ninja*> ninjas;
    };


    class Team2 : public Team 
    {
    public:
        Team2(Character* leader);
        void attack(Team* enemy) override;
    private:
        std::vector<Character*> characters;
    };



    class SmartTeam : public Team
    {
    public:
        SmartTeam(Character* leader);
        void attack(Team* enemy) override;
    private:
        std::vector<Character*> characters;
    };







}