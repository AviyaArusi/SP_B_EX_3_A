#include "doctest.h"

#include "sources/Character.hpp"
#include "sources/OldNinja.hpp"
#include "sources/YoungNinja.hpp"
#include "sources/TrainedNinja.hpp"
#include "sources/Cowboy.hpp"
#include "sources/Team.hpp"
#include "sources/Team2.hpp"

#include <iostream>

using namespace std;
using namespace ariel;

TEST_CASE("Point")
{
    Point a;
    CHECK_EQ(a.get_x(), 0);
    CHECK_EQ(a.get_x(), 0);

}

TEST_SUITE("Point class tests") 
{
    Point p1(3.0, 4.0);
    Point p2(6.0, 8.0);
    Point p3, p4(3,0);
    TEST_CASE("Test get_x and get_y") 
    {
        CHECK_EQ(p1.get_x(), 3.0);
        CHECK_EQ(p1.get_y(), 4.0);
        CHECK_EQ(p3.get_x(), 0);// Empty constructor
        CHECK_EQ(p3.get_y(), 0);
        CHECK_FALSE(p3.get_x() != 0);
        CHECK_FALSE(p3.get_y() != 0);
    }

    TEST_CASE("Test distance") 
    {
        CHECK_EQ(p3.distance(p4), (3.0));
        CHECK_FALSE(p3.distance(p4) != (3.0));
    }

    TEST_CASE("Test print") 
    {
        CHECK_EQ(p1.print(), "(3.0, 4.0)");
        CHECK_FALSE(p1.print() != "(3.0, 4.0)");
    }

    TEST_CASE("Test moveTowards")
    {
        Point p5 = Point::moveTowards(p3, p4, 3);
        CHECK_EQ(p5.get_x(), 3.0);
        CHECK_EQ(p5.get_y(), 0.0);
    }
}


TEST_SUITE("Cowboy class tests") 
{
    Point p(0.0, 0.0);
    Cowboy c1("Aviya", p);
    Cowboy c2("Arusi", p);

    TEST_CASE("Cowboy constructor")
    {
        CHECK_EQ(c1.getName(), "Aviya");
        CHECK_FALSE(c1.getName() != "Aviya");
        CHECK_EQ(c1.getLocation().get_x(), 0);
        CHECK_EQ(c1.getLocation().get_y(), 0);
        CHECK(c1.hasBullets());
        CHECK_EQ(c1.getHealth(), 110);
        CHECK_FALSE(c1.getHealth() != 110);

    }

    TEST_CASE("Test shoot and hasBullets") 
    {
        for (size_t i = 0; i < 6; i++)
        {
            c1.shoot(&c2);
        }
        CHECK_EQ(c2.getHealth(), 104);
        CHECK_FALSE(c1.hasBullets());
    }

    TEST_CASE("Test reload") 
    {
        c1.reload();
        CHECK(c1.hasBullets());
    }
    
    TEST_CASE("isAlive")
    {
        CHECK(c2.isAlive() == true);
        for (size_t i = 0; i < 104; i++)
        {
            c1.shoot(&c2);
        }        
        CHECK_FALSE(c2.isAlive());
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
        CHECK_EQ(young.getLocation().get_x(), (0));
        CHECK_EQ(young.getLocation().get_y(), (0));
        CHECK_EQ(young.getHealth(), 100);
        CHECK_EQ(young.getSpeed(), 14);
        CHECK_EQ(young.getName(), "YoungNinja");
        CHECK(young.isAlive()); 

    }

    TEST_CASE("Test move") 
    {
        
        young.move(&young2);
        CHECK_EQ(young.getLocation().get_x(), (0.0));
        CHECK_EQ(young.getLocation().get_y(), (8.0));
    }

    TEST_CASE("Test slash") 
    {
        CHECK_EQ(young2.getHealth(), 100); // because the character is within 1m distance
        young.slash(&young2);
        CHECK_EQ(young2.getHealth(), 60); // because the character is within 1m distance
    }
}

TEST_SUITE("TrainedNinja class")
{
    Point p2(1.0, 1.0);
    TrainedNinja trained("TrainedNinja", p2);

    TEST_CASE("TrainedNinja constructor")
    {
        CHECK_EQ(trained.getLocation().get_x(), (1));
        CHECK_EQ(trained.getLocation().get_y(), (1));
        CHECK_EQ(trained.getLocation().get_x(), (0));
        CHECK_EQ(trained.getLocation().get_y(), (0));
        CHECK_EQ(trained.getHealth(), 120);
        CHECK_EQ(trained.getSpeed(), 12);
        CHECK_EQ(trained.getName(), "TrainedNinja");
        CHECK(trained.isAlive()); 
    }

}

TEST_SUITE("OldNinja class")
{
    Point p3(3.0, 3.0);
    OldNinja old("OldNinja", p3);

    TEST_CASE("OlddNinja constructor")
    {
        CHECK_EQ(old.getLocation().get_x(), (2));
        CHECK_EQ(old.getLocation().get_y(), (2));
        CHECK_EQ(old.getLocation().get_x(), (0));
        CHECK_EQ(old.getLocation().get_y(), (0));
        CHECK_EQ(old.getHealth(), 150);
        CHECK_EQ(old.getSpeed(), 8);
        CHECK_EQ(old.getName(), "OlddNinja");
        CHECK(old.isAlive()); 
    }
}


TEST_SUITE("Team class") 
{
    Point p1(4.0, 0.0);
    OldNinja N1("N1", p1);

    Point p2(0.0, 0.0);
    YoungNinja N2("N2", p2);
    
    Point p3(4.0, 4.0);
    TrainedNinja N3("N3", p3);
    
    Point p4(0.0, 4.0);
    Cowboy C1("N4", p1);
    
    Team t1;
    Team t2(&N1);
    TEST_CASE("Team onstructors")
    {
        CHECK_EQ(t1.getLeader(), nullptr);
        CHECK_EQ(t2.getLeader(), &N1);
    }

    TEST_CASE("Adding characters to team and checking their count") 
    {
        CHECK_EQ(t1.stillAlive(), 1);
        t1.add(&N2);
        CHECK_EQ(t1.stillAlive(), 2);
    }

    TEST_CASE("Testing attack function") 
    {
        CHECK_THROWS(t1.attack(&t2));
        CHECK_THROWS(t2.attack(&t1));
        t1.add(&N3);
        t1.add(&C1);
        CHECK_NOTHROW(t1.attack(&t2));
        int counter = 100;
        while (t2.stillAlive() && counter-- > 0)
        {
            t1.attack(&t2);
        }
        CHECK(counter > 0);
        CHECK(t2.stillAlive() == false);
    }

}

TEST_SUITE("Team2") 
{
    Point p1(4.0, 4.0);
    TrainedNinja N1("N1", p1);
    
    Point p2(8.0, 8.0);
    TrainedNinja N2("N2", p2);

    Point p3(0.0, 4.0);
    Cowboy C1("C1", p3);
    
    Team2 t2(&N1);
    TEST_CASE("Adding characters to team2 and checking their count") 
    {
        t2.add(&C1);
        t2.add(&N2);
        Character * firstMember;
        int counter = 0;
        for (auto member : t2.getTeam())
        {
            if(counter == 0) { firstMember = member; break;}
        }
        CHECK_EQ(firstMember, &C1);// Check that the cowboy is first.
    }

}

