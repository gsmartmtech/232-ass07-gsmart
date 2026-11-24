// ============================================================
// CSCI 232 Assignment 07 – Shapes, Polymorphism and Insertion Sort
// Student Implementation
// ============================================================

#include "code.hpp"
#include <iostream>
#include <iterator>
#include <numbers>

// Uncomment the author block below and fill in your name:

std::string AUTHOR_NAME = "Garrett Smart";
std::string AUTHOR_AUTHORSHIP = "I acknowledge that I have worked on this assignment independently, except where explicitly noted and referenced. Any collaboration or use of external resources has been properly cited. I am fully aware of the consequences of academic dishonesty and agree to abide by the university's academic integrity policy.";

// ============================================================
// PART 1: Shape, Circle, Square, Rectangle
// ============================================================

/// True if THIS shape has a strictly smaller area() than other.
bool Shape::operator<(const Shape &other) const
{
    return this->area() < other.area();
}

/// Constructor with a member initializer list.
Circle::Circle(double newRadius)
{
   radius = newRadius;
}

/// pi * radius * radius, use std::numbers::pi
double Circle::area() const
{
    double result = std::numbers::pi * this->radius * this->radius;
    return result;
}

/// Return exactly "Circle".
std::string Circle::name() const
{
    return std::string("Circle");
}

Square::Square(double newSide)
{
    side = newSide;
}

/// side * side
double Square::area() const
{
    double result = this->side * this->side;
    return result;
}

/// Return exactly "Square".
std::string Square::name() const
{
    return std::string("Square");
}

Rectangle::Rectangle(double newWidth, double newHeight)
{
    width = newWidth;
    height = newHeight;
}

/// width * height
double Rectangle::area() const
{
    double result = this->width * this->height;
    return result;
}

/// Return exactly "Rectangle".
std::string Rectangle::name() const
{
    return std::string("Rectangle");
}

// ============================================================
// PART 2: ShapeList
// ============================================================

/// RAII: delete EVERY shape, then clear the list.
ShapeList::~ShapeList()
{
    while(this->length() > 0)
    {
        this->removeFirst();
    }
}

/// Append at the end. Return -1 if newShapePtr is nullptr, 0 on success.
int ShapeList::addShape(Shape *newShapePtr)
{
    if (newShapePtr == nullptr)
    {
        return -1;
    }
    else
    {
        this->data.push_back(newShapePtr);
        return 0;
    }
}

/// Delete the first shape and remove it from the list.
/// Return false if the list is empty, true otherwise.
bool ShapeList::removeFirst()
{
    if (this->data.empty() == true)
    {
        return false;
    }
    else
    {
        this->data.pop_front();
        return true;
    }
}

/// Number of shapes in the list.
int ShapeList::length() const
{
    return static_cast<int>(this->data.size());
}

/// Sum of area() of all shapes (0.0 if empty).
double ShapeList::totalArea() const
{
    double sum = 0.0;
    if (this->data.empty() == true)
    {
        return 0.0;
    }
    else
    {
        for (Shape* v: this->data)
        {
            sum += v->area();
        }
    }
}

/// One line per shape: name, one space, area. Return the number of shapes.
int ShapeList::printList() const
{
    int count = 0;
    for (Shape* v: this->data)
    {
        std::cout << v->name() << " " << v->area() << '\n';
        count += 1;
    }
    return 0;
}

/// area() of the shape at index, or std::nullopt if index is out of range.
/// Hint: std::next(data.begin(), index) // should not return null
std::optional<double> ShapeList::areaAt(int index) const
{
    std::next(data.begin(), index);
    //return std::nullopt;
}

/// name() of the shape at index, or std::nullopt if index is out of range.
std::optional<std::string> ShapeList::nameAt(int index) const //whole implementation must be done cause segmention fault will occur otherwise
{
    // TODO: implement
    return std::nullopt;
}

/// Your own STABLE insertion sort, smallest area first.
/// Compare shapes with operator< (dereference the pointers!).
/// Hint: for every element, walk left while the previous shape is bigger,
/// then move the element there with data.splice(...).
void ShapeList::insertionSort()
{
    // TODO: implement
}

/// True if no shape is smaller than the one before it.
bool ShapeList::isSorted() const
{
    // TODO: implement
    return false;
}
