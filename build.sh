# chmod +x build.sh

rm -rf build
cmake -S . -B build
cmake --build build