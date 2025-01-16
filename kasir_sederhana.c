//A_PKP01_L0124016_FirizqiAdityaMulya

#include <stdio.h>
#include <string.h>

int main () {

    char nama_barang [50];
    int jumlah_barang;
    double harga_per_unit, total_harga, total_semua_barang = 0, total_setelah_diskon;
    char tambah_barang;

    //menggunakan 'do' untuk menjalankan program sekali
    do {
        //input nama barang
        printf("Masukkan nama barang: ");
        fgets(nama_barang, 50, stdin);

        //fgets memasukkan semua termasuk newline yang muncul karena user menekan tombol enter
        //sehingga dibutuhkan kode ini untuk menghilangkan newline
        //tanpa kode ini 'nama_barang\n', dengan kode ini 'nama_barang'
        nama_barang[strcspn(nama_barang, "\n")] = 0;

        //input kuantitas barang
        printf("Masukkan jumlah barang: ");
        scanf("%d", &jumlah_barang);

        //input harga barang per unit
        printf("Masukkan harga barang: ");
        scanf("%lf", &harga_per_unit);

        //ini untuk membersihkan newline dari buffer setelah scanf
        getchar();

        printf("Harga %s per unit adalah Rp%.2lf\n\n", nama_barang, harga_per_unit);

        //rumus total harga untuk satu jenis barang
        total_harga = jumlah_barang * harga_per_unit;
        printf("Total harga untuk %d %s adalah Rp%.2lf\n\n", jumlah_barang, nama_barang, total_harga);
        
        //rumus total harga untuk semua barang
        total_semua_barang += total_harga;
        printf("Total harga semua barang adalah Rp%.2lf\n", total_semua_barang);

        printf("Apakah kamu ingin menambah barang? (Y/N)");
        scanf("%c", &tambah_barang);

        getchar();

    //menggunakan 'while' untuk pengecekan pengulangan
    } while (tambah_barang == 'Y' || tambah_barang == 'y');

    printf("\nTotal harga semua barang adalah Rp%.2lf\n\n", total_semua_barang);

    //pengecekan apakah total harga semua barang mendapat diskon atau tidak
    if (total_semua_barang > 100000) {
        total_setelah_diskon = total_semua_barang * 0.9;

        printf("Kamu mendapat diskon 10%% karena total harga semua barang lebih dari Rp100.000!\n");

        printf("Total harga semua barang setelah diskon adalah Rp%.2lf\n", total_setelah_diskon);
    } else {
        printf("Total harga semua barang tidak mendapat diskon.\n");
    }

    return 0;
}
