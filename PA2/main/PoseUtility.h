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
  PoseUtility(double xAverage = 0.0, double yAverage = 0.0,
    double zAverage = 0.0) : xAverage(xAverage),
    yAverage(yAverage), zAverage(zAverage){}

  double x, y, z;
  double xAverage, yAverage, zAverage;
  int lineNumber;
  vector<vector<Point3D>> vectorOfVectors;

  int Read(istream& iss);
  int PopulatePoint3DVect();
  int Normalize(vector<vector<Point3D>>& vectorReference);
  int PointAverages(vector<vector<Point3D>>& vectorReference);

  int Run(const string& outputfilename);
  int Error(string errStr, int lineNum=0, bool checkThrow=false);

};
#endif
