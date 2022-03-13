/*EL2208 Praktikum Pemecahan Masalah dengan C 2021/2022
*Modul            : 4 - Structures and Dynamic Arrays
*Percobaan        : -
*Hari dan Tanggal : Kamis, 17 Maret 2022
*Nama (NIM)       : -
*Asisten (NIM)    : -
*Nama File        : soal-02.c
*Deskripsi        : -
*/

#include <stdio.h>
#include <stdlib.h>

typedef struct complex {
	int real;
	int imag;
} complex;

int main() {

	int baris, kolom;
	scanf("%d %d",&baris, &kolom);

	int is_hermitian=1;
	int is_skew_hermitian=1;

	// jika baris tidak sama dengan kolom, sudah pasti bukan matriks hermitian
	if(baris!=kolom) {
		printf("Matriks bukan merupakan keduanya\n");
	}
	else {
		//deklarasi matrices of struct
		complex matriks[baris][kolom];
		complex conjugate_transpose[kolom][baris];

		for (int i=0;i<baris;i++) {
			for(int j=0;j<baris;j++) {
				scanf("%d %d", &matriks[i][j].real, &matriks[i][j].imag);
			}
		}
		//melakukan conjugate transpose matriks
		for (int i=0; i<baris;i++) {
			for(int j=0;j<kolom;j++) {
				conjugate_transpose[j][i].real=matriks[i][j].real;
				conjugate_transpose[j][i].imag=(-1)*matriks[i][j].imag;
			}
		}
		for(int i=0;i<baris;i++) {

			for(int j=0;j<kolom;j++) {
				if(is_hermitian==1) { //cek apakah suatu matriks masih hermitian
					if(conjugate_transpose[i][j].real!=matriks[i][j].real || conjugate_transpose[i][j].imag!=matriks[i][j].imag) {
						is_hermitian=0;
					}
				}
				if(is_skew_hermitian==1) {
					if(conjugate_transpose[i][j].real!=-1*matriks[i][j].real || conjugate_transpose[i][j].imag!= -1*matriks[i][j].imag) {
						is_skew_hermitian=0;
					}
				}
				if(is_hermitian==0 && is_skew_hermitian==0) {
					printf("Matriks bukan merupakan keduanya\n");
					return 0;
				}
			}   
		}
		
		//sudah menyelesaikan loop di atas, artinya semua komponen sama, matriks merupakan matriks hermitian
		
		if(is_hermitian==1) {
			if(is_skew_hermitian==1) {
				printf("Matriks merupakan matriks skew hermitian dan matriks hermitian\n");
			}
			else {
				printf("Matriks merupakan matriks hermitian\n");
			}
		}
		else {
			if(is_skew_hermitian==1) {
				printf("Matriks merupakan matriks skew hermitian\n");
			}
			else {
				printf("Matriks bukan merupakan keduanya\n");
			}
		}
	}
}
