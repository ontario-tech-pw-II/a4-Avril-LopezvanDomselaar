#include <iostream>
#include <cmath>
using namespace std;

class Circle {
  private:
    int x,y;      // center of circle
    double r;    // radius of circle

  public:

    Circle(int =0,int=0, double =1.0);
    void print() const;
    double area() const;

    double operator+(const Circle &) const;

    Circle & operator++();
    Circle operator++(int);

  friend ostream & operator<<(ostream &out, const Circle &);
  friend istream & operator>>(istream &in, Circle &);
};

Circle::Circle(int xcoord,int ycoord, double radius)
{
  // Initialize the object here
  x = xcoord;
  y = ycoord;
  r = radius;
}

double Circle::area() const {
  // Return the area of a circle
  return (3.141592653589793238463)*r*r;
}

double Circle::operator+(const Circle & c) const
{
   // + Return the area of two circles
   Circle temp = Circle(x+c.x, y+c.y, r+c.r);
   double final_area = temp.area();
   return final_area;
}

Circle & Circle::operator++()
{
  // Increment the radius by 1
  r++;
  return *this;
}

Circle Circle::operator++(int)
{
  Circle temp = *this;

  //increment the radius by 1
  r++;
  return temp;
}

ostream & operator<<(ostream &out, const Circle &c)
{

  // print a circle in the out stream (the format is the same as print())
  out << "Circle =(" << c.x << "," << c.y << "," << c.r << ")" << endl;
  return out;
}

istream & operator>>(istream &in, Circle &c)
{

 // Read a circle information from the in stream
  int tempX, tempY;
  double tempR;

  cout << "\tX coordinate: ";
  in >> tempX;

  cout << "\tY coordinate: ";
  in >> tempY;

  cout << "\tRadius: ";
  in >> tempR;

  c = Circle(tempX, tempY, tempR);

  return in;
}


void Circle::print() const
{
  cout << "Circle =(" << x << "," << y << "," << r << ")" << endl;
}



int main()
{
  Circle a;
  Circle b(2,3,3.0);

  a.print();
  b.print();

  cout << "The area a + b is: " << a+b << endl;
  ++a;
  a.print();

  a++;
  a.print();

  cout << a;

  cin >> a;
  cout <<a;

  return 0;

}
