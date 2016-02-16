
#include <PoseUtility.h>


int Usage(char* arg0){
	cerr << "\033[1;37mUsage: \033[0m" << arg0 << " <filename> <outputfilename>" << endl;
	cerr << "-Where filename contains 75 doubles on each line" << endl;
	cerr << "-Where outputfilename can be written to" << endl;
	return -1;
}

int main(int argc, char* argv[]){
	if(argc != 3) return Usage(argv[0]);

	std::ifstream istr(argv[1]);
	if(istr.fail()) return Usage(argv[0]);

	PoseUtility poseUtil;

	if(poseUtil.Read(istr) == 1){
		poseUtil.PointAverages(poseUtil.vectorOfVectors);
		poseUtil.FindMaxes(poseUtil.vectorOfVectors);
		poseUtil.Normalize(poseUtil.vectorOfVectors);
		poseUtil.DistMagOutput(poseUtil.vectorOfVectors);
		poseUtil.WriteOutput(poseUtil.distMagVector, argv[2]);
	}else{
		return -1;
	}
	return 1;
}
