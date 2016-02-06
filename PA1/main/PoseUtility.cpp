
#include <PoseUtility.h>


int PoseUtility::Read(istream& iss)
{
  string line;
  Point3D p;

  int lineNumber = 0;


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
