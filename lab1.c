#include <stdio.h>
#include <string.h>
#include <windows.h>
#include <stdlib.h>

struct carRent {
    char name[50], ID_number[8];
    int rent_time, car_type[100], age;
};

int total_pay(int);
int computation(int temp[],int *iMax, int *min, int *iMin);

int total = 0;

int main(){

    int i, status, hour[100], new_total = 0, check, temp[5]={}, iMax, min, iMin, max, size = 0;
    char carName[5][10]={"Myvi","Axia","Benza","Viva","Saga"};
    struct carRent car[100];

    // user input
    for(i = 0; i < 100; i++){
        printf("Name: ");
        scanf("%s", car[i].name);
        printf("Student ID: ");
        scanf("%s", car[i].ID_number);
        printf("Age: ");
        scanf("%d", &car[i].age);

        do{
            printf("Type of car(1.Myvi, 2.Axia, 3.Benza, 4.Viva, 5.Saga): ");
            scanf("%d", &car[i].car_type[i]);
            
            // record every car rented
            if(car[i].car_type[i] == 1){
                temp[0] += car[i].car_type[i];

            }else if(car[i].car_type[i] == 2){
                temp[1] += (car[i].car_type[i] - 1);

            }else if(car[i].car_type[i] == 3){
                temp[2] += (car[i].car_type[i] - 2);

            }else if(car[i].car_type[i] == 4){
                temp[3] += (car[i].car_type[i] - 3);

            }else if(car[i].car_type[i] == 5){
                temp[4] += (car[i].car_type[i] - 4);
            }

            // input validation
            if (car[i].car_type[i] < 1 || car[i].car_type[i] > 5){
                printf("Please enter the given car number below. Thank you :)\n");
                check = 1; // 1 return as true
            } else {
                check = 0; // 0 return as false
            }
        }while(check);
        
        printf("Hours rent: ");
        scanf("%d", &hour[i]);

        
        if(car[i].car_type[i] == 1){
            car[i].rent_time = hour[i] * 5;
        }
        else if(car[i].car_type[i] == 2){
            car[i].rent_time = hour[i] * 4;
        }
        else if(car[i].car_type[i] == 3){
            car[i].rent_time = hour[i] * 6;
        }
        else if(car[i].car_type[i] == 4){
            car[i].rent_time = hour[i] * 3;
        }
        else if(car[i].car_type[i] == 5){
            car[i].rent_time = hour[i] * 5;
        }
        new_total = total_pay(car[i].rent_time);
        size++;

        // continue or exit options
        printf("Is it all for today (1 = Yes, 0 = No?)");
        scanf("%d", &status);
        if(status == 1){
            break;
        }
    }
    max = computation(temp, &iMax, &min, &iMin);

    // owner report
    for(i = 0; i < size; i++){
        printf("Name: %s\n", car[i].name);
        printf("ID Number: %s\n", car[i].ID_number);
        printf("Age: %d\n", car[i].age);
        if(car[i].car_type[i] == 1){
            printf("Car type: %s", carName[0]);
        }
        if(car[i].car_type[i] == 2){
            printf("Car type: %s", carName[1]);
        }
        if(car[i].car_type[i] == 3){
            printf("Car type: %s", carName[2]);
        }
        if(car[i].car_type[i] == 4){
            printf("Car type: %s", carName[3]);
        }
        if(car[i].car_type[i] == 5){
            printf("Car type: %s", carName[4]);
        }
        printf("\n");
        printf("Hours: %d\n\n", hour[i]);
    }
    printf("Overall Report\n\n");
    printf("The most famous car is %s with amount rented by %d", carName[iMax], max);
    printf("\nThe most least famous car is %s with amount rented by %d", carName[iMin], min);
    printf("\nTotal rent today is %d", new_total);
}

int total_pay(int car){
    
    return total = total + car;
}

int computation(int temp[], int *iMax, int *min, int *iMin){
    int max = temp[0];
    *min = temp[0];
    *iMax = 0;
    *iMin = 0;

    for(int i=1;i < 5;i++){
        if(temp[i] > max){
            max = temp[i];
            *iMax = i;
        }
    }
    for(int i=1;i < 5;i++){
        if(temp[i] < *min){
            *min = temp[i];
            *iMin = i;
        }
    }
    return max;
}

/* SYSTEMTIME t;
    GetLocalTime(&t);

    printf("Year : %d\n", t.wYear);
 */
    /*if(ic_depan < 22){
        tahun = 22 - ic_depan;
    }else(ic_depan > 22){
        tahun = 100 - ic_depan + 22;
    }*/

   /*for(int j=0;j < 2;j++){
            icFront[j] = car[i].ic;
        }*/