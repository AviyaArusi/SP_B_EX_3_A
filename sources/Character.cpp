#include "Character.hpp"

using namespace std;

namespace ariel
{
    // Check validation!!
    Character::Character(Point& location, int healthPoints, string name) : location(location) 
    {
        // this->location = location;
        this->healthPoints = healthPoints;
        this->name = name;
    }

    bool Character::isAlive() const { return healthPoints > 0; }

    double Character::distance(Character* other) const 
    {
        Point otherPoint;
        if(other != NULL)
        {
            otherPoint = other->getLocation();
        } 
        return location.distance(otherPoint); 
    }

    void Character::hit(int damage) { healthPoints -= damage; }

    string Character::getName() const { return name; }

    Point Character::getLocation() const { return location; }

    void Character::print() 
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



    Cowboy::Cowboy(Point& location, string name) : Character(location, 110, name) 
    {
        bullets = 6;
    }

    void Cowboy::shoot(Character* enemy) 
    {
        if (enemy->isAlive() && bullets > 0) 
        {
            enemy->hit(10);
            bullets--;
        }
    }

    bool Cowboy::hasBullets() { return bullets > 0; }

    void Cowboy::reload()  { bullets = 6; }

    void Cowboy::print() const 
    {
        std::cout << "C - ";
        Character::print();
        std::cout << ", Bullets: " << bullets << std::endl;
    }


    class Ninja : public Character 
    {
    private:
        int speed;

    public:
        Ninja(Point& location, int healthPoints, string name, int speed) : Character(location, healthPoints, name) {
            this->speed = speed;
        }

        void move(Character* enemy) {
            if (isAlive()) {
                Point enemyLocation = enemy->getLocation();
                double dist = location.distance(enemyLocation);
                if (dist > speed) {
                    double dx = enemyLocation.getX() - location.getX();
                    double dy = enemyLocation.getY() - location.getY();
                    double ratio = speed / dist;
                    double newX = location.getX() + dx * ratio;
                    double newY = location.getY() + dy * ratio;
                    location = Point(newX, newY);
                }
            }
        }

        void slash(Character* enemy) 
        {
            if (isAlive() && distance(enemy) < 1.0) 
            {
                enemy->hit(40);
            }
        }

        void print() const
        {
            cout << "N - ";
            Character::print();
            std::cout << ", Speed: " << speed << std::endl;
        }
    };

}