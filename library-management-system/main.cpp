#include "Library.hpp"
#include <iostream>

using namespace std;

int main() {
  Library myLibrary; 

  // Setup items
  myLibrary.addBook("The Great Gatsby", 300.0);
  myLibrary.addBook("1984", 400.0);
  myLibrary.addBook("To Kill a Mockingbird", 350.0);

  cout << "--- Testing Feature 3: Library Membership ---" << endl;
  myLibrary.addMember("Alice Smith");
  myLibrary.addMember("Bob Jones");
  
  // FIXED: Changed from addLineup() to listMembers()
  myLibrary.listMembers(); 
  
  cout << "\n--- Testing Feature 2: Reservation Waitlist Block ---" << endl;
  myLibrary.reserveBook("1984"); // Places "1984" on reserve list
  myLibrary.borrowBook("1984");  // Will FAIL to borrow due to active reservation rule

  return 0;
}
