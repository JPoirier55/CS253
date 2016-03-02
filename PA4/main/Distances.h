#ifndef DISTANCES_H_INCLUDE
#define DISTANCES_H_INCLUDE

#include <string>
#include <fstream>
#include <vector>
#include <sstream>
#include <iostream>
#include <Point3D.h>
#include <PoseDisplay.h>
#include <PoseUtility.h>

using std::string;
using std::cerr;
using std::cout;
using std::endl;
using std::istream;
using std::vector;
using std::ifstream;

class Distances {
public:
  Distances(){}
  vector<vector<vector<Point3D>>> allFilesPoses;
  vector<double> distMagVector;
  vector<vector<double>> allFilesDistMagVectors;

  int NormalizeFiles(ifstream& istr);
  int DistMagOutputTwoFiles(vector<vector<Point3D>>& shortVector,
      vector<vector<Point3D>>& longVector);
  int DistMagOutput(vector<vector<Point3D>>& vectorReference);
  int WriteOutput(vector<vector<double>>& distMagVectorReference, char *outputfilename);
  int Error(string errStr, int lineNum=0, bool checkThrow=false);

};
#endif
