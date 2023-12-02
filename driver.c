#include "sha256.h"

int main(int argc, char* argv[]) {
    sha256_testing("./test_vectors/SHA256LongMsg.bin");
    // sha256_testing("./test_vectors/SHA256ShortMsg.bin");
    return 0;
}