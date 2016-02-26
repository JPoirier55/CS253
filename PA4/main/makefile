OBJS= PoseDisplay.o Distances.o PoseUtility.o main.o

PA4: $(OBJS)
	g++ PoseDisplay.o Distances.o PoseUtility.o main.o -o PA4 -lX11
PoseDisplay.o: PoseDisplay.cpp PoseDisplay.h Point3D.h
	g++ -Wall -c -std=c++11 -I. PoseDisplay.cpp -lX11
PoseUtility.o: PoseUtility.cpp PoseUtility.h PoseDisplay.h Point3D.h
	g++ -Wall -c -std=c++11 -I. PoseUtility.cpp -lX11
Distances.o: Distances.cpp Distances.h PoseUtility.h PoseDisplay.h Point3D.h
	g++ -Wall -c -std=c++11 -I. Distances.cpp -lX11
main.o: main.cpp PoseUtility.h Distances.h
	g++ -Wall -c -std=c++11 -I. main.cpp -lX11
clean:
	rm $(OBJS) PA4
