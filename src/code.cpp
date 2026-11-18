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
    return std::numbers::pi * this->radius * this->radius;
}

/// Return exactly "Circle".
std::string Circle::name() const
{
    return "Circle";
}

Square::Square(double newSide)
{
    side = newSide;
}

/// side * side
double Square::area() const
{
    return this->side * this->side;
}

/// Return exactly "Square".
std::string Square::name() const
{
    return "Square";
}

Rectangle::Rectangle(double newWidth, double newHeight)
{
    width = newWidth;
    height = newHeight;
}

/// width * height
double Rectangle::area() const
{
    return this->width * this->height;
}

/// Return exactly "Rectangle".
std::string Rectangle::name() const
{
    return "Rectangle";
}

// ============================================================
// PART 2: ShapeList
// ============================================================

/// RAII: delete EVERY shape, then clear the list.
ShapeList::~ShapeList()
{
    // TODO: implement
}

/// Append at the end. Return -1 if newShapePtr is nullptr, 0 on success.
int ShapeList::addShape(Shape *newShapePtr)
{
    // TODO: implement
    return -1;
}

/// Delete the first shape and remove it from the list.
/// Return false if the list is empty, true otherwise.
bool ShapeList::removeFirst()
{
    // TODO: implement
    return false;
}

/// Number of shapes in the list.
int ShapeList::length() const
{
    // TODO: implement
    return 0;
}

/// Sum of area() of all shapes (0.0 if empty).
double ShapeList::totalArea() const
{
    // TODO: implement
    return 0.0;
}

/// One line per shape: name, one space, area. Return the number of shapes.
int ShapeList::printList() const
{
    // TODO: implement
    return 0;
}

/// area() of the shape at index, or std::nullopt if index is out of range.
/// Hint: std::next(data.begin(), index)
std::optional<double> ShapeList::areaAt(int index) const
{
    // TODO: implement
    return std::nullopt;
}

/// name() of the shape at index, or std::nullopt if index is out of range.
std::optional<std::string> ShapeList::nameAt(int index) const
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
