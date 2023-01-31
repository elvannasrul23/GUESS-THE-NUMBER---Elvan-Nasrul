#include <iostream>
#include <windows.h>
#include <unistd.h>
#include <stdlib.h>
#include <time.h>
using namespace std;

    // untuk mengubah warna sebagian teks
    HANDLE h=GetStdHandle (STD_OUTPUT_HANDLE);
    //fungsi judul
    void judulGame (){
        SetConsoleTextAttribute (h,7);
        cout << "==============================================\n";
        string bagianKiri = "12345678910 ||";
            for (int i = 0; i < bagianKiri.length(); i++) {
                SetConsoleTextAttribute (h,10);
                cout << bagianKiri[i] ;
                usleep(100000);
            }
        string judulGame = " GUESS THE NUMBER ";
            for (int i = 0; i < judulGame.length(); i++) {
                SetConsoleTextAttribute (h,79);
                cout << judulGame[i] ;
                usleep(100000);
            }
        string bagianKanan = "|| 01987654321";
            for (int i = 0; i < bagianKanan.length(); i++) {
                SetConsoleTextAttribute (h,10);
                cout << bagianKanan[i] ;
                usleep(100000);
            }
        cout << endl;
        SetConsoleTextAttribute (h,7);
        cout << "==============================================\n";
        cout << endl;
    }
// struct untuk menyimpan informasi pemain
struct Pemain {
    string nama;
    int skor;
};

int main() {

    // loop untuk permainan
    while (true) {
    // array untuk menyimpan data pemain
    Pemain pemain[3];
    // judul game
    judulGame();
    sleep (3);
    // pertanyaan untuk memulai game
    string mulai;
        SetConsoleTextAttribute (h,7);
        cout << ">Mulai game ? ";
        SetConsoleTextAttribute (h,10);
        cout <<"Y";
        SetConsoleTextAttribute (h,7);
        cout <<"/";
        SetConsoleTextAttribute (h,12);
        cout <<"N ";
        SetConsoleTextAttribute (h,7);
        cin >> mulai;
        if (mulai != "Y" && mulai != "y") {
            break;
        }
    system ("cls");

    // input data pemain/memberi nama pada pemain
    for (int i = 0; i < 3; i++) {
            if ( i == 0 ){
                SetConsoleTextAttribute (h,30);
            }else if ( i == 1){
                SetConsoleTextAttribute (h,94);
            }else {
                SetConsoleTextAttribute (h,111);
            }
        cout << ">Masukkan nama player " << i+1 << " : ";
        cin >> pemain[i].nama;
        cout << endl;
        pemain[i].skor = 0;
        // periksa namaplayer (namanya jangan sama)
        for (int j = 0; j < i; j++){
            if (pemain[j].nama == pemain[i].nama){
                SetConsoleTextAttribute (h,4);
                cout << "*Nama player sudah dipakai, gunakan nama lain\n" << endl;
                i--;
                break;
            }
        }
    }
    cout << endl;
    sleep(1);
    system ("cls");
    system("color 0F"); // set latar belakang default

    // loop untuk setiap pemain (game dimulai)
    for (int i = 0; i < 3; i++) {
        cout << "Player ";
         if ( i == 0 ){
                SetConsoleTextAttribute (h,30);
            }else if ( i == 1){
                SetConsoleTextAttribute (h,94);
            }else {
                SetConsoleTextAttribute (h,111);
            }
        cout << " ";
        cout << pemain[i].nama;
        cout << " ";
        SetConsoleTextAttribute (h,7);
        cout << ", bersiap...\n" << endl;
        sleep(3);
        system ("cls");
        cout << "||";
         if ( i == 0 ){
                SetConsoleTextAttribute (h,30);
            }else if ( i == 1){
                SetConsoleTextAttribute (h,94);
            }else {
                SetConsoleTextAttribute (h,111);
            }

        cout << "  TEBAKAN PLAYER " << pemain[i].nama;
        cout << "  ";
        SetConsoleTextAttribute (h,7);
        cout << "||" <<  endl;
        cout << "================================="<< endl;
        cout << "*Tebak angka dari 1 sampai 10 !!! " << endl;
        cout << "================================="<< endl;

          // seed untuk random number generator
            srand(time(0));

        // loop untuk mengambil tebakan dari pemain
        for (int j = 0; j < 3; j++) {
            // angka acak yang harus ditebak
            int target = rand() % 10+1;
            int tebakan;
                cout << ">Tebakan ke-" << j+1 << " : ";
                cin >> tebakan;

    // cek tebakan
                if (tebakan == target) {
                    cout << ">Tebakan kamu BENAR :)" << endl;
                    cout << ">Skor kamu : " << pemain[i].skor+1 << endl;
                    cout << "==========================="<< endl;
                    system("color 2F"); //set latar belakang hijau
                    pemain[i].skor++;
                    sleep(2);
            } else {
                    cout << ">Tebakan kamu SALAH :(" << endl;
                    cout << ">Skor kamu : " << pemain[i].skor << endl;
                    cout << "==========================="<< endl;
                    system("color 4F"); //set latar belakang merah
                    sleep(2);
                    }
                system("color 0F"); // set latar belakang default
                }
            system ("cls");
        }

    // tampilkan pemenang
        int pemenang = 0;
        for (int i = 0; i < 3; i++) {
            if (pemain[i].skor > pemain[pemenang].skor) {
                pemenang = i;
            }
        }
       int imbang = 0;
       for (int i = 0; i < 3; i++){
            if (i != pemenang && pemain[i].skor == pemain[pemenang].skor){
                imbang = 1;
                break;
            }
       }
       if (!imbang){
            cout << "PEMENANGNYA adalah ";
            SetConsoleTextAttribute (h,47);
            cout << "  ";
            cout << pemain[pemenang].nama ;
            cout << "  ";
            SetConsoleTextAttribute (h,7);
            cout << " dengan skor : " << pemain[pemenang].skor << endl;
            cout << "===================================="<< endl;
            SetConsoleTextAttribute (h,47);
            cout << "\t   SELAMAT !!! \n";
            SetConsoleTextAttribute (h,7);
            cout << "====================================\n\n"<< endl;
    } else {
            cout << "TIDAK ADA PEMENANG ada skor IMBANG" << endl;
            cout << "=================================="<< endl;
            SetConsoleTextAttribute (h,111);
            cout << "\t    COBA LAGI !!! \n";
            SetConsoleTextAttribute (h,7);
            cout << "==================================\n\n"<< endl;
      }
    // pertanyaan untuk mengulang permainan
        string jawab;
        cout << ">Main lagi ? ";
        SetConsoleTextAttribute (h,10);
        cout <<"Y";
        SetConsoleTextAttribute (h,7);
        cout <<"/";
        SetConsoleTextAttribute (h,12);
        cout <<"N ";
        SetConsoleTextAttribute (h,7);
        cin >> jawab;
        if (jawab != "Y" && jawab != "y") {
            break;
        }
         system ("cls");
    }
    return 0;
}
