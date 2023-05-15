#include "Character.hpp"

using namespace std;

namespace ariel
{
    // Check validation!!
    Character::Character(const std::string& name, const Point& location, int healthPoints) : 
                        name(name), location(location), healthPoints(healthPoints) 
    {
        // this->location = location;
        // this->healthPoints = healthPoints;
        // this->name = name;
    }

    bool Character::isAlive() const { return healthPoints > 0; }

    double Character::distance(const Character* other) const 
    {
        if(other != NULL) // Check if throw exception
        {
            return NULL;
        } 
        return location.distance(other->getLocation()); 
    }

    void Character::hit(int damage) { healthPoints -= damage; }

    string Character::getName() const { return name; }

    Point Character::getLocation() const { return location; }

    void Character::print() const
    {
        cout << name << ": ";
        if (isAlive()) 
        {
            cout << "HP: " << healthPoints << ", Location: ";
            location.print();
        } 
        else 
        {
            cout << "(DEAD)" << endl;
        }
    }



    Cowboy::Cowboy(const string& name, const Point& location) 
                : Character(name, location, 110) , bullets(6) {}

    void Cowboy::shoot(Character* enemy) 
    {
        if (enemy->isAlive() && bullets > 0) 
        {
            enemy->hit(10);
            bullets--;
        }
    }

    bool Cowboy::hasBullets() const { return bullets > 0; }

    void Cowboy::reload()  { bullets = 6; }

    void Cowboy::print() const
    {
        cout << "C - ";
        Character::print();
        cout << ", Bullets: " << bullets << endl;
    }


    
    Ninja::Ninja(const std::string& name, const Point& location, int healthPoints , int speed) 
                : Character(name, location, healthPoints), speed(speed) {}

    void Ninja::move(Character* enemy) 
    {
        if (isAlive()) 
        {
            Point enemyLocation = enemy->getLocation();
            double dist = location.distance(enemyLocation);
            if (dist > speed) 
            {
                double dx = enemyLocation.getX() - location.getX();
                double dy = enemyLocation.getY() - location.getY();
                double ratio = speed / dist;
                double newX = location.getX() + dx * ratio;
                double newY = location.getY() + dy * ratio;
                location = Point(newX, newY);
            }
        }
    }

    void Ninja::slash(Character* enemy) 
    {
        if (isAlive() && distance(enemy) < 1.0) 
        {
            enemy->hit(40);
        }
    }

    void Ninja::print() const
    {
        cout << "N - ";
        Character::print();
        std::cout << ", Speed: " << speed << std::endl;
    }


    YoungNinja::YoungNinja(const std::string& name, const Point& location)
                            : Ninja(name, location, 100, 14) {}


    TrainedNinja::TrainedNinja(const std::string& name, const Point& location)
                            : Ninja(name, location, 120, 12) {}


    OldNinja::OldNinja(const std::string& name, const Point& location)
                        : Ninja(name, location, 150, 8) {}

}