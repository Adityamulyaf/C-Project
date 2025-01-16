//A_PKP04_L0124016_FirizqiAdityaMulya

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// mendefinisikan jumlah kesempatan
#define jumlahKesempatan 6

// fungsi untuk mengecek apakah tebakan benar
void cekTebakan(int angkaTebakan, int angkaRahasia) {
    // jika tebakan sama dengan angka rahasia
    if (angkaTebakan == angkaRahasia) {
        printf("Angka rahasia adalah %d, selamat kamu berhasil menebak dengan benar!\n", angkaRahasia);
    } 
    // jika tebakan lebih kecil dari angka rahasia
    else if (angkaTebakan < angkaRahasia) {
        printf("Tebakan kamu terlalu rendah. Coba lagi!\n");
    } 
    // jika tebakan lebih besar dari angka rahasia
    else {
        printf("Tebakan kamu terlalu tinggi. Coba lagi!\n");
    }
}

int main() {
    // mendeklarasikan variabel
    int angkaRahasia; // angka yang harus ditebak
    int angkaTebakan; // variabel untuk menyimpan tebakan
    int i;

    // inisialisasi random seed
    srand(time(NULL));
    // menghasilkan angka rahasia antara 1 dan 100
    angkaRahasia = rand() % 100 + 1;

    printf("\t\t<<< TEBAK ANGKA >>>\n\n");
    printf("Kamu punya %d kesempatan untuk menebak angka yang benar dari 1-100.\n\n", jumlahKesempatan);

    // loop untuk meminta tebakan dari pemain
    for (i = 0; i < jumlahKesempatan; i++) {
        printf("Tebakan ke-%d: ", i + 1);
        scanf("%d", &angkaTebakan); // mengambil input tebakan dari pemain

        // memanggil fungsi untuk cek tebakan
        cekTebakan(angkaTebakan, angkaRahasia);
        
        // jika tebakan benar, keluar dari loop
        if (angkaTebakan == angkaRahasia) {
            break;
        }
    }

    // jika pemain tidak berhasil menebak dalam jumlah kesempatan
    if (i == jumlahKesempatan) {
        printf("Kesempatan habis. Angka rahasianya adalah %d.\n", angkaRahasia);
    }

    return 0;
}
