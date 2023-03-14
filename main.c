/** EL2208 Praktikum Pemecahan Masalah dengan C 2022/2023
 *   Modul               : 
 *   Hari dan Tanggal    :
 *   Nama (NIM)          :
 *   Nama File           : main.c
 *   Deskripsi           :
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Fungsi rekursif untuk melakukan transkripsi DNA ke RNA
void transkripsi(char dna[], char rna[], int i) {
    ...
}

// Fungsi untuk melakukan translasi RNA menjadi protein
void translasi(char rna[]) {
    ...
}

int main() {
    char dna_seq[100], rna_seq[100];
    printf("Masukkan sekuens DNA: ");
    scanf("%s", dna_seq);

    // Lakukan transkripsi DNA ke RNA menggunakan fungsi rekursif
    transkripsi(dna_seq, rna_seq, 0);

    // Cetak hasil transkripsi
    printf("RNA: %s\n", rna_seq);

    // Lakukan translasi RNA ke protein
    printf("Protein: ");
    translasi(rna_seq);

    return 0;
}
