#include <iostream>
#include <conio.h>
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
void show();
void push(); //fungsi menampilkan barang baru
void searchByName();
void searchById();

int main() {
    init();
    int choice; // untuk menampilkan menu pilihan
    
    do{
      system("cls");
      cout << " \n-----Program Pendataan Barang Gudang-----\n\n";
      cout << "1. Tambahkan Barang\n";
      cout << "2. Tampilkan Barang\n";
      cout << "3. Cari Barang Berdasarkan Nama\n";
      cout << "4. Cari Barang Berdasarkan ID\n";
      cout << "5. Keluar\n\n";
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
            cout <<"Keluar dari program.\n\n";
            break;
            default:
            cout << "Pilihan tidak valid. Silahkan coba lagi./n";
        }
    }while(choice != 5);
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

void show() {
    if (!empty ()){
        cout<<"\n----Menampilkan Daftar Barang ----\n";
        for(int i = stack.top; i>=0; i--) {
            cout<<"Id          : "<< stack.data[i].id<<endl;
            cout<<"Nama        : "<< stack.data[i].nama<<endl;
            cout<<"Jumlah      : "<< stack.data[i].jumlah<<endl;
        }
    }else {
        cout<<"\nStack Kosong";
    } 
    cin.get();
}

void push() {
    if (!full()) {
        cout << "Masukkan ID Barang: "; cin >> barang.id;
        cout << "Masukkan Nama Barang:"; cin >> barang.nama;
        cout << "Masukkan Jumlah Barang:"; cin >> barang.jumlah;
        stack.data[++stack.top] = barang;
    }else {
        cout <<"Stack sudah penuh.\n";
    }
}

void searchByName() {
    string name;
    cout << " Masukkan Nama Barang yang dicari: ";
    cin >> name;
    bool found = false;

    for (int i = 0; i <= stack.top; i++) {
        if (stack.data [i].nama == name) {
            cout << "Barang ditemukan:\n";
            cout << " ID      : " << stack.data[i].id<< endl;
            cout << "Nama     : " << stack.data[i].nama<< endl;
            cout << "Jumlah   : " << stack.data[i].jumlah << endl;
            found = true;
            break;
        }
    }
    if (found == false ) {
        cout << " Barang dengan nama '"<< name << "' tidak ditemukan.\n";
    }
}

void searchById() {
    int id;
    cout << " Masukkan ID barang yang dicari: ";
    cin >> id;
    bool found = false;

    for (int i = 0; i <= stack.top; i++) {
        if (stack.data[i].id == id) {
            cout << "Barang ditemukkan:\n";
            cout  << " ID    : " << stack.data[i].id <<endl;
            cout << " Nama   : " << stack.data[i].nama <<endl;
            cout << "Jumlah : " << stack.data[i].jumlah << endl;
            found = true;
            break;
        }
    }
    if (!found) { 
        cout << " Barang dengan ID '" << id << "' tidak ditemukan.\n";
    }
}
