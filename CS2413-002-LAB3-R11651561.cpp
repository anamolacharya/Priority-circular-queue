// AUTHOR: Anamol Acharya
// FILENAME: CS2413-002-LAB3-R11651561.cpp
// SPECIFICATION: CREATING THREE RAMDOM NUMBERS, 3 LEVEL PRIORITY CIRCULAR QUEUE DATA STRUCTURE USING ARRAYS.
// FOR: CS 2413 Data Structure Section 002



#include <stdio.h>
#include <conio.h>
#include <iostream>
#include <ctime>
#define maximum 10
using namespace std;


int que1[maximum], que2[maximum], que3[maximum];
int front1=-1, rear1=-1, front2 =-1, rear2 =-2, front3=-1, rear3=-1;    //place value for front and rear of each queue

void insert1(void);                                                     //operations for queue 1
int delete1_element(void);
int peek1(void);
void display1(void);

void insert2(void);                                                     //operartions for queue2
int delete2_element(void);
int peek2(void);
void display2(void);

void insert3(void);                                                     //operations for queue3
int delete3_element(void);
int peek3(void);
void display3(void);

int main()
{
    int option, value;                                                  //place the varible option and value
    srand(time(NULL));
    cout << "Creating 3 Random Numbers " << endl;
    cout<<"First : " << rand() % 10<< endl;                           // To create a random Number between 0-9
    cout<<"Second : " << rand() % 100<< endl;                        // To create a random number between 10-99
    cout<<"Third : " << rand() % 1000<< endl;                        // To create a random number between 100 -999
    do
    {
        cout << endl;
        cout << " <<<<<< MAIN MENU >>>>>>" << endl;
        cout << "    On Queue 1 " << endl;
        cout << " 1. Insert an element" << endl;
        cout << " 2. Delete an element" << endl;
        cout << " 3. Peek" << endl;
        cout << " 4. Display" << endl;

        cout << "    On Queue 2 " << endl;
        cout << " 5. Insert an element" << endl;
        cout << " 6. Delete an element" << endl;
        cout << " 7. Peek" << endl;
        cout << " 8. Display" << endl;

        cout << "    On Queue 3 " << endl;
        cout << " 9. Insert an element" << endl;
        cout << "10. Delete an element" << endl;
        cout << "11. Peek" << endl;
        cout << "12. Display" << endl;
        cout << "13. EXIT " << endl;
        cout << endl;



        cout << " Enter your option : ";

        cin >> option;
switch(option)
{
    case 1: insert1();                                                  //switch case for inseting
    break;
    case 2: value = delete1_element();                                  //switch case for deleting a element
            if(value!=-1)
                printf("\n The number deleted is : %d", value);
    break;
    case 3: value = peek1();
            if(value!=-1)
                printf("\n The first value in queue is : %d", value);
    break;
    case 4:  display1();
    break;
    case 5: insert2();                                                  //switch case for inseting
    break;
    case 6: value = delete2_element();                                  //switch case for deleting a element
            if(value!=-1)
                printf("\n The number deleted is : %d", value);
    break;
    case 7: value = peek2();
            if(value!=-1)
                printf("\n The first value in queue is : %d", value);
    break;
    case 8:  display2();
    break;
    case 9: insert3();                                                  //switch case for inseting
    break;
    case 10: value = delete3_element();                                 //switch case for deleting a element
            if(value!=-1)
                printf("\n The number deleted is : %d", value);
    break;
    case 11: value = peek3();
            if(value!=-1)
                printf("\n The first value in queue is : %d", value);
    break;
    case 12:  display3();
    break;
    
}

}
while(option!=13);
    getch();
    return 0;
}


void insert1()                                                  //place a function insert1 
{
    int number;                                                 //introduce number variable
    printf("\n Enter the number to be inserted in the queue : ");
    scanf("%d", &number);
    if(front1==0 && rear1==maximum-1)                           //check if queue is overflow
    printf("\n QUEUE OVERFLOW");
    else if(front1==-1 && rear1==-1)                            
{
    front1=rear1=0;                                             //insert element in first node of queue
    que1[rear1]=number;
}
    else if(rear1==maximum-1 && front1!=0)                      // check if front part of queue has empty sapce
{
    rear1=0;
    que1[rear1]=number;
}
    else
    {
        rear1++;
        que1[rear1]=number;                                     //insert the number in the rear part of the queue
    }
}

int delete1_element()                                           //place a function delete1_element
{
    int value;                                                  //place a new variable value
    if(front1==-1 && rear1==-1)                                 //check if the queue is under flow or not
{
    printf("\n QUEUE UNDERFLOW");
    return -1;
}
    value = que1[front1];                                   
    if(front1==rear1)                                           //check if there is only 1 element
    front1=rear1=-1;
    else
{
    if(front1==maximum-1)
    front1=0;
    else
    front1++;
}
    return value;
}

int peek1()                                                     //make a function peek1
{
    if(front1==-1 && rear1==-1)                                 //to check if queue is empty or not
{
    printf("\n QUEUE IS EMPTY");
    return -1;}
    else
{
    return que1[front1];                                        // return the value to que1
}
}

void display1()                                                 //place a function display1
{
    int i;                                                      //intruduce a variable i
    printf("\n");
    if (front1 ==-1 && rear1==-1)                               //check if an queue is empty
    printf ("\n QUEUE IS EMPTY");
    else
{
    if(front1 < rear1)
{
    for(i=front1;i<=rear1;i++)
    printf("\t %d", que1[i]);
}
    else
    {
        for(i=front1 ;i<maximum; i++)
        printf("\t %d", que1[i]);
        for(i=0;i<=rear1;i++)
        printf("\t %d", que1[i]);
    }
}
}


void insert2()                                                          //place a function insert2
{
    int number;                                                         //introduce number variable
    printf("\n Enter the number to be inserted in the queue : ");
    scanf("%d", &number);
    if(front2==0 && rear2==maximum-1)                                   //check if queue is overflow
    printf("\n QUEUE OVERFLOW");
    else if(front2==-1 && rear2==-1)
{
    front2=rear2=0;                                                     //insert element in first node of queue
    que2[rear2]=number;
}
    else if(rear2==maximum-1 && front2!=0)                              // check if front part of queue has empty sapce
{
    rear2=0;
    que2[rear2]=number;                                                 //insert the number in the rear part of the queue
}
    else
    {
        rear2++;
        que2[rear2]=number;
    }
}

int delete2_element()                                                   //place a function delete2_element
{
    int value;                                                          //place a new variable value
    if(front2==-1 && rear2==-1)                                         //check if the queue is under flow or not
    {
        printf("\n QUEUE UNDERFLOW");
        return -1;
    }
    value = que2[front2];                                               //check if there is only 1 element
    if(front2==rear2)
    front2=rear2=-1;
    else
    {
        if(front2==maximum-1)
        front2=0;
        else
        front2++;
    }
    return value;
}

int peek2()                                                         //make a function peek2
{
    if(front2==-1 && rear2==-1)                                     //to check if queue is empty or not
{
    printf("\n QUEUE IS EMPTY");
    return -1;}
    else
    {
        return que2[front2];                                        // return the value to que2
    }
}

void display2()                                                     //place a function display2
{
    int i;                                                          //intruduce a variable i
    printf("\n");
    if (front2 ==-1 && rear2 ==-1)                                  //check if an queue is empty
    printf ("\n QUEUE IS EMPTY");                                                   
    else
{
    if(front2 < rear2)
{
    for(i=front2;i<=rear2;i++)
    printf("\t %d", que2[i]);
    }
    else
    {
        for(i=front2 ;i<maximum; i++)
        printf("\t %d", que2[i]);
        for(i=0;i<=rear2;i++)
        printf("\t %d", que2[i]);
    }
}
}

void insert3()                                                          //place a function insert3
{
    int number;                                                         //introduce number variable
    printf("\n Enter the number to be inserted in the queue : ");
    scanf("%d", &number);
    if(front3==0 && rear3==maximum-1)                                   //check if queue is overflow
    printf("\n QUEUE OVERFLOW");
    else if(front3==-1 && rear3==-1)
{
    front3=rear3=0;                                                      //insert element in first node of queue
    que3[rear3]=number;
}
 else if(rear3==maximum-1 && front3!=0)                                 // check if front part of queue has empty sapce
{
    rear3=0;
    que3[rear3]=number;                                                 //insert the number in the rear part of the queue
}
else
{
    rear3++;
    que3[rear3]=number;
}
}

int delete3_element()                                                   //place a function delete3_element
{
    int value;                                                          //place a new variable value
    if(front3==-1 && rear3==-1)                                         //check if the queue is under flow or not
{
    printf("\n QUEUE UNDERFLOW");
    return -1;
}
    value = que3[front3];                                               //check if there is only 1 element
    if(front3==rear3)
    front3=rear3=-1;
    else
    {
            if(front3==maximum-1)
            front3=0;
            else
            front3++;
    }
    return value;
}

int peek3()                                                                 //make a function peek3
{
    if(front3==-1 && rear3==-1)                                             //to check if queue is empty or not
{
    printf("\n QUEUE IS EMPTY");
    return -1;}
    else
{
    return que3[front3];                                                    // return the value to que3
}
}

void display3()                                                             //place a function display3
{
    int i;                                                                  //intruduce a variable i
    printf("\n");
    if (front3 ==-1 && rear3==-1)                                           //check if an queue is empty
    printf ("\n QUEUE IS EMPTY");
    else
{
    if(front3<rear3)
    {
        for(i=front3;i<=rear3;i++)
        printf("\t %d", que3[i]);
    }
    else
    {
        for(i=front3 ;i<maximum; i++)
        printf("\t %d", que3[i]);
        for(i=0;i<=rear3;i++)
        printf("\t %d", que3[i]);
    }
}
}