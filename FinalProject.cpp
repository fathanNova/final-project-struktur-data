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

void init();
bool full();
bool empty();
string toLowerCase(string str);
void show();
void push(); //fungsi menampilkan barang baru
void searchByName();
void searchById();
void restock();
void takeByQuantity();

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
      cout << "7. Keluar\n\n";
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
                cout <<"Keluar dari program.\n\n";
                break;
            default:
            cout << "Pilihan tidak valid. Silahkan coba lagi./n";
            getchar();
        }
    }while(choice != 7);
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
    /*
    if (!empty ()){
        cout<<"\n----- Menampilkan Daftar Barang -----\n";
        for(int i = stack.top; i>=0; i--) {
            cout<<"ID          : "<< stack.data[i].id<<endl;
            cout<<"Nama        : "<< stack.data[i].nama<<endl;
            cout<<"Jumlah      : "<< stack.data[i].jumlah<<endl<<endl;
        }
    }else {
        cout<<"\nBarang Masih Kosong!\n\n";
    }
        */
    cout << "Show Barang (Stack)\n";
    if (empty()) {
        cout << "Stack kosong!\n";
    } else {
        cout << setw(5) << "ID"
             << setw(20) << "Nama"
             << setw(10) << "Jumlah" << endl;
        for (int i = stack.top; i >= 0; i--) {
            cout << setw(5) << stack.data[i].id
                 << setw(20) << stack.data[i].nama
                 << setw(10) << stack.data[i].jumlah << endl;
        }
    }
 
    getchar();
}

void push() {
    if (!full()) {
        cin.ignore();
        stack.top++;
        barang.id = stack.top+1;
        cout << "\n----- Menambahkan Barang -----\n";
        cout << "\nID Barang\t\t: "<<barang.id<<endl;
        cout << "Masukkan Nama Barang\t: "; getline(cin, barang.nama); 
        cout << "Masukkan Jumlah Barang \t: "; cin >> barang.jumlah;
        stack.data[stack.top] = barang;
        cin.ignore();
    }else {
        cout <<"\nBarang Sudah Penuh!\n\n";
    }
    getchar();
}

void searchByName() {
    cin.ignore();
    string name;
    cout << "\nMasukkan Nama Barang yang dicari: "; getline(cin, name);
    bool found = false;

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
    if (!found) {
        cout << "\nBarang dengan Nama '"<< name << "' Tidak Ditemukan.\n";
    }
    getchar();
}

void searchById() {
    int id;
    bool found = false;
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

    cout<<"\nMasukkan Nama Barang yang Ingin di Restock: "; getline(cin, name);
    for(int i = 0; i <= stack.top; i++){
        if(toLowerCase(stack.data[i].nama) == toLowerCase(name)){
            cout<<"Masukkan Jumlah "<<name<<" yang Akan di Restock: "; cin>>restock;
            stack.data[i].jumlah += restock;
            found = true;
            cin.ignore();

            cout<<"\nData Berhasil Disimpan\n\n";
            break;
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

    cout<<"\nMasukkan Nama Barang yang Akan Diambil: "; getline(cin, name);
    for(int i = 0; i <= stack.top; i++){
        if(toLowerCase(stack.data[i].nama) == toLowerCase(name)){
            cout<<"Masukkan Jumlah "<<name<<" yang Akan Diambil: "; cin>>take;
            stack.data[i].jumlah -= take;
            found = true;
            cin.ignore();

            cout<<"\nData Berhasil Disimpan\n\n";
            break;
        }
    }
    if(!found){
        cout<<"\nBarang dengan Nama '"<<name<<"' Tidak Ditemukan !\n\n";
    }
    getchar();
}