
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
        if(iss >> x >> y >> z){
          p = Point3D(x, y, z);
          vect.push_back(p);
        }else{
          Error("Line cannot be parsed\n");
        }
      }
      vectorOfVectors.push_back(vect);
    }
  }
  return 1;
}

int PoseUtility::Run(PoseDisplay poseDisplay){

  if(vectorOfVectors.size() == 0){
    Error("File contains no data\n");
  }
  for(std::size_t n = 0; n < vectorOfVectors.size(); n ++){
    poseDisplay.Pose(vectorOfVectors[n], 33);

  }
  return 1;
}

int PoseUtility::Error(string errStr, bool checkThrow=false){
  if(checkThrow){
    return 0;
  }else{
    cerr << "Error: " << errStr << endl;
    return -1;
  }
}
