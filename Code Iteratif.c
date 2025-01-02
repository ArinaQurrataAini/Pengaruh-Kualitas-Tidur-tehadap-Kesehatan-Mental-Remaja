#include <stdio.h>
#include <string.h>
#include <time.h>
#include <math.h> 

double hitung_konsentrasi_iteratif(int hari, double konsentrasi_awal, int kualitas_tidur) {
    double konsentrasi = konsentrasi_awal;

    for (int i = 0; i < hari; i++) {
        if (kualitas_tidur <= 0) {
            konsentrasi *= 0.50;
        } else if (kualitas_tidur < 6) {
            konsentrasi *= 0.90;
        } else if (kualitas_tidur >= 6 && kualitas_tidur <= 8) {
            konsentrasi *= 0.95;
        }
        if (konsentrasi < 10.0) {
            konsentrasi = 10.0;
            break;
        }
    }
    return konsentrasi;
}

void buat_nama_mahasiswa(char nama[], int id) {
    const char* daftar_nama[] = {"Andi", "Budi", "Citra", "Dewi", "Eka", "Fajar", "Gita", "Hendra", "Indah", "Joko"};
    sprintf(nama, "%s", daftar_nama[id % 10]); // Memilih nama dari daftar secara siklis
}

void evaluasi_kesehatan_mental(const char* nama, double konsentrasi_akhir, int kualitas_tidur) {
    printf("\n=== Evaluasi Kesehatan Mental untuk %s ===\n", nama);

    if (kualitas_tidur < 6) {
        printf("Kualitas tidur: Rendah. Risiko depresi tinggi.\n");
    } else if (kualitas_tidur <= 8) {
        printf("Kualitas tidur: Sedang. Risiko depresi sedang.\n");
    } else {
        printf("Kualitas tidur: Tinggi. Risiko depresi ringan.\n");
    }

    if (konsentrasi_akhir < 50.0) {
        printf("Konsentrasi: Rendah. Ada risiko gangguan serius.\n");
    } else if (konsentrasi_akhir <= 80.0) {
        printf("Konsentrasi: Sedang. Ada risiko gangguan kecil.\n");
    } else {
        printf("Konsentrasi: Tinggi. Kondisi mental baik.\n");
    }

    printf("Rekomendasi: ");
    if (kualitas_tidur < 6) {
        printf("Tingkatkan waktu tidur, hindari kafein, dan kurangi stres.\n");
    } else if (kualitas_tidur <= 8) {
        printf("Pertahankan pola tidur, hindari gadget sebelum tidur.\n");
    } else {
        printf("Pertahankan kualitas tidur dan gaya hidup sehat.\n");
    }
}

void cetak_hasil(const char* dataset, int no_urut, const char* nama, int hari, double konsentrasi_awal, double konsentrasi_akhir, int kualitas_tidur) {
    printf("\n%s: Data %d\n", dataset, no_urut);
    printf("Nama: %s\n", nama);
    printf("Konsentrasi awal: %.2f%%\n", konsentrasi_awal);
    printf("Jumlah hari: %d\n", hari);
    printf("Kualitas tidur rata-rata: %d jam/hari\n", kualitas_tidur);
    printf("Konsentrasi akhir setelah %d hari: %.2f%%\n", hari, konsentrasi_akhir);

    evaluasi_kesehatan_mental(nama, konsentrasi_akhir, kualitas_tidur);
}

int main() {
    int hari, kualitas_tidur;
    double konsentrasi_awal;
    char nama[50];

    clock_t start, end;
    double waktu_dataset1, waktu_dataset2;

    printf("=== Program Pengaruh Kualitas Tidur terhadap Konsentrasi ===\n");

    printf("\n--- Dataset 1: Iteratif ---\n");
    start = clock(); // Mulai waktu untuk Dataset 1

    for (int i = 1; i <= 100; i++) {
        buat_nama_mahasiswa(nama, i); // Buat nama mahasiswa secara otomatis
        hari = i;
        kualitas_tidur = (i % 3 == 0) ? 6 : ((i % 2 == 0) ? 8 : 7); 
        konsentrasi_awal = 100.0; 

        double konsentrasi_akhir = hitung_konsentrasi_iteratif(hari, konsentrasi_awal, kualitas_tidur);
        cetak_hasil("Dataset 1", i, nama, hari, konsentrasi_awal, konsentrasi_akhir, kualitas_tidur);
    }

    end = clock(); // Akhir waktu untuk Dataset 1
    waktu_dataset1 = ((double)(end - start)) / CLOCKS_PER_SEC;
    printf("\nWaktu eksekusi Dataset 1: %.2f detik\n", waktu_dataset1);

    double estimasi_waktu_dataset1 = pow(100, 2) * waktu_dataset1 / 100; // O(n^2)
    printf("Estimasi waktu eksekusi O(n^2) untuk Dataset 1: %.2f detik\n", estimasi_waktu_dataset1);

    printf("\n--- Dataset 2: Iteratif ---\n");
    start = clock(); 

    for (int i = 1; i <= 10; i++) {
        buat_nama_mahasiswa(nama, i + 100);
        hari = i * 2;
        kualitas_tidur = (i % 2 == 0) ? 7 : 8; 
        konsentrasi_awal = 90.0;

        double konsentrasi_akhir = hitung_konsentrasi_iteratif(hari, konsentrasi_awal, kualitas_tidur);
        cetak_hasil("Dataset 2", i, nama, hari, konsentrasi_awal, konsentrasi_akhir, kualitas_tidur);
    }

    end = clock(); 
    waktu_dataset2 = ((double)(end - start)) / CLOCKS_PER_SEC;
    printf("\nWaktu eksekusi Dataset 2: %.2f detik\n", waktu_dataset2);

    double estimasi_waktu_dataset2 = pow(10, 2) * waktu_dataset2 / 10; // O(n^2)
    printf("Estimasi waktu eksekusi O(n^2) untuk Dataset 2: %.2f detik\n", estimasi_waktu_dataset2);

    printf("\nProgram selesai. Terima kasih!\n");
    return 0;
}
