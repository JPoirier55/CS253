
#include <PoseUtility.h>


int PoseUtility::Read(istream& iss)
{
  string line;
  Point3D p;

  if(iss.fail()){
    Error("Cannot read file\n");
  }else{
    while(getline(iss, line)){
      std::istringstream iss(line);
      vector<Point3D> vect;

      while(!iss.eof()){
        if(iss >> x >> y >> z >> std::ws){
          p = Point3D(x, y, z);
          vect.push_back(p);
        }else{
          Error("Line cannot be parsed correctly.\n");
          return -1;
        }
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

int PoseUtility::Error(string errStr, bool checkThrow){
  if(checkThrow){
    cerr << "\033[1;31mThrown: \033[0m" << errStr << endl;
    return 1;
  }else{
    cerr << "\033[1;31mERROR : \033[0m" << errStr << endl;
    return -1;
  }
}
