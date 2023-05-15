#pragma once

#include <iostream>
#include <math.h>
#include "Point.hpp"

namespace ariel
{

    class Character
    {
        private:
            Point& location;
            int healthPoints;
            string name;

        public:
            Character(Point&, int, std::string);
            string getName() const;
            Point getLocation() const;
            bool isAlive() const;
            double distance(Character*) const;
            void hit(int);
            void print();
    };


    class Cowboy : public Character 
    {
    private:
        int bullets;

    public:
        Cowboy(Point&, std::string);
        void shoot(Character*);
        bool hasBullets();
        void reload(); 
        void print() const;
    };


    class Ninja : public Character 
    {
    private:
        int speed;

    public:
        Ninja(Point&, int, std::string, int);
        void move(Character*);
        void slash(Character*);
        void print() const;
    };







}