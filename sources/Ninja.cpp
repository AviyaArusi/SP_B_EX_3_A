#include "Ninja.hpp"

using namespace std;

namespace ariel
{    
    Ninja::Ninja(const std::string& name, const Point& location, int healthPoints , int speed) 
    : Character(name, location, healthPoints), _speed(speed) {}
    
    int Ninja::getSpeed() const {return 0;};

    void Ninja::move(Character* enemy) {}

    void Ninja::slash(Character* enemy) {}

    string Ninja::print() const { return "";}

}