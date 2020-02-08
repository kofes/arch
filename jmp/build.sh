nasm -felf64 src/self_modify.s -o ./build/self_modify.o &&
g++ src/main.cpp build/self_modify.o -std=c++17 -DNDEBUG -o build/main
