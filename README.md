# CS253
Homework for CS253

PA1: 
Reading in text file of 25 points per line\n
command : `./PA1 input_example.txt output.txt`\n
Taking each point and making a Point3D object\n
Creating vector of vectors : `vector<vector<Point3D>>`\n
Create PoseDisplay object, pass vector of vectors to it
PoseDisplay runs X11 window with video, then writes to output file
 
PA2:
Reading in text file of points, then manipulating those points
First calculate the average of the spine points (first points online)
Then subtract that average from all points in the file
Take all points and find the maximum value of any x, y or z
Divide that value by 1, then multiply each value in the points by that scale factor
Display with pointdisplay object

*Passed the same Point3D vector of vectors to all functions

PA3:
Go through all points and find the difference in magnitude between each pose
Calculate magnitude across each line in the file 

