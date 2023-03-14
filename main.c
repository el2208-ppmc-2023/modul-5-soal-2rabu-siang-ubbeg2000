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
    if (dna[i] == '\0') {
        rna[i] = '\0';
        return;
    }

    // Transkripsi adenin (A) menjadi urasil (U)
    if (dna[i] == 'A') {
        rna[i] = 'U';
    }
    // Transkripsi sitosin (C) menjadi guanin (G)
    else if (dna[i] == 'C') {
        rna[i] = 'G';
    }
    // Transkripsi guanin (G) menjadi sitosin (C)
    else if (dna[i] == 'G') {
        rna[i] = 'C';
    }
    // Transkripsi timin (T) menjadi adenin (A)
    else if (dna[i] == 'T') {
        rna[i] = 'A';
    }

    // Panggil fungsi transkripsi rekursif pada indeks selanjutnya
    transkripsi(dna, rna, i + 1);
}

// Fungsi untuk melakukan translasi RNA menjadi protein
void translasi(char rna[]) {
    char codon[4];
    int i, len = strlen(rna), amino_count = 0;

    for (i = 0; i < len; i += 3) {
        // Ambil setiap tiga basa (kodon) dari RNA
        strncpy(codon, rna + i, 3);
        codon[3] = '\0';

        // Terjemahkan kodon menjadi asam amino
        if (strcmp(codon, "AUG") == 0) {
            printf("Met ");
            amino_count++;
        }
        else if (strcmp(codon, "UUU") == 0 || strcmp(codon, "UUC") == 0) {
            printf("Phe ");
            amino_count++;
        }
        else if (strcmp(codon, "UUA") == 0 || strcmp(codon, "UUG") == 0 ||
            strcmp(codon, "CUU") == 0 || strcmp(codon, "CUC") == 0 ||
            strcmp(codon, "CUA") == 0 || strcmp(codon, "CUG") == 0) {
            printf("Leu ");
            amino_count++;
        }
        else if (strcmp(codon, "GUU") == 0 || strcmp(codon, "GUC") == 0 ||
            strcmp(codon, "GUA") == 0 || strcmp(codon, "GUG") == 0) {
            printf("Val ");
            amino_count++;
        }
        else if (strcmp(codon, "UCU") == 0 || strcmp(codon, "UCC") == 0 ||
            strcmp(codon, "UCA") == 0 || strcmp(codon, "UCG") == 0 ||
            strcmp(codon, "AGU") == 0 || strcmp(codon, "AGC") == 0) {
            printf("Ser ");
            amino_count++;
        }
        else if (strcmp(codon, "CCU") == 0 || strcmp(codon, "CCC") == 0 || strcmp(codon, "CCA") == 0 || strcmp(codon, "CCG") == 0) {
            printf("Prolin ");
            amino_count++;
        }
        else if (strcmp(codon, "ACU") == 0 || strcmp(codon, "ACC") == 0 || strcmp(codon, "ACA") == 0 || strcmp(codon, "ACG") == 0) {
        printf("Thr ");
        amino_count++;
        }
        else if (strcmp(codon, "GCU") == 0 || strcmp(codon, "GCC") == 0 || strcmp(codon, "GCA") == 0 || strcmp(codon, "GCG") == 0) {
            printf("Ala ");
            amino_count++;
        }
        else if (strcmp(codon, "UAU") == 0 || strcmp(codon, "UAC") == 0) {
            printf("Tyr ");
            amino_count++;
        }
        else if (strcmp(codon, "CAU") == 0 || strcmp(codon, "CAC") == 0) {
            printf("His ");
            amino_count++;
        }
        else if (strcmp(codon, "CAA") == 0 || strcmp(codon, "CAG") == 0) {
            printf("Gln ");
            amino_count++;
        }
        else if (strcmp(codon, "AAU") == 0 || strcmp(codon, "AAC") == 0) {
            printf("Asn ");
            amino_count++;
        }
        else if (strcmp(codon, "AAA") == 0 || strcmp(codon, "AAG") == 0) {
            printf("Lys ");
            amino_count++;
        }
        else if (strcmp(codon, "GAU") == 0 || strcmp(codon, "GAC") == 0) {
            printf("Asp ");
            amino_count++;
        }
        else if (strcmp(codon, "GAA") == 0 || strcmp(codon, "GAG") == 0) {
            printf("Glu ");
            amino_count++;
        }
        else if (strcmp(codon, "UGU") == 0 || strcmp(codon, "UGC") == 0) {
            printf("Cys ");
            amino_count++;
        }
        else if (strcmp(codon, "UGG") == 0) {
            printf("Trp ");
            amino_count++;
        }
        else if (strcmp(codon, "AGA") == 0 || strcmp(codon, "AGG") == 0 ||
            strcmp(codon, "CGU") == 0 || strcmp(codon, "CGC") == 0 ||
            strcmp(codon, "CGA") == 0 || strcmp(codon, "CGG") == 0) {
            printf("Arg ");
            amino_count++;
        }
        else if (strcmp(codon, "GGU") == 0 || strcmp(codon, "GGC") == 0 || strcmp(codon, "GGA") == 0 || strcmp(codon, "GGG") == 0) {
            printf("Gly ");
            amino_count++;
        }
        else {
            printf("XXX ");  //Stop Kodon atau Kodon yang ditranslasi belum 3 buah
        }

        // Jika asam amino yang ditranslasi melebihi 10, maka hentikan translasi dan cetak "protein misfolded"
        if (amino_count > 10) {
            printf("\nProtein Misfolded\n");
            break;
        }
    }
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
