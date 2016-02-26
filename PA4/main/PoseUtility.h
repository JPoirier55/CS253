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
  double max = -1;
  double sumAv = 0;
  int lineNumber;
  vector<vector<Point3D>> vectorOfPoses;

  int Read(istream& iss);
  int PopulatePoint3DVect();
  int Normalize(vector<vector<Point3D>>& vectorReference);
  int FindMaxes(vector<vector<Point3D>>& vectorReference);
  int PointAverages(vector<vector<Point3D>>& vectorReference);

  int WriteOutput(vector<double>& distMagVectorReference, char *outputfilename);
  int Run(const string& outputfilename);
  int Error(string errStr, int lineNum=0, bool checkThrow=false);

};
#endif
