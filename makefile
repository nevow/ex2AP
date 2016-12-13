# weichsn1 305108706
# darsham1 203393210

a.out: main.o BFS.o GridControl.o Matrix.o Node.o Point.o
	g++ main.o BFS.o GridControl.o Matrix.o Node.o Point.o

main.o: main.cpp
	g++ -c main.cpp

BFS.o: BFS.cpp BFS.h
	g++ -c BFS.cpp

GridControl.o: GridControl.cpp GridControl.h Grid.h CoordinatedItem.h
	g++ -c GridControl.cpp

Matrix.o: Matrix.cpp Matrix.h
	g++ -c Matrix.cpp

Node.o: Node.cpp Node.h
	g++ -c Node.cpp

Point.o: Point.cpp Point.h
	g++ -c Point.cpp

