#include "stringtracker.h"

// Adds a string to the list in accending order if it does not exist on the list
// If a string exists do not increment the count
// Returns true if the word could be added or eas already on the list
// false if it failed to create a node
bool StringTracker::addString(const std::string &str)
{
    // Pointers to traverse the list
    Node *prev = nullptr;
    Node *current = headptr;

    // Traverse to find the correct insertion point (or a duplicate)
    while (current != nullptr && current->Value < str)
    {
        prev = current;
        current = current->next;
    }

    // Found a duplicate, do nothing.
    if (current != nullptr && current->Value == str)
    {
        return true;
    }

    // Create the new node, using (nothrow) to prevent exceptions
    Node *newNode = new (std::nothrow) Node{str, 1, current};

    // Check if memory allocation failed
    if (newNode == nullptr)
    {
        return false;
    }

    // Link the new node into the list
    if (prev == nullptr)
    {
        headptr = newNode; // Insert at head
    }
    else
    {
        prev->next = newNode; // Insert in middle or at end
    }

    return true;
}

// Removes a string from the list
bool StringTracker::removeString(const std::string &str)
{
    // Pointers to traverse the list
    Node *prev = nullptr;
    Node *current = headptr;

    // Traverse to find the node to remove
    while (current != nullptr && current->Value != str)
    {
        prev = current;
        current = current->next;
    }

    // Node not found
    if (current == nullptr)
    {
        return false;
    }

    // Unlink the node from the list
    if (prev == nullptr)
    {
        headptr = current->next; // Removing the head
    }
    else
    {
        prev->next = current->next; // Removing from middle/end
    }

    // Free the memory
    delete current;
    return true;
}

// Increments a string's count
bool StringTracker::incrementCount(const std::string &str)
{
    Node *current = headptr;

    // Traverse to find the node (sorted list optimization)
    while (current != nullptr && current->Value < str)
    {
        current = current->next;
    }

    // Found it, increment count
    if (current != nullptr && current->Value == str)
    {
        current->count++;
        return true;
    }

    return false; // Not found
}

// Decrements a string's count
bool StringTracker::decrementCount(const std::string &str)
{
    Node *current = headptr;

    // Traverse to find the node (sorted list optimization)
    while (current != nullptr && current->Value < str)
    {
        current = current->next;
    }

    // Found it, decrement count
    if (current != nullptr && current->Value == str)
    {
        current->count--;
        return true;
    }

    return false; // Not found
}

// Gets a string's count
int StringTracker::getCount(const std::string &str) const
{
    Node *current = headptr;

    // Traverse to find the node (sorted list optimization)
    while (current != nullptr && current->Value < str)
    {
        current = current->next;
    }

    // Found it, return count
    if (current != nullptr && current->Value == str)
    {
        return current->count;
    }

    return 0; // Not found, return 0
}

// Gets the highest count in the list
int StringTracker::getMaximumCount() const
{
    int maxSoFar = 0;
    Node *current = headptr;

    // Handle empty list
    if (headptr == nullptr)
    {
        return 0;
    }

    // Check every node
    while (current != nullptr)
    {
        // Update max if this node's count is higher
        if (current->count > maxSoFar)
        {
            maxSoFar = current->count;
        }
        current = current->next;
    }

    return maxSoFar;
}

// Prints the list in format: "val1(count1),val2(count2)"
void StringTracker::print(std::ostream &out) const
{
    Node *current = headptr;
    while (current != nullptr)
    {
        // Print the node's data
        out << current->Value << "(" << current->count << ")";
        
        // Add a comma if this is not the last node
        if (current->next != nullptr)
        {
            out << ",";
        }
        current = current->next;
    }
}