
#include<Distances.h>
#include <cmath>
#include <math.h>
using std::abs;


int Distances::NormalizeFiles(ifstream& istr){
	PoseUtility poseUtil;

	if(poseUtil.Read(istr) == 1){
		if(poseUtil.PointAverages(poseUtil.vectorOfPoses) == -1){
			return -1;
		}
		poseUtil.FindMaxes(poseUtil.vectorOfPoses);
		poseUtil.Normalize(poseUtil.vectorOfPoses);
	}else{
		return -1;
	}

	allFilesPoses.push_back(poseUtil.vectorOfPoses);

  return 1;
}

int Distances::DistMagOutputTwoFiles(vector<vector<Point3D>>& shortVector, vector<vector<Point3D>>& longVector){

  for(std::size_t r = 0; r < shortVector.size(); r++){
		vector<double> tempMagVector;
    for(std::size_t j = 0; j < longVector.size(); j++){
      double overallSum = 0;
      for(std::size_t k = 0; k < 25; k++){
        double xMag = pow(longVector[j][k].X() - shortVector[r][k].X(), 2);
        double yMag = pow(longVector[j][k].Y() - shortVector[r][k].Y(), 2);
        double zMag = pow(longVector[j][k].Z() - shortVector[r][k].Z(), 2);
        overallSum += sqrt(xMag + yMag + zMag);
      }
      tempMagVector.push_back(overallSum);
    }
		allFilesDistMagVectors.push_back(tempMagVector);
  }
  return 1;
}

int Distances::WriteOutput(vector<vector<double>>& distMagVectorReference, char *outputfilename){
	ofstream outputfile;
  outputfile.open(outputfilename);
  for(std::size_t i = 0; i < distMagVectorReference.size(); i++){
    for(std::size_t j = 0; j < distMagVectorReference[0].size(); j++){
      outputfile << distMagVectorReference[i][j] << " ";
    }
    outputfile << endl;
  }
  outputfile.close();
	return 1;
}

int Distances::DistMagOutput(vector<vector<Point3D>>& vectorReference){

  if(vectorReference.size() < 2){
    Error("The file is too small to complete magnitude: ");
    return -1;
  }

  for(std::size_t i = 1; i < vectorReference.size(); i ++){
    double overallSum = 0;
    for(std::size_t j = 0; j < vectorReference[0].size(); j ++){
      double xMag = pow(vectorReference[i][j].X() - vectorReference[i-1][j].X(), 2);
      double yMag = pow(vectorReference[i][j].Y() - vectorReference[i-1][j].Y(), 2);
      double zMag = pow(vectorReference[i][j].Z() - vectorReference[i-1][j].Z(), 2);
      overallSum += sqrt(xMag + yMag + zMag);
    }
    distMagVector.push_back(overallSum);
  }
  return 1;
}

int Distances::Error(string errStr, int lineNum, bool checkThrow){
  if(checkThrow){
    cerr << "\033[1;31mThrown: \033[0m" << errStr << lineNum << endl;
    return 1;
  }else{
    cerr << "\033[1;31mERROR : \033[0m" << errStr << lineNum << endl;
    return -1;
  }
}
