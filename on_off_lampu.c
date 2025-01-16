//A_PKP07_L0124016_FirizqiAdityaMulya

#include <stdio.h>

// enum untuk mendefinisikan tipe lampu lalu lintas
// setiap lampu diwakili oleh angka, 0 untuk Merah, 1 untuk Kuning, 2 untuk Hijau
typedef enum {
    LAMPU_MERAH = 0,
    LAMPU_KUNING = 1,
    LAMPU_HIJAU = 2
} Lampu;

// fungsi untuk mencetak status lampu dalam format biner
// format biner menampilkan status ketiga lampu dalam bentuk 0 atau 1
void cetakStatusBinary(int status) {
    printf("Status Binary: ");
    for (int i = 2; i >= 0; i--) { // loop dari lampu tertinggi (Hijau) ke terendah (Merah)
        printf("%d", (status >> i) & 1); // geser bit ke kanan, lalu ambil bit terkecil
    }
    printf("\n");
}

// fungsi untuk mencetak status setiap lampu dalam bentuk teks
// fungsi ini menunjukkan apakah masing-masing lampu dalam keadaan ON atau OFF
void cetakStatusLampu(int status) {
    printf("Lampu Merah: %s\n", (status & (1 << LAMPU_MERAH)) ? "ON" : "OFF");
    printf("Lampu Kuning: %s\n", (status & (1 << LAMPU_KUNING)) ? "ON" : "OFF");
    printf("Lampu Hijau: %s\n", (status & (1 << LAMPU_HIJAU)) ? "ON" : "OFF");
}

// fungsi untuk menghidupkan lampu tertentu
// menggunakan pointer ke variabel `status` agar dapat langsung mengubah nilai status
// lampu dihidupkan dengan operasi bitwise OR pada bit yang sesuai
void hidupkanLampu(int *status, Lampu lampu) {
    *status |= (1 << lampu); // geser bit ke posisi lampu, lalu set menjadi 1
    // cetak pesan bahwa lampu telah dihidupkan
    printf("Lampu %s dihidupkan.\n", lampu == LAMPU_MERAH ? "Merah" : lampu == LAMPU_KUNING ? "Kuning" : "Hijau");
}

// fungsi untuk mematikan lampu tertentu
// mirip dengan fungsi hidupkanLampu, tetapi menggunakan operasi bitwise AND dan NOT untuk mematikan lampu
void matikanLampu(int *status, Lampu lampu) {
    *status &= ~(1 << lampu); // geser bit ke posisi lampu, lalu set menjadi 0
    // cetak pesan bahwa lampu telah dimatikan
    printf("Lampu %s dimatikan.\n", lampu == LAMPU_MERAH ? "Merah" : lampu == LAMPU_KUNING ? "Kuning" : "Hijau");
}

int main() {
    int status = 0; // status awalnya adalah semua lampu mati
    int pilihan, lampu;

    // loop utama untuk berinteraksi dengan pengguna
    while (1) {
        printf("\n=== Sistem Pengelolaan Lampu Lalu Lintas ===\n");
        // mencetak status lampu saat ini dalam format biner dan teks
        cetakStatusBinary(status);
        cetakStatusLampu(status);

        // mencetak menu aksi
        printf("\nPilih aksi:\n");
        printf("1. Hidupkan lampu\n");
        printf("2. Matikan lampu\n");
        printf("3. Keluar\n");
        printf("Pilihan Anda: ");
        scanf("%d", &pilihan);

        // jika pengguna memilih keluar, program akan berhenti
        if (pilihan == 3) {
            printf("Program selesai.\n");
            break;
        }

        // jika pengguna memilih untuk menghidupkan atau mematikan lampu
        if (pilihan == 1 || pilihan == 2) {
            // mencetak daftar lampu
            printf("\nPilih lampu:\n");
            printf("0. Lampu Merah\n");
            printf("1. Lampu Kuning\n");
            printf("2. Lampu Hijau\n");
            printf("Pilihan Anda: ");
            scanf("%d", &lampu);

            // validasi input
            if (lampu >= 0 && lampu <= 2) {
                // jika valid, ubah status lampu sesuai aksi
                if (pilihan == 1) {
                    hidupkanLampu(&status, (Lampu)lampu);
                } else {
                    matikanLampu(&status, (Lampu)lampu);
                }
            } else {
                // jika input tidak valid, cetak pesan kesalahan
                printf("Pilihan lampu tidak valid.\n");
            }
        } else {
            // jika pilihan aksi tidak valid, cetak pesan kesalahan
            printf("Pilihan aksi tidak valid.\n");
        }
    }
    return 0;
}
