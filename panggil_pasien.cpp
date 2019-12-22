#include <iostream>
#include <string.h>
#include <conio.h>
#include <cstdio>
#include <stdlib.h>
#include <iomanip>
#include "tambah_pasien.cpp"

#define file_database "database_rumah_sakit.txt"
#define database_mata_1 "database_antrean_mata_s1.txt"
#define database_mata_2 "database_antrean_mata_s2.txt"
#define database_gigi_1 "database_antrean_gigi_s1.txt"
#define database_gigi_2 "database_antrean_gigi_s2.txt"
#define database_pd_1 "database_antrean_pd_s1.txt"
#define database_pd_2 "database_antrean_pd_s2.txt"
#define database_tht_1 "database_antrean_tht_s1.txt"
#define database_tht_2 "database_antrean_tht_s2.txt"
#define database_umum_1 "database_antrean_umum_s1.txt"
#define database_umum_2 "database_antrean_umum_s2.txt"
#define database_kandungan_1 "database_antrean_kandungan_s1.txt"
#define database_kandungan_2 "database_antrean_kandungan_s2.txt"


using namespace std;

struct dokter{
	string nama;
	string jam[10];
	string ruang[20];
	
};

int dokter_mata(char *kode_pasien){
	Mata:
	int pilih,last_antrean;
	FILE *handle;
	char x;
	struct _pasien pasien,tmp;
	
	struct dokter dokter_mata[] = {
		{
			"Dokter A",
			{"10.00","14.00"},
			"Ruang 5.3.4"
		},
		{
			"Dokter B",
			{"15.00","17.00"},
			"Ruang 5.4.4"
		}
	};

	#define daftar_dokter_mata (sizeof(dokter_mata)/sizeof(dokter_mata[0]))
	cout<<setw(63)<<"++++++++++++++++++++++++++++++++++++++\n\n";
	cout<<setw(45)<<"Daftar dokter Mata :\n\n";
	for(int i = 0 ; i < daftar_dokter_mata ; i++ ){
	
		cout<<setw(24)<<(i+1)<<". "<<dokter_mata[i].nama<<" ( "<<dokter_mata[i].jam[0]<<" - "<<dokter_mata[i].jam[1]
		<<" ) "<<" ( "<<dokter_mata[i].ruang[0]<<" ) "<<endl;
	}
	cout<<"\n"<<setw(38)<<"Pilih Dokter : ";
	cin>>pilih;
	if(pilih == 1){
		system("cls");
		cout<<setw(57)<<"++++++++++++++++++++++++++++++++\n";
		cout<<setw(57)<<"++        Data Antrean        ++\n";
		cout<<setw(58)<<"++++++++++++++++++++++++++++++++\n\n";
		cout<<setw(38)<<"Kode Pasien\t: "<<kode_pasien<<endl;
		cout<<setw(38)<<"Nama Dokter\t: "<<dokter_mata[0].nama<<endl;
		cout<<setw(38)<<"Jam Periksa\t: "<<dokter_mata[0].jam[0]<<" - "<<dokter_mata[0].jam[1]<<endl;
		cout<<setw(40)<<"Ruang Periksa\t: "<<dokter_mata[0].ruang[0]<<endl;
		cout<<"\n"<<setw(51)<<"Lanjut mengantri ? [y/n] : ";
		cin>>x;
		if(x == 'Y' || x == 'y'){
			handle = fopen(database_mata_1 , "r");
			if(handle == NULL){
				strcpy(pasien.antrean, "01A");
			}else{
				while(!feof(handle)){
					fread (&tmp, sizeof(struct _pasien), 1, handle);
				}
				last_antrean = atoi (tmp.antrean) + 1;
				sprintf(pasien.antrean, "%02dA", last_antrean);
			}
			fclose(handle);

			handle = fopen(database_mata_1, "a");
			fwrite(&pasien, sizeof(pasien), 1, handle);
			fclose(handle);

			system("cls");
			cout<<setw(60)<<"+++++++++++++++++++++++++++++++++++++++++\n";
			cout<<setw(60)<<"++      Struct Antrean RS Harapan      ++\n";
			cout<<setw(61)<<"+++++++++++++++++++++++++++++++++++++++++\n\n";
			cout<<setw(41)<<"Nomor Antrean\t: "<<pasien.antrean<<endl;
			cout<<setw(39)<<"Kode Pasien\t: "<<kode_pasien<<endl;
			cout<<setw(39)<<"Nama Dokter\t: "<<dokter_mata[0].nama<<endl;
			cout<<setw(39)<<"Jam Periksa\t: "<<dokter_mata[0].jam[0]<<" - "<<dokter_mata[0].jam[1]<<endl;
			cout<<setw(41)<<"Ruang Periksa\t: "<<dokter_mata[0].ruang[0]<<endl;
			cout<<"\n"<<setw(59)<<"+++++++++++++++++++++++++++++++++++++++++";
			return 0;


		}else{
			cout<<"\n"<<setw(61)<<"Silahkan masukkan ulang pilihan Anda\n";
			getch();
			goto Mata;
		}
	}else if(pilih == 2 ){
		system("cls");
		cout<<setw(57)<<"++++++++++++++++++++++++++++++++\n";
		cout<<setw(57)<<"++        Data Antrean        ++\n";
		cout<<setw(58)<<"++++++++++++++++++++++++++++++++\n\n";
		cout<<setw(38)<<"Kode Pasien\t: "<<kode_pasien<<endl;
		cout<<setw(38)<<"Nama Dokter\t: "<<dokter_mata[1].nama<<endl;
		cout<<setw(38)<<"Jam Periksa\t: "<<dokter_mata[1].jam[0]<<" - "<<dokter_mata[1].jam[1]<<endl;
		cout<<setw(40)<<"Ruang Periksa\t: "<<dokter_mata[1].ruang[0]<<endl;
		cout<<"\n"<<setw(51)<<"Lanjut mengantri ? [y/n] : ";
		cin>>x;
		if(x == 'Y' || x == 'y'){
			handle = fopen(database_mata_2 , "r");
			if(handle == NULL){
				strcpy(pasien.antrean, "01A");
			}else{
				while(!feof(handle)){
					fread (&tmp, sizeof(struct _pasien), 1, handle);
				}
				last_antrean = atoi (tmp.antrean) + 1;
				sprintf(pasien.antrean, "%02dA", last_antrean);
			}
			fclose(handle);

			handle = fopen(database_mata_2, "a");
			fwrite(&pasien, sizeof(pasien), 1, handle);
			fclose(handle);

			system("cls");
			cout<<setw(60)<<"+++++++++++++++++++++++++++++++++++++++++\n";
			cout<<setw(60)<<"++      Struct Antrean RS Harapan      ++\n";
			cout<<setw(61)<<"+++++++++++++++++++++++++++++++++++++++++\n\n";
			cout<<setw(41)<<"Nomor Antrean\t: "<<pasien.antrean<<endl;
			cout<<setw(39)<<"Kode Pasien\t: "<<kode_pasien<<endl;
			cout<<setw(39)<<"Nama Dokter\t: "<<dokter_mata[1].nama<<endl;
			cout<<setw(39)<<"Jam Periksa\t: "<<dokter_mata[1].jam[0]<<" - "<<dokter_mata[1].jam[1]<<endl;
			cout<<setw(41)<<"Ruang Periksa\t: "<<dokter_mata[1].ruang[0]<<endl;
			cout<<"\n"<<setw(59)<<"+++++++++++++++++++++++++++++++++++++++++";
			return 0;


		}else{
			cout<<"\n"<<setw(61)<<"Silahkan masukkan ulang pilihan Anda\n\n";
			getch();
			goto Mata;
		}
	}else{
		cout<<"\n"<<setw(74)<<"Incorrect number, please enter the correct number!\n";
		getch();
		cout<<"\n";
		goto Mata;
	}
	return 0;
}

int dokter_gigi(char *kode_pasien){
	Gigi:
	int pilih,last_antrean;
	FILE *handle;
	char x;
	struct _pasien pasien,tmp;
	struct dokter dokter_gigi[] = {
		{
			"Dokter C",
			{"10.00","14.00"},
			"Ruang 5.3.4"
		},
		{
			"Dokter D",
			{"15.00","17.00"},
			"Ruang 5.4.4"
		}
	};

	#define daftar_dokter_gigi (sizeof(dokter_gigi)/sizeof(dokter_gigi[0]))
	cout<<setw(63)<<"++++++++++++++++++++++++++++++++++++++\n\n";
	cout<<setw(45)<<"Daftar dokter Gigi :\n\n";
	for(int i = 0 ; i < daftar_dokter_gigi ; i++ ){
	
		cout<<setw(24)<<(i+1)<<". "<<dokter_gigi[i].nama<<" ( "<<dokter_gigi[i].jam[0]<<" - "<<dokter_gigi[i].jam[1]
		<<" ) "<<" ( "<<dokter_gigi[i].ruang[0]<<" ) "<<endl;
	}
	cout<<"\n"<<setw(38)<<"Pilih Dokter : ";
	cin>>pilih;
	if(pilih == 1){
		system("cls");
		cout<<setw(57)<<"++++++++++++++++++++++++++++++++\n";
		cout<<setw(57)<<"++        Data Antrean        ++\n";
		cout<<setw(58)<<"++++++++++++++++++++++++++++++++\n\n";
		cout<<setw(38)<<"Kode Pasien\t: "<<kode_pasien<<endl;
		cout<<setw(38)<<"Nama Dokter\t: "<<dokter_gigi[0].nama<<endl;
		cout<<setw(38)<<"Jam Periksa\t: "<<dokter_gigi[0].jam[0]<<" - "<<dokter_gigi[0].jam[1]<<endl;
		cout<<setw(40)<<"Ruang Periksa\t: "<<dokter_gigi[0].ruang[0]<<endl;
		cout<<"\n"<<setw(51)<<"Lanjut mengantri ? [y/n] : ";
		cin>>x;
		if(x == 'Y' || x == 'y'){
			handle = fopen(database_gigi_1 , "r");
			if(handle == NULL){
				strcpy(pasien.antrean, "01A");
			}else{
				while(!feof(handle)){
					fread (&tmp, sizeof(struct _pasien), 1, handle);
				}
				last_antrean = atoi (tmp.antrean) + 1;
				sprintf(pasien.antrean, "%02dA", last_antrean);
			}
			fclose(handle);

			handle = fopen(database_gigi_1, "a");
			fwrite(&pasien, sizeof(pasien), 1, handle);
			fclose(handle);

			system("cls");
			cout<<setw(60)<<"+++++++++++++++++++++++++++++++++++++++++\n";
			cout<<setw(60)<<"++      Struct Antrean RS Harapan      ++\n";
			cout<<setw(61)<<"+++++++++++++++++++++++++++++++++++++++++\n\n";
			cout<<setw(41)<<"Nomor Antrean\t: "<<pasien.antrean<<endl;
			cout<<setw(39)<<"Kode Pasien\t: "<<kode_pasien<<endl;
			cout<<setw(39)<<"Nama Dokter\t: "<<dokter_gigi[0].nama<<endl;
			cout<<setw(39)<<"Jam Periksa\t: "<<dokter_gigi[0].jam[0]<<" - "<<dokter_gigi[0].jam[1]<<endl;
			cout<<setw(41)<<"Ruang Periksa\t: "<<dokter_gigi[0].ruang[0]<<endl;
			cout<<"\n"<<setw(59)<<"+++++++++++++++++++++++++++++++++++++++++";
			return 0;


		}else{
			cout<<"\n"<<setw(61)<<"Silahkan masukkan ulang pilihan Anda\n";
			getch();
			goto Gigi;
		}


	}else if(pilih == 2 ){
		system("cls");
		cout<<setw(57)<<"++++++++++++++++++++++++++++++++\n";
		cout<<setw(57)<<"++        Data Antrean        ++\n";
		cout<<setw(58)<<"++++++++++++++++++++++++++++++++\n\n";
		cout<<setw(38)<<"Kode Pasien\t: "<<kode_pasien<<endl;
		cout<<setw(38)<<"Nama Dokter\t: "<<dokter_gigi[1].nama<<endl;
		cout<<setw(38)<<"Jam Periksa\t: "<<dokter_gigi[1].jam[0]<<" - "<<dokter_gigi[1].jam[1]<<endl;
		cout<<setw(40)<<"Ruang Periksa\t: "<<dokter_gigi[1].ruang[0]<<endl;
		cout<<"\n"<<setw(51)<<"Lanjut mengantri ? [y/n] : ";
		cin>>x;
		if(x == 'Y' || x == 'y'){
			handle = fopen(database_gigi_2 , "r");
			if(handle == NULL){
				strcpy(pasien.antrean, "01A");
			}else{
				while(!feof(handle)){
					fread (&tmp, sizeof(struct _pasien), 1, handle);
				}
				last_antrean = atoi (tmp.antrean) + 1;
				sprintf(pasien.antrean, "%02dA", last_antrean);
			}
			fclose(handle);

			handle = fopen(database_gigi_2, "a");
			fwrite(&pasien, sizeof(pasien), 1, handle);
			fclose(handle);

			system("cls");
			cout<<setw(60)<<"+++++++++++++++++++++++++++++++++++++++++\n";
			cout<<setw(60)<<"++      Struct Antrean RS Harapan      ++\n";
			cout<<setw(61)<<"+++++++++++++++++++++++++++++++++++++++++\n\n";
			cout<<setw(41)<<"Nomor Antrean\t: "<<pasien.antrean<<endl;
			cout<<setw(39)<<"Kode Pasien\t: "<<kode_pasien<<endl;
			cout<<setw(39)<<"Nama Dokter\t: "<<dokter_gigi[1].nama<<endl;
			cout<<setw(39)<<"Jam Periksa\t: "<<dokter_gigi[1].jam[0]<<" - "<<dokter_gigi[1].jam[1]<<endl;
			cout<<setw(41)<<"Ruang Periksa\t: "<<dokter_gigi[1].ruang[0]<<endl;
			cout<<"\n"<<setw(59)<<"+++++++++++++++++++++++++++++++++++++++++";
			return 0;

		}else{
			cout<<"\n"<<setw(61)<<"Silahkan masukkan ulang pilihan Anda\n";
			getch();
			goto Gigi;
		}

	}else{
		cout<<"\n"<<setw(74)<<"Incorrect number, please enter the correct number!\n";
		getch();
		cout<<"\n";
		goto Gigi;
	}
	return 0;
}

int dokter_pd(char *kode_pasien){
	Pd:
	int pilih,last_antrean;
	FILE *handle;
	char x;
	struct _pasien pasien,tmp;
	struct dokter dokter_pd[] = {
		{
			"Dokter E",
			{"10.00","14.00"},
			"Ruang 5.3.4"
		},
		{
			"Dokter F",
			{"15.00","17.00"},
			"Ruang 5.4.4"
		}
	};

	#define daftar_dokter_pd (sizeof(dokter_pd)/sizeof(dokter_pd[0]))
	cout<<setw(63)<<"++++++++++++++++++++++++++++++++++++++\n\n";
	cout<<setw(55)<<"Daftar dokter Penyakit Dalam :\n\n";
	for(int i = 0 ; i < daftar_dokter_pd ; i++ ){
	
		cout<<setw(24)<<(i+1)<<". "<<dokter_pd[i].nama<<" ( "<<dokter_pd[i].jam[0]<<" - "<<dokter_pd[i].jam[1]
		<<" ) "<<" ( "<<dokter_pd[i].ruang[0]<<" ) "<<endl;
	}
	cout<<"\n"<<setw(38)<<"Pilih Dokter : ";
	cin>>pilih;
	if(pilih == 1){
		system("cls");
		cout<<setw(57)<<"++++++++++++++++++++++++++++++++\n";
		cout<<setw(57)<<"++        Data Antrean        ++\n";
		cout<<setw(58)<<"++++++++++++++++++++++++++++++++\n\n";
		cout<<setw(38)<<"Kode Pasien\t: "<<kode_pasien<<endl;
		cout<<setw(38)<<"Nama Dokter\t: "<<dokter_pd[0].nama<<endl;
		cout<<setw(38)<<"Jam Periksa\t: "<<dokter_pd[0].jam[0]<<" - "<<dokter_pd[0].jam[1]<<endl;
		cout<<setw(40)<<"Ruang Periksa\t: "<<dokter_pd[0].ruang[0]<<endl;
		cout<<"\n"<<setw(51)<<"Lanjut mengantri ? [y/n] : ";
		cin>>x;
		if(x == 'Y' || x == 'y'){
			handle = fopen(database_pd_1 , "r");
			if(handle == NULL){
				strcpy(pasien.antrean, "01A");
			}else{
				while(!feof(handle)){
					fread (&tmp, sizeof(struct _pasien), 1, handle);
				}
				last_antrean = atoi (tmp.antrean) + 1;
				sprintf(pasien.antrean, "%02dA", last_antrean);
			}
			fclose(handle);

			handle = fopen(database_pd_1, "a");
			fwrite(&pasien, sizeof(pasien), 1, handle);
			fclose(handle);

			system("cls");
			cout<<setw(60)<<"+++++++++++++++++++++++++++++++++++++++++\n";
			cout<<setw(60)<<"++      Struct Antrean RS Harapan      ++\n";
			cout<<setw(61)<<"+++++++++++++++++++++++++++++++++++++++++\n\n";
			cout<<setw(41)<<"Nomor Antrean\t: "<<pasien.antrean<<endl;
			cout<<setw(39)<<"Kode Pasien\t: "<<kode_pasien<<endl;
			cout<<setw(39)<<"Nama Dokter\t: "<<dokter_pd[0].nama<<endl;
			cout<<setw(39)<<"Jam Periksa\t: "<<dokter_pd[0].jam[0]<<" - "<<dokter_pd[0].jam[1]<<endl;
			cout<<setw(41)<<"Ruang Periksa\t: "<<dokter_pd[0].ruang[0]<<endl;
			cout<<"\n"<<setw(59)<<"+++++++++++++++++++++++++++++++++++++++++";
			return 0;


		}else{
			cout<<"\n"<<setw(61)<<"Silahkan masukkan ulang pilihan Anda\n";
			getch();
			goto Pd;
		}
	}else if(pilih == 2 ){
		system("cls");
		cout<<setw(57)<<"++++++++++++++++++++++++++++++++\n";
		cout<<setw(57)<<"++        Data Antrean        ++\n";
		cout<<setw(58)<<"++++++++++++++++++++++++++++++++\n\n";
		cout<<setw(38)<<"Kode Pasien\t: "<<kode_pasien<<endl;
		cout<<setw(38)<<"Nama Dokter\t: "<<dokter_pd[1].nama<<endl;
		cout<<setw(38)<<"Jam Periksa\t: "<<dokter_pd[1].jam[0]<<" - "<<dokter_pd[1].jam[1]<<endl;
		cout<<setw(40)<<"Ruang Periksa\t: "<<dokter_pd[1].ruang[0]<<endl;
		cout<<"\n"<<setw(51)<<"Lanjut mengantri ? [y/n] : ";
		cin>>x;
		if(x == 'Y' || x == 'y'){
			handle = fopen(database_pd_2 , "r");
			if(handle == NULL){
				strcpy(pasien.antrean, "01A");
			}else{
				while(!feof(handle)){
					fread (&tmp, sizeof(struct _pasien), 1, handle);
				}
				last_antrean = atoi (tmp.antrean) + 1;
				sprintf(pasien.antrean, "%02dA", last_antrean);
			}
			fclose(handle);

			handle = fopen(database_pd_2, "a");
			fwrite(&pasien, sizeof(pasien), 1, handle);
			fclose(handle);

			system("cls");
			cout<<setw(60)<<"+++++++++++++++++++++++++++++++++++++++++\n";
			cout<<setw(60)<<"++      Struct Antrean RS Harapan      ++\n";
			cout<<setw(61)<<"+++++++++++++++++++++++++++++++++++++++++\n\n";
			cout<<setw(41)<<"Nomor Antrean\t: "<<pasien.antrean<<endl;
			cout<<setw(39)<<"Kode Pasien\t: "<<kode_pasien<<endl;
			cout<<setw(39)<<"Nama Dokter\t: "<<dokter_pd[1].nama<<endl;
			cout<<setw(39)<<"Jam Periksa\t: "<<dokter_pd[1].jam[0]<<" - "<<dokter_pd[1].jam[1]<<endl;
			cout<<setw(41)<<"Ruang Periksa\t: "<<dokter_pd[1].ruang[0]<<endl;
			cout<<"\n"<<setw(59)<<"+++++++++++++++++++++++++++++++++++++++++";
			return 0;

		}else{
			cout<<"\n"<<setw(61)<<"Silahkan masukkan ulang pilihan Anda\n";
			getch();
			goto Pd;
		}
	}else{
		cout<<"\n"<<setw(74)<<"Incorrect number, please enter the correct number!\n";
		getch();
		cout<<"\n";
		goto Pd;
	}
	return 0;
}

int dokter_tht(char *kode_pasien){
	THT:
	int pilih,last_antrean;
	FILE *handle;
	char x;
	struct _pasien pasien,tmp;
	struct dokter dokter_tht[] = {
		{
			"Dokter G",
			{"10.00","14.00"},
			"Ruang 5.3.4"
		},
		{
			"Dokter H",
			{"15.00","17.00"},
			"Ruang 5.4.4"
		}
	};

	#define daftar_dokter_tht (sizeof(dokter_tht)/sizeof(dokter_tht[0]))
	cout<<setw(63)<<"++++++++++++++++++++++++++++++++++++++\n\n";
	cout<<setw(44)<<"Daftar dokter THT :\n\n";
	for(int i = 0 ; i < daftar_dokter_tht ; i++ ){
	
		cout<<setw(24)<<(i+1)<<". "<<dokter_tht[i].nama<<" ( "<<dokter_tht[i].jam[0]<<" - "<<dokter_tht[i].jam[1]
		<<" ) "<<" ( "<<dokter_tht[i].ruang[0]<<" ) "<<endl;
	}
	cout<<"\n"<<setw(38)<<"Pilih Dokter : ";
	cin>>pilih;
	if(pilih == 1){
		system("cls");
		cout<<setw(57)<<"++++++++++++++++++++++++++++++++\n";
		cout<<setw(57)<<"++        Data Antrean        ++\n";
		cout<<setw(58)<<"++++++++++++++++++++++++++++++++\n\n";
		cout<<setw(38)<<"Kode Pasien\t: "<<kode_pasien<<endl;
		cout<<setw(38)<<"Nama Dokter\t: "<<dokter_tht[0].nama<<endl;
		cout<<setw(38)<<"Jam Periksa\t: "<<dokter_tht[0].jam[0]<<" - "<<dokter_tht[0].jam[1]<<endl;
		cout<<setw(40)<<"Ruang Periksa\t: "<<dokter_tht[0].ruang[0]<<endl;
		cout<<"\n"<<setw(51)<<"Lanjut mengantri ? [y/n] : ";
		cin>>x;
		if(x == 'Y' || x == 'y'){
			handle = fopen(database_tht_1 , "r");
			if(handle == NULL){
				strcpy(pasien.antrean, "01A");
			}else{
				while(!feof(handle)){
					fread (&tmp, sizeof(struct _pasien), 1, handle);
				}
				last_antrean = atoi (tmp.antrean) + 1;
				sprintf(pasien.antrean, "%02dA", last_antrean);
			}
			fclose(handle);

			handle = fopen(database_tht_1, "a");
			fwrite(&pasien, sizeof(pasien), 1, handle);
			fclose(handle);

			system("cls");
			cout<<setw(60)<<"+++++++++++++++++++++++++++++++++++++++++\n";
			cout<<setw(60)<<"++      Struct Antrean RS Harapan      ++\n";
			cout<<setw(61)<<"+++++++++++++++++++++++++++++++++++++++++\n\n";
			cout<<setw(41)<<"Nomor Antrean\t: "<<pasien.antrean<<endl;
			cout<<setw(39)<<"Kode Pasien\t: "<<kode_pasien<<endl;
			cout<<setw(39)<<"Nama Dokter\t: "<<dokter_tht[0].nama<<endl;
			cout<<setw(39)<<"Jam Periksa\t: "<<dokter_tht[0].jam[0]<<" - "<<dokter_tht[0].jam[1]<<endl;
			cout<<setw(41)<<"Ruang Periksa\t: "<<dokter_tht[0].ruang[0]<<endl;
			cout<<"\n"<<setw(59)<<"+++++++++++++++++++++++++++++++++++++++++";
			return 0;


		}else{
			cout<<"\n"<<setw(61)<<"Silahkan masukkan ulang pilihan Anda\n";
			getch();
			goto THT;
		}
	}else if(pilih == 2 ){
		system("cls");
		cout<<setw(57)<<"++++++++++++++++++++++++++++++++\n";
		cout<<setw(57)<<"++        Data Antrean        ++\n";
		cout<<setw(58)<<"++++++++++++++++++++++++++++++++\n\n";
		cout<<setw(38)<<"Kode Pasien\t: "<<kode_pasien<<endl;
		cout<<setw(38)<<"Nama Dokter\t: "<<dokter_tht[1].nama<<endl;
		cout<<setw(38)<<"Jam Periksa\t: "<<dokter_tht[1].jam[0]<<" - "<<dokter_tht[1].jam[1]<<endl;
		cout<<setw(40)<<"Ruang Periksa\t: "<<dokter_tht[1].ruang[0]<<endl;
		cout<<"\n"<<setw(51)<<"Lanjut mengantri ? [y/n] : ";
		cin>>x;
		if(x == 'Y' || x == 'y'){
			handle = fopen(database_tht_2 , "r");
			if(handle == NULL){
				strcpy(pasien.antrean, "01A");
			}else{
				while(!feof(handle)){
					fread (&tmp, sizeof(struct _pasien), 1, handle);
				}
				last_antrean = atoi (tmp.antrean) + 1;
				sprintf(pasien.antrean, "%02dA", last_antrean);
			}
			fclose(handle);

			handle = fopen(database_tht_2, "a");
			fwrite(&pasien, sizeof(pasien), 1, handle);
			fclose(handle);

			system("cls");
			cout<<setw(60)<<"+++++++++++++++++++++++++++++++++++++++++\n";
			cout<<setw(60)<<"++      Struct Antrean RS Harapan      ++\n";
			cout<<setw(61)<<"+++++++++++++++++++++++++++++++++++++++++\n\n";
			cout<<setw(41)<<"Nomor Antrean\t: "<<pasien.antrean<<endl;
			cout<<setw(39)<<"Kode Pasien\t: "<<kode_pasien<<endl;
			cout<<setw(39)<<"Nama Dokter\t: "<<dokter_tht[1].nama<<endl;
			cout<<setw(39)<<"Jam Periksa\t: "<<dokter_tht[1].jam[0]<<" - "<<dokter_tht[1].jam[1]<<endl;
			cout<<setw(41)<<"Ruang Periksa\t: "<<dokter_tht[1].ruang[0]<<endl;
			cout<<"\n"<<setw(59)<<"+++++++++++++++++++++++++++++++++++++++++";
			return 0;

		}else{
			cout<<"\n"<<setw(61)<<"Silahkan masukkan ulang pilihan Anda\n";
			getch();
			goto THT;
		}
	}else{
		cout<<"\n"<<setw(74)<<"Incorrect number, please enter the correct number!\n";
		getch();
		cout<<"\n";
		goto THT;
	}
	return 0;
}

int dokter_umum(char *kode_pasien){
	Umum:
	int pilih,last_antrean;
	FILE *handle;
	char x;
	struct _pasien pasien,tmp;
	struct dokter dokter_umum[] = {
		{
			"Dokter I",
			{"10.00","14.00"},
			"Ruang 5.3.4"
		},
		{
			"Dokter J",
			{"15.00","17.00"},
			"Ruang 5.4.4"
		}
	};

	#define daftar_dokter_umum (sizeof(dokter_umum)/sizeof(dokter_umum[0]))
	cout<<setw(63)<<"++++++++++++++++++++++++++++++++++++++\n\n";
	cout<<setw(45)<<"Daftar dokter Umum :\n\n";
	for(int i = 0 ; i < daftar_dokter_umum ; i++ ){
	
		cout<<setw(24)<<(i+1)<<". "<<dokter_umum[i].nama<<" ( "<<dokter_umum[i].jam[0]<<" - "<<dokter_umum[i].jam[1]
		<<" ) "<<" ( "<<dokter_umum[i].ruang[0]<<" ) "<<endl;
	}
	cout<<"\n"<<setw(38)<<"Pilih Dokter : ";
	cin>>pilih;
	if(pilih == 1){
		system("cls");
		cout<<setw(57)<<"++++++++++++++++++++++++++++++++\n";
		cout<<setw(57)<<"++        Data Antrean        ++\n";
		cout<<setw(58)<<"++++++++++++++++++++++++++++++++\n\n";
		cout<<setw(38)<<"Kode Pasien\t: "<<kode_pasien<<endl;
		cout<<setw(38)<<"Nama Dokter\t: "<<dokter_umum[0].nama<<endl;
		cout<<setw(38)<<"Jam Periksa\t: "<<dokter_umum[0].jam[0]<<" - "<<dokter_umum[0].jam[1]<<endl;
		cout<<setw(40)<<"Ruang Periksa\t: "<<dokter_umum[0].ruang[0]<<endl;
		cout<<"\n"<<setw(51)<<"Lanjut mengantri ? [y/n] : ";
		cin>>x;
		if(x == 'Y' || x == 'y'){
			handle = fopen(database_umum_1 , "r");
			if(handle == NULL){
				strcpy(pasien.antrean, "01A");
			}else{
				while(!feof(handle)){
					fread (&tmp, sizeof(struct _pasien), 1, handle);
				}
				last_antrean = atoi (tmp.antrean) + 1;
				sprintf(pasien.antrean, "%02dA", last_antrean);
			}
			fclose(handle);

			handle = fopen(database_umum_1, "a");
			fwrite(&pasien, sizeof(pasien), 1, handle);
			fclose(handle);

			system("cls");
			cout<<setw(60)<<"+++++++++++++++++++++++++++++++++++++++++\n";
			cout<<setw(60)<<"++      Struct Antrean RS Harapan      ++\n";
			cout<<setw(61)<<"+++++++++++++++++++++++++++++++++++++++++\n\n";
			cout<<setw(41)<<"Nomor Antrean\t: "<<pasien.antrean<<endl;
			cout<<setw(39)<<"Kode Pasien\t: "<<kode_pasien<<endl;
			cout<<setw(39)<<"Nama Dokter\t: "<<dokter_umum[0].nama<<endl;
			cout<<setw(39)<<"Jam Periksa\t: "<<dokter_umum[0].jam[0]<<" - "<<dokter_umum[0].jam[1]<<endl;
			cout<<setw(41)<<"Ruang Periksa\t: "<<dokter_umum[0].ruang[0]<<endl;
			cout<<"\n"<<setw(59)<<"+++++++++++++++++++++++++++++++++++++++++";
			return 0;


		}else{
			cout<<"\n"<<setw(61)<<"Silahkan masukkan ulang pilihan Anda\n";
			getch();
			goto Umum;
		}
	}else if(pilih == 2 ){
		system("cls");
		system("cls");
		cout<<setw(57)<<"++++++++++++++++++++++++++++++++\n";
		cout<<setw(57)<<"++        Data Antrean        ++\n";
		cout<<setw(58)<<"++++++++++++++++++++++++++++++++\n\n";
		cout<<setw(38)<<"Kode Pasien\t: "<<kode_pasien<<endl;
		cout<<setw(38)<<"Nama Dokter\t: "<<dokter_umum[1].nama<<endl;
		cout<<setw(38)<<"Jam Periksa\t: "<<dokter_umum[1].jam[0]<<" - "<<dokter_umum[1].jam[1]<<endl;
		cout<<setw(40)<<"Ruang Periksa\t: "<<dokter_umum[1].ruang[0]<<endl;
		cout<<"\n"<<setw(51)<<"Lanjut mengantri ? [y/n] : ";
		cin>>x;
		if(x == 'Y' || x == 'y'){
			handle = fopen(database_umum_2 , "r");
			if(handle == NULL){
				strcpy(pasien.antrean, "01A");
			}else{
				while(!feof(handle)){
					fread (&tmp, sizeof(struct _pasien), 1, handle);
				}
				last_antrean = atoi (tmp.antrean) + 1;
				sprintf(pasien.antrean, "%02dA", last_antrean);
			}
			fclose(handle);

			handle = fopen(database_umum_2, "a");
			fwrite(&pasien, sizeof(pasien), 1, handle);
			fclose(handle);

			system("cls");
			cout<<setw(60)<<"+++++++++++++++++++++++++++++++++++++++++\n";
			cout<<setw(60)<<"++      Struct Antrean RS Harapan      ++\n";
			cout<<setw(61)<<"+++++++++++++++++++++++++++++++++++++++++\n\n";
			cout<<setw(41)<<"Nomor Antrean\t: "<<pasien.antrean<<endl;
			cout<<setw(39)<<"Kode Pasien\t: "<<kode_pasien<<endl;
			cout<<setw(39)<<"Nama Dokter\t: "<<dokter_umum[1].nama<<endl;
			cout<<setw(39)<<"Jam Periksa\t: "<<dokter_umum[1].jam[0]<<" - "<<dokter_umum[1].jam[1]<<endl;
			cout<<setw(41)<<"Ruang Periksa\t: "<<dokter_umum[1].ruang[0]<<endl;
			cout<<"\n"<<setw(59)<<"+++++++++++++++++++++++++++++++++++++++++";
			return 0;

		}else{
			cout<<"\n"<<setw(61)<<"Silahkan masukkan ulang pilihan Anda\n";
			getch();
			goto Umum;
		}

	}else{
		cout<<"\n"<<setw(74)<<"Incorrect number, please enter the correct number!\n";
		getch();
		cout<<"\n";
		goto Umum;
	}
	return 0;
}

int dokter_kandungan(char *kode_pasien){
	Kandungan:
	int pilih,last_antrean;
	FILE *handle;
	char x;
	struct _pasien pasien,tmp;
	struct dokter dokter_kandungan[] = {
		{
			"Dokter K",
			{"10.00","14.00"},
			"Ruang 5.3.4"
		},
		{
			"Dokter L",
			{"15.00","17.00"},
			"Ruang 5.4.4"
		}
	};

	#define daftar_dokter_kandungan (sizeof(dokter_kandungan)/sizeof(dokter_kandungan[0]))
	cout<<setw(63)<<"++++++++++++++++++++++++++++++++++++++\n\n";
	cout<<setw(50)<<"Daftar dokter Kandungan :\n\n";
	for(int i = 0 ; i < daftar_dokter_kandungan ; i++ ){
	
		cout<<setw(24)<<(i+1)<<". "<<dokter_kandungan[i].nama<<" ( "<<dokter_kandungan[i].jam[0]<<" - "<<dokter_kandungan[i].jam[1]
		<<" ) "<<" ( "<<dokter_kandungan[i].ruang[0]<<" ) "<<endl;
	}
	cout<<"\n"<<setw(38)<<"Pilih Dokter : ";
	cin>>pilih;
	if(pilih == 1){
		system("cls");
		cout<<setw(57)<<"++++++++++++++++++++++++++++++++\n";
		cout<<setw(57)<<"++        Data Antrean        ++\n";
		cout<<setw(58)<<"++++++++++++++++++++++++++++++++\n\n";
		cout<<setw(38)<<"Kode Pasien\t: "<<kode_pasien<<endl;
		cout<<setw(38)<<"Nama Dokter\t: "<<dokter_kandungan[0].nama<<endl;
		cout<<setw(38)<<"Jam Periksa\t: "<<dokter_kandungan[0].jam[0]<<" - "<<dokter_kandungan[0].jam[1]<<endl;
		cout<<setw(40)<<"Ruang Periksa\t: "<<dokter_kandungan[0].ruang[0]<<endl;
		cout<<"\n"<<setw(51)<<"Lanjut mengantri ? [y/n] : ";
		cin>>x;
		if(x == 'Y' || x == 'y'){
			handle = fopen(database_kandungan_1 , "r");
			if(handle == NULL){
				strcpy(pasien.antrean, "01A");
			}else{
				while(!feof(handle)){
					fread (&tmp, sizeof(struct _pasien), 1, handle);
				}
				last_antrean = atoi (tmp.antrean) + 1;
				sprintf(pasien.antrean, "%02dA", last_antrean);
			}
			fclose(handle);

			handle = fopen(database_kandungan_1, "a");
			fwrite(&pasien, sizeof(pasien), 1, handle);
			fclose(handle);

			system("cls");
			cout<<setw(60)<<"+++++++++++++++++++++++++++++++++++++++++\n";
			cout<<setw(60)<<"++      Struct Antrean RS Harapan      ++\n";
			cout<<setw(61)<<"+++++++++++++++++++++++++++++++++++++++++\n\n";
			cout<<setw(41)<<"Nomor Antrean\t: "<<pasien.antrean<<endl;
			cout<<setw(39)<<"Kode Pasien\t: "<<kode_pasien<<endl;
			cout<<setw(39)<<"Nama Dokter\t: "<<dokter_kandungan[0].nama<<endl;
			cout<<setw(39)<<"Jam Periksa\t: "<<dokter_kandungan[0].jam[0]<<" - "<<dokter_kandungan[0].jam[1]<<endl;
			cout<<setw(41)<<"Ruang Periksa\t: "<<dokter_kandungan[0].ruang[0]<<endl;
			cout<<"\n"<<setw(59)<<"+++++++++++++++++++++++++++++++++++++++++";
			return 0;


		}else{
			cout<<"\n"<<setw(61)<<"Silahkan masukkan ulang pilihan Anda\n";
			getch();
			goto Kandungan;
		}
	}else if(pilih == 2 ){
		system("cls");
		cout<<setw(57)<<"++++++++++++++++++++++++++++++++\n";
		cout<<setw(57)<<"++        Data Antrean        ++\n";
		cout<<setw(58)<<"++++++++++++++++++++++++++++++++\n\n";
		cout<<setw(38)<<"Kode Pasien\t: "<<kode_pasien<<endl;
		cout<<setw(38)<<"Nama Dokter\t: "<<dokter_kandungan[1].nama<<endl;
		cout<<setw(38)<<"Jam Periksa\t: "<<dokter_kandungan[1].jam[0]<<" - "<<dokter_kandungan[1].jam[1]<<endl;
		cout<<setw(40)<<"Ruang Periksa\t: "<<dokter_kandungan[1].ruang[0]<<endl;
		cout<<"\n"<<setw(51)<<"Lanjut mengantri ? [y/n] : ";
		cin>>x;
		if(x == 'Y' || x == 'y'){
			handle = fopen(database_kandungan_2 , "r");
			if(handle == NULL){
				strcpy(pasien.antrean, "01A");
			}else{
				while(!feof(handle)){
					fread (&tmp, sizeof(struct _pasien), 1, handle);
				}
				last_antrean = atoi (tmp.antrean) + 1;
				sprintf(pasien.antrean, "%02dA", last_antrean);
			}
			fclose(handle);

			handle = fopen(database_kandungan_2, "a");
			fwrite(&pasien, sizeof(pasien), 1, handle);
			fclose(handle);

			system("cls");
			cout<<setw(60)<<"+++++++++++++++++++++++++++++++++++++++++\n";
			cout<<setw(60)<<"++      Struct Antrean RS Harapan      ++\n";
			cout<<setw(61)<<"+++++++++++++++++++++++++++++++++++++++++\n\n";
			cout<<setw(41)<<"Nomor Antrean\t: "<<pasien.antrean<<endl;
			cout<<setw(39)<<"Kode Pasien\t: "<<kode_pasien<<endl;
			cout<<setw(39)<<"Nama Dokter\t: "<<dokter_kandungan[1].nama<<endl;
			cout<<setw(39)<<"Jam Periksa\t: "<<dokter_kandungan[1].jam[0]<<" - "<<dokter_kandungan[1].jam[1]<<endl;
			cout<<setw(41)<<"Ruang Periksa\t: "<<dokter_kandungan[1].ruang[0]<<endl;
			cout<<"\n"<<setw(59)<<"+++++++++++++++++++++++++++++++++++++++++";
			return 0;

		}else{
			cout<<"\n"<<setw(61)<<"Silahkan masukkan ulang pilihan Anda\n";
			getch();
			goto Kandungan;
		}
	}else{
		cout<<"\n"<<setw(74)<<"Incorrect number, please enter the correct number!\n";
		getch();
		cout<<"\n";
		goto Kandungan;
	}
	return 0;
}

int antrean(char *kode_pasien){
	int keluhan;
	string _penyakit [] = {
	"Mata",
	"Gigi",
	"Penyakit Dalam",
	"THT",
	"Umum",
	"Kandungan"
	
	};

	#define penyakit (sizeof(_penyakit)/sizeof(_penyakit[0]))

	keluhan:
	cout<<"\n"<<setw(62)<<"++++++++++++++++++++++++++++++++++++++\n";
	cout<<"\n"<<setw(42)<<"Pilihan Keluhan :\n\n";
	for(int i = 0; i < penyakit ; i++ ){
		cout<<setw(24)<<i+1<<". "<<_penyakit[i]<<endl;
	}
	cout<<"\n\n"<<setw(35)<<"99. Kembali\n";
	cout<<"\n"<<setw(62)<<"++++++++++++++++++++++++++++++++++++++\n";
	cout<<"\n"<<setw(31)<<"Pilih : ";
	cin>>keluhan;
	cout<<"\n";
	if(keluhan == 1){
		dokter_mata(kode_pasien);

	}else if(keluhan == 2){
		dokter_gigi(kode_pasien);

	}else if(keluhan == 3){
		dokter_pd(kode_pasien);

	}else if(keluhan == 4){
		dokter_tht(kode_pasien);

	}else if(keluhan == 5){
		dokter_umum(kode_pasien);

	}else if(keluhan == 6){
		dokter_kandungan(kode_pasien);

	}else if(keluhan == 99){
		cout<<setw(43)<<"Press Enter to Back!";
		return 0;
		
	}else{

		cout<<"\n"<<setw(69)<<"Wrong Number, Please Input the correct Number!";
		getch();
		cout<<"\n";
		goto keluhan;

	}
	return 0;
}



void panggil_pasien(){
	
	FILE *handle;
	char buffer[1024],kode_pasien[8];
	struct _pasien pasien;
	unsigned int nread;
	bool found = false;

	input:
	system("cls");
	cout<<setw(62)<<"++++++++++++++++++++++++++++++++++++++\n";
	cout<<setw(62)<<"++      PROGRAM ANTREAN PASIEN      ++\n";
	cout<<setw(63)<<"++++++++++++++++++++++++++++++++++++++\n\n";
	cout<<setw(46)<<"Masukkan kode pasien : ";
	fgets(kode_pasien, 1023, stdin);

	if(*kode_pasien == 0xa ){
		cout<<"\n"<<setw(51)<<"Masukkan kode dengan benar !";
		getch();
		goto input;;
	}
	kode_pasien[strlen(kode_pasien) - 1] = '\0';

	handle = fopen(file_database, "r");
	if(handle == NULL){
		cout<<"Database Kosong";
	}else{
		while(!feof(handle)){
			fread(&pasien , sizeof(pasien), 1, handle);
			if(!strcmp(pasien.kode, kode_pasien)){
			found = true;
			antrean(kode_pasien);
			}
		}
		if(!found){
		cout<<"\n"<<setw(38)<<"Kode Anda salah";
		cout<<"\n"<<setw(51)<<"Masukkan kode dengan benar !";
		getch();
		goto input;
		}
		
	}
	
	
	getch();

}