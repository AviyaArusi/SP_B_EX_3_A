#include "Cowboy.hpp"

const int COWBOY_POINTS = 110;
const int COWBOY_BULLETS = 6;

using namespace std;

namespace ariel
{
    Cowboy::Cowboy(const string& name, const Point& location) 
    : Character(name, location, COWBOY_POINTS) , _bullets(COWBOY_BULLETS) {}

    void Cowboy::shoot(Character* enemy) {}

    bool Cowboy::hasBullets() const { return _bullets > 0; }

    void Cowboy::reload()  { _bullets = COWBOY_BULLETS; }

    string Cowboy::print() const{ return "";}

}