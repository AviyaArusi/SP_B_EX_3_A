#include <stdexcept>
#include <iostream>
#include <sstream>
// #include <catch2/catch.hpp>  
#include "doctest.h"

#include "sources/Character.hpp"
#include "sources/OldNinja.hpp"
#include "sources/YoungNinja.hpp"
#include "sources/TrainedNinja.hpp"
#include "sources/Cowboy.hpp"
#include "sources/Team.hpp"
#include "sources/Team2.hpp"

using namespace ariel;
using namespace std;

TEST_CASE("Point")
{
    Point a;
    CHECK(a.get_x() == 0);
}

TEST_SUITE("Point class tests") 
{
    Point p1(3.0, 4.0);
    Point p2(6.0, 8.0);

    TEST_CASE("Test get_x and get_y") 
    {
        CHECK(p1.get_x() == Approx(3.0));
        CHECK(p1.get_y() == Approx(4.0));
    }

    TEST_CASE("Test distance") 
    {
        CHECK(p1.distance(p2) == Approx(5.0));
    }

    TEST_CASE("Test print") 
    {
        CHECK(p1.print() == "(3.00, 4.00)");
    }

    TEST_CASE("Test moveTowards") 
    {
        Point p3 = moveTowards(p1, p2, 1.0);
        CHECK(p3.get_x() == 3.6);
        CHECK(p3.get_y() == 4.8);
    }
}

TEST_SUITE("Character class tests") 
{
    Point p1(0.0, 0.0);
    Point p2(3.0, 4.0);
    Character character1("TestCharacter1", p1, 100);

    TEST_CASE("Test getName and getLocation") 
    {
        CHECK(character1.getName() == "TestCharacter1");
        CHECK(character1.getLocation().get_x() == 0.0);
        CHECK(character1.getLocation().get_y() == 0.0);
    }

    TEST_CASE("Test isAlive and getHealth") 
    {
        CHECK(character1.isAlive() == true);
        CHECK(character1.getHealth() == 100);
        character1.hit(100);
        CHECK(character1.isAlive() == false);
    }

    TEST_CASE("Test distance") 
    {
        Character character2("TestCharacter2", p2, 100);
        CHECK(character1.distance(&character2) == Approx(5.0));
    }
}

TEST_SUITE("Cowboy class tests") 
{
    Point p(0.0, 0.0);
    Cowboy cowboy("TestCowboy", p);

    TEST_CASE("Test shoot and hasBullets") 
    {
        Character character1("TestCharacter1", p, 100);
        CHECK(cowboy.hasBullets() == true);
        cowboy.shoot(&character1);
        CHECK(character1.getHealth() == 90);
        CHECK(cowboy.hasBullets() == true); // Now has 5 bullets
    }

    TEST_CASE("Test reload") 
    {
        for (int i = 0; i < 6; i++) { // empty the gun
            Character character1("TestCharacter1", p, 100);
            cowboy.shoot(&character1);
        }
        CHECK(cowboy.hasBullets() == false);
        cowboy.reload();
        CHECK(cowboy.hasBullets() == true);
    }
}

TEST_SUITE("Ninja classes tests") 
{
    Point p1(0.0, 0.0);
    Point p2(1.0, 1.0);
    YoungNinja youngNinja("TestYoungNinja", p1);
    TrainedNinja trainedNinja("TestTrainedNinja", p1);
    OldNinja oldNinja("TestOldNinja", p1);

    TEST_CASE("Test move") 
    {
        Character character1("TestCharacter1", p2, 100);
        youngNinja.move(&character1);
        CHECK(youngNinja.getLocation().get_x() == Approx(0.707107));
        CHECK(youngNinja.getLocation().get_y() == Approx(0.707107));
    }

    TEST_CASE("Test slash") 
    {
        Character character1("TestCharacter1", p1, 100);
        youngNinja.slash(&character1);
        CHECK(character1.getHealth() == 60); // because the character is within 1m distance
    }
}


TEST_SUITE("Team") 
{
    TEST_CASE("Adding characters to team and checking their count") 
    {
        Team team(new Ninja(1, 2, 3));
        CHECK(team.stillAlive() == 1);
        team.add(new Cowboy(2, 3, 4, 5));
        CHECK(team.stillAlive() == 2);
        team.add(new Ninja(3, 4, 5));
        CHECK(team.stillAlive() == 3);
    }

    TEST_CASE("Testing attack function") 
    {
        Team team1(new Ninja(1, 2, 3));
        Team team2(new Cowboy(2, 3, 4, 5));
        team1.attack(&team2);
        // Add your own checks based on your implementation of attack() function
    }

    TEST_CASE("Testing print function") 
    {
        Team team(new Ninja(1, 2, 3));
        team.add(new Cowboy(2, 3, 4, 5));
        string output = team.print();
        // Check output based on your implementation of print() function
    }
}

TEST_SUITE("Team2") 
{
    TEST_CASE("Adding characters to team2 and checking their count") 
    {
        Team2 team2(new Ninja(1, 2, 3));
        CHECK(team2.stillAlive() == 1);
        team2.add(new Cowboy(2, 3, 4, 5));
        CHECK(team2.stillAlive() == 2);
    }

    // Add more test cases for Team2 as needed
}

TEST_SUITE("SmartTeam") 
{
    TEST_CASE("Adding characters to SmartTeam and checking their count") 
    {
        SmartTeam smartTeam(new Ninja(1, 2, 3));
        CHECK(smartTeam.stillAlive() == 1);
        smartTeam.add(new Cowboy(2, 3, 4, 5));
        CHECK(smartTeam.stillAlive() == 2);
    }

    // Add more test cases for SmartTeam as needed
}

