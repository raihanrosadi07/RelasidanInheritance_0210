#ifndef MANUSIA_H
#define MANUSIA_H

class manusia {
public:
    string name;
    Jantung varJantung;

    manusia(string pName) : name(pName) {
        cout << name << "Hidup\n";
    }
    ~manusia() {
        cout << name << "Mati\n";
    }
};
#endif