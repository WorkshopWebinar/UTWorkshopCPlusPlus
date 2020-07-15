# UTWorkshopCPlusPlus
Example C++ project with google test is a framework + Lcov coverage + CMake build

Start by installing the gtest development package:

sudo apt-get install libgtest-dev

Note that this package only install source files. You have to compile the code yourself to create the necessary library files. These source files should be located at /usr/src/gtest. Browse to this folder and use cmake to compile the library:

sudo apt-get install cmake # install cmake

cd /usr/src/gtest

sudo cmake CMakeLists.txt

sudo make

 
#copy or symlink libgtest.a and libgtest_main.a to your /usr/lib folder

sudo cp *.a /usr/lib



## Compile and run the tests: 

cmake CMakeLists.txt

make

./runTests

## Generating Code Coverage Report

Mkdir build

Cd build

cmake -DCMAKE_BUILD_TYPE=Coverage ..

make

./runTests

Cd ..

lcov -t "result" -o coverage.info -c -d build/CMakeFiles/runTests.dir/

genhtml -o res coverage.info
