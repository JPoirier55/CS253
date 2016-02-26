
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

int Distances::DistMagOutputTwoFiles(vector<vector<vector<Point3D>>>& allFilesPosesReference){
  int minSize = 100000;
  int minSizeIndex = 0;
  for(std::size_t i = 0; i < allFilesPosesReference.size(); i++){
    if(allFilesPosesReference[i].size() < unsigned(minSize)){
      minSize = allFilesPosesReference[i].size();
      minSizeIndex = i;
    }
		cout << allFilesPosesReference[i].size() << endl;
  }
  for(std::size_t i = 0; i < allFilesPosesReference.size(); i++){
    if(i != unsigned(minSizeIndex)){


      for(std::size_t j = 0; j < allFilesPosesReference[minSizeIndex].size(); j++){
				vector<double> tempMagVector;
        for(std::size_t r = 0; r < allFilesPosesReference[minSizeIndex].size(); r++){
          double overallSum = 0;
          for(std::size_t k = 0; k < allFilesPosesReference[minSizeIndex][0].size(); k++){
            double xMag = pow(allFilesPosesReference[minSizeIndex][j][k].X() - allFilesPosesReference[i][r][k].X(), 2);
            double yMag = pow(allFilesPosesReference[minSizeIndex][j][k].Y() - allFilesPosesReference[i][r][k].Y(), 2);
            double zMag = pow(allFilesPosesReference[minSizeIndex][j][k].Z() - allFilesPosesReference[i][r][k].Z(), 2);
            overallSum += sqrt(xMag + yMag + zMag);
          }
          tempMagVector.push_back(overallSum);
        }
				allFilesDistMagVectors.push_back(tempMagVector);
      }


    }
  }
  ofstream outputfile;
  outputfile.open("output.txt");
  for(std::size_t i = 0; i < allFilesDistMagVectors.size(); i++){
    for(std::size_t j = 0; j < allFilesDistMagVectors[0].size(); j++){
      outputfile << allFilesDistMagVectors[i][j] << " ";
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
