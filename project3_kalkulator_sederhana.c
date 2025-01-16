//A_PKP03_L0124016_FirizqiAdityaMulya

#include <stdio.h>
#include <math.h> // untuk memunculkan (fabs) : float absolute

// fungsi rekursif untuk menghitung pangkat (power)
double rekursifPangkat(double basis, int eksponen) {

    // semua bilangan yang dipangkatkan 0 akan menghasilkan 1 (N^0 = 1)
    if (eksponen == 0) { //jika eksponen 0
        return 1; //akan menghasilkan nilai 1

    // jika eksponen positif, kalikan basis dengan hasil rekursif dari basis dengan eksponen dikurangi 1
    } else if (eksponen > 0) { //jika eksponen adalah bilangan positif
        return basis * rekursifPangkat(basis, eksponen - 1); //rekursi untuk eksponen bilangan positif
        /* penjelasan logika rekursif pangkat
        misal, 2^2
        2^2 dipecah menjadi 2 dikali 2^1
        tapi fungsi belum tahu nilai dari 2^1, memanggil dirinya sendiri untuk menghitung 2^1

        2^1 dipecah menjadi 2 dikali 2^0
        memanggil dirinya sendiri untuk menghitung 2^0

        2^0
        program mengetahui bahwa semua yang dipangkatkan 0 bernilai 1 karena telah diinstruksikan dalam kode untuk mengembalikan 1 saat eksponen bernilai 0

        setelah menemukan salah satu hasil, program akan mengembalikan nilai ke setiap panggilan rekursif sebelumnya

        2^1, mendapat hasil dari 2^0
        2 * 1 = 1

        2^2, mendapat hasil dari 2^1
        2 * 2 = 4 */

    // jika eksponen negatif, hitung pangkat positif dari eksponen tersebut dan kemudian mengambil kebalikannya (1 dibagi hasil rekursif)
    } else {
        return 1 / rekursifPangkat(basis, -eksponen);
    }
}

// fungsi rekursif untuk menghitung akar kuadrat (sqrt)
double rekursifAkar(double bilangan, double tebakan) {
    // cek apakah tebakan sudah cukup dekat dengan akar kuadrat, menggunakan perbandingan
    // dengan toleransi 0.000001 untuk menentukan kedekatan
    if (fabs(tebakan * tebakan - bilangan) < 0.000001) {
        // jika ya, kembalikan tebakan sebagai hasil
        return tebakan;
    }
        /* jika belum, hitung tebakan baru yang lebih mendekati
        misal, akar kuadrat dari 9, dengan tebakan 3:
        (3 + 9 / 3) / 2 = (3 + 3) / 2 = 3
        3*3 = 9 (sudah akurat dengan bilangan yang ingin dicari akarnya yakni 9) */
    return rekursifAkar(bilangan, (tebakan + bilangan / tebakan) / 2);
}


// fungsi utama kalkulator
void kalkulator(double angka1, double angka2, char operasi) {
    double hasil; // variabel hasil perhitungan, hanya terlihat di dalam fungsi ini (local scope)
    
    switch (operasi) {
        case '+':
            hasil = angka1 + angka2; // rumus untuk operasi penjumlahan
            printf("\n\tHasil dari %.2lf + %.2lf = %.2lf\n", angka1, angka2, hasil);
            break;
        case '-':
            hasil = angka1 - angka2; // rumus untuk operasi pengurangan
            printf("\n\tHasil dari %.2lf - %.2lf = %.2lf\n", angka1, angka2, hasil);
            break;
        case '*':
            hasil = angka1 * angka2; // rumus untuk operasi perkalian
            printf("\n\tHasil dari %.2lf * %.2lf = %.2lf\n", angka1, angka2, hasil);
            break;
        case '/':
            if (angka2 == 0) { // error handling apabila memasukkan 0 sebagai pembagi
                printf("\n\tTidak bisa membagi dengan 0!\n");
            } else {
                hasil = angka1 / angka2; // rumus pembagian
                printf("\n\tHasil dari %.2lf / %.2lf = %.2lf\n", angka1, angka2, hasil);
            }
            break;
        case '^':
            hasil = rekursifPangkat(angka1, (int)angka2); // memanggil fungsi pangkat (power)
            printf("\n\tHasil dari %.2lf ^ %.2lf = %.2lf\n", angka1, angka2, hasil);
            break;
        case 's':
            if (angka1 < 0) { // error handling apabila memasukkan bilangan negatif
                printf("\n\tTidak bisa menghitung akar bilangan negatif!\n");
            } else {
                hasil = rekursifAkar(angka1, angka1 / 2); //memanggil fungsi akar (sqrt)
                printf("\n\tHasil dari akar(%.2lf) = %.2lf\n", angka1, hasil);
            }
            break;
        default:
            printf("\n\tOperasi yang dipilih tidak valid!\n"); // error handling apabila memasukkan selain character operasi
    }
}

int main() {
    double angka1, angka2;
    char operasi;

    printf("Masukkan angka pertama: \n"); // input angka pertama
    scanf("%lf", &angka1);

    printf("Masukkan angka kedua (abaikan untuk operasi akar): \n"); // input angka kedua
    scanf("%lf", &angka2);

    printf("Masukkan operasi (+, -, *, /, ^, s (sqrt)): "); // memilih operasi
    scanf(" %c", &operasi);

    // memanggil fungsi kalkulator
    kalkulator(angka1, angka2, operasi);

    return 0;
}
