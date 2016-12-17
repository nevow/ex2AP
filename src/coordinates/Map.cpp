//
// Map.
// inherit Grid, has rows, columns and list of nodes
//

#include <stdexcept>
#include "Map.h"

using namespace std;

/**
 * constructor.
 *
 * @param c is the size of columns
 * @param r is the size of rows
 */
Map::Map(int c, int r) {
    if (c <= 0 || r <= 0) {
        throw runtime_error("can't create Map from negative values");
    }
    rows = r;
    columns = c;

    matrix = new Node **[columns];

    // creates the nodes of the matrix
    for (int i = 0; i < columns; i++) {
        matrix[i] = new Node *[rows];
        for (int j = 0; j < rows; j++) {
            Point p(i, j);
            Node *n = new Node(&p);
            matrix[i][j] = n;
        }
    }
}

/**
 * destructor.
 */
Map::~Map() {
    for (int i = 0; i < columns; i++) {
        for (int j = 0; j < rows; j++) {
            delete (matrix[i][j]);
        }
        delete[] matrix[i];
    }
    delete[] matrix;
}

/**
 *
 * @return the rows of the map
 */
int Map::getRows() const {
    return rows;
}

/**
 *
 * @return the columns of the map
 */
int Map::getColumns() const {
    return columns;
}

/**
 * @param c is the column value
 * @param r is the row value
 * @return the node on the correct position.
 */
CoordinatedItem *Map::getValue(int c, int r) {
    if (r < 0 || r >= rows || c < 0 || c > columns) {
        return NULL;
    }
    return matrix[c][r];
}

/**
 * @return the root of the matrix
 */
Node *Map::getRoot() {
    for (int i = 0; i < columns; i++) {
        for (int j = 0; j < rows; ++j) {
            if (matrix[i][j]->getDistance() == 0) {
                return matrix[i][j];
            }
        }
    }
    return matrix[0][0];
}

/**
 * @param dist is the value to set all the nodes with.
 */
void Map::setAll(int dist) {
    for (int i = 0; i < columns; i++) {
        for (int j = 0; j < rows; ++j) {
            matrix[i][j]->setDistance(dist);
            matrix[i][j]->setParent(NULL);
        }
    }
}

/**
 * @param item to set its distance value.
 * @param dist is the value.
 */
void Map::setItem(CoordinatedItem *item, int dist) {
    int **coords = item->getCoordinates();
    matrix[*(coords[0])][*(coords[1])]->setDistance(dist);
    delete (coords[0]);
    delete (coords[1]);
    delete[] (coords);
}

/**
 * @param item to get his neighbours
 * @return an array of the neighbours, according to the order of 9, 12, 3 and 6
 */
CoordinatedItem **Map::getAllNeighbours(CoordinatedItem *item) {
    CoordinatedItem **adj = new CoordinatedItem *[5];
    int **coords = item->getCoordinates();
    int c = *(coords[0]), r = *(coords[1]);
    int i = 0;

    if (c > 0) {                          // check left
        adj[i] = getValue(c - 1, r);
        i++;
    }

    if (r < rows - 1) {                   // check up
        adj[i] = getValue(c, r + 1);
        i++;
    }

    if (c < columns - 1) {                // check right
        adj[i] = getValue(c + 1, r);
        i++;
    }

    if (r > 0) {                          // check down
        adj[i] = getValue(c, r - 1);
        i++;
    }
    delete[] (coords);
    adj[i] = NULL;
    return adj;
}
