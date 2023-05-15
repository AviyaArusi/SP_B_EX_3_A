#pragma once

#include <iostream>
#include <cmath>

namespace ariel
{

    class Point
    {

        private:
            double _x;
            double _y;

        public:
            Point(double x = 0, double y = 0);
            // Point(Point&);
            int get_x() const;
            int get_y() const;
            double distance(Point &other) const;
            void print();
            friend void moveTowards(Point&, Point&, int);







    };

}