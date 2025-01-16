//A_PKP06_L0124016_FirizqiAdityaMulya

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// mendefinisikan alias untuk struct Book menggunakan typedef
typedef struct {
    char *judul;
    char *penulis;
    int tahunTerbit;
    char *penerbit;
    char *genre;
    int jumlahHalaman;
} Book;

// fungsi untuk membuat buku baru dan mengalokasikan memori secara dinamis
Book* createBook(int totalBuku) {
    Book *buku = (Book*) malloc(totalBuku * sizeof(Book));

    // memeriksa apakah memori berhasil dialokasikan
    if (buku == NULL) {
        printf("ERROR: Gagal mengalokasikan memori.\n");
        exit(1);
    }

    for (int i = 0; i < totalBuku; i++) {
        // mengalokasikan memori untuk string
        buku[i].judul = (char*) malloc(100 * sizeof(char));
        buku[i].penulis = (char*) malloc(100 * sizeof(char));
        buku[i].penerbit = (char*) malloc(100 * sizeof(char));
        buku[i].genre = (char*) malloc(50 * sizeof(char));

        // memeriksa apakah memori untuk setiap string berhasil dialokasikan
        if (buku[i].judul == NULL || buku[i].penulis == NULL || buku[i].penerbit == NULL || buku[i].genre == NULL) {
            printf("ERROR: Gagal mengalokasikan memori.\n");
            exit(1);
        }

        // menerima input untuk setiap data buku
        printf("Masukkan judul buku ke-%d: ", i + 1);
        fgets(buku[i].judul, 100, stdin);
        buku[i].judul[strcspn(buku[i].judul, "\n")] = 0;  // menghapus newline

        printf("Masukkan nama penulis buku ke-%d: ", i + 1);
        fgets(buku[i].penulis, 100, stdin);
        buku[i].penulis[strcspn(buku[i].penulis, "\n")] = 0;  // menghapus newline

        printf("Masukkan tahun terbit buku ke-%d: ", i + 1);
        scanf("%d", &buku[i].tahunTerbit);
        getchar();  // menghapus karakter newline sisa dari scanf

        printf("Masukkan nama penerbit buku ke-%d: ", i + 1);
        fgets(buku[i].penerbit, 100, stdin);
        buku[i].penerbit[strcspn(buku[i].penerbit, "\n")] = 0;  // menghapus newline

        printf("Masukkan genre buku ke-%d: ", i + 1);
        fgets(buku[i].genre, 50, stdin);
        buku[i].genre[strcspn(buku[i].genre, "\n")] = 0;  // menghapus newline

        printf("Masukkan jumlah halaman buku ke-%d: ", i + 1);
        scanf("%d", &buku[i].jumlahHalaman);
        getchar();  // menghapus karakter newline sisa dari scanf
    }

    return buku;
}

// fungsi untuk menampilkan data buku
void displayBooks(Book *buku, int totalBuku) {
    printf("\n\t<<<DAFTAR BUKU>>>\n\n");
    for (int i = 0; i < totalBuku; i++) {
        printf("Buku ke-%d:\n", i + 1);
        printf("Judul: %s\n", buku[i].judul);
        printf("Penulis: %s\n", buku[i].penulis);
        printf("Tahun terbit: %d\n", buku[i].tahunTerbit);
        printf("Penerbit: %s\n", buku[i].penerbit);
        printf("Genre: %s\n", buku[i].genre);
        printf("Jumlah Halaman: %d\n\n", buku[i].jumlahHalaman);
    }
}

// fungsi untuk membebaskan memori yang telah dialokasikan
void freeBooks(Book *buku, int totalBuku) {
    for (int i = 0; i < totalBuku; i++) {
        free(buku[i].judul);
        free(buku[i].penulis);
        free(buku[i].penerbit);
        free(buku[i].genre);
    }
    free(buku);
}

int main() {
    int totalBuku;

    // ucapan selamat datang
    printf("\t<<<SELAMAT DATANG DI PERPUSTAKODING>>>\n\n");

    printf("Masukkan jumlah buku yang ingin ditambahkan: ");
    scanf("%d", &totalBuku);
    getchar();  // menghapus karakter newline sisa dari scanf

    // membuat data buku menggunakan dynamic memory allocation
    Book *perpustakaan = createBook(totalBuku);

    // menampilkan seluruh data buku
    displayBooks(perpustakaan, totalBuku);

    // membebaskan memori yang telah dialokasikan
    freeBooks(perpustakaan, totalBuku);

    // ucapan terima kasih
    printf("\t<<<TERIMA KODING>>>\n");

    return 0;
}
