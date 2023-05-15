#pragma once

#include <iostream>
// #include <math.h>
#include <cmath>
#include <string>
#include "Point.hpp"

namespace ariel
{

    class Character
    {
        protected:
            Point _location;
            int _healthPoints;
            std::string _name;

        public:
            Character (const std::string&, const Point&, int);
            std::string getName() const;
            Point getLocation() const;
            bool isAlive() const;
            double distance(const Character*) const;
            void hit(int);
            virtual void print() const = 0; // Pure virtual function
    };


    class Cowboy : public Character 
    {
    private:
        int _bullets;

    public:
        Cowboy(const std::string&, const Point&);
        void shoot(Character*);
        bool hasBullets() const;
        void reload(); 
        void print() const override;
    };


    class Ninja : public Character 
    {
    protected:
        int _speed;

    public:
        Ninja(const std::string&, const Point&, int, int);
        void move(Character*);
        void slash(Character*);
        void print() const override;
    };


    class YoungNinja : public Ninja 
    {
    public:
        YoungNinja(const std::string& name, const Point& location);
    };

    class TrainedNinja : public Ninja 
    {
    public:
        TrainedNinja(const std::string& name, const Point& location);
    };

    class OldNinja : public Ninja 
    {
    public:
        OldNinja(const std::string& name, const Point& location);
    };







}