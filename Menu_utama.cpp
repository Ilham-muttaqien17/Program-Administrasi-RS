#include <iostream>
#include <cstdio>
#include <string.h>
#include <conio.h>
#include <stdlib.h>
#include <iomanip>
#include "tambah_pasien.cpp"
#include "daftar_pasien.cpp"
#include "cek_kode_pasien.cpp"
#include "cari_pasien.cpp"
#include "panggil_pasien.cpp"
// #include "tes_panggil.cpp"

using namespace std;

int main(){
	int pilih;
	char x;
	string daftar_menu[] = {
		"Tambah Pasien",
		"Daftar Pasien",
		"Cek Kode Pasien",
		"Cari Pasien",
		"Panggil Pasien",
		"Exit"
	};

#define menu (sizeof(daftar_menu)/sizeof(daftar_menu[0]))

	Menu:
	system("cls");
	cout<<setw(63)<<"+++++++++++++++++++++++++++++++++++++++++\n";
	cout<<setw(63)<<"++   PROGRAM ADMINISTRASI RS HARAPAN   ++\n";
	cout<<setw(63)<<"+++++++++++++++++++++++++++++++++++++++++\n";
	cout<<"\n"<<setw(30)<<"Menu : \n\n";

	for(int i = 0; i < menu ; i++){
		cout<<setw(22)<<i+1<<". "<<daftar_menu[i]<<endl;
	}
	cout<<"\n"<<setw(34)<<"Pilih Menu : ";
	cin>>pilih;
	cin.ignore();


	if(pilih >= (menu + 1) || pilih < 1){
		cout<<"\n"<<setw(43)<<"Pilihan Tidak Tersedia";
		getch();
		goto Menu;
	}else if(pilih == 1){
		tambah_pasien();
	}else if(pilih == 2){
		daftar_pasien();
	}else if(pilih == 3){
		cek_kode_pasien();
	}else if(pilih == 4){
		cari_pasien();
	}else if(pilih == 5){
		panggil_pasien();
		
	}else if(pilih == 6){
		cout<<"\n"<<setw(74)<<"Apakah Anda Yakin Ingin Keluar dar Program ? [y/n] : ";
		cin>>x;
		if(x == 'Y' || x == 'y'){
			exit(0);
		}else{
			goto Menu;
		}
	}
	goto Menu;

}