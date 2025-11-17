#include "thpe02.h"

void checkArgc(int argc)
{
    // makes sure that launch command has 3 arguement, else returns usage
    // statement and triggers error flag.
    if (argc != 4)
    {
        std::cout << "Usage: thpe01 inputfile outputfile1 outputfile2" 
                  << std::endl;
        std::cout << "inputfile - text file containing the words to be "
                  << " processed." << std::endl;
        std::cout << "outputfile1 - filename for the file that contains words"
                  << " listed alphabetically by their first character." 
                  << std::endl;
        std::cout << "outputfile2 - filename for the file that contains words"
                  << " listed in descending order by their frequency count." 
                  << std::endl;
        exit(1);
    }
    return;
}

void openInFile(std::ifstream &fin, char fileName[])
{
    // opens file, makes sure file opened succesfully or ourputs error message
    // and triggers error flag.
    fin.open(fileName);
    if (!fin.is_open())
    {
        std::cout << "File, " << fileName << ", not opened succesfully."
                  << std::endl;
        exit(1);
    }
    std::cout << "File, " << fileName << ", opened succesfully." << std::endl;
    return;
}

void openOutFile(std::ofstream &fout, char fileName[])
{
    // opens file, makes sure file opened succesfully or ourputs error message
    // and triggers error flag.
    fout.open(fileName);
    if (!fout.is_open())
    {
        std::cout << "File, " << fileName << ", not opened succesfully."
                  << std::endl;
        exit(1);
    }
    std::cout << "File, " << fileName << ", opened succesfully." << std::endl;
    return;
}