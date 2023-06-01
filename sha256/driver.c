#include "sha256.h"

int main(int argc, char* argv[]) {
    char* file_path = argv[1];
    sha256(file_path);
    return 0;
}