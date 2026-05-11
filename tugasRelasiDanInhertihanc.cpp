#include <iostream>
#include <vector>
using namespace std;

class User {
protected:
    int id;
    string nama, email;
    static int globalId;
public:
    User(string nama, string email) : nama(nama), email(email), id(generateId()) {}
    int generateId() { return ++globalId; }
};
int User::globalId = 0;

class Member : public User {
    bool status;
public:
    Member(string nama, string email) : User(nama, email), status(true) {}
    void setStatus(bool s) { status = s; }
    bool getStatus() { return status; }
    int getId() { return id; }
    string getNama() { return nama; }
    void showProfile() {
        cout << "ID: " << id << " | Nama: " << nama
             << " | Email: " << email
             << " | Status: " << (status ? "Aktif" : "Nonaktif") << endl;
    }
};

class Admin : public User {
    vector<Member*> members;
public:
    Admin(string nama, string email) : User(nama, email) {}
    void addMember(Member* m) { members.push_back(m); }
    void showAllMember() {
        for (auto m : members) m->showProfile();
    }
    void toggleActivationMember(int targetId) {
        for (auto m : members)
            if (m->getId() == targetId) m->setStatus(!m->getStatus());
    }
};

int main() {
    Admin admin("Budi", "budi@admin.com");
    Member m1("Andi", "andi@mail.com");
    Member m2("Sari", "sari@mail.com");

    admin.addMember(&m1);
    admin.addMember(&m2);
    admin.showAllMember();

    admin.toggleActivationMember(m1.getId());
    admin.showAllMember();
}