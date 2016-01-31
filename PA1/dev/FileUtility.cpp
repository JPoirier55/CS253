#include <fstream>
using std::ofstream;
#include <string>
using std::string;
#include <iostream>
#include <sstream>
#include <Point3D.h>
#include <PoseDisplay.h>
#include <vector>
using std::vector;


int PoseUtility::PopulatePoint3DVect(char* filename)
{

}

double a, b, c;
string line;
string temp;
Point3D p;

vector<vector<Point3D>> vect2;

std::ifstream file("input_example.txt");
if(!file.is_open()){
  printf("Error while opening file\n");
}

while(getline(file, line)){
  std::istringstream iss(line);
  vector<Point3D> vect;
  while(!iss.eof()){
    if(iss >> a >> b >> c){
      p = Point3D(a, b, c);
      vect.push_back(p);
    }else{
      printf("Error in the line \n" );
      return -1;
    }

  }
  vect2.push_back(vect);
}

const string s = "output.txt";
PoseDisplay poseDisplay(s, true);
poseDisplay.Pause(1500);
for(std::size_t n = 0; n < vect2.size(); n ++){
poseDisplay.Pose(vect2[n], 33);
