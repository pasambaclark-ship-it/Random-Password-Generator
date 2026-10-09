#include<stdio.h>
#include<stdlib.h>
#include<time.h>

void seperator(int length) {
    for(int i = 0; i<=length; i++){
        printf("=");
    }
    printf("\n");
}

void gen_password(char *password, int length){
    const char uppercase[]="ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    const char lowercase[]="abcdefghijklmnopqrstuvwxyz";
    const char digits[]="0123456789";
    const char symbol[]="!@#$^&*()_+-=[]{};:'<>/?";
    const char all_chars[]="ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789!@#$^&*()_+-=[]{};:'<>/?";

    

    password[0]= uppercase[rand() % (sizeof(uppercase)-1)];
    password[1]= lowercase[rand() % (sizeof(lowercase)-1)];
    password[2]= digits[rand() % (sizeof(digits)-1)];
    password[3]= symbol[rand() % (sizeof(symbol)-1)];


    for(int i=3; i<length; i++) {
        password[i]= all_chars[rand() % (sizeof(all_chars)-1)];
    }
    for(int i=length - 1; i>0; i--) {
        int j= rand() % (i + 1);
        char temp = password[i];
        password[i] = password[j];
        password[j] = temp;
    }
    password[length] = '\0';
} 

int main () {
    char username[50];
    char password[9];
    char choice;

    srand((unsigned int)time(NULL));

do{
    seperator(50);
    printf("\t\tSIGN UP\n\n");
    printf("SYSTEM GENERATED PASSWORD? ");
    scanf(" %c", &choice);

    if(choice == 'Y' || choice == 'y'){
        printf("USERNAME: ");
        scanf("%49s", &username);
        printf("\n");

        gen_password(password, 8);
        printf("PASSWORD: %s", password);
      
        printf("\n");
        seperator(50);
    } else {
        printf("Can not Generate a Password, Please try again.");
    }
}while(choice != 'Y' || choice != 'y');
    return 0;
}
