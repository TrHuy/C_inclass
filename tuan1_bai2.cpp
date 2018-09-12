#include <iostream>
#include <iomanip>
using namespace std;

class Point
{
    double x_, y_;
public:
    Point() : x_(0), y_(0) {}
    Point(double x, double y) : x_(x), y_(y) {}
    double getX() const { return x_; }
    double getY() const { return y_; }
};

class Line
{
    double a_, b_, c_;
public:
    Line() : a_(1), b_(1), c_(0) {}
    Line(const Point &p1, const Point &p2)
    {
        double x1 = p1.getX(),
            x2 = p2.getX(),
            y1 = p1.getY(),
            y2 = p2.getY();
        a_ = y2 - y1;
        b_ = x1 - x2;
        c_ = a_ * x1 + b_ * y1;
    }
    double getA() const { return a_; }
    double getB() const { return b_; }
    double getC() const { return c_; }

    void printEquation()
    {
        cout << a_ << "*x+" << b_ << "*y=" << c_ << endl;
    }
};

void printIntersection(const Line &l1, const Line &l2)
{
    double a1 = l1.getA(),
        a2 = l2.getA(),
        b1 = l1.getB(),
        b2 = l2.getB(),
        c1 = l1.getC(),
        c2 = l2.getC();
    double det = a1*b2 - a2*b1;
    if (det == 0)
    {
        // NO or MANY
    }
    else
    {
        double x = (c1*b2 - c2*b1) / det;
        double y = (c2*a1 - c1*a2) / det;
        cout << fixed << setprecision(2) << x << " " << y << endl;
    }
}

int main()
{
    Point A(0,0), B(1,1), C(0,1), D(1,0);
    Line l1(A, B), l2(C, D);
    printIntersection(l1, l2);
    return 0;
}
