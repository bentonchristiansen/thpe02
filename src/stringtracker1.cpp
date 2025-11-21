#include "stringtracker.h"

StringTracker::StringTracker()
{
    // initializes list
    this->headptr = nullptr;
}

StringTracker::~StringTracker()
{
    // initializes temp Nodes
    Node *temp1 = this->headptr;
    Node *temp2;

    // Walks through each Node and deletes the previous Node, then deletes
    //  The previous node.
    while (temp1 != nullptr)
    {
        temp2 = temp1;
        temp1 = temp1->next;
        delete temp2;
    }
    delete temp1;
}

bool StringTracker::findString(const std::string str) const
{
    Node *temp1;

    // empty list or headptr is greater value than string
    if (headptr == nullptr || headptr->Value > str)
    {
        return false;
    }

    // if headptr is the same as string we want to find
    if (headptr->Value == str)
    {
        return true;
    }

    // initialize temp nodes
    temp1 = this->headptr->next;

    // go until end or temp 1 isn't less than string
    while (temp1 != nullptr && temp1->Value < str)
    {
        temp1 = temp1->next;
    }
    // if temp 1 is string
    if (temp1 != nullptr && temp1->Value == str)
    {
        return true;
    }

    // else string not found
    return false;
}

bool StringTracker::empty()
{
    // returns whether or not headptr is pointing to anything.
    return (headptr == nullptr);
}

int StringTracker::size()
{
    // Initializes temp node, declares variable
    int count = 0;
    Node *temp1 = this->headptr;

    // Walks through list, adds to count.
    while (temp1 != nullptr)
    {
        count += 1;
        temp1 = temp1->next;
    }

    return count;
}

void StringTracker::clear()
{
    // Initializes temp nodes.
    Node *temp1 = this->headptr;
    Node *temp2;

    // if empty, returns
    if (headptr == nullptr)
    {
        return;
    }

    // walks through the list, deletes each node
    while (temp1 != nullptr)
    {
        temp2 = temp1;
        temp1 = temp1->next;
        delete temp2;
    }
    delete temp1;

    // reinitializes list.
    headptr = nullptr;

    return;
}

void StringTracker::printPhrases(std::ostream &out) const
{
    // initializes variables, sets width to 25 and centers the text to the left
    int i;
    int j;
    int n;
    Node *temp1;
    bool headerCheck;
    bool firstHeaderCheck = true;
    std::string alphabet = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";

    if (headptr == nullptr)
        return;

    // for loop to work through the alphabet
    for (i = 0; i < 25; i++)
    {
        temp1 = headptr;
        std::string tempc;
        headerCheck = false;
        n = 0;
        while (temp1 != nullptr)
        {
            tempc = tolower(alphabet[i]);
            // if first letter matches, print letter
            if ((temp1->Value).front() == alphabet[i] || (temp1->Value).front() 
            == tempc.front())
            {
                // if header hasn't been printed, print header;
                if (headerCheck == false)
                {
                    out << std::setw(0) << std::left;
                    if( firstHeaderCheck == false)
                        out << std::endl << std::endl;
                    else
                        firstHeaderCheck = false;
                    for (j = 0; j < 75; j++)
                    {
                        out << '*';
                    }

                    out << std::endl
                        << "*  Phrases " << "Starting With: "
                        << tempc << std::endl;

                    for (j = 0; j < 75; j++)
                    {
                        out << '*';
                    }
                    headerCheck = true;
                }

                out << std::setw(25) << std::left;

                // if n words printed divisible by 3, new line
                if (n % 3 == 0)
                {
                    out << std::endl;
                }
                // print Value
                out << temp1->Value;

                // increment Node & n.
                n++;
            }
            temp1 = temp1->next;
        }
    }

    return;
}

void StringTracker::printCounters(std::ostream &out) const
{
    // variable declarations and terminal
    int max;
    int min;
    int n;
    int j;
    int r;

    Node *temp1 = headptr;
    bool headerCheck;
    bool firstHeaderCheck = true;
    out << std::setw(25) << std::left;

    if (headptr == nullptr)
    {
        return;
    }
    max = headptr->count;
    min = headptr->count;

    // find max count
    while (temp1 != nullptr)
    {
        if (temp1->count > max)
        {
            max = temp1->count;
        }
        if (temp1->count < min)
        {
            min = temp1->count;
        }
        temp1 = temp1->next;
    }

    // go from max count til 1
    for (j = max; j >= min; j--)
    {
        temp1 = headptr;
        headerCheck = false;
        n = 0;
        while (temp1 != nullptr)
        {
            // if no header for this count, print header
            if (temp1->count == j && headerCheck == false)
            {
                out << std::setw(0) << std::left;
                if(firstHeaderCheck == false)
                    out << std::endl << std::endl;
                else
                    firstHeaderCheck = false;
                for (r = 0; r < 75; r++)
                {
                    out << '*';
                }

                out << std::endl
                    << "*  Phrases " << "With Counts Of: "
                    << j << std::endl;

                for (r = 0; r < 75; r++)
                {
                    out << '*';
                }
                headerCheck = true;
            }
            out << std::setw(25) << std::left;
            // if n words printed divisible by 3, new line
            // print Value
            if (temp1->count == j)
            {
                if (n % 3 == 0)
                {
                    out << std::endl;
                }
                out << temp1->Value;
                n++;
            }

            // increment Node & n.
            temp1 = temp1->next;
        }
    }

    return;
}