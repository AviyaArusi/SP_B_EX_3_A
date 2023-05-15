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
            // Point(double x, double y);
            // Point(Point&);
            
            Point();
            Point(double, double);
            
            int get_x() const;
            int get_y() const;
            double distance(const Point& other) const;
            std::string print() const;
            friend Point moveTowards(const Point&, const Point&, int);

    };

}