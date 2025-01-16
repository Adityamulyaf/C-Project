// A_PKP08_L0124016_FirizqiAdityaMulya

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// struct untuk menyimpan agenda
typedef struct {
    char hari[10]; // hari agenda
    int tanggal; // tanggal agenda
    char bulan[10]; // bulan agenda
    int tahun; // tahun agenda
    char deskripsi[255]; // deskripsi agenda
} Agenda;

// array untuk menyimpan agenda
Agenda agendaList[100];
int jumlahAgenda = 0; // jumlah agenda yang tersimpan
int isSaved = 1; // flag untuk status penyimpanan

// fungsi untuk menampilkan daftar agenda
void tampilkanAgenda() {
    printf("\n=======================\n");
    printf("     Daftar Agenda     \n");
    printf("=======================\n");

    if (jumlahAgenda == 0) {
        printf("| Tidak ada agenda saat ini. |\n");
    } else {
        for (int i = 0; i < jumlahAgenda; i++) {
            printf("| %d. [%s, %02d %s %d] %s\n", 
                   i + 1, 
                   agendaList[i].hari, 
                   agendaList[i].tanggal, 
                   agendaList[i].bulan, 
                   agendaList[i].tahun, 
                   agendaList[i].deskripsi);
        }
    }

    printf("=======================\n");
}

// fungsi untuk menambah agenda baru
void tambahAgenda() {
    if (jumlahAgenda >= 100) {
        printf("Agenda penuh, tidak dapat menambah lagi.\n");
        return;
    }

    printf("\nMasukkan hari (contoh: Senin): ");
    scanf(" %[^\n]", agendaList[jumlahAgenda].hari);
    printf("Masukkan tanggal (1-31): ");
    scanf("%d", &agendaList[jumlahAgenda].tanggal);
    printf("Masukkan bulan (contoh: Januari): ");
    scanf(" %[^\n]", agendaList[jumlahAgenda].bulan);
    printf("Masukkan tahun (contoh: 2024): ");
    scanf("%d", &agendaList[jumlahAgenda].tahun);
    printf("Masukkan deskripsi agenda: ");
    scanf(" %[^\n]", agendaList[jumlahAgenda].deskripsi);

    jumlahAgenda++;
    isSaved = 0; // status penyimpanan diubah karena ada perubahan
    printf("Agenda berhasil ditambahkan!\n");
}

// fungsi untuk menghapus agenda berdasarkan nomor
void hapusAgenda() {
    if (jumlahAgenda == 0) {
        printf("Tidak ada agenda yang dapat dihapus.\n");
        return;
    }

    tampilkanAgenda();

    int nomor;
    printf("\nMasukkan nomor agenda yang ingin dihapus: ");
    scanf("%d", &nomor);

    if (nomor < 1 || nomor > jumlahAgenda) {
        printf("Nomor tidak valid. Silakan coba lagi.\n");
        return;
    }

    for (int i = nomor - 1; i < jumlahAgenda - 1; i++) {
        agendaList[i] = agendaList[i + 1];
    }
    jumlahAgenda--;
    isSaved = 0; // status penyimpanan diubah karena ada perubahan
    printf("Agenda berhasil dihapus!\n");
}

// fungsi untuk menyimpan agenda ke file
void simpanKeFile(const char *namaFile) {
    FILE *file = fopen(namaFile, "w");
    if (file == NULL) {
        printf("Gagal membuka file untuk menyimpan.\n");
        return;
    }

    for (int i = 0; i < jumlahAgenda; i++) {
        fprintf(file, "%s|%d|%s|%d|%s\n", 
                agendaList[i].hari, 
                agendaList[i].tanggal, 
                agendaList[i].bulan, 
                agendaList[i].tahun, 
                agendaList[i].deskripsi);
    }

    fclose(file);
    isSaved = 1; // status penyimpanan diubah menjadi sudah tersimpan
    printf("Agenda berhasil disimpan ke file %s.\n", namaFile);
}

// fungsi untuk memuat agenda dari file
void muatDariFile(const char *namaFile) {
    FILE *file = fopen(namaFile, "r");
    if (file == NULL) {
        printf("File tidak ditemukan atau kosong. Memulai agenda baru.\n");
        return;
    }

    jumlahAgenda = 0;
    while (fscanf(file, " %9[^|]|%d|%9[^|]|%d|%254[^\n]", 
                  agendaList[jumlahAgenda].hari, 
                  &agendaList[jumlahAgenda].tanggal, 
                  agendaList[jumlahAgenda].bulan, 
                  &agendaList[jumlahAgenda].tahun, 
                  agendaList[jumlahAgenda].deskripsi) == 5) {
        jumlahAgenda++;
    }

    fclose(file);
    printf("Agenda berhasil dimuat dari file %s.\n", namaFile);
}

int main() {
    char namaFile[50];
    printf("Masukkan nama file untuk menyimpan agenda (contoh: agenda.txt): ");
    scanf(" %[^\n]", namaFile);

    muatDariFile(namaFile);

    int pilihan;
    do {
        printf("\n=== Manajemen Agenda Harian ===\n");
        printf("1. Tampilkan semua agenda\n");
        printf("2. Tambah agenda baru\n");
        printf("3. Hapus agenda\n");
        printf("4. Simpan agenda ke file\n");
        printf("5. Keluar\n");
        printf("Pilih opsi: ");
        scanf("%d", &pilihan);

        switch (pilihan) {
            case 1:
                tampilkanAgenda();
                break;
            case 2:
                tambahAgenda();
                break;
            case 3:
                hapusAgenda();
                break;
            case 4:
                simpanKeFile(namaFile);
                break;
            case 5:
            // pengondisian apabila user belum menyimpan agenda ke file
                if (!isSaved) {
                    printf("Perubahan belum disimpan ke file.\n");
                    simpanKeFile(namaFile);
                }
                printf("Kamu telah keluar dari program.\n");
                break;
            default:
                printf("Pilihan tidak valid. Pilih antara nomor 1-5.\n");
        }
    } while (pilihan != 5);

    return 0;
}
