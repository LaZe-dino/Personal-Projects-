#include "Library.hpp"
#include "removeElement.hpp"
#include <iostream>
#include <algorithm>

using namespace std;

int Library::totalBorrowedBooks = 0;

Library::Library() : reservedCount(0), libraryBudget(5000.0) {}

void Library::reserveBook(const std::string& title) {
  auto it_exists = std::find(bookList.begin(), bookList.end(), title);
  auto it_reserved = std::find(reservedBooks.begin(), reservedBooks.end(), title);

  if (it_exists != bookList.end() && it_reserved == reservedBooks.end()) {
    reservedBooks.push_back(title);
    reservedCount++;
    cout << "Book reserved: " << title << "\n";
    cout << "Reserved book count: " << reservedCount << "\n";
  } else {
    cout << "Book not reserved!\n";
  }
}

// Upgraded borrowBook function
bool Library::borrowBook(string title) {
  // Check if the book is currently marked as reserved
  auto it_reserved = std::find(reservedBooks.begin(), reservedBooks.end(), title);
  
  // Feature 2: Waitlist Functionality (Block borrowing if the item is reserved)
  if (it_reserved != reservedBooks.end()) {
    cout << "Cannot borrow \"" << title << "\" because it is currently reserved on the waitlist!\n";
    return false;
  }

  // Look through standard book list to borrow
  for (const string& book : bookList) {
    if (book == title) {
      removeElement(bookList, title);
      totalBorrowedBooks++; 
      cout << "Book borrowed: " << title << endl;
      return true;
    }
  }
  
  cout << "Book not found!" << endl;
  return false;
}

// Feature 3: Membership tracking functions
void Library::addMember(const string& name) {
  membersList.push_back(name);
  cout << "Member registered successfully: " << name << endl;
}

void Library::listMembers() {
  if (membersList.empty()) {
    cout << "No members registered yet." << endl;
    return;
  }
  cout << "Active Library Members:" << endl;
  for (const string& member : membersList) {
    cout << "- " << member << endl;
  }
}

void Library::addBook(string title, double bookCost) {
  if (bookList.size() < 100) {
    bookList.push_back(title);
    libraryBudget -= bookCost;
  } else {
    cout << "Library is at full capacity!" << endl;
  }
}

void Library::listBooks() {
  if (bookList.empty()) {
    cout << "No books available in the library." << endl;
    return;
  }
  cout << "Available Books:" << endl;
  for (const string& book : bookList) {
    cout << "- " << book << endl;
  }
}

int Library::getTotalBorrowedBooks() {
  return totalBorrowedBooks;
}
