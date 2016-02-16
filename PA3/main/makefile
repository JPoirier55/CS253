OBJS= PoseDisplay.o PoseUtility.o main.o

PA3: $(OBJS)
	g++ PoseDisplay.o PoseUtility.o main.o -o PA3 -lX11
PoseDisplay.o: PoseDisplay.cpp PoseDisplay.h Point3D.h
	g++ -Wall -c -std=c++11 -I. PoseDisplay.cpp -lX11
PoseUtility.o: PoseUtility.cpp PoseUtility.h PoseDisplay.h Point3D.h
	g++ -Wall -c -std=c++11 -I. PoseUtility.cpp -lX11
main.o: main.cpp PoseUtility.h
	g++ -Wall -c -std=c++11 -I. main.cpp -lX11
clean:
	rm $(OBJS) PA3
