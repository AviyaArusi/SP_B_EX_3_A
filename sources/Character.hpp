#pragma once

#include <iostream>
#include <cmath>
#include <string>
#include "Point.hpp"

namespace ariel
{

    class Character
    {
        private:
            Point _location;
            int _healthPoints;
            std::string _name;

        public:
            Character (const std::string&, const Point&, int);
            
            Character(Character&);
            Character(Character&&) noexcept;
            Character& operator=(const Character&);
            Character& operator=(Character&&) noexcept;
            virtual ~Character() = default;

            std::string getName() const;
            Point getLocation() const;
            int getHealth() const;
            bool isAlive() const;
            double distance(const Character*) const;
            void hit(int);
            virtual std::string print() const = 0; // Pure virtual function
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
        std::string print() const override;
    };


    class Ninja : public Character 
    {
    private:
        int _speed;

    public:
        Ninja(const std::string&, const Point&, int, int);
        void move(Character*);
        void slash(Character*);
        int getSpeed() const;
        std::string print() const override;
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