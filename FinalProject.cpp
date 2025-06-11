#include <iostream>
#include <conio.h>
#include <algorithm>
#include <cctype>
#include <stdio.h>
#include <iomanip>
using namespace std;
#define max 50

struct barangGudang{
    int id;
    string nama;
    int jumlah;
}barang;

struct stackBarang{
    barangGudang data[max];
    int top;
}stack;

struct historyNode{
    string activity;
    historyNode *next;
};
historyNode *head = NULL;

void init();
bool full();
bool empty();
string toLowerCase(string str);
void show();
void push(); //fungsi menampilkan barang baru
void deleteByName();
void searchByName();
void searchById();
void restock();
void takeByQuantity();
void addHistory(string activity);
void showHistory();

int main() {
    init();
    int choice; // untuk menampilkan menu pilihan
    do{
      system("cls");
      cout << " \n----- Program Pendataan Barang Gudang -----\n\n";
      cout << "1. Tambahkan Barang\n";
      cout << "2. Tampilkan Barang\n";
      cout << "3. Cari Barang Berdasarkan Nama\n";
      cout << "4. Cari Barang Berdasarkan ID\n";
      cout << "5. Restock Barang\n";
      cout << "6. Ambil Barang\n";
      cout << "7. Hapus Barang\n";
      cout << "8. Tampilkan Riwayat Aktivitas\n";
      cout << "9. Keluar\n\n";
      cout << "Masukkan Pilihan Anda : "; cin >> choice;
        switch (choice) {
            case 1:
                push();
                break;
            case 2:
                show();
                break;
            case 3:
                searchByName();
                break;
            case 4:
                searchById();
                break;
            case 5:
                restock();
                break;
            case 6:
                takeByQuantity();
                break;
            case 7:
                deleteByName();
                break;
            case 8:
                showHistory();
                break;
            case 9:
                cout <<"Keluar dari program.\n\n";
                break;
            default:
            cout << "Pilihan tidak valid. Silahkan coba lagi.\n\n";
            getchar();
            cin.get();
        }
    }while(choice != 9);
    system("pause");
    return 0;
}

void init(){    
    stack.top = -1;
}

bool full (){ 
    return stack.top == max-1;
}

bool empty() {  
    return stack.top == -1;
}

string toLowerCase(string str){
    transform(str.begin(), str.end(), str.begin(), ::tolower);
    return str;
}

void show() {
    cin.ignore();
    cout << "\n======= Menampilkan Daftar Barang =======\n";
    if (empty()) {
        cout <<"\nBarang Kosong!\n\n";
    } else {
        cout << left << setw(10) << "ID"
             << left << setw(25) << "Nama"
             << left << setw(10) << "Jumlah" << endl;
        for (int i = stack.top; i >= 0; i--) {
            cout << left << setw(10) << stack.data[i].id
                 << left << setw(25) << stack.data[i].nama
                 << left << setw(10) << stack.data[i].jumlah << endl;
        }
    }
 
    getchar();
}

void push() {
    if (!full()) {
        cin.ignore();
        barang.id = stack.top+2;
        cout << "\n----- Menambahkan Barang -----\n";
        cout << "\nID Barang\t\t: "<<barang.id<<endl;
        cout << "Masukkan Nama Barang\t: "; getline(cin, barang.nama); 
        cout << "Masukkan Jumlah Barang \t: "; cin >> barang.jumlah;
        stack.top++;
        stack.data[stack.top] = barang;
        cin.ignore();

        cout<<"\nData Berhasil Ditambahkan\n\n";
        addHistory("Menambahkan Barang: " + barang.nama);
    }else {
        cout <<"\nBarang Sudah Penuh!\n\n";
    }
    getchar();
}

void deleteByName() {
    cin.ignore();
    string name;
    bool found = false;
    if (empty()) {
        cout << "\nBarang kosong! Tidak Ada Barang yang Dapat Dihapus.\n";
        getchar();
        return;
    }else{
        cout << "\nMasukkan Nama Barang yang Ingin Dihapus: ";
        getline(cin, name);

        for (int i = 0; i <= stack.top; i++) {
            if (toLowerCase(stack.data[i].nama) == toLowerCase(name)) {

                addHistory("Menghapus Barang: " + stack.data[i].nama);
                found = true;
                
                for (int j = i; j < stack.top; j++) {
                    stack.data[j] = stack.data[j + 1];
                }
                stack.top--;

                cout << "\nBarang dengan Nama '" << name << "' Berhasil Dihapus.\n";
               break;
            }
        }
    }
    if (!found) {
        cout << "\nBarang dengan Nama '" << name << "' Tidak Ditemukan.\n";
    }
    getchar();
}

void searchByName() {
    cin.ignore();
    string name;
    bool found = false;
    if(empty()){
        cout << "\nBarang kosong!\n";
        getchar();
        return; 
    }else{
        cout << "\nMasukkan Nama Barang yang Dicari: "; getline(cin, name);
        for (int i = 0; i <= stack.top; i++) {
            if (toLowerCase(stack.data[i].nama) == toLowerCase(name)) {
                cout << "Barang ditemukan:\n";
                cout << "ID       : " << stack.data[i].id<< endl;
                cout << "Nama     : " << stack.data[i].nama<< endl;
                cout << "Jumlah   : " << stack.data[i].jumlah << endl<<endl;
                found = true;
                break;
            }
        }
    }
    if (!found) {
        cout << "\nBarang dengan Nama '"<< name << "' Tidak Ditemukan.\n";
    }
    getchar();
}

void searchById() {
    int id;
    bool found = false;
    if(empty()){
        cout << "\nBarang kosong!\n";
        getchar();
        cin.get();
        return; 
    }else{
        cout << "\nMasukkan ID barang yang dicari: ";cin >> id;
        cin.ignore();

        for (int i = 0; i <= stack.top; i++) {
            if (stack.data[i].id == id) {
                cout << "Barang ditemukkan:\n";
                cout << "ID     : " << stack.data[i].id <<endl;
                cout << "Nama   : " << stack.data[i].nama <<endl;
                cout << "Jumlah : " << stack.data[i].jumlah <<endl<<endl;
                found = true;
                break;
            }
        }
    }
    if (!found) { 
        cout << "\nBarang dengan ID '" << id << "' Tidak Ditemukan.\n\n";
    }
    getchar();
}

void restock(){
    cin.ignore();
    string name;
    int restock;
    bool found = false;

    if(empty()){
         cout << "\nBarang kosong!\n";
        getchar();
        return;
    }else{
        cout<<"\nMasukkan Nama Barang yang Ingin di Restock: "; getline(cin, name);
        for(int i = 0; i <= stack.top; i++){
            if(toLowerCase(stack.data[i].nama) == toLowerCase(name)){
                cout<<"Masukkan Jumlah "<<name<<" yang Akan di Restock: "; cin>>restock;
                stack.data[i].jumlah += restock;
                found = true;
                cin.ignore();

                cout<<"\nData Berhasil Disimpan\n\n";
                addHistory("Restock Barang: " + stack.data[i].nama + " Sejumlah " + to_string(restock));
                break;
            }
        } 
    }
    if(!found){
        cout<<"\nBarang dengan Nama '"<<name<<"' Tidak Ditemukan !\n\n";
    }
    getchar();
}

void takeByQuantity(){
    cin.ignore();
    string name;
    int take;
    bool found = false;

    if(empty()){
         cout << "\nBarang kosong!\n";
        getchar();
        return;
    }else{
        cout<<"\nMasukkan Nama Barang yang Akan Diambil: "; getline(cin, name);
        for(int i = 0; i <= stack.top; i++){
            if(toLowerCase(stack.data[i].nama) == toLowerCase(name)){
                cout<<"Masukkan Jumlah "<<name<<" yang Akan Diambil: "; cin>>take;
                stack.data[i].jumlah -= take;
                found = true;
                cin.ignore();

                cout<<"\nData Berhasil Disimpan\n\n";
                addHistory("Mengambil Barang: " + stack.data[i].nama + " Sejumlah " + to_string(take));
                break;
            }
        }
    }
    if(!found){
        cout<<"\nBarang dengan Nama '"<<name<<"' Tidak Ditemukan !\n\n";
    }
    getchar();
}

void addHistory(string activity){
    historyNode *add = new historyNode;
    add -> activity = activity;
    add -> next = head;
    head = add;
}

void showHistory(){
    cin.ignore();
    cout<<"\n\n====== Riwayat Aktivitas =======\n\n";
    if(head == NULL){
        cout<<"\nTidak Ada Aktivitas\n\n";
        getchar();
        return;
    }
    historyNode *now = head;
    while(now != NULL){
        cout<<"- "<<now -> activity<<endl;
        now = now -> next;
    }
    getchar();
}