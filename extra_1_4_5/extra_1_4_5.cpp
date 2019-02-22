#include <iostream>
using namespace std;

class rectangleType {
public:
    void setDimension(double l, double w){
        if (l >= 0)
            length = l;
        else
            length = 0;
        if (w >= 0)
            width = w;
        else
            width = 0;
    };
    //Function to set the length and width of the rectangle. //Postcondition: length = l; width = w;
    double getLength() const {
        return length;
    };
    //Function to return the length of the rectangle. //Postcondition: The value of length is returned.
    double getWidth() const {
        return width;
    };
    //Function to return the width of the rectangle. //Postcondition: The value of width is returned.
    double area() const {
        return length * width;
    };
    //Function to return the area of the rectangle. //Postcondition: The area of the rectangle is calculated // and returned.
    double perimeter() const {
        return 2 * (length + width);
    };
    //Function to return the perimeter of the rectangle. //Postcondition: The perimeter of the rectangle is // calculated and returned.
    void print() const {
        cout << "Length = "  << length
        << "; Width = " << width;
    };
    //Function to output the length and width of the rectangle.
    rectangleType() {
        length = 0;
        width = 0;
    };
    //default constructor
    //Postcondition: length = 0; width = 0;
    rectangleType(double l, double w) {
        setDimension(l, w);
    };
    //constructor with parameters
    //Postcondition: length = l; width = w;
private:
    double length;
    double width;
};

class boxType: public rectangleType
{
public:
    void setDimension(double l, double w, double h) {
        rectangleType::setDimension(l, w);
        if (h >= 0)
            height = h;
        else
            height = 0;
    };
    //Function to set the length, width, and height of the box. //Postcondition: length = l; width = w; height = h;
    double getHeight() const {
        return height;
    };
    //Function to return
    //Postcondition: The the height of the box.value of height is returned.
    double area() const {
        return 2 * (getLength() * getWidth()
                    + getLength() * height
                    + getWidth() * height);
    };
    //Function to return
    //Postcondition: The
    //    calculated and returned.
    double volume() const{
        return rectangleType::area() * height;
    };
    //Function to return
    //Postcondition: The
    //    returned.
    void print() const {
        rectangleType::print();
        cout << "; Height = " << height;
    };
    //Function to output the volume of the box.volume of the box is calculated and the length, width, and height of a box.
    boxType() {
        height = 0.0;
    };
    //Default constructor
    //Postcondition: length = 0; width =
    boxType(double l, double w, double h)
    : rectangleType(l, w)
    {
        if (h >= 0)
            height = h;
        else
            height = 0;
    };
    //Constructor with parameters
    //Postcondition: length = l; width =
private:
    double height;
};

int main() {
    rectangleType myRectangle(5.0, 3.0);
    boxType myBox(6.0, 5.0, 4.0);
    myRectangle.print();
    cout << endl;
    myBox.print();
    cout << endl;
    return 0;
}
