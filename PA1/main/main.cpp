
#include <PoseUtility.h>


int Usage(char* arg0){
	cout << "Usage: " << arg0 << "<filename> <outputfilename>" << endl;
	cout << "Where filename contains 75 doubles on each line" << endl;
	cout << "Where outputfilename can be written to" << endl;
	return -1;
}

int main(int argc, char* argv[]){
	if(argc != 3) return Usage(argv[0]);

	std::ifstream istr(argv[1]);
	if(istr.fail()) return Usage(argv[0]);

	PoseUtility poseUtil;
	if(!poseUtil.Read(istr)) return Usage(argv[0]);

	PoseDisplay poseDisplay(argv[2]);
	if(!poseUtil.Run(poseDisplay)) return Usage(argv[0]);





}
