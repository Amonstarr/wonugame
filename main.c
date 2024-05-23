#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct operator
{
    char username[20], password[20], email[20], nomor_telepon[20], menu[20], status[20];
} data_operator, operator_aktif;

struct customer
{
    char username[20], password[20], email[20], nomor_telepon[20], menu[20], status[20];
    int saldo, harga, jumlah, pengeluaran;
} data_customer, customer_aktif;

struct pesanan
{
    char nama[20], makanan[20], minuman[20];
    int jumlah, harga;
} pesanan[500];

struct game
{
    char game[20]
} game;

struct warnet
{
    int lama, total;
} warnet;


void menu_registrasi();
void registrasi_operator();
void resigtrasi_customer();
int login_operator();
int login_customer();
void menu_operator();
void manajemen_pc();
void manajemen_akun();
//void tambah_menu();
void ubah_status();
void hapus_akun_cust();
void lihat_akun_cust();
void install_sistem();
void install_game();
void install_program();
void hapus_game();
void hapus_program();
void billing_warnet();
//void pilih_game();
//void pesan_makanan_minuman();
void cek_status();
void informasi_saldo();
void topup_saldo();
void bayar();

int main()
{
    int menu;

    printf("============================================================\n");
    printf("------------------------- D'WARNET -------------------------\n");
    printf("============================================================\n");
    printf("1.Registrasi Akun\n2.Login Operator\n3.Login Customer\n4.Keluar\n");
    printf("pilih menu (1/2/3/4/5) : "); scanf("%d", &menu);   
    getchar();
    system("cls");

    switch (menu)
    {
        case 1:
        menu_registrasi();
        break;

        case 2:
        login_operator(3);
        break;

        case 3:
        login_customer();
        break;

        case 4:
        printf("Exiting the program\n");
        break;

        case 5:
        printf("Maaf Pilihan Tidak Tersedia\n");
        main();
        break;
    }
    return 0;
}

void menu_registrasi()
{
    int menu;

    printf("============================================================\n");
    printf("------------------------- D'WARNET -------------------------\n");
    printf("============================================================\n");

    printf("1. Registrasi Operator\n2. Registrasi Customer\n3. Keluar\n");
    printf("pilih menu (1/2/3) : "); scanf("%d", &menu);
    getchar();
    system("cls");

    switch (menu)
    {
        case 1:
        registrasi_operator();
        break;

        case 2:
        resigtrasi_customer();
        break;

        case 3:
        main();
        break;

        default:
        printf("Maaf Pilihan Tidak Tersedia\n");
        main();
        break;
    }
}

void registrasi_operator()
{
    printf("============================================================\n");
    printf("------------------------- D'WARNET -------------------------\n");
    printf("============================================================\n");
    FILE *akun;
    struct operator data_operator = {0};

    akun = fopen("akun_operator.dat", "ab");

    printf("Masukkan Username : ");
    gets(data_operator.username);
    printf("Masukkan Password : ");
    gets(data_operator.password);
    printf("Masukkan Email : ");
    gets(data_operator.email);
    printf("Masukkan Nomor Telepon : ");
    gets(data_operator.nomor_telepon);

    fwrite(&data_operator, sizeof(data_operator), 1, akun);
    fclose(akun);

    printf("Registrasi Berhasil\n");
    system("pause");
    system("cls");
    main();
}

void resigtrasi_customer()
{
    printf("============================================================\n");
    printf("------------------------- D'WARNET -------------------------\n");
    printf("============================================================\n");
    FILE *akun;
    struct operator data_customer = {0};

    akun = fopen("akun_customer.dat", "ab");

    printf("Masukkan Username : ");
    gets(data_customer.username);
    printf("Masukkan Password : ");
    gets(data_customer.password);
    printf("Masukkan Email : ");
    gets(data_customer.email);
    printf("Masukkan Nomor Telepon : ");
    gets(data_customer.nomor_telepon);

    fwrite(&data_customer, sizeof(data_customer), 1, akun);
    fclose(akun);

    printf("Registrasi Berhasil\n");
    system("pause");
    system("cls");
    main();
}

int login_operator(int attempt)
{
    printf("============================================================\n");
    printf("------------------------- D'WARNET -------------------------\n");
    printf("============================================================\n");

    FILE *akun_operator;
    struct operator data_operator;

    akun_operator = fopen("akun_operator.dat", "rb");

    char username[30], password[30];

    printf("Masukkan Username : ");
    gets(username);

    while (fread(&data_operator, sizeof(data_operator), 1, akun_operator)==1)
    {
        if (strcmp(data_operator.username, username)==0)
        {
            printf("Masukkan Password : ");
            gets(password);
            if (strcmp(data_operator.password, password)==0)
            {
                operator_aktif = data_operator;
                fclose(akun_operator);
                system("cls");
                attempt = -1;
                break;
            }
            else
            {
                attempt--;
            }
        }
    }
    if (attempt == -1)
    {
        menu_operator();
    }
    else if (attempt > 0)
    {
        printf("============================================================\n");
        printf("------------------------- D'WARNET -------------------------\n");
        printf("============================================================\n");
        fclose(akun_operator);
        login_operator(attempt);
    }
    else
    {
        printf("Maaf kesempatan percobaan sudah habis\n");
        system("pause");
        system("cls");
        fclose(akun_operator);
        main();
    }
}

int login_customer(int attempt)
{
    printf("============================================================\n");
    printf("------------------------- D'WARNET -------------------------\n");
    printf("============================================================\n");

    FILE *akun_customer;
    struct operator data_customer;

    akun_customer = fopen("akun_customer.dat", "rb");

    char username[30], password[30];

    printf("Masukkan Username : ");
    gets(username);

    while (fread(&data_customer, sizeof(data_customer), 1, akun_customer)==1)
    {
        if (strcmp(data_customer.username, username)==0)
        {
            printf("Masukkan Password : ");
            gets(password);
            if (strcmp(data_customer.password, password)==0)
            {
                operator_aktif = data_customer;
                fclose(akun_customer);
                system("cls");
                attempt = -1;
                break;
            }
            else
            {
                attempt--;
            }
        }
    }
    if (attempt == -1)
    {
        menu_operator();
    }
    else if (attempt > 0)
    {
        printf("============================================================\n");
        printf("------------------------- D'WARNET -------------------------\n");
        printf("============================================================\n");
        fclose(akun_customer);
        login_operator(attempt);
    }
    else
    {
        printf("Maaf kesempatan percobaan sudah habis\n");
        system("pause");
        system("cls");
        fclose(akun_customer);
        main();
    }
}

void menu_operator()
{
    int menu;

    printf("============================================================\n");
    printf("------------------------- D'WARNET -------------------------\n");
    printf("============================================================\n");

    printf("1. Manajemen PC Customer\n2. Manajemen Akun Customer\n3. Tambah Menu Pesanan\n4. Ubah Status Pesanan Customer\n5. Log Out\n");
    printf("pilih menu (1/2/3/4/5) : "); scanf("%d", &menu);
    getchar();
    system("cls");

    switch (menu)
    {
        case 1:
        manajemen_pc();
        break;

        case 2:
        manajemen_akun();
        break;

        case 3:
        //tambah_menu();
        break;

        case 4:
        ubah_status();
        break;

        case 5:
        printf("Berhasil Logout\n");
        system("pause");
        system("cls");
        main();

        default:
        printf("Maaf pilihan anda tidak tersedia\n");
        break;
    }
}

void menu_customer()
{
    int menu;

    printf("============================================================\n");
    printf("------------------------- D'WARNET -------------------------\n");
    printf("============================================================\n");

    printf("1. Paket warnet\n2. Pilih game\n3. Pesan makanan/minuman\n4. Lihat status makanan\n5. informasi saldo\n6. Kembali\n");
    printf("pilih menu (1/2/3/4/5/6) : ");
    scanf("%d", &menu);
    getchar();
    system("cls");

    switch (menu)
    {
        case 1:
        billing_warnet();
        break;

        case 2:
        //pilih_game();
        break;

        case 3:
        //pesan_makanan_minuman();
        break;

        case 4:
        cek_status();
        break;

        case 5:
        informasi_saldo();
        break;

        case 6:
        printf("Berhasil Kembali\n");
        system("pause");
        system("cls");
        main();

        default:
        printf("Maaf pilihan anda tidak tersedia\n");
        main();
        break;
    }
}


void manajemen_akun()
{
    int menu;

    printf("====================== Manajemen Akun =====================\n");
    printf("1. Hapus Akun Customer\n2. Lihat Akun Customer\n3. Kembali");
    printf("pilih menu (1/2/3) : "); scanf("%d", &menu);
    getchar();
    system("cls");
    
    switch (menu)
    {
        case 1:
        hapus_akun_cust();
        break;

        case 2:
        lihat_akun_cust();
        break;

        case 3:
        system("pause");
        system("cls");
        menu_operator();

        default:
        printf("Maaf pilihan anda tidak tersedia\n");
        break;
    }
}

void manajemen_pc()
{
    int menu;

    printf("====================== Manajemen Akun =====================\n");
    printf("1. Install Windows\n2. Install Game\n3. Install Program\n4. Hapus Game\n5. Hapus Program\n6. Kembali");
    printf("pilih menu (1/2/3/4/5/6) : "); scanf("%d", &menu); 
    getchar();
    system("cls");
    
    switch (menu)
    {
        case 1:
        install_sistem();
        break;

        case 2:
        install_game();
        break;

        case 3:
        install_program();
        break;

        case 4:
        hapus_game();
        break;

        case 5:
        hapus_program();
        break;

        case 6:
        system("pause");
        system("cls");
        menu_operator();

        default:
        printf("Maaf pilihan anda tidak tersedia\n");
        break;
    }
}

void ubah_status()
{
    FILE *akun;
    FILE *akun2;

    char cari[20], tempStatus[20];
    int menu;

    akun = fopen("akun_customer.dat", "rb");
    akun = fopen("akun_customer.dat", "wb");

    printf("============================================================\n");
    printf("------------------------- D'WARNET -------------------------\n");
    printf("============================================================\n");

    printf("Masukkan username akun customer "); gets(cari);

    printf("Pilih Status baru : \n");
    printf("1. Belum dikerjakan\n2. Sedang dikerjakan\n3. Selesai\n");
    printf("pilih menu (1/2/3) : "); scanf("%d", &menu);
    getchar();

    switch (menu)
    {
        case 1:
        strcpy(tempStatus, "Belum dikerjakan\n");
        system("cls");
        break;

        case 2:
        strcpy(tempStatus, "Sedang dikerjakan\n");
        system("cls");
        break;

        case 3:
        strcpy(tempStatus, "Selesai\n");
        system("cls");
        break;

        default:
        printf("Pilihan tidak valid.\n");
        fclose(akun);
        fclose(akun2);
        menu_operator();
        break;
    }
    while (fread(&data_customer, sizeof(data_customer), 1, akun)==1)
    {
        if (strcmp(data_customer.username, cari)==0)
        {
            strcpy(data_customer.status, tempStatus);
        }
        fwrite(&data_customer, sizeof(data_customer), 1, akun2);
    }
    fclose(akun);
    fclose(akun);
    remove("akun_customer.dat");
    rename("akun_customer2.dat", "akun_customer.dat");
    printf("Status pesanan berhasil diubah");
    system("pause");
    system("cls");
    menu_operator();
}

void hapus_akun_cust()
{
    FILE *akun_customer;
    struct operator data_customer;

    akun_customer = fopen("akun_customer", "rb");
    
    if (akun_customer == 0)
    {
        printf("Gagal membuka file\n");
        return;
    }

    printf("Data akun customer");

    while(fread(&data_customer, sizeof(data_customer), 1, akun_customer)==1)
    {
        printf("Username: %s\n", data_customer.username);
        printf("\n");
    }

    FILE *akun;
    FILE *akun2;

    char cari[20];

    akun = fopen("akun_customer.dat", "rb");
    akun2 = fopen("akun_customer2.dat", "wb");

    printf("Masukkan Username Akun Yang Ingin Dihapus : "); gets(cari);

    while (fread(&data_customer, sizeof(data_customer), 1, akun)==1)
    {
        if(strcmp(data_customer.username, cari)!=0){
            fwrite(&data_customer, sizeof(data_customer), 1, akun2);
        }

        fclose(akun);
        fclose(akun2);
        remove("akun");
        rename("akun2", "akun");
        printf("data berhasil dihapus");
        system("pause");
        menu_operator();
    }
}

void cek_status()
{
    FILE *file;
    struct pesanan pesan;

    file = fopen("data pesanan.dat", "rb");
    if (file == NULL)
    {
        printf("Gagal membuka file pesanan.\n");
        return;
    }

    printf("========================= Indormasi Pesanan ========================\n");  

    while (fread(&pesan, sizeof(pesan), 1, file) == 1)
    {
        printf("Nama Pemesan\t: %s\n", pesan.nama);
        printf("Jumlah Pesanan\t: %d\n", pesan.jumlah);
        printf("status pesanan : %s\n", customer_aktif.status);
    }

    fclose(file);
    system("pause");
    system("cls");
    menu_customer();
}

void informasi_akun_customer()
{

    FILE *file;
    struct operator operator_aktif;

    file = fopen("akun_customer.dat", "rb");

    if (file == NULL)
    {
        printf("Gagal membuka file.\n");
        return;
    }

    printf("Data Akun Customer:\n");
    while (fread(&data_customer, sizeof(data_customer), 1, file) == 1)
    {
        printf("Username: %s\n", data_customer.username);
        printf("Password: %s\n", data_customer.password);
        printf("Nomor telepon : %s\n", data_customer.nomor_telepon);
        printf("Email: %s\n", data_customer.email);
        printf("\n");
    }

    fclose(file);
    system("pause");
    system("cls");
    menu_operator();
}

void informasi_saldo()
{
    int jumlah, menu, hasil = 0;
    FILE *akun;
    FILE *akun2;

    printf("========================= Menu Saldo ========================\n");
    printf("1. Cek saldo\n2. Topup saldo\n3. Kembali\n");
    printf("Pilih menu (1/2/3) : ");
    scanf("%d", &menu);
    system("cls");

    switch (menu)
    {
        case 1:
        akun = fopen("akun_customer", "rb");
        if (akun == NULL)
        {
            printf("Gagal membuka file");
            return;
        }
        while (fread(&customer_aktif, sizeof(customer_aktif), 1, akun)==1)
        {
            if (strcmp(data_customer.username, customer_aktif.username)==0)
            {
                printf("Saldo Anda: Rp %d\n", customer_aktif.saldo);
                break;
            }
        }

        fclose(akun);
        system("pause");
        system("cls");
        break;

        case 2:
        hasil = customer_aktif.saldo;
        akun = fopen("akun_customer.dat", "rb");
        akun = fopen("akun_customer2.dat", "wb");

        printf("========================= Top Up ========================\n");
        printf("Masukkan jumlah top up saldo : Rp  ");
        scanf("%d", &jumlah);
        hasil = data_customer.saldo + jumlah;

        while (fread(&data_customer, sizeof(data_customer), 1, akun)==1)
        {
            if (strcmp(data_customer.username, customer_aktif.username)==0)
            {
                data_customer.saldo = hasil;
            }
            fwrite(&data_customer, sizeof(data_customer), 1, akun2);
        }
        printf("Top Up berhasil\nSaldo sekarang : Rp %d\n", hasil);
        fclose(akun);
        fclose(akun2);

        remove("akun_customer.dat");
        rename("akun_customer2.dat", "akun_customer.dat");
        system("pause");
        system("cls");
        menu_customer();
        break;

        case 3:
        fclose(akun);
        menu_customer();
        break;

        default:
        printf("Pilihan tidak valid. Silakan coba lagi.\n");
        informasi_saldo();
        break;
    }
}

void bayar()
{
    int harga, total;
    printf("============================================================\n");
    printf("------------------------- D'WARNET -------------------------\n");
    printf("============================================================\n");

    FILE *akun;
    FILE *akun2;

    akun = fopen("akun_customer.dat", "rb");
    akun2 = fopen("akun_customer2.dat", "wb");

    if (total > customer_aktif.saldo)
    {
    printf("Mohon maaf saldo anda tidak mencukupi\n");
        fclose(akun);
        fclose(akun2);
        system("pause");
        system("cls");
        menu_customer();
    }
    else
    {
        while (fread(&data_customer, sizeof(data_customer), 1, akun) == 1)
        {
            if (strcmp(customer_aktif.username, data_customer.username) == 0)
            {
                data_customer.saldo -= harga;
                data_customer.pengeluaran += harga;
                data_customer.jumlah += 1;
            }
            fwrite(&data_customer, sizeof(data_customer), 1, akun2);
        }
        fclose(akun);
        fclose(akun2);
        remove("akun_customer.dat");
        rename("akun_customer2.dat", "akun_customer.dat");
        printf("Setor Berhasil\n");
        system("pause");
        system("cls");
        menu_customer();
    }
}

void billing_warnet()
{
    int menu, total, harga = 5000, lama;

    FILE *akun;
    FILE *akun2;

    printf("====================== Pilih Paket =====================\n");
    printf("1. Paket 1\n2. Paket 2\n3. Paket 3\n4. Kembali");
    printf("pilih menu (1/2/3/4/5) : "); scanf("%d", &menu); 
    getchar();
    system("cls");

    switch (menu)
    {
        case 1:
        total = harga * 1;
        if (total > customer_aktif.saldo)
    {
    printf("Mohon maaf saldo anda tidak mencukupi\n");
        fclose(akun);
        fclose(akun2);
        system("pause");
        system("cls");
        menu_customer();
    }
    else
    {
        while (fread(&data_customer, sizeof(data_customer), 1, akun) == 1)
        {
            if (strcmp(customer_aktif.username, data_customer.username) == 0)
            {
                data_customer.saldo -= harga;
                data_customer.pengeluaran += harga;
                data_customer.jumlah += 1;
            }
            fwrite(&data_customer, sizeof(data_customer), 1, akun2);
        }
        fclose(akun);
        fclose(akun2);
        remove("akun_customer.dat");
        rename("akun_customer2.dat", "akun_customer.dat");
        printf("Setor Berhasil\n");
        system("pause");
        system("cls");
        menu_customer();
    }
        break;

        case 2:
        total = harga * 2;
        if (total > customer_aktif.saldo)
    {
    printf("Mohon maaf saldo anda tidak mencukupi\n");
        fclose(akun);
        fclose(akun2);
        system("pause");
        system("cls");
        menu_customer();
    }
    else
    {
        while (fread(&data_customer, sizeof(data_customer), 1, akun) == 1)
        {
            if (strcmp(customer_aktif.username, data_customer.username) == 0)
            {
                data_customer.saldo -= harga;
                data_customer.pengeluaran += harga;
                data_customer.jumlah += 1;
            }
            fwrite(&data_customer, sizeof(data_customer), 1, akun2);
        }
        fclose(akun);
        fclose(akun2);
        remove("akun_customer.dat");
        rename("akun_customer2.dat", "akun_customer.dat");
        printf("Setor Berhasil\n");
        system("pause");
        system("cls");
        menu_customer();
    }
        break;

        case 3:
        total = harga * 3;
        if (total > customer_aktif.saldo)
    {
    printf("Mohon maaf saldo anda tidak mencukupi\n");
        fclose(akun);
        fclose(akun2);
        system("pause");
        system("cls");
        menu_customer();
    }
    else
    {
        while (fread(&data_customer, sizeof(data_customer), 1, akun) == 1)
        {
            if (strcmp(customer_aktif.username, data_customer.username) == 0)
            {
                data_customer.saldo -= harga;
                data_customer.pengeluaran += harga;
                data_customer.jumlah += 1;
            }
            fwrite(&data_customer, sizeof(data_customer), 1, akun2);
        }
        fclose(akun);
        fclose(akun2);
        remove("akun_customer.dat");
        rename("akun_customer2.dat", "akun_customer.dat");
        printf("Setor Berhasil\n");
        system("pause");
        system("cls");
        menu_customer();
    }
        break;

        default:
        printf("Pilihan tidak tersedia\n");
        system("pause");
        system("cls");
        main();
    }
}
