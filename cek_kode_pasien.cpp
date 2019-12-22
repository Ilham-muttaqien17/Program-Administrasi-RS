#include <iostream>
#include <string.h>
#include <conio.h>
#include <cstdio>
#include <stdlib.h>
#include <iomanip>
#include "tambah_pasien.cpp"

#define file_database "database_rumah_sakit.txt"


using namespace std;

int cek_kode_pasien(){
	system("cls");
	FILE *handle;
	int i=1;
	char input_nama[8];
	struct _pasien pasien;
	unsigned int nread;

	cek:
	cout<<setw(59)<<"+++++++++++++++++++++++++++++++++\n";
	cout<<setw(59)<<"++       CEK KODE PASIEN       ++\n";
	cout<<setw(59)<<"+++++++++++++++++++++++++++++++++\n";
	
	cout<<"\n"<<setw(48)<<"Masukkan nama pasien : ";
	fgets(input_nama, 1023, stdin);
	cout<<"\n";

	if(*input_nama == 0xa && *(input_nama + 1) == '\0'){
		cout<<setw(53)<<"Inputan tidak boleh kosong !";
		getch();
		system("cls");
		goto cek;
	}
	input_nama[strlen(input_nama) - 1] = '\0';

	handle = fopen(file_database, "r");
	if(handle == NULL){
		cout<<"Database Kosong";
	}else{
		while(!feof(handle)){
			nread = fread(&pasien, sizeof(pasien), 1, handle);
			if(nread == 0){
				break;
			}
			if(strstr(pasien.nama, input_nama)){
				cout<<setw(26)<<i<<". "<<" ( "<<pasien.kode<<" ) "<<pasien.nama<<endl;
				i++;
			}
		}
		i--;
		if(i == 0){
			cout<<"\n"<<setw(59)<<"Tidak ditemukan data dengan nama \""<<input_nama<<"\"";
			
		}else{
			cout<<"\n"<<setw(35)<<"Ditemukan "<<i<<" data dengan inputan \""<<input_nama<<"\"\n";

		}
	}
	fclose(handle);
	getch();
	return 0;
}