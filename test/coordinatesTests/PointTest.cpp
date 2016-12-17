//
// check Point Class.
//

#include <gtest/gtest.h>
#include "../../src/coordinates/Point.h"

/**
 * setup.
 */
class PointTest : public ::testing::Test {

protected:
    Point *p1;
    Point *p2;
    Point *p3;
    Point *p4;

    virtual void SetUp() {
        p1 = new Point(1, 2);
        p2 = new Point(2, 1);
        p3 = new Point(2, 2);
        p4 = new Point(2, 2);
    }

    virtual void TearDown() {
        delete (p1);
        delete (p2);
        delete (p3);
        delete (p4);
    }
};

/**
* check the getX.
*/
TEST_F(PointTest, getX) {
    // checks the x coordinate of the point
    ASSERT_TRUE(1 == p1->getX());
    ASSERT_TRUE(1 != p2->getX());
}

/**
 * check the getY.
 */
TEST_F(PointTest, getY) {
    // checks the y coordinate of the point
    ASSERT_TRUE(2 == p1->getY());
    ASSERT_TRUE(2 != p2->getY());
}

/**
 * check the setX.
 */
TEST_F(PointTest, setX) {
    p1->setX(-5);
    // checks if the x coordinate changed
    ASSERT_TRUE(-5 == p1->getX());
}

/**
 * check the setY.
 */
TEST_F(PointTest, setY) {

    p1->setY(-7);
    // checks if the y coordinate changed
    ASSERT_TRUE(-7 == p1->getY());
}

/**
 * check the &operator<<.
 */
TEST_F(PointTest, outputTest) {
    std::stringstream out;
    out << p1;
    ASSERT_TRUE(out.str() == "(1 ,2)\n");
}

/**
 * check the &operator>>.
 */
TEST_F(PointTest, inputTest) {
    Point p5;
    std::istringstream in("3,4");
    in >> p5;
    ASSERT_TRUE((p5.getX() == 3) && (p5.getY() == 4));
}

/**
 *  check the comparing of two Points.
 */
TEST_F(PointTest, equalTest) {
    EXPECT_TRUE(p3 == p4);  // check X and Y unmatched
    EXPECT_FALSE(p1 == p3); // check only Y matched
    EXPECT_FALSE(p2 == p4); // check only X matched
}

/**
 * check the comparing of two Points.
 */
TEST_F(PointTest, notEqualTest) {
    EXPECT_TRUE(p1 != p3); // check only Y unmatched
    EXPECT_TRUE(p2 != p4); // check only X unmatched
}

