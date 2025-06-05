#include <iostream>
#include <conio.h>
#include <algorithm>
#include <cctype>
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
      cout << "6. Keluar\n\n";
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
                cout <<"Keluar dari program.\n\n";
                break;
            default:
            cout << "Pilihan tidak valid. Silahkan coba lagi./n";
        }
    }while(choice != 6);
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
    getchar();
}

void push() {
    if (!full()) {
        cin.ignore();
        stack.top++;
        barang.id = stack.top+1;
        cout << "\n----- Menambahkan Barang -----\n";
        cout << "\nID Barang: "<<barang.id<<endl;
        cout << "Masukkan Nama Barang: "; getline(cin, barang.nama); 
        cout << "Masukkan Jumlah Barang: "; cin >> barang.jumlah;
        stack.data[stack.top] = barang;
    }else {
        cout <<"\nBarang Sudah Penuh!\n\n";
    }
    cout<<endl;
    getchar();
    cin.get();
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
    if (found == false ) {
        cout << "\nBarang dengan nama '"<< name << "' tidak ditemukan.\n";
    }
    getchar();
}

void searchById() {
    cin.ignore();
    int id;
    cout << "\nMasukkan ID barang yang dicari: ";
    cin >> id;
    bool found = false;

    for (int i = 0; i <= stack.top; i++) {
        if (stack.data[i].id == id) {
            cout << "Barang ditemukkan:\n";
            cout << "ID     : " << stack.data[i].id <<endl;
            cout << "Nama   : " << stack.data[i].nama <<endl;
            cout << "Jumlah : " << stack.data[i].jumlah << endl;
            found = true;
            break;
        }
    }
    if (!found) { 
        cout << "Barang dengan ID '" << id << "' Tidak Ditemukan.\n";
    }
    getchar();
}

void restock(){
    cin.ignore();
    string name;
    int restock;

    cout<<"\nMasukkan Nama Barang yang Ingin di Restock: "; getline(cin, name);
    for(int i = 0; i <= stack.top; i++){
        if(toLowerCase(stack.data[i].nama) == toLowerCase(name)){
            cout<<"Masukkan Jumlah "<<name<<" yang Akan di Restock: "; cin>>restock;
            stack.data[i].jumlah += restock;
            
            cout<<"\nData Berhasil Ditambahkan\n\n";
            getchar();
            cin.get();
            break;
        }else{
            cout<<"\nBarang dengan Nama '"<<name<<"' Tidak Ditemukan !\n\n";
            getchar();
        }
    } 
}