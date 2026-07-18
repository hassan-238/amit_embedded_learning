// #include <stdio.h>


// struct Employee{
//     int id;
//     int age;
//     int salary;
//     char name[48];
// };

// struct Employee InputEmployee()
// {
//     struct Employee employee;
//     printf("Enter ID: ");
//     scanf(" %d",&employee.id);
//     printf("Enter name: ");
//     scanf(" %46s",employee.name);
//     employee.name[47] = '\0';
//     printf("Enter salary: ");
//     scanf(" %d",&employee.salary);
//     printf("Enter age: ");
//     scanf(" %d",&employee.age);

//     return employee;
// }

// void PrintEmployee(const struct Employee * self)
// {
//     printf("ID: %d\n",self->id);
//     printf("NAME: %s\n",self->name);
//     printf("SALARY: %d\n",self->salary);
//     printf("AGE: %d\n",self->age);
// }

// int main(void)
// {
//     struct Employee e = InputEmployee();
//     struct Employee e2 = InputEmployee();
//     PrintEmployee(&e);
//     PrintEmployee(&e2);

//     return 0;
// }

#include <stdio.h>

typedef struct {
    char name[32];
    int age;
    float mark;
}Student;

typedef struct {
   int x:32;
   int y:8;
   int k:8;
   int z:8;
   int l:7;
   int f:1;
}test;

void func(int* x){
    return;
}

int main(void)
{
    int c[] = {1,2,3};
    int* ptr = c;
    printf("%d\n",*ptr++);
    func(c);
    return 0;
    printf("%d",sizeof(test));
    return 0;
    Student students[3];
    for(int i = 0; i < 3; i ++)
    {
        printf("Enter Name: ");
        scanf("%31s",students[i].name);

        printf("Enter Age: ");
        scanf("%d",&students[i].age);

        printf("Enter Mark: ");
        scanf("%f",&students[i].mark);
    }

    for(int i = 0 ; i < 3; i++)
    {
        printf("%s, %d, %.2f\n",students[i].name,students[i].age,students[i].mark);
    }
}