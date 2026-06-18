#include <iostream>
#include <vector>
#include <string>

using namespace std;

// Custom Exceptions
class DuplicateBookIDException {};
class DuplicateMemberIDException {};
class EmptyFieldException {};

class Book {
public:
    int bookID;
    string title;
    string author;
    bool issued;

    Book(int id, string t, string a) {
        bookID = id;
        title = t;
        author = a;
        issued = false;
    }
};

class Member {
public:
    int memberID;
    string name;

    Member(int id, string n) {
        memberID = id;
        name = n;
    }
};

class Library {
private:
    vector<Book> books;
    vector<Member> members;

public:

    void addBook() {
        int id;
        string title, author;

        try {
            cout << "Enter Book ID: ";
            cin >> id;
            cin.ignore();

            for (auto &book : books) {
                if (book.bookID == id)
                    throw DuplicateBookIDException();
            }

            cout << "Enter Book Title: ";
            getline(cin, title);

            if (title.empty())
                throw EmptyFieldException();

            cout << "Enter Author Name: ";
            getline(cin, author);

            if (author.empty())
                throw EmptyFieldException();

            books.push_back(Book(id, title, author));

            cout << "Book Added Successfully!\n";
        }

        catch (DuplicateBookIDException) {
            cout << "Exception: Book ID already exists!\n";
        }

        catch (EmptyFieldException) {
            cout << "Exception: Title/Author cannot be empty!\n";
        }
    }

    void addMember() {
        int id;
        string name;

        try {
            cout << "Enter Member ID: ";
            cin >> id;
            cin.ignore();

            for (auto &member : members) {
                if (member.memberID == id)
                    throw DuplicateMemberIDException();
            }

            cout << "Enter Member Name: ";
            getline(cin, name);

            if (name.empty())
                throw EmptyFieldException();

            members.push_back(Member(id, name));

            cout << "Member Added Successfully!\n";
        }

        catch (DuplicateMemberIDException) {
            cout << "Exception: Member ID already exists!\n";
        }

        catch (EmptyFieldException) {
            cout << "Exception: Name cannot be empty!\n";
        }
    }

    void issueBook() {
        int id;

        cout << "Enter Book ID to Issue: ";
        cin >> id;

        for (auto &book : books) {
            if (book.bookID == id) {
                if (!book.issued) {
                    book.issued = true;
                    cout << "Book Issued Successfully!\n";
                } else {
                    cout << "Book Already Issued!\n";
                }
                return;
            }
        }

        cout << "Book Not Found!\n";
    }

    void returnBook() {
        int id;

        cout << "Enter Book ID to Return: ";
        cin >> id;

        for (auto &book : books) {
            if (book.bookID == id) {
                if (book.issued) {
                    book.issued = false;
                    cout << "Book Returned Successfully!\n";
                } else {
                    cout << "Book Was Not Issued!\n";
                }
                return;
            }
        }

        cout << "Book Not Found!\n";
    }

    void searchByID() {
        int id;

        cout << "Enter Book ID: ";
        cin >> id;

        for (auto &book : books) {
            if (book.bookID == id) {
                cout << "\nBook Found\n";
                cout << "Book ID : " << book.bookID << endl;
                cout << "Title   : " << book.title << endl;
                cout << "Author  : " << book.author << endl;
                cout << "Status  : "
                     << (book.issued ? "Issued" : "Available")
                     << endl;
                return;
            }
        }

        cout << "Book Not Found!\n";
    }

    void searchByTitle() {
        string title;

        cin.ignore();

        cout << "Enter Book Title: ";
        getline(cin, title);

        bool found = false;

        for (auto &book : books) {
            if (book.title == title) {
                cout << "\nBook ID : " << book.bookID << endl;
                cout << "Title   : " << book.title << endl;
                cout << "Author  : " << book.author << endl;
                cout << "Status  : "
                     << (book.issued ? "Issued" : "Available")
                     << endl;

                found = true;
            }
        }

        if (!found)
            cout << "Book Not Found!\n";
    }

    void searchByAuthor() {
        string author;

        cin.ignore();

        cout << "Enter Author Name: ";
        getline(cin, author);

        bool found = false;

        for (auto &book : books) {
            if (book.author == author) {
                cout << "\nBook ID : " << book.bookID << endl;
                cout << "Title   : " << book.title << endl;
                cout << "Author  : " << book.author << endl;
                cout << "Status  : "
                     << (book.issued ? "Issued" : "Available")
                     << endl;

                found = true;
            }
        }

        if (!found)
            cout << "Book Not Found!\n";
    }

    void displayBooks() {
        if (books.empty()) {
            cout << "No Books Available!\n";
            return;
        }

        cout << "\n========== BOOK LIST ==========\n";

        for (auto &book : books) {
            cout << "Book ID : " << book.bookID << endl;
            cout << "Title   : " << book.title << endl;
            cout << "Author  : " << book.author << endl;
            cout << "Status  : "
                 << (book.issued ? "Issued" : "Available")
                 << endl;
            cout << "------------------------------\n";
        }
    }
};

int main() {
    Library lib;
    int choice;

    do {
        cout << "\n========== LIBRARY MANAGEMENT SYSTEM ==========\n";
        cout << "1. Add Book\n";
        cout << "2. Add Member\n";
        cout << "3. Issue Book\n";
        cout << "4. Return Book\n";
        cout << "5. Search Book By ID\n";
        cout << "6. Search Book By Title\n";
        cout << "7. Search Book By Author\n";
        cout << "8. Display All Books\n";
        cout << "9. Exit\n";
        cout << "Enter Choice: ";
        cin >> choice;

        switch (choice) {

        case 1:
            lib.addBook();
            break;

        case 2:
            lib.addMember();
            break;

        case 3:
            lib.issueBook();
            break;

        case 4:
            lib.returnBook();
            break;

        case 5:
            lib.searchByID();
            break;

        case 6:
            lib.searchByTitle();
            break;

        case 7:
            lib.searchByAuthor();
            break;

        case 8:
            lib.displayBooks();
            break;

        case 9:
            cout << "Thank You!\n";
            break;

        default:
            cout << "Invalid Choice!\n";
        }

    } while (choice != 9);

    return 0;
}