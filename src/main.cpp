#include <iostream>
#include <exception>

int checkArgs(int argc, char** args){
	int arg1;
	int arg2;
	if (args[1] && args[2]) {
		arg1 = std::atoi(args[1]);
		arg2 = std::atoi(args[2]);
	}
	if (argc != 3 || !arg1 || !arg2 || arg1 < 0 || arg2 < 0)
		return 0;
	return 1;
}

int main(int argc, char **argv){
	try{
		if (!checkArgs(argc, argv))
			throw std::runtime_error("Format should be \"nibbler [width] [height]\"");
	} catch (std::exception &e){
		std::cout << "Error: " << e.what() << std::endl;
	}
	return 0;
}