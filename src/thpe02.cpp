#include "thpe02.h"

int main(int argc, char**argv)
{
    StringTracker wordTracker;
    std::ifstream fin;
    std::ofstream fout;

    //ensures correct argument count, files opened succesfully.
    checkArgc(argc);
    openInFile(fin, argv[1]);
    openOutFile(fout, argv[2]);



    return 0;
}