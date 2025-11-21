#include "thpe02.h"

int main(int argc, char**argv)
{
    StringTracker wordTracker;
    std::ifstream fin;
    std::ofstream fout1;
    std::ofstream fout2;

    //ensures correct argument count, files opened succesfully, ends program
    //if any unsuccessful.
    checkArgc(argc);
    openInFile(fin, argv[1]);
    openOutFile(fout1, argv[2]);
    openOutFile(fout2, argv[3]);

    //reads words into tracker.
    readWords(fin, wordTracker);

    //prints phrases and counters into file 1 and 2.
    wordTracker.printPhrases(fout1);
    wordTracker.printCounters(fout2);

    //closes files, returns.
    fin.close();
    fout1.close();
    fout2.close();

    return 0;
}