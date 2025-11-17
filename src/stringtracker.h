#ifndef STRINGTRACKER_H
#define STRINGTRACKER_H

#include <string>
#include <iostream>
#include <iomanip>
#include <new>

class StringTracker
{
    public:
        StringTracker();
        ~StringTracker();

        bool addString(const std::string& str);
        bool removeString(const std::string& str);

        bool findString(const std::string str) const;

        bool incrementCount(const std::string& str);
        bool decrementCount(const std::string& str);

        int getCount(const std::string& str) const;
        int getMaximumCount() const;

        bool empty();
        int size();
        void clear();

        void print(std::ostream &out) const;
        void printPhrases( std::ostream &out ) const;
        void printCounters( std::ostream &out) const;

    private:
        struct Node
        {
            std::string Value;
            int count;
            Node* next;
        };
        Node* headptr;
};

#endif