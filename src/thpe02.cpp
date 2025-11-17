#include "thpe02.h"

int main(int argc, char**argv)
{
    StringTracker wordTracker;
    std::ifstream fin;
    std::ofstream fout1;
    std::ofstream fout2;

    //ensures correct argument count, files opened succesfully.
    checkArgc(argc);
    openInFile(fin, argv[1]);
    openOutFile(fout1, argv[2]);
    openOutFile(fout2, argv[2]);

    //poop

    fin.close();
    fout1.close();
    fout2.close();
    return 0;
}