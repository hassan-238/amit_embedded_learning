#include <stdio.h>
#define STR_MAX_LENGTH 32
struct Student {
  int rollNumber;
  char name[STR_MAX_LENGTH + 1];
  int mark;
};
void Student_Read(struct Student *self) {
  printf("Enter Roll number: ");
  scanf(" %d", &self->rollNumber);
  printf("Enter Name: ");
  scanf(" %32s", self->name);
  self->name[STR_MAX_LENGTH] = '\0';

  printf("Mark: ");
  scanf(" %d", &self->mark);
}

void Student_Write(const struct Student *self) {
  printf("%d) %s  ##  %d\n", self->rollNumber, self->name, self->mark);
}

struct Employee {
  int id;
  char name[STR_MAX_LENGTH + 1];
  int salary;
};
void Employee_Read(struct Employee *self) {
  printf("Enter id: ");
  scanf(" %d", &self->id);

  printf("Enter Name: ");
  scanf(" %32s", self->name);
  self->name[STR_MAX_LENGTH] = '\0';

  printf("salary: ");
  scanf(" %d", &self->salary);
}

void Employee_Write(const struct Employee *self) {
  printf("%d) %s  ##  %d egp\n", self->id, self->name, self->salary);
}
void Employee_SetSalary(struct Employee *self, float newSalary) {
  self->salary = newSalary;
}
void q3() {
  struct Student students[5];
  for (int i = 0; i < 5; i++) {
    Student_Read(students + i);
  }
  for (int i = 0; i < 5; i++) {
    Student_Write(students + i);
  }
}

struct Student q4(struct Student students[], int size) {
  float max = students[0].mark;
  int index = 0;
  for (int i = 1; i < size; i++) {
    if (students[i].mark > max)
      index = i;
  }
  return students[index];
}
float q5(struct Student students[], int size) {
  float marks = 0;
  for (int i = 0; i < size; i++) {
    marks += (float)students[i].mark;
  }
  return marks / (float)size;
}

struct Book {
  int id;
  char title[STR_MAX_LENGTH + 1];
  float price;
};
void Book_Read(struct Book *self) {
  printf("Enter id: ");
  scanf(" %d", &self->id);

  printf("Enter Title: ");
  scanf(" %32s", self->title);
  self->title[STR_MAX_LENGTH] = '\0';

  printf("Price: ");
  scanf(" %f", &self->price);
}

void Book_Write(const struct Book *self) {
  printf("%d) %s  ##  %.2f\n", self->id, self->title, self->price);
}
void Book_program(const struct Book books[], int size) {
  float value = books[0].price;
  printf("Enter min price: ");
  scanf(" %f", &value);
  for (int i = 0; i < size; i++) {
    if (books[i].price >= value) {
      Book_Write(books + i);
    }
  }
}

struct Product {
  int id;
  char name[STR_MAX_LENGTH + 1];
  float price;
};

void Product_Read(struct Product *self) {
  printf("Enter id: ");
  scanf(" %d", &self->id);

  printf("Enter Title: ");
  scanf(" %32s", self->name);
  self->name[STR_MAX_LENGTH] = '\0';

  printf("Price: ");
  scanf(" %f", &self->price);
}

void Product_Write(const struct Product *self) {
  printf("%d) %s  ##  %.2f\n", self->id, self->name, self->price);
}
void Product_program(const struct Product *self) {
  struct Product product = {0};
  Product_Read(&product);
  int quantity = 0;
  printf("Enter quantity: ");
  scanf("%d", &quantity);

  printf("Total price: %f", quantity * self->price);
}

struct Time {
  int seconds;
  int minutes;
  int hours;
  int days;
};

struct Time Time_Add(const struct Time *self, const struct Time *other) {
  struct Time time = {0};
  time.seconds = self->seconds + other->seconds;
  time.minutes += time.minutes / 60;
  time.minutes += self->minutes + other->minutes;
  time.hours += time.minutes / 24;
  time.hours += self->hours + other->hours;

  return time;
}

struct Distance {
  int amount;
};
struct Distance Distance_Add(const struct Distance *d1,
                             const struct Distance *d2) {
  return (struct Distance){d1->amount + d2->amount};
}

struct Date {
  int day;
  int month;
  int year;
};

void Date_Write(const struct Date *self) {
  printf("%02d/%02d/%02d\n", self->day, self->month, self->year);
}
struct Date Date_GetEarlier(const struct Date *d1, const struct Date *d2) {
  if (d1->year < d2->year)
    return *d1;
  else if (d2->year < d1->year)
    return *d2;
  else {
    if (d1->month < d2->month)
      return *d1;
    else if (d2->month < d1->month)
      return *d2;
    else {
      if (d1->day < d2->day)
        return *d1;
      else if (d2->day < d1->day)
        return *d2;
    }
  }
  return *d1;
}

struct Address {
  int blockNo;
  char roadName[STR_MAX_LENGTH];
  char city[STR_MAX_LENGTH];
  char country[STR_MAX_LENGTH];
};
struct Student2 {
  int id;
  char name[STR_MAX_LENGTH + 1];
  int mark;
  struct Address Address;
};

void Student2_Write(const struct Student2 *self) {
  printf("%d) %s  ##  %d\n", self->id, self->name, self->mark);
  printf("\tAddress: %s,%s,%s,%d", self->Address.country, self->Address.city,
         self->Address.roadName, self->Address.blockNo);
}

void Addess_Print_PTR(const struct Address *self) {
  int *blockNoPtr = (int *)self;
  printf("BlockNo: %d\n", *blockNoPtr);
  char (*strPtr)[STR_MAX_LENGTH] = (char (*)[STR_MAX_LENGTH])(blockNoPtr + 1);
  printf("ROAD: %s\n", *strPtr++);
  printf("City: %s\n", *strPtr++);
  printf("Country: %s\n", *strPtr);
}

const struct Student *Student_Search(const struct Student students[], int size,
                                     int rollNumber) {
  for (int i = 0; i < size; i++) {
    if (students[i].rollNumber == rollNumber)
      return (students + i);
  }
  return NULL;
}

void Employee_SortSalary(struct Employee employees[], int size) {
  int swapped = 1;
  while (swapped) {
    swapped = 0;
    for (int i = 0; i < size - 1; i++) {
      if (employees[i].salary < employees[i + 1].salary) {
        struct Employee temp = employees[i];
        employees[i] = employees[i + 1];
        employees[i + 1] = temp;
        swapped = 1;
      }
    }
  }
}

struct BankAccount {
  int id;
  char ownerName[STR_MAX_LENGTH];
  int amount;
};

void Bank_Deposit(struct BankAccount *self, int amount) {
  self->amount += amount;
}
void Bank_Withdraw(struct BankAccount *self, int amount) {
  self->amount -= amount;
}

int main(void) {
  char *str;
  const char *msg = (str == NULL) ? "TRUE" : "FALSE";
  printf("%s\n", msg);
  struct Address add = {22, "Mohsen", "Beh2", "NIOICE"};
  Addess_Print_PTR(&add);
  return 0;
}
