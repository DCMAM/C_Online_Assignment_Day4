#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define max_song 200
#define max_user 20

void song_by_title();
void song_by_artist();	
	
/*

note (bug):
- harus fullscreen biar rapih
- kalo habis add sesuatu musti keluar dari program dulu
- belum validasi '.com' di menu add user
- sorting nya baru jalan setengah 

*/


void print_menu(){
	printf("Welcome to SOtify\n");
	printf("\"Where Listening is Everything\"\n");
	printf("===============================\n");
	printf("1. Login\n");
	printf("2. Register\n");
	printf("3. Exit\n");
	printf(">> ");
}

void print_menu2(char email[32]){
	printf("Hello %s\n", email);
	printf("==================\n");
	printf("1. View All Songs\n");
	printf("2. Add New Song\n");
	printf("3. Search Song\n");
	printf("4. View My Library\n");
	printf("5. Logout\n");
	printf(">> ");
}

void print_song(){
	char line[max_song][100];
	
	char title[max_song][100];
	char artist[max_song][50];
	char year[max_song][50];
	char genre[max_song][50];
	
	FILE *fp = fopen("dataSong.txt", "r+");
	
	if(! fp ){
		printf("Creating File..\n");
		fopen("dataSong.txt", "w");
		return;
	}
	
	int x=0;
    while (1) {
    	if(feof(fp)) break;
		fscanf(fp, "%[^\n]", line[x]); 
		fgetc(fp);
		
		char *p = strtok(line[x], "\t");
	
		int z=0;
	    while(p != NULL){
	    	if(z%4 == 0) strcpy(title[x], p);
	    	if(z%4 == 1) strcpy(artist[x], p);
	    	if(z%4 == 2) strcpy(year[x], p);
	    	if(z%4 == 3) strcpy(genre[x], p);
	        p = strtok (NULL, "\t");
	        z++;
		}
		
		x++;
    }
    
	printf("=========================================================================================================================\n");
	printf("%| %-4s | %-32s | %-32s | %5s | %-32s |\n", "No.", "Song Title", "Artist", "Year", "Genre");
	printf("=========================================================================================================================\n");
	for(int i=0; i<x; i++){
		printf("| %-4d | %-32s | %-32s | %5s | %-32s |\n", i+1, title[i], artist[i], year[i], genre[i]);
//    	printf("%s\n", line2[i2]);
	}
	printf("=========================================================================================================================\n");
	
	int menu;
	printf("1. Sort by Song Title\n");
	printf("2. Sort by Artist\n");
	printf("> ");
	scanf("%d", &menu);
	if(menu == 1){
		song_by_title();
	}
	else if(menu == 2){
		song_by_artist();	
	}
	else if(menu == 3){
		return;
	}
}

void print_song_name(char name[50], char user[50]){
	char line[max_song][100];
	
	char title[max_song][100];
	char artist[max_song][50];
	char year[max_song][50];
	char genre[max_song][50];
	
	FILE *fp = fopen("dataSong.txt", "r+");
	
	if(! fp ){
		printf("Creating File..\n");
		fopen("dataSong.txt", "w");
		return;
	}
	
	int x=0;
    while (1) {
    	if(feof(fp)) break;
		fscanf(fp, "%[^\n]", line[x]); 
		fgetc(fp);
		
		char *p = strtok(line[x], "\t");
	
		int z=0;
	    while(p != NULL){
	    	if(z%4 == 0) strcpy(title[x], p);
	    	if(z%4 == 1) strcpy(artist[x], p);
	    	if(z%4 == 2) strcpy(year[x], p);
	    	if(z%4 == 3) strcpy(genre[x], p);
	        p = strtok (NULL, "\t");
	        z++;
		}
		
		x++;
    }
    
	printf("=========================================================================================================================\n");
	printf("%| %-4s | %-32s | %-32s | %5s | %-32s |\n", "No.", "Song Title", "Artist", "Year", "Genre");
	printf("=========================================================================================================================\n");
	for(int i=0; i<x; i++){
		if(strcmp(artist[i], name) == 0) printf("| %-4d | %-32s | %-32s | %5s | %-32s |\n", i+1, title[i], artist[i], year[i], genre[i]);
//    	printf("%s\n", line2[i2]);
	}
	printf("=========================================================================================================================\n");
	int menu;
	printf("1. Add Song to Library\n");
	printf("2. Back\n");
	printf("> ");
	scanf("%d", &menu);
	if(menu == 1){
		FILE *fp2 = fopen("dataLibrary.txt", "a+");
//		fprintf(fp2, "%s\t%s\t%d\t%s\t%s\n", title, artist, year, genre, user);	
		for(int i=0; i<x; i++){
			if(strcmp(title[i], name) == 0) fprintf(fp2, "%s\t%s\t%d\t%s\t%s\n", title[i], artist[i], year[i], genre[i], user);
	//    	printf("%s\n", line2[i2]);
		}
	}
}

void print_song_song(char song[100], char user[50]){
	char line[max_song][100];
	
	char title[max_song][100];
	char artist[max_song][50];
	char year[max_song][50];
	char genre[max_song][50];
	
	FILE *fp = fopen("dataSong.txt", "r+");
	
	if(! fp ){
		printf("Creating File..\n");
		fopen("dataSong.txt", "w");
		return;
	}
	
	int x=0;
    while (1) {
    	if(feof(fp)) break;
		fscanf(fp, "%[^\n]", line[x]); 
		fgetc(fp);
		
		char *p = strtok(line[x], "\t");
	
		int z=0;
	    while(p != NULL){
	    	if(z%4 == 0) strcpy(title[x], p);
	    	if(z%4 == 1) strcpy(artist[x], p);
	    	if(z%4 == 2) strcpy(year[x], p);
	    	if(z%4 == 3) strcpy(genre[x], p);
	        p = strtok (NULL, "\t");
	        z++;
		}
		
		x++;
    }
    
	printf("=========================================================================================================================\n");
	printf("%| %-4s | %-32s | %-32s | %5s | %-32s |\n", "No.", "Song Title", "Artist", "Year", "Genre");
	printf("=========================================================================================================================\n");
	for(int i=0; i<x; i++){
		if(strcmp(title[i], song) == 0) printf("| %-4d | %-32s | %-32s | %5s | %-32s |\n", i+1, title[i], artist[i], year[i], genre[i]);
//    	printf("%s\n", line2[i2]);
	}
	printf("=========================================================================================================================\n");
	int menu;
	printf("1. Add Song to Library\n");
	printf("2. Back\n");
	printf("> ");
	scanf("%d", &menu);
	if(menu == 1){
		FILE *fp2 = fopen("dataLibrary.txt", "a+");
//		fprintf(fp2, "%s\t%s\t%d\t%s\t%s\n", title, artist, year, genre, user);	
		for(int i=0; i<x; i++){
			if(strcmp(title[i], song) == 0) fprintf(fp2, "%s\t%s\t%d\t%s\t%s\n", title[i], artist[i], year[i], genre[i], user);
	//    	printf("%s\n", line2[i2]);
		}
	}
}

void print_library(char user[32]){
	char line[max_song][100];
	
	char title[max_song][100];
	char artist[max_song][50];
	char year[max_song][50];
	char genre[max_song][50];
	char email[max_song][32];
	
	FILE *fp = fopen("dataLibrary.txt", "r+");
	
	if(! fp ){
		printf("Creating File..\n");
		fopen("dataLibrary.txt", "w");
		return;
	}
	
	int x=0;
    while (1) {
    	if(feof(fp)) break;
		fscanf(fp, "%[^\n]", line[x]); 
		fgetc(fp);
		
		char *p = strtok(line[x], "\t");
	
		int z=0;
	    while(p != NULL){
	    	if(z%5 == 0) strcpy(title[x], p);
	    	if(z%5 == 1) strcpy(artist[x], p);
	    	if(z%5 == 2) strcpy(year[x], p);
	    	if(z%5 == 3) strcpy(genre[x], p);
	    	if(z%5 == 4) strcpy(email[x], p);
	        p = strtok (NULL, "\t");
	        z++;
		}
		
		x++;
    }

	
	printf("============================================================================================================================================================\n");
	printf("%| %-4s | %-32s | %-32s | %5s | %-32s | %-32s |\n", "No.", "Song Title", "Artist", "Year", "Genre", "User");
	printf("============================================================================================================================================================\n");
	for(int i=0; i<x; i++){
//		printf("| %-4d | %-32s | %-32s | %5s | %-32s | %-32s |\n", i+1, title[i], artist[i], year[i], genre[i], email[i]);
		if(strcmp(user, email[i])==0) printf("| %-4d | %-32s | %-32s | %5s | %-32s | %-32s |\n", i+1, title[i], artist[i], year[i], genre[i], email[i]);
//    	printf("%s\n", line2[i2]);
	}
	printf("============================================================================================================================================================\n");
}

//int get_data_song_size(int data_song_size){
//	FILE *fp = fopen("dataSong.txt", "r");
//	
//	char line[max_song][100];
//    
//	while (1) {
//    	if(feof(fp)) break;
//		fscanf(fp, "%[^\n]", line[data_song_size]); 
//		fgetc(fp);
//		data_song_size++;
//    }
//    return data_song_size;
//}
//
//void load_song(char title[][100], char artist[][50], char year[][50], char genre[][50], int data_song_size){
//	char line[max_song][100];
//	
//	FILE *fp = fopen("dataSong.txt", "r");
//	
//	data_song_size=0;
//    while (1) {
//    	if(feof(fp)) break;
//		fscanf(fp, "%[^\n]", line[data_song_size]); 
//		fgetc(fp);
//		
//		char *p = strtok(line[data_song_size], "\t");
//	
//		int z=0;
//	    while(p != NULL){
//	    	if(z%4 == 0) strcpy(title[data_song_size], p);
//	    	if(z%4 == 1) strcpy(artist[data_song_size], p);
//	    	if(z%4 == 2) strcpy(year[data_song_size], p);
//	    	if(z%4 == 3) strcpy(genre[data_song_size], p);
//	        p = strtok (NULL, "\t");
//	        z++;
//		}
//		
//		data_song_size++;
//    }
//}

void song_by_title(){
	char line[max_song][100];
	
	char title[max_song][100];
	char artist[max_song][50];
	char year[max_song][50];
	char genre[max_song][50];
	
	FILE *fp = fopen("dataSong.txt", "r+");
	
	if(! fp ){
		printf("Creating File..\n");
		fopen("dataSong.txt", "w");
		return;
	}
	
	int x=0;
    while (1) {
    	if(feof(fp)) break;
		fscanf(fp, "%[^\n]", line[x]); 
		fgetc(fp);
		
		char *p = strtok(line[x], "\t");
	
		int z=0;
	    while(p != NULL){
	    	if(z%4 == 0) strcpy(title[x], p);
	    	if(z%4 == 1) strcpy(artist[x], p);
	    	if(z%4 == 2) strcpy(year[x], p);
	    	if(z%4 == 3) strcpy(genre[x], p);
	        p = strtok (NULL, "\t");
	        z++;
		}
		
		x++;
    }

	for(int i=0; i<x; x++){
		for(int j=0; j<x; j++){
			if(strcmp(title[j], title[j+1]) > 0) {
				char t[100];
				strcpy(t, title[j]);
				strcpy(title[j], title[j+1]);
				strcpy(title[j+1], t);
				char t2[50];
				strcpy(t2, artist[j]);
				strcpy(artist[j], artist[j+1]);
				strcpy(artist[j+1], t);
				
				strcpy(t2, year[j]);
				strcpy(year[j], year[j+1]);
				strcpy(year[j+1], t);
				
				strcpy(t2, genre[j]);
				strcpy(genre[j], genre[j+1]);
				strcpy(genre[j+1], t);
			}
		}
	}
	    
	printf("=========================================================================================================================\n");
	printf("%| %-4s | %-32s | %-32s | %5s | %-32s |\n", "No.", "Song Title", "Artist", "Year", "Genre");
	printf("=========================================================================================================================\n");
	for(int i=0; i<x; i++){
		printf("| %-4d | %-32s | %-32s | %5s | %-32s |\n", i+1, title[i], artist[i], year[i], genre[i]);
//    	printf("%s\n", line2[i2]);
	}
	printf("=========================================================================================================================\n");

}

void song_by_artist(){
	char line[max_song][100];
	
	char title[max_song][100];
	char artist[max_song][50];
	char year[max_song][50];
	char genre[max_song][50];
	
	FILE *fp = fopen("dataSong.txt", "r+");
	
	if(! fp ){
		printf("Creating File..\n");
		fopen("dataSong.txt", "w");
		return;
	}
	
	int x=0;
    while (1) {
    	if(feof(fp)) break;
		fscanf(fp, "%[^\n]", line[x]); 
		fgetc(fp);
		
		char *p = strtok(line[x], "\t");
	
		int z=0;
	    while(p != NULL){
	    	if(z%4 == 0) strcpy(title[x], p);
	    	if(z%4 == 1) strcpy(artist[x], p);
	    	if(z%4 == 2) strcpy(year[x], p);
	    	if(z%4 == 3) strcpy(genre[x], p);
	        p = strtok (NULL, "\t");
	        z++;
		}
		
		x++;
    }
    
    for(int i=0; i<x; x++){
		for(int j=0; j<x; j++){
			if(strcmp(artist[j], artist[j+1]) > 0) {
				char t[100];
				strcpy(t, title[j]);
				strcpy(title[j], title[j+1]);
				strcpy(title[j+1], t);
				
				char t2[50];
				strcpy(t2, artist[j]);
				strcpy(artist[j], artist[j+1]);
				strcpy(artist[j+1], t);
				
				strcpy(t2, year[j]);
				strcpy(year[j], year[j+1]);
				strcpy(year[j+1], t);
				
				strcpy(t2, genre[j]);
				strcpy(genre[j], genre[j+1]);
				strcpy(genre[j+1], t);
			}
		}
	}
    
	printf("=========================================================================================================================\n");
	printf("%| %-4s | %-32s | %-32s | %5s | %-32s |\n", "No.", "Song Title", "Artist", "Year", "Genre");
	printf("=========================================================================================================================\n");
	for(int i=0; i<x; i++){
		printf("| %-4d | %-32s | %-32s | %5s | %-32s |\n", i+1, title[i], artist[i], year[i], genre[i]);
//    	printf("%s\n", line2[i2]);
	}
	printf("=========================================================================================================================\n");
}

void print_menu2_3(){
	printf("Search\n");
	printf("1. By Title\n");
	printf("2. By Artist\n");
	printf("3. Back\n");
	printf("> ");
}

void add_user(char email2[32], char password2[16]){
	
	char email[max_user][50];
	char password[max_user][50];
	
	char line[10][100];
	
	FILE *fp = fopen("dataUser.txt", "r+");
	
	if(! fp ){
		printf("Creating File..\n");
		fopen("dataUser.txt", "w");
	}
	
	int x=0;
    while (1) {
    	if(feof(fp)) break;
		fscanf(fp, "%[^\n]", line[x]); 
		fgetc(fp);
		
		char *p = strtok(line[x], ";");
	
		int z=0;
	    while(p != NULL){
	    	if(z%2 == 0) strcpy(email[x], p);
	    	if(z%2 == 1) strcpy(password[x], p);
	        p = strtok (NULL, "/");
	        z++;
		}
		
		x++;
    }
    
    int flag = 1;
    for(int i=0; i<x; i++){
		if(strcmp(email[i], email2) == 0){
			flag = 0;
		}
	}
	
	if (flag == 1) {
		FILE *fp2 = fopen("dataUser.txt", "a+");
		fprintf(fp2, "%s;%s\n", email2, password2);
	}
	else printf("Username already used!\n");
	system("pause");
}

void add_song(char title[50], char artist[32], int year, char genre[26], char email[32]){
	FILE *fp = fopen("dataSong.txt", "a+");
	fprintf(fp, "%s\t%s\t%d\t%s\n", title, artist, year, genre);
}

int main(){
	int menu;
	 
	do{
		start_a:
		print_menu();
		scanf("%d", &menu);
		
		if(menu == 1){
			char email1[32], password1[16];
			printf("Email (type 'cancel' to back): ");
			scanf("%s", email1);getchar();
			if(strcmp(email1, "cancel") == 0) {
				system("cls");
				goto start_a;
			}
			printf("Password : ");
			scanf("%s", password1);getchar();
			
			char email[max_user][50];
			char password[max_user][50];
			
			char line[10][100];
			
			FILE *fp = fopen("dataUser.txt", "r+");
			
			if(! fp ){
				printf("Creating File..\n");
				fopen("dataUser.txt", "w");
			}
			
			int x=0;
		    while (1) {
		    	if(feof(fp)) break;
				fscanf(fp, "%[^\n]", line[x]); 
				fgetc(fp);
				
				char *p = strtok(line[x], ";");
			
				int z=0;
			    while(p != NULL){
			    	if(z%2 == 0) strcpy(email[x], p);
			    	if(z%2 == 1) strcpy(password[x], p);
			        p = strtok (NULL, "/");
			        z++;
				}
				
				x++;
		    }
		    
		    for(int i=0; i<x; i++){
				if(strcmp(email[i], email1) == 0 && strcmp(password[i], password1) == 0){
					do{
						system("cls");
						int menu2=0;
						print_menu2(email1);
						scanf("%d", &menu2);getchar();
						if(menu2 == 1){
//							int song_size = get_data_song_size(0);	
							print_song();
//							printf("%d\n", size);
						}	
						else if(menu2 == 2){
							char title[50], artist[32], genre[26];
							int year;
							do{
								printf("Input Song Title [must be unique]: ");
								scanf("%s", title);	getchar();
								break;
							}while(true);
							do{
								printf("Input Song Artist [ more than 3 characters] :");
								scanf("%s", artist);getchar();
							}while(strlen(artist) <= 3);
							do{
								printf("Input Song Year [ > 1945] : ");
								scanf("%d", &year);getchar();
							}while(year < 1945);
							do{
								printf("Input Song Genre (less than 25 characters): ");
								scanf("%s", genre);getchar();
							}while(strlen(genre) >= 25);
							// masukin username juga
							
							add_song(title, artist, year, genre, email1);
						}
						else if(menu2 == 3){
							do{
								int menu3;
								print_menu2_3();
								scanf("%d", &menu3); getchar();
								if(menu3 == 1){
									char song[100];
									printf("Input song: ");
									scanf("%[^\n]", song); getchar();
									print_song_song(song, email1);
								}
								else if(menu3 == 2){
									char name[100];
									printf("Input name: ");
									scanf("%[^\n]", name); getchar();
									print_song_name(name, email1);
								}
								else if(menu3 == 3){
									break;
								}
							}while(1);
						}	
						else if(menu2 == 4){
							print_library(email1);
						}	
						else if(menu2 == 5){
							break;
						}	
						else{
							printf("You should input 1-5!\n");
						}	
						system("pause");				
					}while(1);
				}
			}
			
		}
		else if(menu == 2){
			char email[32], password[16], password2[16];
			do{
				printf("Input email [must be ended with '.com'] : ");
				scanf("%s", email); getchar();
				break;
			}while(true);
			do{
				printf("Input Password [must be more than 5 characters] : ");
				scanf("%s", &password);	getchar();
			}while(strlen(password) <= 5);
			do{
				printf("Confirm Password : ");
				scanf("%s", &password2); getchar();
			}while(strcmp(password, password2) != 0);
			
			add_user(email, password);
		}
		else if(menu == 3){
			break;
		}
		else{
			printf("You should input 1-3!\n");
		}
		
//		system("pause");
		system("cls");
	}while(1);
	
	
	return 0;
}
