/*****************************************************************************
 *  "Hospital Management System" 
 *
 * This code performs various operations mainly used in hospital.
 *
 * Copyright (C) 2015 Ashlesha Deshmukh
 *
 * This program is free software; you can redistribute it and/or modify it
 * under the terms of the GNU Lesser General Public License as published by
 * the Free Software Foundation; either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 * GNU Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public License
 * along with this program; if not, see <http://www.gnu.org/licenses/>
 *****************************************************************************/
#include<stdio.h>
#include<string.h>
#include<math.h>
#include<ctype.h>
#include<stdlib.h>
#include<termios.h>
#include<unistd.h>
#define sclear() printf("\033[H\033[J")
#define rw 80
#define cl 50
int s,z;
struct hospitalp {
	char pno[20];
	char name[50];
	char address[50];
	char sex[10];
	char disease[50];
	char department[50];
	char date[50];
	char age[50];
	char roomno[50];
};
struct hospitald {
	char dno[20];
	char name[50];
	char address[50];
	char sex[10];
	char department[50];
	char date[50];
	char age[50];
	char roomno[50];
};
void add_pat();
void listrecord();
void editrecord();
void delrecord();
void dadd_pat();
void dlistrecord();
void deditrecord();
void ddelrecord();
void print();
void welcome();
void displaydepartment();
void main_menu();
   
int getch() {
	struct termios oldt, newt;
	int ch;
	tcgetattr(STDIN_FILENO, &oldt);
	newt = oldt;
	newt.c_lflag &= ~( ICANON | ECHO );
	tcsetattr(STDIN_FILENO, TCSANOW, &newt);
	ch = getchar();
	tcsetattr(STDIN_FILENO, TCSANOW, &oldt);
	return ch;
}
int getche() {
	struct termios oldt, newt;
	int ch;
	tcgetattr(STDIN_FILENO, &oldt);
	newt = oldt;
	newt.c_lflag &= ~( ICANON | ECHO );
	tcsetattr(STDIN_FILENO, TCSANOW, &newt);
	ch = getchar();
	tcsetattr(STDIN_FILENO, TCSANOW, &oldt);
	return ch;
}
         
int main() {
	char name[15];
	char pass[15];
	int count=0,i;
	sclear();
	start:
	printf(" Welcome to LOGIN ");
	printf("Enter user name :");
	gets(name);
	printf("Enter password  :");
	gets(pass);
	if(strcmp(name,"ashlesha") || strcmp(pass,"ash")) {
		sclear();
	 	printf("Please Enter vailid Username & Passward!!!!!");
	 	count++;
	 	printf("%d chance left!!!!",3-count);
	 	getch();
	 	sclear();
	 	if(count==3)
	 		exit(0);
	 	else
	 		goto start;
	}
	else {
		main_menu();
	}
return(0);
}
void main_menu() {
	sclear();
	welcome();
	fflush(stdin);
	printf("1.Patient\n");
	printf("2.Doctor\n");
	printf("3.Exit\n");
	printf("Enter the corresponding No = ");
	switch(getch()) {
		case '1':
			printf("\n\n");
			printf("1.Add Record");
			printf("\n\n");
			printf("2.Update Record");
			printf("\n\n");
			printf("3.List Record");
			printf("\n\n");
			printf("4.Delete the records");
			printf("\n\n");
			printf("5.Exit from the system");
			printf("\n\n");
			printf("Enter the corresponding no = ");
			switch(getch()) {
				case '1':
					printf("\n\n");
					add_pat();
					break;
				case '2':
					printf("\n\n");
					editrecord();
					break;
				case '3':
					listrecord();
					break;
				case '4':
					delrecord();
					break;
				default:
					sclear();
					printf("Wrong choice");
					main_menu();								
			}
			break;
		case '2':               
			printf("\n\n");
			printf("1.Add Record");
			printf("\n\n");
			printf("2.Update Record");
			printf("\n\n");
			printf("3.List Record");
			printf("\n\n");
			printf("4.Delete the records");
			printf("\n\n");
			printf("5.Exit from the system");
			printf("\n\n");
			printf("Enter the corresponding no = ");
			switch(getch()) {
				case '1':
					printf("\n\n");
					dadd_pat();
					break;
				case '2':
					printf("\n\n");
					deditrecord();
					break;
				case '3':
					dlistrecord();
					break;
				case '4':
					ddelrecord();
					break;
				default:
					sclear();
					printf("Wrong choice");
					main_menu();
			}
			break;
		case '3': 
			exit(0);
		default:
			sclear();
			printf("Wrong choice");
			main_menu();
	}
}
void add_pat() {
	FILE *hmf, *hpfe, *hpfo;
	struct hospitalp p;
	char a;
	hmf=fopen("hmf.txt","ab+");
	hpfe=fopen("hpfe.txt","ab+");
	hpfo=fopen("hpfo.txt","ab+");
	sclear();
	printf("1.Admit Patient in Emergency\n");
	printf("2.Admit Patient in OPD\n");
	switch(getch()) {
		case '1':
			sclear();
			printf("Patient Record no: ");
			fgets(p.pno,sizeof(p.pno),stdin);					
			printf("\n\n");
			printf("Date(dd-mm-yyyy): ");
			fgets(p.date,sizeof(p.date),stdin);
			printf("\n\n");
			printf("Name: ");
			fflush(stdin); 
			fgets(p.name,sizeof(p.name),stdin);
			printf("\n\n");
			printf("Address: ");
			fflush(stdin);
			fgets(p.address,sizeof(p.address),stdin);
			printf("\n\n");
			printf("Age: ");
			fflush(stdin);
			fgets(p.age,sizeof(p.age),stdin);
			printf("\n\n");
			printf("Sex(m/f): ");
			fgets(p.sex,sizeof(p.sex),stdin);
			printf("\n\n");
			printf("Disease Description: ");
			fflush(stdin); 
			fgets(p.disease,sizeof(p.disease),stdin);
			printf("\n\n");
			tryagain:
			printf("Select Number form below Menu to insert Department and Room no\n\n");
			printf("1.General Physician\n2.E.N.T\n3.Cardiologist\n");
			printf("4.Dermatologist\n5.General Surgeon \n6.Orthopaedic\n");
			printf("7.EYE Specialist\n8.Neurologist\n9.Paediatrician\n0.Acupuncturist\n");
			printf("Now Select = ");
			switch(getch()) {
				case '1':
					strcpy(p.department,"General Physician");
					strcpy(p.roomno,"101A");
					break;
				case '2':
					strcpy(p.department,"E.N.T");
					strcpy(p.roomno,"201A");
					break;
				case '3':
					strcpy(p.department,"Cardiologist");
					strcpy(p.roomno,"301A");
					break;
				case '4':
					strcpy(p.department,"Dermatologist");
					strcpy(p.roomno,"401A");
					break;
				case '5':
					strcpy(p.department,"General Surgeon");
					strcpy(p.roomno,"501A");
					break;
				case '6':
					strcpy(p.department,"Orthopaedic");
					strcpy(p.roomno,"101B");
					break;
				case '7':
					strcpy(p.department,"EYE Specialist");
					strcpy(p.roomno,"201B");
					break;
				case '8':
					strcpy(p.department,"Neurologist");
					strcpy(p.roomno,"301B");
					break;
				case '9':
					strcpy(p.department,"Paediatrician");
					strcpy(p.roomno,"401B");
					break;
				case '0':
					strcpy(p.department,"Acupuncturist");
					strcpy(p.roomno,"501B");
					break;
				default:
					printf("Wrong choice!! Try Again"); 
					goto tryagain;
				}
				fwrite(&p,sizeof(p),1,hpfe);
				fclose(hpfe);
			break;
			case '2':
				printf("Patient Record no: ");
				fgets(p.pno,sizeof(p.pno),stdin);						
				printf("\n\n");
				printf("Date(dd-mm-yyyy): ");
				fgets(p.date,sizeof(p.date),stdin);
				printf("\n\n");
				printf("Name: ");
				fflush(stdin); 
				fgets(p.name,sizeof(p.name),stdin);
				printf("\n\n");
				printf("Address: ");
				fflush(stdin);
				fgets(p.address,sizeof(p.address),stdin);
				printf("\n\n");
				printf("Age: ");
				fflush(stdin);
				fgets(p.age,sizeof(p.age),stdin);
				printf("\n\n");
				printf("Sex(m/f): ");
				fgets(p.sex,sizeof(p.sex),stdin);
				printf("\n\n");
				printf("Disease Description: ");
				fflush(stdin); 
				fgets(p.disease,sizeof(p.disease),stdin);
				printf("\n\n");
				tryagain1:
					printf("Select Number form below Menu to insert Department and Room no\n\n");
					printf("1.General Physician\n2.E.N.T\n3.Cardiologist\n");
					printf("4.Dermatologist\n5.General Surgeon \n6.Orthopaedic\n");
					printf("7.EYE Specialist\n8.Neurologist\n9.Paediatrician\n0.Acupuncturist\n");
					printf("Now Select = ");
				switch(getch()) {
					case '1':
						strcpy(p.department,"General Physician");
						strcpy(p.roomno,"101A");
						break;
					case '2':
						strcpy(p.department,"E.N.T");
						strcpy(p.roomno,"201A");
						break;
					case '3':
						strcpy(p.department,"Cardiologist");
						strcpy(p.roomno,"301A");
						break;
					case '4':
						strcpy(p.department,"Dermatologist");
						strcpy(p.roomno,"401A");
						break;
					case '5':
						strcpy(p.department,"General Surgeon");
						strcpy(p.roomno,"501A");
						break;
					case '6':
						strcpy(p.department,"Orthopaedic");
						strcpy(p.roomno,"101B");
						break;
					case '7':
						strcpy(p.department,"EYE Specialist");
						strcpy(p.roomno,"201B");
						break;
					case '8':
						strcpy(p.department,"Neurologist");
						strcpy(p.roomno,"301B");
						break;
					case '9':	
						strcpy(p.department,"Paediatrician");
						strcpy(p.roomno,"401B");
						break;
					case '0':
						strcpy(p.department,"Acupuncturist");
						strcpy(p.roomno,"501B");
						break;
					default:
						printf("Wrong choice!! Try Again"); 
						goto tryagain1;
					}
					fwrite(&p,sizeof(p),1,hpfo);
					fclose(hpfo);
					break;
				default:
					printf("Wrong choice!! Try Again"); 
	}
	fwrite(&p,sizeof(p),1,hmf);
	fclose(hmf);
	printf("\n\nRecord Save Enter any key");
	getch();
        sclear();
        main_menu();
}
void dadd_pat() {
	FILE *hmf,*hpft,*hpfp;
	struct hospitald p;
	hmf=fopen("hmfd.txt","ab+");
	hpft=fopen("hpft.txt","ab+");
	hpfp=fopen("hpfp.txt","ab+");
	sclear();
	printf("1.Permanent Doctor \n");
	printf("2.Temporary Doctor \n");
	printf("Enter the corresponding No = ");
	switch(getch()) {
		case '1':
			printf("Doctor Record no: ");
			fgets(p.dno,sizeof(p.dno),stdin);
			printf("\n\n");
			printf("Joining Date(dd-mm-yyyy): ");
			fgets(p.date,sizeof(p.date),stdin);
			printf("\n\n");
			printf("Name: ");
			fflush(stdin); 
			fgets(p.name,sizeof(p.name),stdin);
			printf("\n\n");
			printf("Address: ");
			fflush(stdin);
			fgets(p.address,sizeof(p.address),stdin);
			printf("\n\n");
			printf("Age: ");
			fflush(stdin);
			fgets(p.age,sizeof(p.age),stdin);
			printf("\n\n");
			printf("Sex(m/f): ");
			fgets(p.sex,sizeof(p.sex),stdin);
			printf("\n\n");
			tryagain1:
				printf("Select Number form below Menu to insert Department and Room no\n\n");
				printf("1.General Physician\n2.E.N.T\n3.Cardiologist\n");
				printf("4.Dermatologist\n5.General Surgeon \n6.Orthopaedic\n");
				printf("7.EYE Specialist\n8.Neurologist\n9.Paediatrician\n0.Acupuncturist\n");
				printf("Now Select = ");
			switch(getch()) {
				case '1':
					strcpy(p.department,"General Physician");
					strcpy(p.roomno,"101A");
					break;
				case '2':
					strcpy(p.department,"E.N.T");
					strcpy(p.roomno,"201A");
					break;
				case '3':
					strcpy(p.department,"Cardiologist");
					strcpy(p.roomno,"301A");
					break;
				case '4':
					strcpy(p.department,"Dermatologist");
					strcpy(p.roomno,"401A");
					break;
				case '5':
					strcpy(p.department,"General Surgeon");
					strcpy(p.roomno,"501A");
					break;
				case '6':
					strcpy(p.department,"Orthopaedic");
					strcpy(p.roomno,"101B");
					break;
				case '7':
					strcpy(p.department,"EYE Specialist");
					strcpy(p.roomno,"201B");
					break;
				case '8':
					strcpy(p.department,"Neurologist");
					strcpy(p.roomno,"301B");
					break;
				case '9':	
					strcpy(p.department,"Paediatrician");
					strcpy(p.roomno,"401B");
					break;
				case '0':
					strcpy(p.department,"Acupuncturist");
					strcpy(p.roomno,"501B");
					break;
				default:
					printf("Wrong choice!! Try Again"); 
					goto tryagain1;
				}
				fwrite(&p,sizeof(p),1,hpfp);
				fclose(hpfp);
				break;
			case '2':
				printf("Doctor Record no: ");
				fgets(p.dno,sizeof(p.dno),stdin);
				printf("\n\n");
				printf("Joining Date(dd-mm-yyyy): ");
				fgets(p.date,sizeof(p.date),stdin);
				printf("\n\n");
				printf("Name: ");
				fflush(stdin); 
				fgets(p.name,sizeof(p.name),stdin);
				printf("\n\n");
				printf("Address: ");
				fflush(stdin);
				fgets(p.address,sizeof(p.address),stdin);
				printf("\n\n");
				printf("Age: ");
				fflush(stdin);
				fgets(p.age,sizeof(p.age),stdin);
				printf("\n\n");
				printf("Sex(m/f): ");
				fgets(p.sex,sizeof(p.sex),stdin);
				printf("\n\n");
				tryagain:
					printf("Select Number form below Menu to insert Department and Room no\n\n");
					printf("1.General Physician\n2.E.N.T\n3.Cardiologist\n");
					printf("4.Dermatologist\n5.General Surgeon \n6.Orthopaedic\n");
					printf("7.EYE Specialist\n8.Neurologist\n9.Paediatrician\n0.Acupuncturist\n");
					printf("Now Select = ");
				switch(getch()) {
					case '1':
						strcpy(p.department,"General Physician");
						strcpy(p.roomno,"101A");
						break;
						case '2':
							strcpy(p.department,"E.N.T");
							strcpy(p.roomno,"201A");
							break;
						case '3':
							strcpy(p.department,"Cardiologist");
							strcpy(p.roomno,"301A");
							break;
						case '4':
							strcpy(p.department,"Dermatologist");
							strcpy(p.roomno,"401A");
								break;
						case '5':
							strcpy(p.department,"General Surgeon");
							strcpy(p.roomno,"501A");
							break;
						case '6':
							strcpy(p.department,"Orthopaedic");
							strcpy(p.roomno,"101B");
							break;
						case '7':
							strcpy(p.department,"EYE Specialist");
							strcpy(p.roomno,"201B");
							break;
						case '8':
							strcpy(p.department,"Neurologist");
							strcpy(p.roomno,"301B");
							break;
						case '9':	
							strcpy(p.department,"Paediatrician");
							strcpy(p.roomno,"401B");
							break;
						case '0':
							strcpy(p.department,"Acupuncturist");
							strcpy(p.roomno,"501B");
							break;
						default:
							printf("Wrong choice!! Try Again"); 
							goto tryagain;
					}
					fwrite(&p,sizeof(p),1,hpft);
					fclose(hpft);
					break;
				default:
					printf("Wrong choice!! Try Again"); 
	}
	fwrite(&p,sizeof(p),1,hmf);
	fclose(hmf);
	printf("\n\nRecord Save Enter any key");
	getch();
    sclear();
    main_menu();
}
void deditrecord() {
	char pno[10];
	FILE *f;
	struct hospitalp p,s;
        int flag;
   	flag=0;
	printf("Enter the Doctor no: "); 
	fflush(stdin);
	fgets(pno,sizeof(pno),stdin);
	f=fopen("hmfp.txt","rb+");
	if(f==NULL) {
		printf("\n cannot open the record file");
		getch();
		main_menu();
	}
	else {
		sclear();
		while(fread(&p,sizeof(p),1,f)==1) {
			if(strcmp(pno,p.pno)==0) {
				printf("Doctor Record no: ");
				fgets(p.pno,sizeof(p.pno),stdin);
				printf("\n\n");
				printf("Joining Date(dd-mm-yyyy): ");
				fgets(s.date,sizeof(s.date),stdin);
				printf("\n\n");
				printf("Name: ");
				fflush(stdin); 
				fgets(s.name,sizeof(s.name),stdin);
				printf("\n\n");
				printf("Address: ");
				fflush(stdin);
				fgets(s.address,sizeof(s.address),stdin);
				printf("\n\n");
				printf("Age: ");
				fflush(stdin);
				fgets(s.age,sizeof(s.age),stdin);
				printf("\n\n");
				printf("Sex(m/f): ");
				fgets(s.sex,sizeof(s.sex),stdin);
				printf("\n\n");
				tryagain:
					printf("Select Number form below Menu to insert Department and Room no\n\n");
					printf("1.General Physician\n2.E.N.T\n3.Cardiologist\n");
						printf("4.Dermatologist\n5.General Surgeon \n6.Orthopaedic\n");
						printf("7.EYE Specialist\n8.Neurologist\n9.Paediatrician\n0.Acupuncturist\n");
					printf("Now Select = ");
					switch(getch()) {
						case '1':
							strcpy(p.department,"General Physician");
							strcpy(p.roomno,"101A");
							break;
						case '2':
							strcpy(p.department,"E.N.T");
							strcpy(p.roomno,"201A");
							break;
						case '3':
							strcpy(p.department,"Cardiologist");
							strcpy(p.roomno,"301A");
							break;
						case '4':
							strcpy(p.department,"Dermatologist");
							strcpy(p.roomno,"401A");
							break;
						case '5':
							strcpy(p.department,"General Surgeon");
							strcpy(p.roomno,"501A");
							break;
						case '6':
							strcpy(p.department,"Orthopaedic");
							strcpy(p.roomno,"101B");
							break;
						case '7':
							strcpy(p.department,"EYE Specialist");
							strcpy(p.roomno,"201B");
							break;
						case '8':
							strcpy(p.department,"Neurologist");
							strcpy(p.roomno,"301B");
							break;
						case '9':	
							strcpy(p.department,"Paediatrician");
							strcpy(p.roomno,"401B");
							break;
						case '0':
							strcpy(p.department,"Acupuncturist");
							strcpy(p.roomno,"501B");
							break;
						default:
							printf("Wrong choice!! Try Again"); 
							goto tryagain;
					}
				fseek(f,-sizeof(p),SEEK_CUR);
				fwrite(&s,sizeof(p),1,f);
				flag=1;
				fflush(stdin);
				break;
			}
			fflush(stdin);
		}
		fclose(f);
		
	}
	f=fopen("hmft.txt","rb+");
	if(f==NULL) {
		printf("\n cannot open the record file");
		getch();
		main_menu();;
	}
	else {
		sclear();
		while(fread(&p,sizeof(p),1,f)==1) {
			if(strcmp(pno,p.pno)==0) {
				printf("Doctor Record no: ");
				fgets(p.pno,sizeof(p.pno),stdin);
				printf("\n\n");
				printf("Joining Date(dd-mm-yyyy): ");
				fgets(s.date,sizeof(s.date),stdin);
				printf("\n\n");
				printf("Name: ");
				fflush(stdin); 
				fgets(s.name,sizeof(s.name),stdin);
				printf("\n\n");
				printf("Address: ");
				fflush(stdin);
				fgets(s.address,sizeof(s.address),stdin);
				printf("\n\n");
				printf("Age: ");
				fflush(stdin);
				fgets(s.age,sizeof(s.age),stdin);
				printf("\n\n");
				printf("Sex(m/f): ");
				fgets(s.sex,sizeof(s.sex),stdin);
				printf("\n\n");
				tryagain1:
					printf("Select Number form below Menu to insert Department and Room no\n\n");
					printf("1.General Physician\n2.E.N.T\n3.Cardiologist\n");
					printf("4.Dermatologist\n5.General Surgeon \n6.Orthopaedic\n");
					printf("7.EYE Specialist\n8.Neurologist\n9.Paediatrician\n0.Acupuncturist\n");
					printf("Now Select = ");
					switch(getch())
					{
						case '1':
							strcpy(p.department,"General Physician");
							strcpy(p.roomno,"101A");
							break;
						case '2':
							strcpy(p.department,"E.N.T");
							strcpy(p.roomno,"201A");
							break;
						case '3':
							strcpy(p.department,"Cardiologist");
							strcpy(p.roomno,"301A");
							break;
						case '4':
							strcpy(p.department,"Dermatologist");
							strcpy(p.roomno,"401A");
							break;
						case '5':
							strcpy(p.department,"General Surgeon");
							strcpy(p.roomno,"501A");
							break;
						case '6':
							strcpy(p.department,"Orthopaedic");
							strcpy(p.roomno,"101B");
							break;
						case '7':
							strcpy(p.department,"EYE Specialist");
							strcpy(p.roomno,"201B");
							break;
						case '8':
							strcpy(p.department,"Neurologist");
							strcpy(p.roomno,"301B");
							break;
						case '9':	
							strcpy(p.department,"Paediatrician");
							strcpy(p.roomno,"401B");
							break;
						case '0':
							strcpy(p.department,"Acupuncturist");
							strcpy(p.roomno,"501B");
							break;
						default:
							printf("Wrong choice!! Try Again"); 
							goto tryagain1;
					}
				fseek(f,-sizeof(p),SEEK_CUR);
				fwrite(&s,sizeof(p),1,f);
				flag=1;
				fflush(stdin);
				break;
			}
			fflush(stdin);
		}
		fclose(f);
		
	}
	f=fopen("hmfd.txt","rb+");
	if(f==NULL) {
		printf("\n cannot open the record file");
		getch();
		main_menu();
	}
	else {
		sclear();
		while(fread(&p,sizeof(p),1,f)==1) {
			if(strcmp(pno,p.pno)==0) {
				fseek(f,-sizeof(p),SEEK_CUR);
				fwrite(&s,sizeof(p),1,f);
				flag=1;
				fflush(stdin);
				break;
			}
			fflush(stdin);
		}
		fclose(f);
	}
	if(flag==1) {
		printf("\n your data is modified");
		main_menu();
	}
	else {
		printf(" \n data is not found");
		main_menu();
	}
}
void editrecord() {
	char pno[10];
	FILE *f;
	struct hospitalp p,s;
   	int flag;
   	flag=0;
	printf("Enter the patient no: "); 
	fgets(pno,sizeof(pno),stdin);
	f=fopen("hpfo.txt","rb+");
	if(f==NULL) {
		printf("\n cannot open the record file");
		getch();
		main_menu();
	}
	else {
		sclear();
		while(fread(&p,sizeof(p),1,f)==1) {
			if(strcmp(pno,p.pno)==0) {
				printf("Patient Record no: ");
				gets(s.pno);					
				printf("\n\n");
				printf("Date(dd-mm-yyyy): ");
				gets(s.date);
				printf("\n\n");
				printf("Name: ");
				fflush(stdin); 
				fgets(s.name,sizeof(s.name),stdin);
				printf("\n\n");
				printf("Address: ");
				fflush(stdin);
				fgets(s.address,sizeof(s.address),stdin);
				printf("\n\n");
				printf("Age: ");
				fflush(stdin);
				fgets(s.age,sizeof(s.age),stdin);
				printf("\n\n");
				printf("Sex(m/f): ");
				fgets(s.sex,sizeof(s.sex),stdin);
				printf("\n\n");
				printf("Disease Description: ");
				fflush(stdin); 
				fgets(s.disease,sizeof(s.disease),stdin);
				printf("\n\n");
				tryagain:
					printf("Select Number form below Menu to insert Department and Room no\n\n");
					printf("1.General Physician\n2.E.N.T\n3.Cardiologist\n");
					printf("4.Dermatologist\n5.General Surgeon \n6.Orthopaedic\n");
					printf("7.EYE Specialist\n8.Neurologist\n9.Paediatrician\n0.Acupuncturist\n");
					printf("Now Select = ");
					switch(getch())
					{
						case '1':
							strcpy(s.department,"General Physician");
							strcpy(s.roomno,"101A");
							break;
						case '2':
							strcpy(s.department,"E.N.T");
							strcpy(s.roomno,"201A");
							break;
						case '3':
							strcpy(s.department,"Cardiologist");
							strcpy(s.roomno,"301A");
							break;
						case '4':
							strcpy(s.department,"Dermatologist");
							strcpy(s.roomno,"401A");
							break;
						case '5':
							strcpy(s.department,"General Surgeon");
							strcpy(s.roomno,"501A");
							break;
						case '6':
							strcpy(s.department,"Orthopaedic");
							strcpy(s.roomno,"101B");
							break;
						case '7':
							strcpy(s.department,"EYE Specialist");
							strcpy(s.roomno,"201B");
							break;
						case '8':
							strcpy(s.department,"Neurologist");
							strcpy(s.roomno,"301B");
							break;
						case '9':	
							strcpy(s.department,"Paediatrician");
							strcpy(s.roomno,"401B");
							break;
						case '0':
							strcpy(s.department,"Acupuncturist");
							strcpy(s.roomno,"501B");
							break;
						default:
							printf("Wrong choice!! Try Again"); 
							goto tryagain;
					}
				fseek(f,-sizeof(p),SEEK_CUR);
				fwrite(&s,sizeof(p),1,f);
				flag=1;
				fflush(stdin);
				break;
			}
			fflush(stdin);
		}
		fclose(f);
		
	}
	f=fopen("hpfe.txt","rb+");
	if(f==NULL) {
		printf("\n cannot open the record file");
		getch();
		main_menu();
	}
	else {
		sclear();
		while(fread(&p,sizeof(p),1,f)==1) {
			if(strcmp(pno,p.pno)==0) {
				printf("Patient Record no: ");
				gets(s.pno);					
				printf("\n\n");
				printf("Date(dd-mm-yyyy): ");
				gets(s.date);
				printf("\n\n");
				printf("Name: ");
				fflush(stdin); 
				fgets(s.name,sizeof(s.name),stdin);
				printf("\n\n");
				printf("Address: ");
				fflush(stdin);
				fgets(s.address,sizeof(s.address),stdin);
				printf("\n\n");
				printf("Age: ");
				fflush(stdin);
				fgets(s.age,sizeof(s.age),stdin);
				printf("\n\n");
				printf("Sex(m/f): ");
				fgets(s.sex,sizeof(s.sex),stdin);
				printf("\n\n");
				printf("Disease Description: ");
				fflush(stdin); 
				fgets(s.disease,sizeof(s.disease),stdin);
				printf("\n\n");
				tryagain1:
				printf("Select Number form below Menu to insert Department and Room no\n\n");
				printf("1.General Physician\n2.E.N.T\n3.Cardiologist\n");
				printf("4.Dermatologist\n5.General Surgeon \n6.Orthopaedic\n");
				printf("7.EYE Specialist\n8.Neurologist\n9.Paediatrician\n0.Acupuncturist\n");
				printf("Now Select = ");
				switch(getch()) {
					case '1':
						strcpy(s.department,"General Physician");
						strcpy(s.roomno,"101A");
						break;
					case '2':
						strcpy(s.department,"E.N.T");
						strcpy(s.roomno,"201A");
						break;
					case '3':
						strcpy(s.department,"Cardiologist");
						strcpy(s.roomno,"301A");
						break;
					case '4':
						strcpy(s.department,"Dermatologist");
						strcpy(s.roomno,"401A");
						break;
					case '5':
						strcpy(s.department,"General Surgeon");
						strcpy(s.roomno,"501A");
						break;
					case '6':
						strcpy(s.department,"Orthopaedic");
						strcpy(s.roomno,"101B");
						break;
					case '7':
						strcpy(s.department,"EYE Specialist");
						strcpy(s.roomno,"201B");
						break;
					case '8':
						strcpy(s.department,"Neurologist");
						strcpy(s.roomno,"301B");
						break;
					case '9':	
						strcpy(s.department,"Paediatrician");
						strcpy(s.roomno,"401B");
						break;
					case '0':
						strcpy(s.department,"Acupuncturist");
						strcpy(s.roomno,"501B");
						break;
					default:
						printf("Wrong choice!! Try Again"); 
						goto tryagain1;
					}
				fseek(f,-sizeof(p),SEEK_CUR);
				fwrite(&s,sizeof(p),1,f);
				flag=1;
				fflush(stdin);
				break;
			}
			fflush(stdin);
		}
		fclose(f);
		
	}
	f=fopen("hmf.txt","rb+");
	if(f==NULL) {
		printf("\n cannot open the record file");
		getch();
		main_menu();
	}
	else {
		sclear();
		while(fread(&p,sizeof(p),1,f)==1) {
			if(strcmp(pno,p.pno)==0) {
				fseek(f,-sizeof(p),SEEK_CUR);
				fwrite(&s,sizeof(p),1,f);
				flag=1;
				fflush(stdin);
				break;
			}
			fflush(stdin);
		}
		fclose(f);
	}
	fflush(stdin);
	if(flag==1) {
		printf("\n your data is modified");
		fflush(stdin);
		main_menu();
	}
	else {
	printf(" \n data is not found");
	main_menu();
	}
}
void listrecord() {
	FILE *fp;
	struct hospitalp p;
	int i;
        unsigned int tsz;
        char c;
        char ddate[30];
	sclear();
	i=0;
	printf("List Record Menu \n\n1.Records in alphabetical order");
	printf("\n2.Records of Emergency patients");
	printf("\n3.Records of O.P.D. patients");
	printf("\n4.Records in particular date");
	printf("\n5.Return to main menu");
	printf("\nEnter the corresponding no = ");
	switch(getch()) {
		case '1':
			if((fp=fopen("hmf.txt","rb+"))==NULL) {
				printf("Cannot open the file");
				getch();
				main_menu();
			}
			while(fread(&p,sizeof(p),1,fp)) {
				sclear();
				printf("Patient Record no: ");
				printf("%s",p.pno); 
				printf("\n\n");
				printf("Date(dd-mm-yyyy): ");
				printf("%s",p.date); 
				printf("\n\n");
				printf("Name: "); 
				printf(" %s",p.name);
				printf("\n\n");	
				printf("Address: "); 
				printf(" %s",p.address); 
				printf("\n\n");
				printf("Age: "); 
				printf("%s",p.age); 
				printf("\n\n");
				printf("Sex(m/f): ");
				printf(" %s",p.sex);
				printf("\n\n");
				printf("Room no:"); 
				printf(" %s",p.roomno); 
				printf("\n\n");
				printf("Department:"); 
				printf(" %s",p.department); 
				printf("\n\n");
				printf("Disease Description: ");
				printf(" %s",p.disease); 
				i=1;
			}
			if(i==0) {
				printf("Data Not found");
			}
			getch();
			fclose(fp);
			fflush(stdin);
			break;
		case '2':
			sclear();
			if((fp=fopen("hpfe.txt","rb+"))==NULL) {
				printf("Cannot open the file");
				getch();
				main_menu();
			}
			while(fread(&p,sizeof(p),1,fp)) {
				sclear();
				printf("Patient Record no: ");
				printf("%s",p.pno); 
				printf("\n\n");
				printf("Date(dd-mm-yyyy): ");
				printf("%s",p.date); 
				printf("\n\n");
				printf("Name: "); 
				printf(" %s",p.name);
				printf("\n\n");	
				printf("Address: "); 
				printf(" %s",p.address); 
				printf("\n\n");
				printf("Age: "); 
				printf("%s",p.age); 
				printf("\n\n");
				printf("Sex(m/f): ");
				printf(" %s",p.sex);
				printf("\n\n");
				printf("Room no:"); 
				printf(" %s",p.roomno); 
				printf("\n\n");
				printf("Department:"); 
				printf(" %s",p.department); 
				printf("\n\n");
				printf("Disease Description: ");
				printf(" %s",p.disease); 
				getch();
				}
				fflush(stdin);
				break;
		case '3':
			sclear();
			if((fp=fopen("hpfo.txt","rb+"))==NULL) {
				printf("Cannot open the file");
				getch();
				main_menu();
				}
			while(fread(&p,sizeof(p),1,fp)) {
				sclear();
				printf("Patient Record no: ");
				printf("%s",p.pno); 
				printf("\n\n");
				printf("Date(dd-mm-yyyy): ");
				printf("%s",p.date); 
				printf("\n\n");
				printf("Name: "); 
				printf(" %s",p.name);
				printf("\n\n");	
				printf("Address: "); 
				printf(" %s",p.address); 
				printf("\n\n");
				printf("Age: "); 
				printf("%s",p.age); 
				printf("\n\n");
				printf("Sex(m/f): ");
				printf(" %s",p.sex);
				printf("\n\n");
				printf("Room no:"); 
				printf(" %s",p.roomno); 
				printf("\n\n");
				printf("Department:"); 
				printf(" %s",p.department); 
				printf("\n\n");
				printf("Disease Description: ");
				printf(" %s",p.disease); 
				getch();
			}
			fflush(stdin);
			break;
		case '4':
			sclear();
			if((fp=fopen("hmf.txt","rb"))==NULL) {
				printf("Cannot open the file");
				getch();
				main_menu();
			}
			printf("Date(dd-mm-yyyy): ");
			fgets(ddate,sizeof(ddate),stdin);
			while(fread(&p,sizeof(p),1,fp)) {
				if(strcmp(p.date,ddate)==NULL) {
					sclear();
					printf("Patient Record no: ");
					printf("%s",p.pno);
					printf("\n\n");
					printf("Date(dd-mm-yyyy): ");
					printf("%s",p.date); 
					printf("\n\n");
					printf("Name: "); 
					printf(" %s",p.name);
					printf("\n\n");	
					printf("Address: "); 
					printf(" %s",p.address); 
					printf("\n\n");
					printf("Age: "); 
					printf("%s",p.age); 
					printf("\n\n");
					printf("Sex(m/f): ");
					printf(" %s",p.sex);
					printf("\n\n");
					printf("Room no:"); 
					printf(" %s",p.roomno); 
					printf("\n\n");
					printf("Department:"); 
					printf(" %s",p.department); 
					printf("\n\n");
					printf("Disease Description: ");
					printf(" %s",p.disease); 
					getch();
					}
				}
				fflush(stdin);
				sclear();
				printf("::No Further Records::");    
				getch();
				fclose(fp);
				break;
		case '5':
			fflush(stdin);
			main_menu();
			break;
		default:
			printf("Invalid Choice!! Try again");  
			listrecord();
	}
	getch();
	fflush(stdin);
	main_menu();
}
void dlistrecord() {
	FILE *fp;
	struct hospitald p,q;
	int i,a,n;
   	unsigned int tsz;
   	char c;
   	char date[30];
	sclear();
	printf("List Record Menu \n\n1.Records in alphabetical order");
	printf("\n2.Records of Permanent Doctor");
	printf("\n3.Records of Temporary Doctor");
	printf("\n4.Records in particular date");
	printf("\n5.Return to main menu");
	printf("\nEnter the corresponding no = ");
	switch(getch()) {
		case '1':
			if((fp=fopen("hmfd.txt","rb+"))==NULL) {
				printf("Cannot open the file");
				getch();
				main_menu();
			 }
			while(fread(&p,sizeof(p),1,fp)) {
				sclear();
				printf("Doctor Record no: ");
				printf("%s",p.dno);
				printf("\n\n");
				printf("Joining Date(dd-mm-yyyy): ");
				printf("%s",p.date); 
				printf("\n\n");
				printf("Name: "); 
				printf(" %s",p.name);
				printf("\n\n");	
				printf("Address: "); 
				printf(" %s",p.address); 
				printf("\n\n");
				printf("Age: "); 
				printf("%s",p.age); 
				printf("\n\n");
				printf("Sex(m/f): ");
				printf(" %s",p.sex);
				printf("\n\n");
				printf("Room no:"); 
				printf(" %s",p.roomno); 
				printf("\n\n");
				printf("Department:"); 
				printf(" %s",p.department); 
				printf("\n\n");
			} 
			getch();
			fclose(fp);
			break;
		case '2':
			if((fp=fopen("hpfp.txt","rb+"))==NULL) {
				printf("Cannot open the file");
				getch();
				main_menu();
			 }
			while(fread(&p,sizeof(p),1,fp)) {
				sclear();
				printf("Doctor Record no: ");
				printf("%s",p.dno);
				printf("\n\n");
				printf("Joining Date(dd-mm-yyyy): ");
				printf("%s",p.date); 
				printf("\n\n");
				printf("Name: "); 
				printf(" %s",p.name);
				printf("\n\n");	
				printf("Address: "); 
				printf(" %s",p.address); 
				printf("\n\n");
				printf("Age: "); 
				printf("%s",p.age); 
				printf("\n\n");
				printf("Sex(m/f): ");
				printf(" %s",p.sex);
				printf("\n\n");
				printf("Room no:"); 
				printf(" %s",p.roomno); 
				printf("\n\n");
				printf("Department:"); 
				printf(" %s",p.department); 
				printf("\n\n");
				getch();
			}	
			fclose(fp);
		case '3':
			if((fp=fopen("hpft.txt","rb+"))==NULL) {
				printf("Cannot open the file");
				getch();
				main_menu();
			 }
			while(fread(&p,sizeof(p),1,fp)) {
				sclear();
				printf("Doctor Record no: ");
				printf("%s",p.dno);
				printf("\n\n");
				printf("Joining Date(dd-mm-yyyy): ");
				printf("%s",p.date); 
				printf("\n\n");
				printf("Name: "); 
				printf(" %s",p.name);
				printf("\n\n");	
				printf("Address: "); 
				printf(" %s",p.address); 
				printf("\n\n");
				printf("Age: "); 
				printf("%s",p.age); 
				printf("\n\n");
				printf("Sex(m/f): ");
				printf(" %s",p.sex);
				printf("\n\n");
				printf("Room no:"); 
				printf(" %s",p.roomno); 
				printf("\n\n");
				printf("Department:"); 
				printf(" %s",p.department); 
				printf("\n\n");
				getch();
			}	
			fclose(fp);
		case '4':
			sclear();
			if((fp=fopen("hmfd.txt","rb"))==NULL) {
				printf("Cannot open the file");
				getch();
				main_menu();
			}
			printf("Date(dd-mm-yyyy): ");
			fgets(date,sizeof(date),stdin);
			while(fread(&p,sizeof(p),1,fp)) {
				if(strcmp(p.date,date)==NULL) {
					sclear();
					printf("Doctor Record no: ");
					printf("%s",p.dno);
					printf("\n\n");
					printf("Date(dd-mm-yyyy): ");
					printf("%s",p.date); 
					printf("\n\n");
					printf("Name: "); 
					printf(" %s",p.name);
					printf("\n\n");	
					printf("Address: "); 
					printf(" %s",p.address); 
					printf("\n\n");
					printf("Age: "); 
					printf("%s",p.age); 
					printf("\n\n");
					printf("Sex(m/f): ");
					printf(" %s",p.sex);
					printf("\n\n");
					printf("Room no:"); 
					printf(" %s",p.roomno); 
					printf("\n\n");
					printf("Department:"); 
					printf(" %s",p.department); 
					printf("\n\n");
					getch();
				}
			}
			sclear();
			printf("::No Further Records::");    
			getch();
			fclose(fp);
			break;
		case 5:
			main_menu();
			break;
		default:
			printf("Invalid Choice!! Try again");  
			listrecord();
	}

	getch();
	fflush(stdin);
	main_menu();

}
void delrecord() {
	FILE *f,*ft;
	struct hospitalp p;
      	char pn[30];
	int flag,df;
	df=0;
	flag=0;
	printf("Enter the patient no");
	fflush(stdin);
      	gets(pn);
	f=fopen("hpfo.txt","rb");
	if(f==NULL) {
		printf("cannot open the file");
		main_menu();
	}
	else {
		ft=fopen("temp.txt","wb+");
		if(ft==NULL) {
			printf("cannot open the file");
			main_menu();
		}
		else {
			while(fread(&p,sizeof(p),1,f)==1) {
				if(strcmp(p.pno,pn)!=0)
					fwrite(&p,sizeof(p),1,ft);
				if(strcmp(p.pno,pn)==0)
					flag=1;
			}
			fclose(f);
			fclose(ft);
			if(flag!=1) {
				remove("temp.txt");
			}
			else {
				remove("hpfo.txt");
				rename("temp.txt","hpfo.txt");
				df=1;
			}
		}
	}
	f=fopen("hpfe.txt","rb");
	if(f==NULL) {
		printf("cannot open the file");
		main_menu();
	}
	else {
		ft=fopen("temp.txt","wb+");
		if(ft==NULL) {
			printf("cannot open the file");
			main_menu();
		}
		else {
			while(fread(&p,sizeof(p),1,f)==1) {
				if(strcmp(p.pno,pn)!=0)
					fwrite(&p,sizeof(p),1,ft);
				if(strcmp(p.pno,pn)==0)
					flag=1;
			}
			fclose(f);
			fclose(ft);
			if(flag!=1) {
				remove("temp.txt");
			}
			else {
				remove("hpfe.txt");
				rename("temp.txt","hpfe.txt");
				df=1;
			}
		}
	}
	f=fopen("hmf.txt","rb");
	if(f==NULL) {
		printf("cannot open the file");
		main_menu();
	}
	else {
		ft=fopen("temp.txt","wb+");
		if(ft==NULL) {
			printf("cannot open the file");
			main_menu();
			}
		else {
			while(fread(&p,sizeof(p),1,f)==1) {
				if(strcmp(p.pno,pn)!=0)
					fwrite(&p,sizeof(p),1,ft);
				if(strcmp(p.pno,pn)==0)
					flag=1;
			}
			fclose(f);
			fclose(ft);
			if(flag!=1) {
				remove("temp.txt");
			}
			else {
				remove("hmf.txt");
				rename("temp.txt","hmf.txt");
				df=1;
			}
		}
	} 
	if(df==1) {
		printf("RECORD DELETED SUCCESSFULLY.");
		fflush(stdin);
	}
	else {
		printf("NO RECORD TO DELETE.");
	}
	getch();
	fflush(stdin);
	main_menu();
}
void ddelrecord() {
	FILE *f,*ft;
	struct hospitald p;
	char pn[30];
	int flag,df;
	df=0;
	flag=0;
	printf("Enter the Doctor no");
	fflush(stdin);
      	gets(pn);
	fflush(stdin);
	f=fopen("hmfd.txt","rb");
	if(f==NULL) {
		printf("cannot open the file");
		main_menu();
	}
	else {
		ft=fopen("temp.txt","wb+");
		if(ft==NULL) {
			printf("cannot open the file");
			main_menu();
		}
		else {
			while(fread(&p,sizeof(p),1,f)==1) {
				if(strcmp(p.dno,pn)!=0)
					fwrite(&p,sizeof(p),1,ft);
				if(strcmp(p.dno,pn)==0)
					flag=1;
			}
			fclose(f);
			fclose(ft);
			if(flag!=1) {
				remove("temp.txt");
			}
			else {
				remove("hmfd.txt");
				rename("temp.txt","hmfd.txt");
				df=1;
			}
		}
	}
	f=fopen("hpfp.txt","rb");
	if(f==NULL) {
		printf("cannot open the file");
		main_menu();
	}
	else {
		ft=fopen("temp.txt","wb+");
		if(ft==NULL) {
			printf("cannot open the file");
			main_menu();
			}
		else {
			while(fread(&p,sizeof(p),1,f)==1) {
				if(strcmp(p.dno,pn)!=0)
					fwrite(&p,sizeof(p),1,ft);
				if(strcmp(p.dno,pn)==0)
					flag=1;
			}
			fclose(f);
			fclose(ft);
			if(flag!=1) {
				remove("temp.txt");
			}
			else {
				remove("hpfp.txt");
				rename("temp.txt","hpfp.txt");
				df=1;
			}
		}
	}
	f=fopen("hpft.txt","rb");
	if(f==NULL) {
	printf("cannot open the file");
	main_menu();
	}
	else {
		ft=fopen("temp.txt","wb+");
		if(ft==NULL) {
			printf("cannot open the file");
			main_menu();
		}
		else {
			while(fread(&p,sizeof(p),1,f)==1) {
				if(strcmp(p.dno,pn)!=0)
					fwrite(&p,sizeof(p),1,ft);
				if(strcmp(p.dno,pn)==0)
					flag=1;
			}
			fclose(f);
			fclose(ft);
			if(flag!=1) {
				remove("temp.txt");
			}
			else {
				remove("hpft.txt");
				rename("temp.txt","hpft.txt");
				df=1;
			}
		}
	} 
	if(df==1) {
		printf("RECORD DELETED SUCCESSFULLY.");
	}
	else {
		printf("NO RECORD TO DELETE.");
	}
	getch();
	fflush(stdin);
	main_menu();
}
void welcome() {
	sclear();
	printf("\n************************************************");
	printf("\nWELCOME TO HOSPITAL MANAGEMENT SYSTEM");
	printf("\n**************************************************");
	printf("\n\n");
}
