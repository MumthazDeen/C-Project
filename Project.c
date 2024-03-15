#include <stdio.h>
#include <stdlib.h>

/**< Lobby Variables */
int options,password,pw=2000;
char username[8];

/**< New Billing  */
char address[75],name[100],discrip[150];
char weightT;
float cus_id = 1;
float weight;
float FPriceC,PriceC;
int nic,carat;

/**< Existing Items */
int category;

/**< Total Sale */
float TSale;



void Lobby()
{
     printf("             \tACES GOLD PAWNBROKERS\n                Licensed PawnBrokers\n\n");
     printf("*************A fresh approach to shopping************\n                   TEL 0719801010\n              No.10,Main street ,Galle.\n\n");

     printf("A very warm welcome to the Ace Gold Shop.\n");
     printf("Please Login to continue.....\n\n");

     while(1==1)
     {
        printf("  UserName:   ");
        scanf("%s", &username);

        if(strlen(username)>=8)
        {
            printf("  Incorrect UserName!!!!");
        }
        else
        {
            printf("  Password:   ");
            scanf("%d", &password);

            if(password==pw)
            {
                printf(" \nLogin Successfull!!!\n\n");

            }
            else
            {
                printf("  Incorrect Password,Try Again!!!");
            }
        }
   }
   //LOptions();
}
//Options after Lobby
void LOptions()
{
     //delay(200000);
     forDelay(100000000000000);
     system("cls");
     printf("[1]> New Billing\n\n[2]> Past Billings\n\n[3]> Existing Items\n\n[4]> Total Sales of the Day\n\n[5]> Exit\n\n");
     printf("Choose a section to enter : ");
     scanf("%d",&options);

     switch(options)
     {
     case 1:
        NewBilling();
        break;
     case 2:
        PastBillings();
        break;
     case 3:
        ExistingItems();
        break;
     case 4:
        TotSale();
        break;
     case 5:
        Exit();
        break;
     default:
        printf("There's no such option number.");
     }
}
//New Billing
void NewBilling()
{
    int Other;


    system("cls");
    printf("..........New Bill..........\n");
    printf("\nName of the Customer :- ");
    scanf("%s",&name);
    printf("NIC NO:-");
    scanf("%f",&nic);

            printf("Customer ID:- APB%.0f\n\n",cus_id++);

            //cus_id = cus_id + 1;

    printf("Choose Carat Type from \n-22\n-24\n\n");
    printf("\nEnter Carat type :-");
    scanf(" %d",&carat);

    printf("\nChoose Weight Type from \n--M - as Milligram\n--G - as Gram\n\n ");
    printf("Weight Type :-");
    scanf(" %c",&weightT);

    printf("\nWeight of the article :-");
    scanf("%f",&weight);

    printf("Description of article mortgaged :-");
    scanf("%s",&discrip);

    printf("Do you want to pawn any other items?? If \nyes - Enter y\n No - Enter N\n");
    scanf(" %c",&Other);

    if(Other=='y' || Other=='Y')
    {
        Calculate();
        FPriceC = FPriceC + PriceC;
        NewBilling();
    }
    else if(Other=='n' || Other=='N')
    {
        Calculate();

        FPriceC = PriceC;
        system("cls");
        printf("Pleasure to help you!!!\n\n\n");
        Display();
    }
}

//calculations
void Calculate()
{
    if(weightT == 'm')
    {

        if(carat==22)
        {
            PriceC = weight * 22.4;

        }
        else if(carat==24)
        {
            PriceC = weight * 2.31;

        }

    }
    else if(weightT=='g')
    {
        if(carat==22)
        {
            PriceC = weight * 9054;

        }
        else if(carat==24)
        {
            PriceC = weight *22420;

        }

    }
    //printf("%f",PriceC);

   // PriceC = 10;
}
void Display()
{
   printf("..........Final Bill..........");
   printf("\n\nYour Item is pawned successfully Mr/Ms : %s\n",name);
   printf("With payment id : GPB%.0f\n",cus_id);
   printf("\nThe price item is pawned for (Rs):- %.2f \n" ,FPriceC);
   printf("\nDate of Repayment:- 3 months from today.");//*

}


void PastBillings()
{
    /**< File Handling PART 1 */
    //FILE *p=fopen("C://Users//DELL//OneDrive//Documents//Mumthaz//C Project//P bills//bills.txt","a");
    //fprintf(p,"Name : %s\nNIC : %f\nDescription : %s\nPawned items price : %.2f",name,nic,discrip,FPriceC);

}
void ExistingItems()
{
    printf("..........Main Categories..........\n\n");
    printf("      [1]Chain\n      [2]Bracelet\n      [3]Rings\n      [4]Anklet\n\n      ");
    printf("Choose a category : ");
    scanf("%d",&category);
    if(category==1)
    {
        printf("Pawned Item Owner : %s\n",&name);
        printf("Pawned Item : %s \n",&discrip);
    }
}
void TotSale()
{
    printf("..........Total Sales..........\n\n");
    TSale=TSale+FPriceC;
    printf("The Total bill is :%f",TSale);
}
void Exit()
{
    return 0;
}

/**< Time and Date */
void def()
{
    time_t t = time(NULL);
    printf("\n %s", ctime(&t));
}

/**< To Delay system Clear */
void forDelay(int x)
{
    int a,b;
    for(int a=1;a>x;a++)
    {
        b=a;
    }
}

int main()
{
    //FILE *p=fopen("C://Users//DELL//OneDrive//Documents//Mumthaz//C Project//P bills//bills.txt","a");
    system("color F0");
    system("cls");
    Lobby();
    forDelay(100000000000000000000000000000000000000);
    LOptions();


}
