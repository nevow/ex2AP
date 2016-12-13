//
// check Point Class.
//

#include <gtest/gtest.h>
#include "../../src/coordinates/Node.h"

/**
* check getCoordinates method.
*/
TEST(getCoordinates, NodeTest) {
    Node node(new Point(3,4));
    int **coords = node.getCoordinates();

    // checks the x coordinate
    EXPECT_EQ(*(coords[0]), 3);
    // checks the y coordinate
    EXPECT_EQ(*(coords[1]), 4);

    node.deleteCoords(coords);
}

/**
 * checks getP method.
 */
TEST(getP, NodeTest) {
    Point p1(3, 4);
    Point p2(4, 4);
    Node node1(new Point(3,4));
    Node node2(new Point(4,4));

    EXPECT_TRUE(*node1.getP() == p1);
    EXPECT_FALSE(*node1.getP() == p2);
}

/**
*  check the comparing of two Nodes.
*/
TEST(equals, NodeTest) {
    Node node1(new Point(3,4));
    Node node2(new Point(4,4));
    Node node3(new Point(4,4));

    // checks unequals Nodes
    EXPECT_FALSE(node1 == node2);
    // checks equals Nodes
    EXPECT_TRUE(node2 == node3);
}

/**
*  check the comparing of two Nodes.
*/
TEST(unequals, NodeTest) {
    Node node1(new Point(3,3));
    Node node2(new Point(2,2));
    Node node3(new Point(3,1));
    EXPECT_TRUE(node1 != node2);
    EXPECT_TRUE(node1 != node3);
}