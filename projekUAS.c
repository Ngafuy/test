#include <stdio.h>
#include <ctype.h>
#include <string.h>
int totalHarga, tiket;

int seat(int kd_krt){
    switch (kd_krt){
    case 1: tiket = 12;
        break;
    case 2: tiket = 5;
        break;
    case 3: tiket = 21;
        break;
    case 4: tiket = 2;
    }
}

int hargaKereta(int kd){
    switch (kd) {
    case 1: totalHarga = 190000;
        break;
    case 2: totalHarga = 220000;
        break;
    case 3: totalHarga = 250000;
        break;
    case 4: totalHarga = 360000;
        break;
    }
}

int main(){
    printf("====================================\n");
    printf("       HARGA TIKET KERETA API      \n");
    printf("        JAKARTA-YOGYAKARTA      \n");
    printf("====================================\n");

    int kereta;
    printf("\n====================================\n");
    printf("KERETA YANG TERSEDIA\n");
    printf("1. Fajar Utama\n");
    printf("2. Mataram\n");
    printf("3. BangunKarta\n");
    printf("4. Taksaka\n");

    do {
        printf("\nPILIH KODE KERETA: ");
        scanf("%d", &kereta);
        if (kereta<1 || kereta>4){
            printf("Kode masukan salah\n");
        }
    } while (kereta<1 || kereta>4);

    hargaKereta(kereta);
    printf("======================================\n");

    int kelas;
    printf("\n======================================\n");
    printf("KELAS YANG TERSEDIA\n");
    printf("1. Eksekutif    Rp %d\n", totalHarga+100000);
    printf("2. Ekonomi      Rp %d\n", totalHarga);

    do{
        printf("\nPILIH KODE KELAS KERETA: ");
        scanf("%d", &kelas);
        if(kelas<1 || kelas>2){
            printf("Kode masukan salah\n");
        }
    } while(kelas<1 || kelas>2);

    if (kelas == 1){
        totalHarga += 100000;
    }

    printf("======================================\n");

    int pesan;
    printf("\n==========================================================\n");
    seat(kereta);
    printf("%d Kursi tersedia\n", tiket);

    do{
        printf("\nTentukan jumlah tiket pemesanan: ");
        scanf("%d", &pesan);
        if (pesan<1 || pesan>tiket){
            printf("Jumlah pemesanan salah atau melebihi kursi yang tersedia!\n");
        }
    } while(pesan<1 || pesan>tiket);
    totalHarga *= pesan;

    printf("Total harga: Rp %d\n", totalHarga);

    char konfirmasi[10];
    printf("\nLanjutkan ke pembayaran?\n");
    printf("Ya\n");
    printf("Tidak\n");

    printf("\nPILIH MASUKAN: ");
    scanf("%s", konfirmasi);

    for(int i=0; konfirmasi[i];i++){
        konfirmasi[i] = tolower(konfirmasi[i]);
    }

    if (strcmp(konfirmasi, "ya") == 0){
        printf("\n==========================================================\n");
        printf("        TERIMA KASIH TELAH MENGGUNAKAN PROGRAM PEMBELIAN\n");
        printf("                    TIKET KERETA API KAMI               \n");
    } if (strcmp(konfirmasi, "tidak") == 0){
        printf("Pemesanan dibatalkan!\n");
    } if (strcmp(konfirmasi, "ya") != 0 && strcmp(konfirmasi, "tidak") != 0) {
        printf("Masukan salah!\n");
        printf("Pemesanan dibatalkan!\n");
    }
    printf("==========================================================\n");

    int end;
    scanf("%d", &end);
}usage: git [-v | --version] [-h | --help] [-C <path>] [-c <name>=<value>]
           [--exec-path[=<path>]] [--html-path] [--man-path] [--info-path]
           [-p | --paginate | -P | --no-pager] [--no-replace-objects] [--bare]
           [--git-dir=<path>] [--work-tree=<path>] [--namespace=<name>]
           [--config-env=<name>=<envvar>] <command> [<args>]

These are common Git commands used in various situations:

start a working area (see also: git help tutorial)
   clone     Clone a repository into a new directory
   init      Create an empty Git repository or reinitialize an existing one

work on the current change (see also: git help everyday)
   add       Add file contents to the index
   mv        Move or rename a file, a directory, or a symlink
   restore   Restore working tree files
   rm        Remove files from the working tree and from the index

examine the history and state (see also: git help revisions)
   bisect    Use binary search to find the commit that introduced a bug
   diff      Show changes between commits, commit and working tree, etc
   grep      Print lines matching a pattern
   log       Show commit logs
   show      Show various types of objects
   status    Show the working tree status

grow, mark and tweak your common history
   branch    List, create, or delete branches
   commit    Record changes to the repository
   merge     Join two or more development histories together
   rebase    Reapply commits on top of another base tip
   reset     Reset current HEAD to the specified state
   switch    Switch branches
   tag       Create, list, delete or verify a tag object signed with GPG

collaborate (see also: git help workflows)
   fetch     Download objects and refs from another repository
   pull      Fetch from and integrate with another repository or a local branch
   push      Update remote refs along with associated objects

'git help -a' and 'git help -g' list available subcommands and some
concept guides. See 'git help <command>' or 'git help <concept>'
to read about a specific subcommand or concept.
See 'git help git' for an overview of the system.
