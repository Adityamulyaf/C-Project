//A_PKP05_L0124016_FirizqiAdityaMulya

#include <stdio.h>

// fungsi untuk menghitung total harga dan diskon
void hitungTotal(float harga, int jumlah, float *total, float *diskon) {
    *total = harga * jumlah; // menghitung total harga

    // mengecek apakah total memenuhi syarat diskon
    if (*total > 100000) {
        *diskon = *total * 0.10; // menghitung diskon 10%
        *total -= *diskon;       // mengurangi total dengan diskon
    } else {
        *diskon = 0; // jika tidak ada diskon, set diskon menjadi 0
    }
}

int main() {
    float harga; // harga satuan barang
    int jumlah;  // jumlah barang yang dibeli
    float total; // total harga setelah diskon
    float diskon; // jumlah diskon yang diberikan

    printf("\t<<< SELAMAT DATANG DI KP-MART >>>\n\n"); // pembuka

    // meminta input dari pengguna
    printf("Masukkan harga barang: ");
    scanf("%f", &harga);
    printf("Masukkan jumlah barang: ");
    scanf("%d", &jumlah);

    // memanggil fungsi hitungTotal dengan pass-by-reference
    hitungTotal(harga, jumlah, &total, &diskon);

    // menampilkan hasil total, diskon, dan total setelah diskon
    printf("\n========= Rincian Pembayaran =========\n");
    printf("Total sebelum diskon: Rp %.2f\n", harga * jumlah);
    printf("Diskon yang diterapkan: Rp %.2f\n", diskon);
    printf("Total setelah diskon: Rp %.2f\n", total);

    printf("\n\t\t<<< TERIMA KASIH >>>\n\n"); // penutup

    return 0;
}
