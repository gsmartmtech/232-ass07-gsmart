#ifndef UNITY_H
#define UNITY_H
#include "unity.h"
#endif

#include "code.hpp"
#include <cmath>
#include <iostream>
#include <numbers>

// ============================================================
// PART 1 Tests: Shapes
// ============================================================

/// Create Circle(1), Square(2), Rectangle(2, 3).
/// Verify area() is pi, 4 and 6 (compare doubles with std::fabs(a - b) < 1e-9).
void test_shape_areas(void)
{
    Shape* circ = new Circle(1);
    Shape* squa = new Square(2);
    Shape* rect = new Rectangle(2, 3);
    bool circRes = fabs(std::numbers::pi - circ->area()) < 1e-9;
    bool squaRes = fabs(4 - squa->area()) < 1e-9;
    bool rectRes = fabs(6 - rect->area()) < 1e-9;
    TEST_ASSERT_TRUE_MESSAGE(circRes, "area did not equal pi");
    TEST_ASSERT_TRUE_MESSAGE(squaRes, "area did not equal 4");
    TEST_ASSERT_TRUE_MESSAGE(rectRes, "area did not equal 6");
    circ->~Shape();
    squa->~Shape();
    rect->~Shape();
}

/// Create an array of three Shape* (a Circle, a Square, a Rectangle) with new.
/// Verify name() through the BASE pointer gives "Circle", "Square", "Rectangle".
/// Delete the shapes through the base pointers.
void test_shape_names_through_base_pointer(void)
{
    Shape* arr[3] = { new Circle(1), new Square(2), new Rectangle(1, 8) };
    Shape& circRef = *arr[0];
    Shape& squaRef = *arr[1];
    Shape& rectRef = *arr[2];

    TEST_ASSERT_TRUE_MESSAGE(circRef.name() == "Circle", "name was not 'Circle'");
    TEST_ASSERT_TRUE_MESSAGE(squaRef.name() == "Square", "name was not 'Square'");
    TEST_ASSERT_TRUE_MESSAGE(rectRef.name() == "Rectangle", "name was not 'Rectangle'");
    arr[0]->~Shape();
    arr[1]->~Shape();
    arr[2]->~Shape();
}

/// Create Square(1) and Square(2). Take two const Shape& to them.
/// Verify small < big is true, big < small is false, small < small is false.
void test_shape_operator_less(void)
{
    Shape* sq1 = new Square(1);
    Shape* sq2 = new Square(2);
    const Shape& small = *sq1;
    const Shape& big = *sq2;
    TEST_ASSERT_TRUE_MESSAGE(small < big, "small was not less than big");
    TEST_ASSERT_TRUE_MESSAGE((big < small == false), "big was not greater than small");
    TEST_ASSERT_TRUE_MESSAGE((small < small == false), "small considered less than itself");
    sq1->~Shape();
    sq2->~Shape();
}

/// Create Square(2) and Rectangle(1, 4): both have area 4.
/// Verify that NEITHER a < b NOR b < a is true.
void test_shape_equal_area_not_less(void)
{
    Shape* sq1 = new Square(1);
    Shape* sq2 = new Square(2);
    const Shape& s1Ref = *sq1;
    const Shape& s2Ref = *sq2;
    TEST_ASSERT_TRUE_MESSAGE(s1Ref < s2Ref, "sq1 was larger than sq2");
    TEST_ASSERT_TRUE_MESSAGE(s1Ref < s2Ref, "sq2 was smaller than sq1");
    sq1->~Shape();
    sq2->~Shape();
}

// ============================================================
// PART 2 Tests: ShapeList
// ============================================================

/// Create a ShapeList. Add new Circle(1) and new Square(2) with addShape.
/// Verify both calls return 0 and length() is 2.
/// (Do NOT delete the shapes yourself: the list owns them.)
void test_list_add_and_length(void)
{
    ShapeList* shapeList = new ShapeList;
    int resC = shapeList->addShape(new Circle(1));
    int resS = shapeList->addShape(new Square(2));
    TEST_ASSERT_EQUAL(0, resC);
    TEST_ASSERT_EQUAL(0, resS);
    int length = shapeList->length();
    TEST_ASSERT_EQUAL(2, length);
}

/// Create a ShapeList. Call addShape(nullptr).
/// Verify it returns -1 and length() stays 0.
void test_list_add_null_guard(void)
{
    ShapeList* shapeList = new ShapeList;
    int resNull = shapeList->addShape(nullptr);
    int length = shapeList->length();
    TEST_ASSERT_EQUAL(-1, resNull);
    TEST_ASSERT_EQUAL(0, length);
}

/// Add Rectangle(2, 5) (area 10), Circle(1) (area 3.14), Square(2) (area 4).
/// Call insertionSort(). Verify nameAt(0), nameAt(1), nameAt(2) are
/// "Circle", "Square", "Rectangle" and isSorted() is true.
void test_insertionSort_orders_by_area(void)
{
    ShapeList* shapeList = new ShapeList;
    shapeList->addShape(new Rectangle(2, 5));
    shapeList->addShape(new Circle(1));
    shapeList->addShape(new Square(2));

    shapeList->insertionSort();

    std::optional<std::string> circRes = shapeList->nameAt(0);
    std::string circString;
    if (circRes.has_value())
    {
        circString = circRes.value();
    }
    std::optional<std::string> squareRes = shapeList->nameAt(1);
    std::string squareString;
    if (squareRes.has_value())
    {
        squareString = squareRes.value();
    }
    std::optional<std::string> rectRes = shapeList->nameAt(2);
    std::string rectString;
    if (rectRes.has_value())
    {
        rectString = rectRes.value();
    }

    std::string circAns = "Circle";
    std::string squareAns = "Square";
    std::string rectAns = "Rectangle";

    TEST_ASSERT_EQUAL_STRING(circAns.c_str(), circString.c_str());
    TEST_ASSERT_EQUAL_STRING(squareAns.c_str(), squareString.c_str());
    TEST_ASSERT_EQUAL_STRING(rectAns.c_str(), rectString.c_str());
}

/// Call insertionSort() on an EMPTY list: no crash, length() is 0.
/// Then add ONE shape and sort again: length() is 1 and nameAt(0) is unchanged.
void test_insertionSort_empty_and_single(void)
{
    ShapeList* shapeList = new ShapeList;
    shapeList->insertionSort();

    shapeList->addShape(new Circle(1));
    shapeList->insertionSort();
    std::optional<std::string> circRes = shapeList->nameAt(0);
    std::string circString;
    if (circRes.has_value())
    {
        circString = circRes.value();
    }
    std::string circAns = "Circle";
    TEST_ASSERT_EQUAL_STRING(circAns.c_str(), circString.c_str());
    TEST_ASSERT_EQUAL(1, shapeList->length());
}
