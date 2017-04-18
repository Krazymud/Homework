#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
typedef struct {
  int year, month, day;
} Date;

Date* CreateDate(int year, int month, int day);
void DestroyDate(Date** p);
Date* CopyDate(const Date* date);

int GetYear(const Date* date);
int GetMonth(const Date* date);
int GetDay(const Date* date);
void SetYear(Date* date, int year);
void SetMonth(Date* date, int month);
void SetDay(Date* date, int day);
void SetDate(Date* date, int year, int month, int day);

char* GetDateString(const Date* date);
void DestroyDateString(char** p);

void IncreaseDate(Date* date);
void DecreaseDate(Date* date);

void TestDate(Date* date, int after, int before) {
  printf("Year: %d\n", GetYear(date));
  printf("Month: %d\n", GetMonth(date));
  printf("Day: %d\n", GetDay(date));

  char* date_string = GetDateString(date);
  printf("Formatted: %s\n", date_string);

  DestroyDateString(&date_string);
  assert(date_string == NULL);
  DestroyDateString(&date_string);

  IncreaseDate(date);
  date_string = GetDateString(date);
  printf("1 day later: %s\n", date_string);
  DestroyDateString(&date_string);

  int i;
  for (i = 0; i < after; ++i) {
    IncreaseDate(date);
  }
  date_string = GetDateString(date);
  printf("Another %d day(s) later: %s\n", after, date_string);
  DestroyDateString(&date_string);

  for (i = 0; i < before; ++i) {
    DecreaseDate(date);
  }
  date_string = GetDateString(date);
  printf("Another %d day(s) earlier: %s\n", before, date_string);
  DestroyDateString(&date_string);  
}


Date* CreateDate(int year, int month, int day){
	Date* newDate = (Date*)malloc(sizeof(Date));
	newDate->day = day;
	newDate->year = year;
	newDate->month = month;
	return newDate;
}
Date* CopyDate(const Date* date){
	Date* newDate = (Date* )malloc(sizeof(Date));
	newDate->day = date->day;
	newDate->year = date->year;
	newDate->month = date->month;
	return newDate;
}
void DestroyDate(Date** p){
	if(*p!=NULL){
		free(*p);
		*p=NULL;
	}
}

int GetYear(const Date* date){
	return date->year;
}
int GetMonth(const Date* date){
	return date->month;
}
int GetDay(const Date* date){
	return date->day;
}
void SetYear(Date* date, int year){
	date->year = year;
}
void SetMonth(Date* date, int month){
	date->month = month;
}
void SetDay(Date* date, int day){
	date->day = day;
}
void SetDate(Date* date, int year, int month, int day){
	date->year = year;
	date->month = month;
	date->day = day;
}

char* GetDateString(const Date* date){
	char* new_string =(char* )malloc(sizeof(char)*11);
	snprintf(new_string, 11, "%d-%02d-%02d", date->year, date->month, date->day);
	return new_string;
}
void DestroyDateString(char** p){
	if(*p!=NULL){
		free(*p);
		*p=NULL;
	}
}
void IncreaseDate(Date* date){
	++date->day;
    if(date->day>daysOfMonth(date->year, date->month)){
    	date->day=1;
    	++date->month;
    	if(date->month>12){
    		date->month=1;
    		++date->year;
		}
	}
}
void DecreaseDate(Date* date){
	--date->day;
	if(date->day==0){
		if(date->month==1){
			date->day=31;
			date->month=12;
			--date->year;
		}
		else{
			--date->month;
			date->day=daysOfMonth(date->year, date->month);
		}
	}
}


int daysOfMonth(int year, int month){
  if(month==2){
     if((year%4==0&&year%100!=0) || year%400==0)
           return 29;
           return 28;
  }
  switch(month){
     case 4:case 6: case 9: case 11:
       return 30;
     default:
       return 31;
   }
}
int main() {
  int year, month, day;
  int after, before;
  scanf("%d%d%d%d%d", &year, &month, &day, &after, &before);

  Date* date1 = CreateDate(year, month, day);
  assert(sizeof(*date1) == sizeof(Date));

  Date* date2 = CopyDate(date1);
  assert(date1 != date2);
  assert(date1->month == date2->month);

  SetDate(date1, year + 1, month, day);
  SetYear(date1, year);
  SetMonth(date1, month);
  SetDay(date1, day);

  TestDate(date1, after, before);

  DestroyDate(&date1);
  DestroyDate(&date2);

  assert(date1 == NULL);
  DestroyDate(&date2);

  return 0;
}


