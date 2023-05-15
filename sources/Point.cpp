#include "Point.hpp"


using namespace std;
namespace ariel
{
    Point::Point(double x = 0, double y = 0) : _x(x), _y(y)
    {

    }
    // Point(Point&);

    int Point::get_x() const { return _x;}
    int Point::get_y() const { return _y;}

    double Point::distance(Point &other) const
    {
        double ans = sqrt( pow( (other.get_x() -_x) , 2) + pow( (other.get_y()-_y) , 2) );
        return ans;
    }

    void Point::print() { cout << "(" << _x << ", " << _y << ")" << endl; }
    
    Point moveTowards(Point source, Point destination, double distance) 
    {   
        double dx = destination.get_x() - source.get_x();
        double dy = destination.get_y() - source.get_y();
        double currentDistance = sqrt(dx * dx + dy * dy);
        if (currentDistance <= distance) 
        {
            return destination;
        } 
        else 
        {
            double ratio = distance / currentDistance;
            double newX = source.get_x() + dx * ratio;
            double newY = source.get_y() + dy * ratio;
            return Point(newX, newY);
        }
    }


}