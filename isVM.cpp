#include <iostream>
#include <cpuid.h>
using namespace std;

bool isHypervisor(){
	int CPUInfo[4] = {-1};
	__get_cpuid(CPUInfo,1);
	if ((CPUInfo[2] >> 31) & 1){
		return true;
	}
	return false;
}

int main(){
	if(isHypervisor()){
		cout << "Virtual machine" << endl;
	} else {
		cout << "Physical machine" << endl;
	}
	return 0;
}
