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
    CHECK(a.get_x() == 0);

}

TEST_SUITE("Point class tests") 
{
    Point p1(3.0, 4.0);
    Point p2(6.0, 8.0);
    Point p3;
    TEST_CASE("Test get_x and get_y") 
    {
        CHECK(p1.get_x() == (3.0));
        CHECK(p1.get_y() == (4.0));
        CHECK(p3.get_x() == 0);// Empty constructor
        CHECK(p3.get_y() == 0);
        CHECK_FALSE(p3.get_x() != 0);
        CHECK_FALSE(p3.get_y() != 0);
    }

    TEST_CASE("Test distance") 
    {
        CHECK(p1.distance(p2) == (5.0));
        CHECK_FALSE(p1.distance(p2) != (5.0));
    }

    TEST_CASE("Test print") 
    {
        CHECK(p1.print() == "(3.0, 4.0)");
        CHECK_FALSE(p1.print() != "(3.0, 4.0)");
    }

    TEST_CASE("Test moveTowards") //!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
    {
        Point p3 = Point::moveTowards(p1, p2, 1.0);
        CHECK(p3.get_x() == 3.6);
        CHECK(p3.get_y() == 4.8);
    }
}

// TEST_SUITE("Character class tests") 
// {
//     Point p1(0.0, 0.0);
//     Point p2(3.0, 4.0);
//     Character character1("TestCharacter1", p1, 100);

//     TEST_CASE("Test getName and getLocation") 
//     {
//         CHECK(character1.getName() == "TestCharacter1");
//         CHECK(character1.getLocation().get_x() == 0.0);
//         CHECK(character1.getLocation().get_y() == 0.0);
//     }

//     TEST_CASE("Test isAlive and getHealth") 
//     {
//         CHECK(character1.isAlive() == true);
//         CHECK(character1.getHealth() == 100);
//         character1.hit(100);
//         CHECK(character1.isAlive() == false);
//     }

//     TEST_CASE("Test distance") 
//     {
//         Character character2("TestCharacter2", p2, 100);
//         CHECK(character1.distance(&character2) == Approx(5.0));
//     }
// }

TEST_SUITE("Cowboy class tests") 
{
    Point p(0.0, 0.0);
    Cowboy c1("Aviya", p);
    Cowboy c2("Arusi", p);

    TEST_CASE("Cowboy constructor")
    {
        CHECK(c1.getName() == "Aviya");
        CHECK_FALSE(c1.getName() != "Aviya");
        CHECK(c1.getLocation().get_x() == 0);
        CHECK(c1.getLocation().get_y() == 0);
        CHECK(c1.hasBullets());
        CHECK(c1.getHealth() == 110);
        CHECK_FALSE(c1.getHealth() != 110);

    }

    TEST_CASE("Test shoot and hasBullets") 
    {
        for (size_t i = 0; i < 6; i++)
        {
            c1.shoot(&c2);
        }
        CHECK(c2.getHealth() == 104);
        CHECK(c1.hasBullets() == false);
    }

    TEST_CASE("Test reload") 
    {
        c1.reload();
        CHECK(c1.hasBullets() == true);
    }
    
    TEST_CASE("isAlive")
    {
        CHECK(c2.isAlive() == true);
        for (size_t i = 0; i < 104; i++)
        {
            c1.shoot(&c2);
        }        
        CHECK(c2.isAlive() == false);
    }
}

TEST_SUITE("YoungNinja class ") 
{
    Point p1(0.0, 0.0);
    YoungNinja young("YoungNinja", p1);
    Point p2(0.0, 9.0);
    YoungNinja young2("YoungNinja", p2);

    TEST_CASE("YoungNinja Constructor")
    {
        CHECK(young.getLocation().get_x() == (0));
        CHECK(young.getLocation().get_y() == (0));
        CHECK(young.getHealth() = 100);
        CHECK(young.getSpeed() = 14);
        CHECK(young.getName() = "YoungNinja");
        CHECK(young.isAlive() == true); 

    }

    TEST_CASE("Test move") 
    {
        
        young.move(&young2);
        CHECK(young.getLocation().get_x() == (0.0));
        CHECK(young.getLocation().get_y() == (8.0));
    }

    TEST_CASE("Test slash") 
    {
        CHECK(young2.getHealth() == 100); // because the character is within 1m distance
        young.slash(&young2);
        CHECK(young2.getHealth() == 60); // because the character is within 1m distance
    }
}

TEST_SUITE("TrainedNinja class")
{
    Point p2(1.0, 1.0);
    TrainedNinja trained("TrainedNinja", p2);

    TEST_CASE("TrainedNinja constructor")
    {
        CHECK(trained.getLocation().get_x() == (1));
        CHECK(trained.getLocation().get_y() == (1));
        CHECK(trained.getLocation().get_x() == (0));
        CHECK(trained.getLocation().get_y() == (0));
        CHECK(trained.getHealth() = 120);
        CHECK(trained.getSpeed() = 12);
        CHECK(trained.getName() = "TrainedNinja");
        CHECK(trained.isAlive() == true); 
    }

}

TEST_SUITE("OldNinja class")
{
    Point p3(3.0, 3.0);
    OldNinja old("OldNinja", p3);

    TEST_CASE("OlddNinja constructor")
    {
        CHECK(old.getLocation().get_x() == (2));
        CHECK(old.getLocation().get_y() == (2));
        CHECK(old.getLocation().get_x() == (0));
        CHECK(old.getLocation().get_y() == (0));
        CHECK(old.getHealth() = 150);
        CHECK(old.getSpeed() = 8);
        CHECK(old.getName() = "OlddNinja");
        CHECK(old.isAlive() == true); 
    }
}


TEST_SUITE("Team class") 
{
    TEST_CASE("Adding characters to team and checking their count") 
    {
        Team team(new Ninja("Ninja1", Point(0.0,0.0), 150, 8));
        CHECK(team.stillAlive() == 1);
        team.add(new Cowboy("Cowboy1", ));
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

