// A_PKP09_L0124016_FirizqiAdityaMulya

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SISWA 100
#define MAX_KEGIATAN 50

// definisi struct untuk data siswa
typedef struct {
    char nama[50];              // nama siswa
    char kelas[10];             // kelas siswa
    int nilaiMatematika;        // nilai matematika
    int nilaiFisika;            // nilai fisika
    int nilaiKimia;             // nilai kimia
    char ekstrakurikuler[50];   // kegiatan ekstrakurikuler siswa
} Siswa;

// definisi struct untuk node dalam linked list kegiatan ekstrakurikuler
typedef struct Node {
    char kegiatan[50];          // nama kegiatan ekstrakurikuler
    struct Node* next;          // pointer ke node berikutnya
} Node;

// variabel global untuk menyimpan data siswa dan kegiatan
Siswa siswa[MAX_SISWA];          // array untuk menyimpan data siswa
int jumlahSiswa = 0;             // jumlah siswa yang sudah ditambahkan
Node* kegiatanHead = NULL;       // pointer ke head dari linked list kegiatan

// fungsi untuk memeriksa apakah suatu kegiatan sudah ada di linked list
int cekKegiatan(const char* kegiatan) {
    Node* temp = kegiatanHead;
    while (temp != NULL) {
        // jika kegiatan ditemukan, kembalikan 1
        if (strcmp(temp->kegiatan, kegiatan) == 0) {
            return 1;
        }
        temp = temp->next;
    }
    // jika kegiatan tidak ditemukan, kembalikan 0
    return 0;
}

// fungsi untuk menambahkan kegiatan baru ke linked list
void tambahKegiatan(const char* kegiatan) {
    // periksa apakah kegiatan sudah ada
    if (cekKegiatan(kegiatan)) {
        printf("Kegiatan sudah ada.\n");
        return;
    }

    // alokasikan memori untuk node baru
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (!newNode) {
        printf("Gagal mengalokasikan memori.\n");
        return;
    }

    // salin nama kegiatan ke node baru
    strcpy(newNode->kegiatan, kegiatan);
    newNode->next = NULL;

    // tambahkan node baru ke linked list
    if (kegiatanHead == NULL) {
        kegiatanHead = newNode; // jika linked list kosong, set node baru sebagai head
    } else {
        Node* temp = kegiatanHead;
        while (temp->next != NULL) {
            temp = temp->next; // iterasi sampai node terakhir
        }
        temp->next = newNode; // tambahkan node baru di akhir linked list
    }
    printf("Kegiatan berhasil ditambahkan.\n");
}

// fungsi untuk meminta input nilai dengan validasi (0-100)
void inputNilai(int* nilai, const char* namaPelajaran) {
    do {
        printf("Masukkan nilai %s (0-100): ", namaPelajaran);
        if (scanf("%d", nilai) != 1 || *nilai < 0 || *nilai > 100) {
            printf("Nilai tidak valid, silakan isi nilai dari 0 - 100.\n");
            while (getchar() != '\n'); // bersihkan buffer input
        } else {
            break; // input valid, keluar dari loop
        }
    } while (1);
}

// fungsi untuk menambahkan data siswa baru
void tambahSiswa() {
    // cek apakah jumlah siswa telah mencapai batas maksimum
    if (jumlahSiswa >= MAX_SISWA) {
        printf("Kapasitas maksimum siswa tercapai.\n");
        return;
    }

    Siswa baru;
    printf("Masukkan nama siswa: ");
    scanf(" %[^\n]", baru.nama);

    // cek apakah nama siswa sudah ada
    for (int i = 0; i < jumlahSiswa; i++) {
        if (strcmp(siswa[i].nama, baru.nama) == 0) {
            printf("Data siswa sudah ditambahkan sebelumnya.\n");
            return;
        }
    }

    // masukkan data siswa
    printf("Masukkan kelas siswa: ");
    scanf(" %[^\n]", baru.kelas);

    // validasi input nilai
    inputNilai(&baru.nilaiMatematika, "Matematika");
    inputNilai(&baru.nilaiFisika, "Fisika");
    inputNilai(&baru.nilaiKimia, "Kimia");

    // input kegiatan ekstrakurikuler
    printf("Masukkan kegiatan ekstrakurikuler siswa: ");
    scanf(" %[^\n]", baru.ekstrakurikuler);

    // tambahkan kegiatan ke linked list jika belum ada
    if (!cekKegiatan(baru.ekstrakurikuler)) {
        printf("Kegiatan belum ada. Menambahkan ke daftar kegiatan...\n");
        tambahKegiatan(baru.ekstrakurikuler);
    }

    // tambahkan siswa ke array siswa
    siswa[jumlahSiswa++] = baru;
    printf("Data siswa berhasil ditambahkan.\n");
}

// fungsi untuk memperbarui data siswa yang sudah ada
void perbaruiSiswa() {
    char nama[50];
    printf("Masukkan nama siswa yang ingin diperbarui: ");
    scanf(" %[^\n]", nama);

    for (int i = 0; i < jumlahSiswa; i++) {
        if (strcmp(siswa[i].nama, nama) == 0) {
            // tampilkan data lama siswa
            printf("Kelas sebelumnya: %s\n", siswa[i].kelas);
            printf("Masukkan kelas baru: ");
            scanf(" %[^\n]", siswa[i].kelas);

            // validasi dan perbarui nilai
            inputNilai(&siswa[i].nilaiMatematika, "Matematika");
            inputNilai(&siswa[i].nilaiFisika, "Fisika");
            inputNilai(&siswa[i].nilaiKimia, "Kimia");

            // perbarui kegiatan ekstrakurikuler
            printf("Kegiatan ekstrakurikuler sebelumnya: %s\n", siswa[i].ekstrakurikuler);
            printf("Masukkan kegiatan ekstrakurikuler baru: ");
            scanf(" %[^\n]", siswa[i].ekstrakurikuler);

            // tambahkan kegiatan baru jika belum ada
            if (!cekKegiatan(siswa[i].ekstrakurikuler)) {
                printf("Kegiatan belum ada. Menambahkan ke daftar kegiatan...\n");
                tambahKegiatan(siswa[i].ekstrakurikuler);
            }
            printf("Data siswa berhasil diperbarui.\n");
            return;
        }
    }
    printf("Siswa tidak ditemukan.\n");
}

// fungsi untuk menampilkan data semua siswa
void tampilkanSiswa() {
    if (jumlahSiswa == 0) {
        printf("Belum ada data siswa.\n");
        return;
    }

    printf("\nDaftar Siswa:\n");
    for (int i = 0; i < jumlahSiswa; i++) {
        printf("Nama: %s, Kelas: %s, Nilai (Matematika: %d, Fisika: %d, Kimia: %d), Ekstrakurikuler: %s\n",
               siswa[i].nama, siswa[i].kelas, siswa[i].nilaiMatematika,
               siswa[i].nilaiFisika, siswa[i].nilaiKimia, siswa[i].ekstrakurikuler);
    }
}

// fungsi untuk menampilkan daftar kegiatan ekstrakurikuler
void tampilkanKegiatan() {
    if (kegiatanHead == NULL) {
        printf("Belum ada kegiatan ekstrakurikuler.\n");
        return;
    }

    printf("\nDaftar Kegiatan Ekstrakurikuler:\n");
    Node* temp = kegiatanHead;
    while (temp != NULL) {
        printf("- %s\n", temp->kegiatan);
        temp = temp->next;
    }
}

// fungsi untuk menampilkan anggota setiap kegiatan ekstrakurikuler
void tampilkanAnggotaKegiatan() {
    if (kegiatanHead == NULL) {
        printf("Belum ada kegiatan ekstrakurikuler.\n");
        return;
    }

    printf("\nDaftar Anggota Kegiatan Ekstrakurikuler:\n");
    Node* temp = kegiatanHead;
    while (temp != NULL) {
        printf("%s:\n", temp->kegiatan);
        for (int i = 0; i < jumlahSiswa; i++) {
            if (strcmp(siswa[i].ekstrakurikuler, temp->kegiatan) == 0) {
                printf("- %s\n", siswa[i].nama);
            }
        }
        temp = temp->next;
    }
}

// fungsi utama
int main() {
    printf("\t<<<<< PROGRAM MANAJEMEN DATA SISWA >>>>>\n");

    int pilihan;
    do {
        // tampilkan menu utama
        printf("\nFitur Manajemen Data Siswa:\n");
        printf("1. Tambah Data Siswa\n");
        printf("2. Perbarui Data Siswa\n");
        printf("3. Tampilkan Data Siswa\n");
        printf("4. Tambah Kegiatan Ekstrakurikuler\n");
        printf("5. Tampilkan Kegiatan Ekstrakurikuler\n");
        printf("6. Tampilkan Anggota Kegiatan Ekstrakurikuler\n");
        printf("7. Keluar\n");
        printf("Pilih fitur: ");
        scanf("%d", &pilihan);

        // eksekusi pilihan fitur
        switch (pilihan) {
            case 1:
                tambahSiswa();
                break;
            case 2:
                perbaruiSiswa();
                break;
            case 3:
                tampilkanSiswa();
                break;
            case 4: {
                char kegiatan[50];
                printf("Masukkan nama kegiatan: ");
                scanf(" %[^\n]", kegiatan);
                tambahKegiatan(kegiatan);
                break;
            }
            case 5:
                tampilkanKegiatan();
                break;
            case 6:
                tampilkanAnggotaKegiatan();
                break;
            case 7:
                printf("Keluar dari program.\n");
                break;
            default:
                printf("Pilihan tidak valid.\n");
        }
    } while (pilihan != 7);

    // membersihkan memori dari linked list sebelum keluar
    Node* temp;
    while (kegiatanHead != NULL) {
        temp = kegiatanHead;
        kegiatanHead = kegiatanHead->next;
        free(temp);
    }

    return 0;
}
