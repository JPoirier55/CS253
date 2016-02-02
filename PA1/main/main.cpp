
#include <PoseUtility.h>


int Usage(char* arg0){
	cout << "\033[1;37mUsage: \033[0m" << arg0 << " <filename> <outputfilename>" << endl;
	cout << "-Where filename contains 75 doubles on each line" << endl;
	cout << "-Where outputfilename can be written to" << endl;
	return -1;
}

int main(int argc, char* argv[]){
	if(argc != 3) return Usage(argv[0]);

	std::ifstream istr(argv[1]);
	if(istr.fail()) return Usage(argv[0]);

	PoseUtility poseUtil;

	if(poseUtil.Read(istr) == 1){
		poseUtil.Run(argv[2]);
	}else{
		return -1;
	}
	return 1;
}
