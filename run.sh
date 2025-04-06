mkdir big_tests
g++ gen.cpp -o gen && ./gen
cmake -B build && cd build && cmake --build . && ./main
rm -rf ../big_tests
rm -rf ../build
