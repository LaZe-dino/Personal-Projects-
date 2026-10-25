#ifndef LIBRARY_HPP
#define LIBRARY_HPP

#include <vector>
#include <string>

class Library {
private:
    std::vector<std::string> bookList;
    double libraryBudget;
    static int totalBorrowedBooks;

    int reservedCount;
    std::vector<std::string> reservedBooks;
    
    // Feature 3: Added a list to track library member names
    std::vector<std::string> membersList; 

public:
    Library();

    void addBook(std::string title, double bookCost);
    bool borrowBook(std::string title);
    void listBooks();
    void reserveBook(const std::string& title);
    
    // Feature 3: Function to register new library members
    void addMember(const std::string& name);
    void listMembers();
    
    static int getTotalBorrowedBooks();
};

#endif
