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
            double distance(const Point& other) const;
            void print() const;
            friend Point moveTowards(const Point&, const Point&, int);

    };

}