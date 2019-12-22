#include <iostream>
#include <string.h>
#include <conio.h>
#include <cstdio>
#include <stdlib.h>
#include <iomanip>
#include "tambah_pasien.cpp"

#define file_database "database_rumah_sakit.txt"


using namespace std;

int cari_pasien(){
	system("cls");
	FILE *handle;
	int i=1;
	char input_kode[8];
	struct _pasien pasien;
	unsigned int nread;

	cari:
	cout<<setw(57)<<"+++++++++++++++++++++++++++++\n";
	cout<<setw(57)<<"++       CARI PASIEN       ++\n";
	cout<<setw(57)<<"+++++++++++++++++++++++++++++\n";
	cout<<"\n"<<setw(50)<<"Masukkan kode pasien : ";
	fgets(input_kode, 1023, stdin);
	cout<<"\n";

	if(*input_kode == 0xa && *(input_kode + 1) == '\0'){
		cout<<setw(55)<<"Masukkan kode dengan benar !";
		getch();
		system("cls");
		goto cari;
	}
	input_kode[strlen(input_kode) - 1] = '\0';

	handle = fopen(file_database, "r");
	if(handle == NULL){
		cout<<"Database Kosong";
	}else{
		while(!feof(handle)){
			nread = fread(&pasien, sizeof(pasien), 1, handle);
			if(nread == 0){
				break;
			}
			if(strstr(pasien.kode, input_kode)){
				cout<<setw(43)<<"+ Nama Pasien\t: "<<pasien.nama<<endl;
				cout<<setw(44)<<"+ No ID Pasien\t: "<<pasien.id<<endl;
				cout<<setw(43)<<"+ Umur Pasien\t: "<<pasien.umur<<endl;
				cout<<setw(45)<<"+ Alamat Pasien\t: "<<pasien.alamat<<endl;
				cout<<setw(43)<<"+ TTL Pasien \t: "<<pasien.ttl<<endl;
				i++;
				
			}

		}
		i--;
		if( i == 0){
			cout<<"\n"<<setw(48)<<"Kode tidak ditemukan\n";
		}
		cout<<"\n"<<setw(61)<<"Press Enter to Back to Main Menu !";
	
	}
	fclose(handle);
	getch();
	return 0;
}