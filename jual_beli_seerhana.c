//NIM   : L0124016
//Nama  : Firizqi Aditya Mulya

#include <stdio.h>

int main() {
    int saldo, barang, harga;
    char lanjut;

    printf("\t<<<<< SELAMAT BERBELANJA DI PENA STATIONERY >>>>>\n\n");

    //pengguna memasukkan (input) saldo awal
    printf("Masukkan saldo awal: Rp ");
    scanf("%d", &saldo);

    //do menjalankan program sekali
    //sebelum mengecek apakah ada pengulangan atau tidak di while
    do {
        //menampilkan barang yang bisa dipilih pengguna
        printf("\n\t<<<<< Pilih Alat Tulis >>>>>\n");
        printf("\t(1) Buku      = Rp 10000\n");
        printf("\t(2) Bolpoin   = Rp 7000\n");
        printf("\t(3) Pensil    = Rp 5000\n");
        printf("\t(4) Spidol    = Rp 8000\n");
        printf("\t(5) Tip-X     = Rp 10000\n");
        printf("\t(6) Penghapus = Rp 5000\n");
        printf("\t(7)\tKeluar\n\n");

        printf("Pilih barang yang ingin kamu beli (1-7): ");
        scanf("%d", &barang);

        //jika pengguna memasukkan angka selain 1 - 7
        //maka akan kembali ke tampilan pilihan
        if (barang < 1 || barang > 7) {
            printf("Pilih antara barang 1 sampai 7 ya....\n");
            continue;
        }

        //harga tiap barang
        switch (barang) {
            case 1:
                harga = 10000;
                break;
            case 2:
                harga = 7000;
                break;
            case 3:
                harga = 5000;
                break;
            case 4:
                harga = 8000;
                break;
            case 5:
                harga = 10000;
                break;
            case 6:
                harga = 5000;
                break;
            case 7:
                printf("Sisa saldo: Rp %d\n\n", saldo);
                printf("\t<<<<< TERIMA KASIH TELAH BERBELANJA DI PENA STATIONERY >>>>>");
                return 0;
        }

        //memeriksa saldo
        if (saldo >= harga) { //jika saldo lebih besar dari harga
            saldo -= harga; //saldo akan dikurangi harga
            printf("Pembelian berhasil! Sisa saldo: Rp %d\n", saldo);
        } else { //jika saldo lebih kecil dari harga
            printf("Saldo tidak cukup untuk membeli barang yang dipilih.\n");
        }

        printf("\nApakah kamu ingin belanja lagi? (y/n): ");
        scanf(" %c", &lanjut);

    //pengecekan apakah program akan diulangi atau tidak
    } while (lanjut == 'y' || lanjut == 'Y');

    printf("Sisa saldo: Rp %d\n\n", saldo);
    printf("\t<<<<< TERIMA KASIH TELAH BERBELANJA DI PENA STATIONERY >>>>>");

return 0;
}