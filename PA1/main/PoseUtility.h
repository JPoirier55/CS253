#ifndef POSEUTILITY_H_INCLUDE
#define POSEUTILITY_H_INCLUDE

#include <string>
#include <fstream>
#include <vector>
#include <sstream>
#include <iostream>
#include <Point3D.h>
#include <PoseDisplay.h>

using std::string;
using std::cerr;
using std::cout;
using std::endl;
using std::istream;
using std::vector;

class PoseUtility {
public:
  PoseUtility(){}
  double x, y, z;
  int Read(istream& iss);
  int PopulatePoint3DVect();
  bool SetPoint();
  vector<vector<Point3D>> vectorOfVectors;
  int Run(const string& outputfilename);
  int Error(string errStr, bool checkThrow=false);

};
#endif
