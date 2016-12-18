//
// check Node Class.
//

#include <gtest/gtest.h>
#include "../../src/coordinates/Node.h"

/**
 * setup.
 */
class NodeTest : public ::testing::Test {

protected:
    Point *p1;
    Point *p2;
    Node *node1;
    Node *node2;
    Node *node3;

    virtual void SetUp() {
        p1 = new Point(0, 0);
        p2 = new Point(1, 1);
        node1 = new Node(p1);
        node2 = new Node(p2);
        node3 = new Node(p2);
    }

    virtual void TearDown() {
        delete (p1);
        delete (p2);
        delete (node1);
        delete (node2);
        delete (node3);
    }
};

/**
 * checks getP method.
 */
TEST_F(NodeTest, getP) {
    EXPECT_FALSE(*(node2->getP()) == *p1);
    EXPECT_TRUE(*(node2->getP()) == *p2);
}

/**
 * checks setP method.
 */
TEST_F(NodeTest, setP) {
    delete (node2->getP());
    node2->setP(p1);
    EXPECT_TRUE(*(node2->getP()) == *p1);
}

/**
* check getCoordinates method.
*/
TEST_F(NodeTest, getCoordinates) {
    int **coords = node2->getCoordinates();

    // checks the x coordinate
    EXPECT_EQ(*(coords[0]), 1);
    // checks the y coordinate
    EXPECT_EQ(*(coords[1]), 1);

    node2->deleteCoords(coords);
}

/**
*  check the comparing of two Nodes.
*/
TEST_F(NodeTest, equals) {

    // checks unequals Nodes
    EXPECT_FALSE(*node1 == *node2);
    // checks equals Nodes
    EXPECT_TRUE(*node2 == *node3);
}

/**
*  check the comparing of two Nodes.
*/
TEST_F(NodeTest, unequals) {
    EXPECT_TRUE(*node1 != *node3);
}