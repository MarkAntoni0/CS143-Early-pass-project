//
//  main.c
//  Early pass (m3mlnahosh)
//
//  Created by Mark Antonio on 6/1/20.
//  Copyright © 2020 Mark Antonio. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
//=========================================//Baby structs

struct studentName{
    char firstName[50];
    char middleName[50];
    char lastName[50];
};

struct studentHomeAddress{
    int flatNumber;
    int houseNumber;
    char streetName[20];
    char areaName[20];
    char cityName[20];
    char governorateName[20];
    char country[20];
    int PostalCode;
};

struct studentDOB{
    int day;
    int month;
    int year;
};

struct studentContact{
    char email[30];
    int homePhone;
    int mobileNumber;
};

struct creditHours{
    int max;
    int current;
    int maximum;
    int remaining;
};

struct GPA{
    float overAllGPA;
    int numberOfSemesters;
};

//=========================================//Elwa74
struct student{
    struct studentName StudentName;
    int studentRegistration;
    char studentNationality[20];
    int studentID;
    struct studentHomeAddress StudentHomeAddress;
    struct studentDOB StudentDOB;
    char studentGender;
    int firstEnrollmentTerm;
    int firstEnrollmentYear;
    char studentDepartment[20];
    int currentTerm;
    struct studentContact StudentContact;
    struct creditHours CreditHours;
    struct GPA gpa;
};

//=========================================//Prototypes
void Filler(struct student arr[],int counts);
void Display(struct student Database[],int pickedNumber);
void DOBcalculator(struct student Database[], int target);
void age(int present_date, int present_month, int present_year, int birth_date, int birth_month, int birth_year);
void BubbleSortingReham(struct student Database[], int counts);
//=========================================//Main

int main(int argc, const char * argv[]) {
    int counts;
    printf("Enter students counts: ");
    scanf("%d",&counts);
    typedef struct student Student;
    Student* Database = (Student*)malloc(counts * sizeof(Student));
    
    
    
    Filler(Database, counts);
    
    int pickedNumber;
    printf("Pick the student to display: ");
    scanf("%d",&pickedNumber);
    
    Display(Database, pickedNumber);
    
    int pickedForAge;
    printf("insert the student index to calculate the age: ");
    scanf("%d",&pickedForAge);
    DOBcalculator(Database, pickedForAge-1);
    
    BubbleSortingReham(Database, counts);
    return 0;
}


//=========================================//Functions
void Filler(struct student Database[],int counts){
    for (int i=0; i<counts; i++) {
        printf("Enter the first name of the [%d] student: ",i+1);
        scanf("%s",Database[i].StudentName.firstName);
        printf("Enter the second name of the [%d] student: ",i+1);
        scanf("%s",Database[i].StudentName.middleName);
        printf("Enter the last name of the [%d] student: ",i+1);
        scanf("%s",Database[i].StudentName.lastName);
        printf("Enter the registration number of the [%d] student: ",i+1);
        scanf("%d",&Database[i].studentRegistration);
        printf("Enter the GPA  of the [%d] student: ",i+1);
        scanf("%f",&Database[i].gpa.overAllGPA);
        printf("Enter the nationality of the [%d] student: ",i+1);
        scanf("%s",Database[i].studentNationality);
        printf("Enter the ID of the [%d] student: ",i+1);
        scanf("%d",&Database[i].studentID);
        printf("Enter the home address <flat number> of the [%d] student: ",i+1);
        scanf("%d",&Database[i].StudentHomeAddress.flatNumber);
        printf("Enter the home address <house number> of the [%d] student: ",i+1);
        scanf("%d",&Database[i].StudentHomeAddress.houseNumber);
        printf("Enter the home address <street name> of the [%d] student: ",i+1);
        scanf("%s",Database[i].StudentHomeAddress.streetName);
        printf("Enter the home address <area name> of the [%d] student: ",i+1);
        scanf("%s",Database[i].StudentHomeAddress.areaName);
        printf("Enter the home address <city name> of the [%d] student: ",i+1);
        scanf("%s",Database[i].StudentHomeAddress.cityName);
        printf("Enter the home address <governorate name> of the [%d] student: ",i+1);
        scanf("%s",Database[i].StudentHomeAddress.governorateName);
        printf("Enter the home address <country> of the [%d] student: ",i+1);
        scanf("%s",Database[i].StudentHomeAddress.country);
        printf("Enter the home address <postal code> of the [%d] student: ",i+1);
        scanf("%d",&Database[i].StudentHomeAddress.PostalCode);
        printf("Enter the date of birth <day from 1 to 31> of the [%d] student: ",i+1);
        scanf("%d",&Database[i].StudentDOB.day);
        printf("Enter the date of birth <month from 1 to 12> of the [%d] student: ",i+1);
        scanf("%d",&Database[i].StudentDOB.month);
        printf("Enter the date of birth <year> of the [%d] student: ",i+1);
        scanf("%d",&Database[i].StudentDOB.year);
        printf("Enter the gender of the [%d] student: ",i+1);
        scanf(" %c",&Database[i].studentGender);
        printf("Enter the first enrollment term of the [%d] student: ",i+1);
        scanf("%d",&Database[i].firstEnrollmentTerm);
        printf("Enter the first enrollment year of the [%d] student: ",i+1);
        scanf("%d",&Database[i].firstEnrollmentYear);
        printf("Enter the department of the [%d] student: ",i+1);
        scanf("%s",Database[i].studentDepartment);
        printf("Enter the current term of the [%d] student: ",i+1);
        scanf("%d",&Database[i].currentTerm);
        printf("\n====================\n");
    }
}

void Display(struct student Database[],int pickedNumber){
    printf("The first name of the student [%d] is: [%s]\n",pickedNumber-1,Database[pickedNumber-1].StudentName.firstName);
    printf("The second name of the student [%d] is: [%s]\n",pickedNumber-1,Database[pickedNumber-1].StudentName.middleName);
    printf("The last name of the student [%d] is: [%s]\n",pickedNumber-1,Database[pickedNumber-1].StudentName.lastName);

}

void DOBcalculator(struct student Database[], int target){
    time_t s, val = 1;
    struct tm* current_time;
    s = time(NULL);
    current_time = localtime(&s);

    printf("Day of the month = %d\n",current_time->tm_mday);
    printf("Month of this year = %d\n",(current_time->tm_mon + 1));
    printf("Current year = %d\n",(current_time->tm_year + 1900));
    
    int present_date = current_time->tm_mday;
    int present_month = current_time->tm_mon + 1;
    int present_year = current_time->tm_year + 1900;
    
    int birth_date = Database[target].StudentDOB.day;
    int birth_month = Database[target].StudentDOB.month;
    int birth_year = Database[target].StudentDOB.year;
    
    age(present_date, present_month, present_year, birth_date, birth_month, birth_year);
    
}

void age(int present_date, int present_month, int present_year, int birth_date, int birth_month, int birth_year) {
   int month[] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
   if (birth_date > present_date) {
      present_date = present_date + month[birth_month - 1];
      present_month = present_month - 1;
   }
   if (birth_month > present_month) {
      present_year = present_year - 1;
      present_month = present_month + 12;
   }
   int final_date = present_date - birth_date;
   int final_month = present_month - birth_month;
   int final_year = present_year - birth_year;
   printf("Present Age Years: %d Months: %d Days: %d\n", final_year, final_month, final_date);
}

void BubbleSortingReham(struct student Database[], int counts){
    float extractedGPA[counts];
    int extractedEnrollmentYear[counts];
    struct studentName extractedNames[counts];
    
    for (int i=0; i<counts; i++) {
        extractedGPA[i] = Database[i].gpa.overAllGPA;
        extractedEnrollmentYear[i] = Database[i].firstEnrollmentYear;
        strcpy(extractedNames[i].firstName, Database[i].StudentName.firstName);
        strcpy(extractedNames[i].middleName, Database[i].StudentName.middleName);
        strcpy(extractedNames[i].lastName, Database[i].StudentName.lastName);
    }
    //bubbleSortReham
    for(int i=1;i<counts;i++){ //passes
        for(int j=0;j<counts-i;j++){ //positions
            if(extractedGPA[j]>extractedGPA[j+1]){
                
                float temp = extractedGPA[j];
                extractedGPA[j] = extractedGPA[j+1];
                extractedGPA[j+1] = temp;
                
                int temp2 = extractedEnrollmentYear[j];
                extractedEnrollmentYear[j] = extractedEnrollmentYear[j+1];
                extractedEnrollmentYear[j+1] = temp2;
                
                char temp3[50];
                strcpy(temp3, extractedNames[j].firstName);
                strcpy(extractedNames[j].firstName, extractedNames[j+1].firstName);
                strcpy(extractedNames[j+1].firstName, temp3);
                
                strcpy(temp3, extractedNames[j].middleName);
                strcpy(extractedNames[j].middleName, extractedNames[j+1].middleName);
                strcpy(extractedNames[j+1].middleName, temp3);
                
                strcpy(temp3, extractedNames[j].lastName);
                strcpy(extractedNames[j].lastName, extractedNames[j+1].lastName);
                strcpy(extractedNames[j+1].lastName, temp3);
            }
        }
    }
    //printing results
    printf("the sorted GPA: \n");
    for (int i=0; i<counts; i++) {
        printf("%5f%5d   %s %s %s\n",extractedGPA[i],extractedEnrollmentYear[i],extractedNames[i].firstName,extractedNames[i].middleName,extractedNames[i].lastName);
    }
}


