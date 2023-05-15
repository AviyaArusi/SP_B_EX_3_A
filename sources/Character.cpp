#include "Character.hpp"

using namespace std;

namespace ariel
{
    // Check validation!!
    Character::Character(const std::string& name, const Point& location, int healthPoints) 
    : _name(name), _location(location), _healthPoints(healthPoints) {}

    // Define copy constructor
    Character::Character(Character& other) {}
    // Define move constructor
    Character::Character(Character&& other) noexcept {}
    // Define copy assignment operator
    Character &Character::operator=(const Character& other) { return (*this);}
    // Define move assignment operator
    Character &Character::operator=(Character&& other) noexcept { return (*this);}


    bool Character::isAlive() const { return _healthPoints > 0; }

    double Character::distance(const Character* other) const { return 0;}

    void Character::hit(int damage) { _healthPoints -= damage; }

    string Character::getName() const { return _name; }

    Point Character::getLocation() const { return _location; }
                
    int Character::getHealth() const { return 0;};

    string Character::print() const { return "";}



    Cowboy::Cowboy(const string& name, const Point& location) 
    : Character(name, location, 110) , _bullets(6) {}

    void Cowboy::shoot(Character* enemy) {}

    bool Cowboy::hasBullets() const { return _bullets > 0; }

    void Cowboy::reload()  { _bullets = 6; }

    string Cowboy::print() const{ return "";}


    
    Ninja::Ninja(const std::string& name, const Point& location, int healthPoints , int speed) 
    : Character(name, location, healthPoints), _speed(speed) {}
    
    int Ninja::getSpeed() const {return 0;};

    void Ninja::move(Character* enemy) {}

    void Ninja::slash(Character* enemy) {}

    string Ninja::print() const { return "";}


    YoungNinja::YoungNinja(const std::string& name, const Point& location)
    : Ninja(name, location, 100, 14) {}


    TrainedNinja::TrainedNinja(const std::string& name, const Point& location)
    : Ninja(name, location, 120, 12) {}


    OldNinja::OldNinja(const std::string& name, const Point& location)
    : Ninja(name, location, 150, 8) {}

}