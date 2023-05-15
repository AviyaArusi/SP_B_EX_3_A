class Team {
private:
    Character* leader;
    std::vector<Character*> members;

public:
    Team(Character* leader) {
        this->leader = leader;
        members.push_back(leader);
    }

    void add(Character* character) {
        members.push_back(character);
    }

    void attack(Team* enemyTeam) {
        if (!leader->isAlive()) {
            Character* closestAlive = findClosestAliveCharacter();
            if (closestAlive != nullptr) {
                leader = closestAlive;
            } else {
                return; // No alive characters left in the attacking team
            }
        }

        Character* target = enemyTeam->findClosestAliveCharacter();
        while (target != nullptr) {
            for (Character* member : members) {
                if (member->isAlive()) {
                    if (member->getName() == "Cowboy") {
                        Cowboy* cowboy = dynamic_cast<Cowboy*>(member);
                        if (cowboy->hasBullets()) {
                            cowboy->shoot(target);
                        } else {
                            cowboy->reload();
                        }
                    } else if (member->getName() == "Ninja") {
                        Ninja* ninja = dynamic_cast<Ninja*>(member);
                        if (ninja->distance(target) < 1.0) {
                            ninja->slash(target);
                        } else {
                            ninja->move(target);
                        }
                    }
                }
            }
            target = enemyTeam->findClosestAliveCharacter();
        }
    }

    int stillAlive() 
    {
        int count = 0;
        for (Character* member : members) 
        {
            if (member->isAlive())
             {
                count++;
            }
        }
        return count;
    }

    void print() 
    {
        for (Character* member : members) 
        {
            member->print();
        }
    }

    ~Team() 
    {
        for (Character* member : members) 
        {
            delete member;
        }
    }

private:
    Character* findClosestAliveCharacter() 
    {
        Character* closestAlive = nullptr;
        double closestDistance = std::numeric_limits<double>::max();

        for (Character* member : members) 
        {
            if (member->isAlive()) 
            {
                double distance = member->distance(leader);
                if (distance < closestDistance) 
                {
                    closestAlive = member;
                    closestDistance = distance;
                }
            }
        }

        return closestAlive;
    }
};