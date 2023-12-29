#include "stdio.h"
#include "src/siron_rw.h"

void read_gso_file(char* path) {
    printf("Reading a Siron file\n");
    // printf("%s %s", "Path:", path);

    siron_object test_file = siron_read_file(path);
}

void write_gso_file(char* path) {
    printf("Writing a Siron file\n");
    printf("%s %s", "Path:", path);
}

int main(int argc, char** argv) {
    if (argv[1][0] == 'r' || argv[1][0] == 'R')
        read_gso_file(argv[2]);
    else
        write_gso_file(argv[2]);
    printf("\n");
    return 0;
}
