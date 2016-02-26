
#include <PoseUtility.h>
#include <Distances.h>


int Usage(char* arg0){
	cerr << "\033[1;37mUsage: \033[0m" << arg0 << " <filename> <filename> <outputfilename>" << endl;
	cerr << "-Where filename contains 75 doubles on each line" << endl;
	cerr << "-Where outputfilename can be written to" << endl;
	return -1;
}

int main(int argc, char* argv[]){
	if(argc < 4) return Usage(argv[0]);

	Distances distancesObj;

	for(std::size_t i = 1; i < unsigned(argc)-1; i++){
		std::ifstream istr(argv[i]);
		if(istr.fail()) return Usage(argv[0]);
		distancesObj.NormalizeFiles(istr);
	}
	distancesObj.DistMagOutputTwoFiles(distancesObj.allFilesPoses);


		// if(dist.DistMagOutput(poseUtil.vectorOfPoses) == -1){
		// 	return -1;
		// }
		// if(poseUtil.WriteOutput(dist.distMagVector, argv[2]) == -1){
		// 	return -1;
		// }

	return 1;
}
