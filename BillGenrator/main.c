#include <stdio.h>  //Standard input and output
#include <string.h> //String functions
#include <stdlib.h> //standard library

struct items // Here stucture is defined which is user defined data
{
    char item[20];
    int qty;
    float price;
};

struct orders
{
    char customer[50];
    char date[50];
    char time[50];
    int noofitems;
    struct items itm[50];
};

void GenrateBillheader(char name[50], char date[30], char time[30]) // Header of the bill function
{
    printf("\n");
    printf("\t Ichiraku Restaurant");
    printf("\n\t -------------------");
    printf("\nDate:%s\tTime:%s", date, time);
    printf("\nInvoice to: %s", name);
    printf("\n--------------------------------------");
    printf("\n Items");
    printf("\t\t Qty");
    printf("\t\t Total \n");
    printf("--------------------------------------");
    printf("\n\n");
}

void GenrateBillbody(char item[30], int qty, float price) // Body of the bill function
{
    printf(" %s\t\t", item);
    printf(" %d\t\t", qty);
    printf("%.2f", price * qty); // %.2f(means 2 decimal place)
    printf("\n");
}

void GenrateBillfooter(float Total) // Footer of the bill
{
    float d = 0.01 * Total;
    float netTotal = Total - d;
    float cgst = 0.09 * netTotal, grandTotal = netTotal + 2 * cgst; // Taking tax cgst ans sgst at 9%
    printf("\n\n");
    printf("--------------------------------------\n");
    printf("Sub Total\t\t\t%.2f\n", netTotal);
    printf("Discount @10%\t\t\t%.2f\n", d);
    printf("\t\t\t\t------\n");
    printf("Net Total\t\t\t%.2f\n", netTotal);
    printf("CGST @9%\t\t\t\t%.2f\n", cgst);
    printf("sGST @9%\t\t\t\t%.2f\n", cgst);
    printf("--------------------------------------\n");
    printf("Grand Total\t\t\t%.2f\n", grandTotal);
    printf("--------------------------------------");
}

int main()
{
    int o; // option variable
    char chr;
    struct orders ord;
    int n; // no of items variable
    float Total;
    // Dashboard
    printf("=============Ichiraku Restaurant=============\n");
    printf("Please select your preferred option: \n");
    printf("1.Genrate Invoice\n");
    printf("2.Exit \n\n");
    printf("Your Choice:\t");
    scanf("%d", &o);
    fgetc(stdin);

    do
    {
        switch (o)
        {
        case 1:
            printf("Enter the name of the coustomer: ");
            fgets(ord.customer, 50, stdin);             // fgets reads a text line or a string from the specified file or console,50 is the length limit and stdin
            ord.customer[strlen(ord.customer) - 1] = 0; // ths line removes the /n from text
            strcpy(ord.date, __DATE__);                 // this function means that the value of _Date_ will be stored in ord.date
            strcpy(ord.time, __TIME__);

            printf("Enter the no. of items:\t");
            scanf("%d", &n);
            ord.noofitems = n;

            for (int i = 0; i < n; i++)
            {
                fgetc(stdin);
                printf("\n\n");
                printf("Please enter the item %d:\t", i + 1);
                fgets(ord.itm[i].item, 20, stdin);
                ord.itm[i].item[strlen(ord.itm[i].item) - 1] = 0;
                printf("Enter the quantity of the item:\t");
                scanf("%d", &ord.itm[i].qty);
                printf("Enter the item price: \t\t");
                scanf("%f", &ord.itm[i].price);
                Total += ord.itm[i].qty * ord.itm[i].price;
            }

            printf("\n\n");
            GenrateBillheader(ord.customer, ord.date, ord.time);
            for (int i = 0; i < ord.noofitems; i++)
            {
                GenrateBillbody(ord.itm[i].item, ord.itm[i].qty, ord.itm[i].price);
            }
            GenrateBillfooter(Total);
            printf("\n\n");
            break;
        case 2:
            printf("\n\t\t Thank You!!");
            exit(0);
            break;
        default:
            printf("Sorry Invalid Option");
        }

        printf("\nDo you want to continue ? ");
        scanf("%s", &chr);
    } while (chr == 'y' || chr == 'Y');

    return 0;
}
