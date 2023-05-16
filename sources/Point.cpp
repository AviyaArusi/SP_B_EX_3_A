#include "Point.hpp"


using namespace std;
namespace ariel
{
    Point::Point() : _x(0), _y(0) {}
    Point::Point(double x, double y) : _x(x), _y(y) {}

    int Point::get_x() const { return _x;}
    int Point::get_y() const { return _y;}

    double Point::distance(const Point &other) const { return 0; }

    string Point::print() const { return ""; }
    
    Point Point::moveTowards(const Point& source, const Point& destination, double distance) { return destination; }


}