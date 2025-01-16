// this code is a modification of the code originally created by BroCode (YouTube). Special thanks to him for his amazing work!

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <time.h>

// mendeklarasikan papan permainan
char papan[3][3];
const char PLAYER = 'X'; // simbol untuk pemain
const char COMP = 'O';   // simbol untuk komputer

// mendeklarasikan fungsi
void resetPapan();
void printPapan();
int cekKosong();
void gerakPlayer();
void gerakComp();
char cekPemenang();
void printPemenang(char pemenang);

int main ()
{
    char pemenang = ' '; // variabel untuk menyimpan pemenang

    resetPapan(); // mengatur ulang papan permainan

    // loop selama belum ada pemenang dan masih ada kotak kosong
    while(pemenang == ' ' && cekKosong() != 0)
    {
        printPapan(); // mencetak papan permainan

        gerakPlayer(); // meminta input dari pemain
        pemenang = cekPemenang(); // mengecek apakah ada pemenang
        if(pemenang != ' ' || cekKosong() == 0) // jika ada pemenang atau tidak ada kotak kosong
        {
            break; // keluar dari loop
        }

        gerakComp(); // komputer melakukan gerakan
        pemenang = cekPemenang(); // mengecek apakah ada pemenang
        if(pemenang != ' ' || cekKosong() == 0) // jika ada pemenang atau tidak ada kotak kosong
        {
            break; // keluar dari loop
        }
    }

    printPapan(); // mencetak papan terakhir
    printPemenang(pemenang); // mencetak hasil permainan

    return 0; // mengakhiri program
}

void resetPapan()
{
    // mengatur papan menjadi kosong
    for(int i = 0; i < 3; i++)
    {
        for(int j = 0; j < 3; j++)
        {
            papan[i][j] = ' '; // mengisi semua kotak dengan spasi
        }
    }
}

void printPapan()
{
    // mencetak papan permainan dengan nomor baris dan kolom
    printf("   1    2    3\n");
    printf("  -------------\n");
    printf("1 | %c | %c | %c |\n", papan[0][0], papan[0][1], papan[0][2]);
    printf("  |---|---|---|\n");
    printf("2 | %c | %c | %c |\n", papan[1][0], papan[1][1], papan[1][2]);
    printf("  |---|---|---|\n");
    printf("3 | %c | %c | %c |\n", papan[2][0], papan[2][1], papan[2][2]);
    printf("  -------------\n");
}

int cekKosong()
{
    int kotakKosong = 9; // menghitung jumlah kotak kosong

    // mengecek setiap kotak di papan
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if(papan[i][j] != ' ') // jika kotak tidak kosong
            {
                kotakKosong--; // kurangi jumlah kotak kosong
            }
        }
    }
    return kotakKosong; // mengembalikan jumlah kotak kosong
}

void gerakPlayer()
{
    int x;
    int y;

    do
    {
        // meminta input dari pemain
        printf("Di baris ke berapa kamu ingin menaruh X? (1-3): ");
        scanf("%d", &x);
        printf("Di kolom ke berapa kamu ingin menaruh X? (1-3): ");
        scanf("%d", &y);
        
        x--;  // mengurangi satu untuk indeks array, karena array dimulai dari 0
        y--;

        if(papan[x][y] != ' ') // jika kotak sudah terisi
        {
            printf("Kotak sudah terisi. Pilih kotak lain!\n");
        }
        else
        {
            papan[x][y] = PLAYER; // menaruh simbol pemain di papan
            break; // keluar dari loop
        }
    } while (papan[x][y] != ' ');
}

void gerakComp()
{
    srand(time(0)); // menginisialisasi seed untuk random
    int x, y;

    // prioritas pertama: cek apakah komputer bisa menang dalam satu langkah
    for (int i = 0; i < 3; i++)
    {
        // cek setiap baris
        if (papan[i][0] == COMP && papan[i][1] == COMP && papan[i][2] == ' ') { papan[i][2] = COMP; return; }
        if (papan[i][0] == COMP && papan[i][2] == COMP && papan[i][1] == ' ') { papan[i][1] = COMP; return; }
        if (papan[i][1] == COMP && papan[i][2] == COMP && papan[i][0] == ' ') { papan[i][0] = COMP; return; }

        // cek setiap kolom
        if (papan[0][i] == COMP && papan[1][i] == COMP && papan[2][i] == ' ') { papan[2][i] = COMP; return; }
        if (papan[0][i] == COMP && papan[2][i] == COMP && papan[1][i] == ' ') { papan[1][i] = COMP; return; }
        if (papan[1][i] == COMP && papan[2][i] == COMP && papan[0][i] == ' ') { papan[0][i] = COMP; return; }
    }

    // cek diagonal utama
    if (papan[0][0] == COMP && papan[1][1] == COMP && papan[2][2] == ' ') { papan[2][2] = COMP; return; }
    if (papan[0][0] == COMP && papan[2][2] == COMP && papan[1][1] == ' ') { papan[1][1] = COMP; return; }
    if (papan[1][1] == COMP && papan[2][2] == COMP && papan[0][0] == ' ') { papan[0][0] = COMP; return; }

    // cek diagonal lainnya
    if (papan[0][2] == COMP && papan[1][1] == COMP && papan[2][0] == ' ') { papan[2][0] = COMP; return; }
    if (papan[0][2] == COMP && papan[2][0] == COMP && papan[1][1] == ' ') { papan[1][1] = COMP; return; }
    if (papan[1][1] == COMP && papan[2][0] == COMP && papan[0][2] == ' ') { papan[0][2] = COMP; return; }

    // prioritas kedua: halangi langkah kemenangan pemain
    for (int i = 0; i < 3; i++)
    {
        // blokir setiap baris
        if (papan[i][0] == PLAYER && papan[i][1] == PLAYER && papan[i][2] == ' ') { papan[i][2] = COMP; return; }
        if (papan[i][0] == PLAYER && papan[i][2] == PLAYER && papan[i][1] == ' ') { papan[i][1] = COMP; return; }
        if (papan[i][1] == PLAYER && papan[i][2] == PLAYER && papan[i][0] == ' ') { papan[i][0] = COMP; return; }

        // blokir setiap kolom
        if (papan[0][i] == PLAYER && papan[1][i] == PLAYER && papan[2][i] == ' ') { papan[2][i] = COMP; return; }
        if (papan[0][i] == PLAYER && papan[2][i] == PLAYER && papan[1][i] == ' ') { papan[1][i] = COMP; return; }
        if (papan[1][i] == PLAYER && papan[2][i] == PLAYER && papan[0][i] == ' ') { papan[0][i] = COMP; return; }
    }

    // blokir diagonal utama
    if (papan[0][0] == PLAYER && papan[1][1] == PLAYER && papan[2][2] == ' ') { papan[2][2] = COMP; return; }
    if (papan[0][0] == PLAYER && papan[2][2] == PLAYER && papan[1][1] == ' ') { papan[1][1] = COMP; return; }
    if (papan[1][1] == PLAYER && papan[2][2] == PLAYER && papan[0][0] == ' ') { papan[0][0] = COMP; return; }

    // blokir diagonal lainnya
    if (papan[0][2] == PLAYER && papan[1][1] == PLAYER && papan[2][0] == ' ') { papan[2][0] = COMP; return; }
    if (papan[0][2] == PLAYER && papan[2][0] == PLAYER && papan[1][1] == ' ') { papan[1][1] = COMP; return; }
    if (papan[1][1] == PLAYER && papan[2][0] == PLAYER && papan[0][2] == ' ') { papan[0][2] = COMP; return; }

    // jika tidak ada ancaman atau peluang, pilih posisi acak
    do
    {
        x = rand() % 3; // memilih baris acak
        y = rand() % 3; // memilih kolom acak
    } while (papan[x][y] != ' '); // ulang hingga menemukan kotak kosong

    papan[x][y] = COMP; // menaruh simbol komputer di papan
}

char cekPemenang()
{
   // cek baris
   for(int i = 0; i < 3; i++)
   {
        if(papan[i][0] == papan[i][1] && papan[i][0] == papan[i][2] && papan[i][0] != ' ')
        {
            return papan[i][0]; // mengembalikan pemenang jika ada
        }
   }
   // cek kolom
   for(int i = 0; i < 3; i++)
   {
        if(papan[0][i] == papan[1][i] && papan[0][i] == papan[2][i] && papan[0][i] != ' ')
        {
            return papan[0][i]; // mengembalikan pemenang jika ada
        }
   }
   // cek diagonal
   if(papan[0][0] == papan[1][1] && papan[0][0] == papan[2][2] && papan[0][0] != ' ')
   {
        return papan[0][0]; // mengembalikan pemenang jika ada
   }
   if(papan[0][2] == papan[1][1] && papan[0][2] == papan[2][0] && papan[0][2] != ' ')
   {
        return papan[0][2]; // mengembalikan pemenang jika ada
   }

    return ' '; // jika tidak ada pemenang
}

void printPemenang(char pemenang)
{
    // mencetak hasil permainan
    if(pemenang == PLAYER)
    {
        printf("Selamat! Kamu menang!\n");
    }
    else if (pemenang == COMP)
    {
        printf("Kamu kalah!\n");
    }
    else
    {
        printf("Hasilnya seri!\n");
    }
}
