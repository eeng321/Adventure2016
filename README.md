Third Party Library Acknowledgements:

	1. Pistache - http://pistache.io/

	2. yaml-cpp - https://github.com/jbeder/yaml-cpp


Current master requires (libyaml-cpp, libboost, and libsqlite3) install with:

	1. sudo apt-get install libyaml-cpp-dev

	2. sudo apt-get install libboost-all-dev

	3. sudo apt-get install libsqlite3-dev

Installation Instructions

	1. Create new build directory. ie. mkdir build

	2. cd build

	3. cmake -G "Unix Makefiles" -DCMAKE_BUILD_TYPE=Release <path to adventure2016> 
	
	4. make
	
	5. binaries located in bin/ 
	
	
