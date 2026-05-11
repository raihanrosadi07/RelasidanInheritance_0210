#ifndef IBU_H
#define IBU_H

class anak;

class ibu {
public:

    string nama;
    vector<anak*> daftar_anak;

    ibu(string pNama) :nama(pNama) {
        cout << "ibu \"" << nama << "\" ada\n";
    };

}