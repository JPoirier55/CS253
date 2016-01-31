#ifndef POSEUTILITY_H_INCLUDE
#define POSEUTILITY_H_INCLUDE

#include <string>
#include <fstream>
#include <vector>
#include <sstream>
#include <iostream>

using std::string;
using std::cerr;
using std::cout;
using std::endl;

class PoseUtility {
public:
  PoseUtility(char* inputFilename = '', char* outputFilename = '')
    : inputFile(inputFilename), outputFile(outputFilename){}
  int x, y, z;
  bool Read();
  bool SetPoint();


};
#endif
