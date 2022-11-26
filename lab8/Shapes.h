//
// Created by Mai on 12/20/2021.
//

#ifndef POLYMORPHISEM_SHAPE_H
#define POLYMORPHISEM_SHAPE_H
using namespace std;
class Point{
public:
    // point zero c'tor
    Point():x(0),y(0){};
    // default c'tor
    explicit Point(int x, int y):x(x),y(y){};
    //copy - c'tor
    Point(const Point& p):x(p.x),y(p.y){};
    // d'tor -> default
    ~Point(){};


    // Setters & Getters
    int getX() const {
        return x;
    }

    void setX(int setX) {
        Point::x = setX;
    }

    int getY() const {
        return y;
    }

    void setY(int setY) {
        Point::y = setY;
    }

private:
    int x;
    int y;
};




class Shape {
public:
    explicit Shape(const Point& base): basePoint(base){}
    virtual ~Shape(){} // virtual destructor
    virtual string ShapeType(){return "Shape";}
    virtual double GetArea() { return -1; }
    virtual double GetPerim() { return -1; }
    virtual void Draw(char symbol) {}
    virtual Point GetPoint(){return basePoint;}
    virtual void SetPoint(int x, int y){basePoint.setX(x); basePoint.setY(y);}

private:
    Point basePoint;
};


class Rectangle : public Shape
{
public:
    Rectangle(const Point& base,int wid, int len):Shape(base), width(wid),length(len){};
    virtual string ShapeType(){return "Rectangle";}
    virtual double GetArea() { return length * width; }
    virtual double GetPerim() {return 2*length + 2*width; }
    virtual int GetLength() { return length; }
    virtual int GetWidth() { return width; }
    virtual void Draw(char symbol){}

private:
    int width;
    int length;
};

class Square : public Rectangle{
public:
    Square(const Point& base, int s): Rectangle(base, s, s), side(s){}
    virtual string ShapeType(){return "Square";}
    virtual int GetSide() { return side; }
    virtual double GetPerim() {return 4 * side;}
    virtual double GetArea() {return side * side;}
    virtual void Draw(char symbol);
private:
    int side;
};





class Triangle : public Shape{
public:
    Triangle(const Point& p, int sBaseSize):Shape(p), baseSize(sBaseSize){}
    virtual string ShapeType(){return "Triangle";}
    virtual double GetArea() { return (double)baseSize*baseSize/2;}
    virtual int getBaseSize() const {return baseSize;}
    virtual void setBaseSize(int setBase) {
        Triangle::baseSize = setBase;
    }
    virtual void Draw(char symbol){}

private:
    int baseSize;
        };

class RightTriangle : public Triangle{

public:
    RightTriangle(const Point& p, int baseSize): Triangle(p,baseSize){}
    virtual string ShapeType(){return "RightTriangle";}
    virtual int getBaseSize() const{return Triangle::getBaseSize();}
    virtual double GetArea() {return Triangle::GetArea()/2;}
    virtual void Draw(char symbol);



};





#endif //POLYMORPHISEM_SHAPE_H
