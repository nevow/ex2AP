//
// check Point Class.
//

#include <gtest/gtest.h>
#include "../../src/coordinates/Point.h"


/**
* check the getX.
*/
TEST(getX, pointTest) {
    Point p1(3, 4);
    Point p2(-3, 4);
    // checks the x coordinate of the point
    ASSERT_TRUE(3 == p1.getX());
    ASSERT_TRUE(3 != p2.getX());
}

/**
 * check the getY.
 */
TEST(getY, pointTest) {
    Point p1(3, 4);
    Point p2(3, -4);
    // checks the y coordinate of the point
    ASSERT_TRUE(4 == p1.getY());
    ASSERT_TRUE(4 != p2.getY());
}

/**
 * check the setX.
 */
TEST(setX, pointTest) {
    Point p1(3, 4);

    p1.setX(-5);
    // checks if the x coordinate changed
    ASSERT_TRUE(-5 == p1.getX());
}

/**
 * check the setY.
 */
TEST(setY, pointTest) {
    Point p1(3, 4);

    p1.setY(-5);
    // checks if the y coordinate changed
    ASSERT_TRUE(-5 == p1.getY());
}

/**
 * check the &operator<<.
 */
TEST(outputTest, pointTest) {
    Point p1(3, 4);
    std::stringstream out;
    out << p1;
    ASSERT_TRUE(out.str() == "(3 ,4)\n");
}

/**
 * check the &operator>>.
 */
TEST(inputTest, pointTest) {
    Point p1;
    std::istringstream in("3,4");
    in >> p1;
    ASSERT_TRUE((p1.getX() == 3) && (p1.getY() == 4));
}


/**
 *  check the comparing of two Points.
 */
TEST(equalTest, pointTest) {
    Point p1(3, 3);
    Point p2(3, 3);

    Point p3(3, 1);
    Point p4(6, 3);

    EXPECT_TRUE(p1 == p2);  // check X and Y unmatched
    EXPECT_FALSE(p1 == p3); // check only X matched
    EXPECT_FALSE(p1 == p4); // check only Y matched
}

/**
 * check the comparing of two Points.
 */
TEST(notEqualTest, pointTest) {
    Point p1(3, 3);
    Point p2(2, 2);

    Point p3(3, 1);
    Point p4(6, 2);


    EXPECT_TRUE(p1 != p2); // check X and Y unmatched
    EXPECT_TRUE(p1 != p3); // check only Y unmatched
    EXPECT_TRUE(p2 != p3); // check only X unmatched
}

