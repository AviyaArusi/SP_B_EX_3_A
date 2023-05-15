#include "Team.hpp"

namespace ariel
{
    Team::Team(Character* leader) : leader(leader) {}

    Team::~Team() 
    {
        // Delete all characters in the team
        for(auto& cowboy : cowboys) 
        {
            delete cowboy;
        }
        for(auto& ninja : ninjas) 
        {
            delete ninja;
        }
    }

    void Team::add(Character* character) 
    {
        // Add the character to the team
        if(dynamic_cast<Cowboy*>(character)) 
        {
            cowboys.push_back(static_cast<Cowboy*>(character));
        } 
        else if(dynamic_cast<Ninja*>(character)) 
        {
            ninjas.push_back(static_cast<Ninja*>(character));
        }
    }

    void Team::attack(Team* enemy) 
    {
        // Check if the leader is alive
        if (!leader->isAlive()) 
        {
            // TODO: Select a new leader, the closest character to the dead leader
        }

        // Select a target from the enemy team
        // The target is the closest living enemy character to the leader
        Character* target = enemy->selectClosestCharacter(leader->getLocation());

        // All living characters in the team attack the target
        for(auto& cowboy : cowboys) 
        {
            if (cowboy->isAlive()) 
            {
                if (cowboy->hasBullets()) 
                {
                    cowboy->shoot(target);
                } 
                else 
                {
                    cowboy->reload();
                }
            }
        }
        for(auto& ninja : ninjas) 
        {
            if (ninja->isAlive()) 
            {
                if (ninja->getDistanceTo(target) <= 1) 
                {
                    ninja->strike(target);
                } 
                else 
                {
                    ninja->move(target);
                }
            }
        }
    }

    int Team::stillAlive() 
    {
        // Return the number of living team members
        int aliveCount = 0;
        for(auto& cowboy : cowboys) 
        {
            if (cowboy->isAlive()) 
            {
                aliveCount++;
            }
        }
        for(auto& ninja : ninjas) 
        {
            if (ninja->isAlive()) 
            {
                aliveCount++;
            }
        }
        return aliveCount;
    }

    void Team::print() 
    {
        // Print the details of all team members
        for(auto& cowboy : cowboys) 
        {
            cowboy->print();
        }
        for(auto& ninja : ninjas) 
        {
            ninja->print();
        }
    }

    Team2::Team2(Character* leader) : leader(leader) {}

    Team2::~Team2() {
        // Delete all characters in the team
        for(auto& character : characters) 
        {
            delete character;
        }
    }

    void Team2::add(Character* character) 
    {
        // Add the character to the team
        characters.push_back(character);
    }

    void Team2::attack(Team2* enemy) 
    {
        // Check if the leader is alive
        if (!leader->isAlive()) 
        {
            // TODO: Select a new leader, the closest character to the dead leader
        }

        // Select a target from the enemy team
        // The target is the closest living enemy character to the leader
        Character* target = enemy->selectClosestCharacter(leader->getLocation());

        // All living characters in the team attack the target
        for(auto& character : characters) 
        {
            if (character->isAlive()) 
            {
                if(dynamic_cast<Cowboy*>(character)) 
                {
                    Cowboy* cowboy = static_cast<Cowboy*>(character);
                    if (cowboy->hasBullets()) 
                    {
                        cowboy->shoot(target);
                    } 
                    else 
                    {
                        cowboy->reload();
                    }
                } 
                else if(dynamic_cast<Ninja*>(character)) 
                {
                    Ninja* ninja = static_cast<Ninja*>(character);
                    if (ninja->getDistanceTo(target) <= 1) 
                    {
                        ninja->strike(target);
                    } 
                    else 
                    {
                        ninja->move(target);
                    }
                }
            }
        }
    }

    int Team2::stillAlive() 
    {
        // Return the number of living team members
        int aliveCount = 0;
        for(auto& character : characters) 
        {
            if (character->isAlive()) 
            {
                aliveCount++;
            }
        }
        return aliveCount;
    }

    void Team2::print() 
    {
        // Print the details of all team members
        for(auto& character : characters) 
        {
            character->print();
        }
    }





}














































// class Team {
// private:
//     Character* leader;
//     std::vector<Character*> members;

// public:
//     Team(Character* leader) {
//         this->leader = leader;
//         members.push_back(leader);
//     }

//     void add(Character* character) {
//         members.push_back(character);
//     }

//     void attack(Team* enemyTeam) {
//         if (!leader->isAlive()) {
//             Character* closestAlive = findClosestAliveCharacter();
//             if (closestAlive != nullptr) {
//                 leader = closestAlive;
//             } else {
//                 return; // No alive characters left in the attacking team
//             }
//         }

//         Character* target = enemyTeam->findClosestAliveCharacter();
//         while (target != nullptr) {
//             for (Character* member : members) {
//                 if (member->isAlive()) {
//                     if (member->getName() == "Cowboy") {
//                         Cowboy* cowboy = dynamic_cast<Cowboy*>(member);
//                         if (cowboy->hasBullets()) {
//                             cowboy->shoot(target);
//                         } else {
//                             cowboy->reload();
//                         }
//                     } else if (member->getName() == "Ninja") {
//                         Ninja* ninja = dynamic_cast<Ninja*>(member);
//                         if (ninja->distance(target) < 1.0) {
//                             ninja->slash(target);
//                         } else {
//                             ninja->move(target);
//                         }
//                     }
//                 }
//             }
//             target = enemyTeam->findClosestAliveCharacter();
//         }
//     }

//     int stillAlive() 
//     {
//         int count = 0;
//         for (Character* member : members) 
//         {
//             if (member->isAlive())
//              {
//                 count++;
//             }
//         }
//         return count;
//     }

//     void print() 
//     {
//         for (Character* member : members) 
//         {
//             member->print();
//         }
//     }

//     ~Team() 
//     {
//         for (Character* member : members) 
//         {
//             delete member;
//         }
//     }

// private:
//     Character* findClosestAliveCharacter() 
//     {
//         Character* closestAlive = nullptr;
//         double closestDistance = std::numeric_limits<double>::max();

//         for (Character* member : members) 
//         {
//             if (member->isAlive()) 
//             {
//                 double distance = member->distance(leader);
//                 if (distance < closestDistance) 
//                 {
//                     closestAlive = member;
//                     closestDistance = distance;
//                 }
//             }
//         }

//         return closestAlive;
//     }
// };