#include "Character.hpp"

using namespace std;

namespace ariel
{
    // Check validation!!
    Character::Character(const std::string& name, const Point& location, int healthPoints) : 
                        _name(name), _location(location), _healthPoints(healthPoints) 
    {
        // this->location = location;
        // this->healthPoints = healthPoints;
        // this->name = name;
    }

    bool Character::isAlive() const { return _healthPoints > 0; }

    double Character::distance(const Character* other) const 
    {
        if(other != NULL) // Check if throw exception
        {
            return NULL;
        } 
        return _location.distance(other->getLocation()); 
    }

    void Character::hit(int damage) { _healthPoints -= damage; }

    string Character::getName() const { return _name; }

    Point Character::getLocation() const { return _location; }

    void Character::print() const
    {
        cout << _name << ": ";
        if (isAlive()) 
        {
            cout << "HP: " << _healthPoints << ", Location: ";
            _location.print();
        } 
        else 
        {
            cout << "(DEAD)" << endl;
        }
    }



    Cowboy::Cowboy(const string& name, const Point& location) 
                : Character(name, location, 110) , _bullets(6) {}

    void Cowboy::shoot(Character* enemy) 
    {
        if (enemy->isAlive() && _bullets > 0) 
        {
            enemy->hit(10);
            _bullets--;
        }
    }

    bool Cowboy::hasBullets() const { return _bullets > 0; }

    void Cowboy::reload()  { _bullets = 6; }

    void Cowboy::print() const
    {
        cout << "C - ";
        Character::print();
        cout << ", Bullets: " << _bullets << endl;
    }


    
    Ninja::Ninja(const std::string& name, const Point& location, int healthPoints , int speed) 
                : Character(name, location, healthPoints), _speed(speed) {}

    void Ninja::move(Character* enemy) 
    {
        if (isAlive()) 
        {
            Point enemyLocation = enemy->getLocation();
            double dist = _location.distance(enemyLocation);
            if (dist > _speed) 
            {
                double dx = enemyLocation.get_x() - _location.get_x();
                double dy = enemyLocation.get_y() - _location.get_y();
                double ratio = _speed / dist;
                double newX = _location.get_x() + dx * ratio;
                double newY = _location.get_y() + dy * ratio;
                _location = Point(newX, newY);
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
        std::cout << ", Speed: " << _speed << std::endl;
    }


    YoungNinja::YoungNinja(const std::string& name, const Point& location)
                            : Ninja(name, location, 100, 14) {}


    TrainedNinja::TrainedNinja(const std::string& name, const Point& location)
                            : Ninja(name, location, 120, 12) {}


    OldNinja::OldNinja(const std::string& name, const Point& location)
                        : Ninja(name, location, 150, 8) {}

}