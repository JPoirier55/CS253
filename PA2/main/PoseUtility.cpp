
#include <PoseUtility.h>
#include <cmath>
using std::abs;

int PoseUtility::Read(istream& iss)
{
  string line;
  Point3D p;

  lineNumber = 0;


  if(iss.fail()){
    Error("Cannot read file, returning: ", -1);
    return -1;
  }else{
    while(getline(iss, line)){
      std::istringstream iss(line);
      vector<Point3D> vect;
      int pointNumber = 0;
      lineNumber += 1;

      while(!iss.eof()){
        if(iss >> x >> y >> z >> std::ws){

          pointNumber += 1;
          p = Point3D(x, y, z);

          vect.push_back(p);
        }else{
          Error("Cannot parse line: ", lineNumber);
          return -1;
        }
      }
      if(pointNumber > 25){
        Error("Too many points in line: ", lineNumber);
        return -1;
      }
      if(pointNumber < 25){
        Error("Too few points in line: ", lineNumber);
        return -1;
      }
      vectorOfVectors.push_back(vect);
    }
  }
  return 1;
}

int PoseUtility::PointAverages(vector<vector<Point3D>>& vectorReference){
  double sumX = 0;
  double sumY = 0;
  double sumZ = 0;

  for(std::size_t n = 0; n < vectorReference.size(); n ++){
    sumX += vectorReference[n][0].X();
    sumY += vectorReference[n][0].Y();
    sumZ += vectorReference[n][0].Z();
  }
  xAverage = sumX / vectorReference.size();
  yAverage = sumY / vectorReference.size();
  zAverage = sumZ / vectorReference.size();

  return 1;
}

int PoseUtility::Normalize(vector<vector<Point3D>>& vectorReference){
  double max = 0;
  for(std::size_t i = 0; i < vectorReference.size(); i ++){
    for(std::size_t j = 0; j < vectorReference[0].size(); j ++){

      double x = vectorReference[i][j].X() - xAverage;
      double y = vectorReference[i][j].Y() - yAverage;
      double z = vectorReference[i][j].Z() - zAverage;

      if(abs(x) > max){
        max = abs(x);
      }
      if(abs(y) > max){
        max = abs(y);
      }
      if(abs(z) > max){
        max = abs(z);
      }
      double scaleFactor;

      if(max == 0.0){
        scaleFactor = 1;
      }else{
        scaleFactor = 1.0 / max;
      }

      x *= scaleFactor;
      y *= scaleFactor;
      z *= scaleFactor;

      vectorReference[i][j] = Point3D(x, y, z);
    }
  }

  return 1;
}

int PoseUtility::Run(const string& outputfilename){

  PoseDisplay poseDisplay(outputfilename);

  for(std::size_t n = 0; n < vectorOfVectors.size(); n ++){
    poseDisplay.Pose(vectorOfVectors[n], 33);
  }
  return 1;
}

int PoseUtility::Error(string errStr, int lineNum, bool checkThrow){
  if(checkThrow){
    cerr << "\033[1;31mThrown: \033[0m" << errStr << lineNum << endl;
    return 1;
  }else{
    cerr << "\033[1;31mERROR : \033[0m" << errStr << lineNum << endl;
    return -1;
  }
}
