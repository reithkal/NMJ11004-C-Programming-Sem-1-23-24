#include <stdio.h>
#include <string.h>

// declaring array
char item_names[5][30]={"Eraser","Exampad","Puncher","Pen","Testpad"};
int item_codes[5]={01,02,03,04,05};
int item_qty[5]={30,30,30,30,30};
int item_num[5]={1,2,3,4,5};
float item_prices[5]={0.90,4.90,25.60,5.80,6.50};

struct details
{
    char name[50];
    char phone[20];
    char email[30];
    char address[99];
};


// function prototype
void itemdisplay();
void cust();
void staff();

int main()
{
    char main_menu;
    char mode;

	do
	{
		//main menu and asking the user's mode (staff or customer)
		printf("\n\n          \t\t===== Welcome to Dusun Buku Stationary Store Application =====");
		printf("\n\t\t                  ----Main menu----");
		printf("\n\n\tAre you a Customer or Staff? :");
		printf("\n\t('C' if you are a Customer)");
		printf("\n\t('S' if you are a Staff)");

		do{
            printf("\n\tCustomer/Staff: ");
            scanf(" %c", &mode);

                if (mode == 'S' || mode == 's')
                    staff(); 					// go to staff function
                else if (mode== 'C'||mode == 'c')
                    cust();  					// go to customer function
                else
                   printf("\tInvalid user type. Please Re-enter.\n");
		}while(mode!='S'&&mode!='s'&&mode!='c'&&mode!='C');

		printf("\n\tReturn to Main Menu?");
		printf("\n\tPress 1 to return to main menu");
		printf("\n\tPress 0 to terminate the program\n");
        do
        {
            printf("\tReturn: ");
            scanf(" %c", &main_menu);

            if (main_menu != '1' && main_menu != '0')
                printf("\tInvalid! Please re-enter\n");
        } while (main_menu != '1' && main_menu != '0');

	}while (main_menu=='1');

	printf("\n\t\t\t  The Stationary Store Application");
	printf("\n\t\tDeveloped by Group 2 from UR6523002 of UNIMAP\n\n");

	return 0;
}

//function definition
void staff() //staff menu
{
    char s_mode,pin[16];
    int i, proceed, added_qty[5];

    //  staff's verification
    printf("\tPlease Enter Staff PIN:");
    scanf("%s", pin);
    if (strcmp(pin, "1234") == 0) // pin entered is true
    {
        printf("\t[ ACCESS GRANTED - STAFF ]\n\n");
		printf("\n\t\t    ----Welcome, STAFF of Stationary Store!----");
		printf("\n\n\tWhat would you like to do today; ");

		do
		{
			// staff mode to add, delete, display or continue
		    printf("\n\tPress D to Display all available items");
		    printf("\n\tEnter Y to End the staff mode");
			printf("\n\tEnter E to Edit Data");
			do{
                printf("\n\n\tInput Staff mode: ");
                scanf(" %c", &s_mode);

                // edit mode
                if(s_mode == 'E'||s_mode == 'e')
                {
                    printf("\n\t\t\t===You're now in Staff-Edit Mode===");
                    printf("\n\n\tEditing the quantity item list. Please enter the quantity to add\n");
                    for( i=0; i<5; i++) // receive staff edit input
                    {
                        printf("\n\tQuantity of item %d to add:" ,i+1);
                        scanf("%d", &added_qty[i]);
                        item_qty[i]=(item_qty[i]+added_qty[i]);		// calculate new item's quantity after editing
                    }
                }
                // display current items
                else if(s_mode == 'D'||s_mode == 'd')
                    {
                        printf("\n\t\t    ----List of available items----");
                        printf("\n\t-----------------------------------------------------------------------------------");
                        printf("\n\t| No.\tCode\tItem Name\t\t\t\tPrice\t\tQuantity |\n");
                        for ( i = 0; i<5; i++ )
                            printf("\t| %d\t%d\t%s\t\t\t\t\t%.2f\t\t%d       |\n", item_num[i],item_codes[i],item_names[i],item_prices[i],item_qty[i]);
                        printf("\t-----------------------------------------------------------------------------------");
                    }
                else if((s_mode == 'Y'||s_mode == 'y'))
                {
                    do{
                        printf("\tAre you sure? (Press 0 to end or press 1 to keep going):");
                        scanf(" %d", &proceed);

                        if(proceed>1)
                            printf("\tInvalid! Please re enter!\n");

                    }while(proceed>1);

                }
                else
                    printf("\tInvalid input! please re enter");

			}while(s_mode!='D'&&s_mode!='d'&&s_mode!='Y'&&s_mode!='y'&&s_mode!='E'&&s_mode!='e');
		} while ( proceed > 0 );
    }
    else // pin entered is false
        printf("\tEnter valid input PIN\n");
}

void cust()
{
    struct details custinfo;

    char proceed, pay, method[30];
    int selected_item, i;
    float total_price = 0, price;

    // asking customer's information
    printf("\n\n\t\t[ Hello, our customer! ]\n");
    printf("\n\tENTER YOUR INFORMATION BELOW !");
    printf("\n\tName: ");
    scanf(" %[^\n]", custinfo.name);
    printf("\tPhone Number: ");
    scanf(" %[^\n]", custinfo.phone);
    printf("\tEmail: ");
    scanf(" %[^\n]", custinfo.email);
    printf("\tAddress: ");
    scanf(" %[^\n]", custinfo.address);

    // displaying list of available items
    itemdisplay(); // fn call to display items

    int counter = 0;

    // Array to store quantity for each item
    int quantity[5] = {0};

    do
    {
        // asking customer's confirmation of purchase
        do
        {
            printf("\n\tWould you like to purchase any of the items?");
            printf("\n\t'Y' for Yes or 'N' for No: ");
            scanf(" %c", &proceed);

            if (proceed == 'Y' || proceed == 'y') // when customer wants to purchase
            {
                // receiving purchase input from user
                printf("\n\tEnter the number of the item you want to purchase (1-5): ");
                scanf("%d", &selected_item);

                if (selected_item >= 1 && selected_item <= 5)
                {
                    printf("\n\tHow many of item No.%d (%s) do you want to purchase?\n", item_num[selected_item - 1], item_names[selected_item - 1]);
                    printf("\n\t-Quantity: ");
                    scanf("%d", &quantity[selected_item - 1]);

                    if (quantity[selected_item - 1] > 0 && quantity[selected_item - 1] <= item_qty[selected_item - 1])
                    {
                        item_qty[selected_item - 1] -= quantity[selected_item - 1]; // calculating new item quantity after purchase
                        price = item_prices[selected_item - 1] * quantity[selected_item - 1];
                        total_price += price; // calculating the total price
                        printf("\n\tItem %d (%s) added to your cart.\n", item_num[selected_item - 1], item_names[selected_item - 1]);
                    }
                    else
                    {
                        printf("\n\tInvalid quantity. Please enter a valid quantity.\n");
                    }
                }
                else
                {
                    printf("\n\tInvalid item number. Please enter a valid item number.\n");
                }

                counter++;
            }
            else if (proceed == 'N' || proceed == 'n') // when customer doesn't want to purchase
            {
                if (counter < 1)
                    return;
                else
                    printf("\n\tThank you for your order, Mr / Mrs %s!\n", custinfo.name);
            }
            else
            {
                printf("\n\t[ INVALID INPUT ]\n"); // when customer input is false
            }

        } while (proceed != 'N' && proceed != 'n' && proceed != 'y' && proceed != 'Y');

    } while (proceed == 'Y' || proceed == 'y');

    // selecting payment method
    printf("\n\tChoose a Payment Method: ");
    printf("\n\t'C' for Cash on Delivery");
    printf("\n\t'O' for Online Banking");

    while (1) // receiving input for payment method
    {
        printf("\n\tPayment Method: ");
        scanf(" %c", &pay);

        if (pay == 'C' || pay == 'c')
        {
            strcpy(method, "Cash on Delivery (COD)"); // assigning the string "COD" to var method
            break;
        }

        else if (pay == 'O' || pay == 'o')
        {
            strcpy(method, "Online Banking"); // assigning the string "Online banking" to var method
            printf("\t------------------------------\n");
            printf("\tPLEASE BANK IN TO THIS ACCOUNT \n\t02201034578863\n\tBANK ISLAM\n");
            printf("\t------------------------------");
            break;
        }

        else
            printf("\n\t[ INVALID PAYMENT METHOD ]\n");
    }

    // print receipt
    printf("\n\n\t=============================  RECEIPT  =============================="); // print customer's information and purchase
    printf("\n\t\t\t        Stationary Store Application");
    printf("\n\tName: %s", custinfo.name);
    printf("\n\tPhone Number: %s", custinfo.phone);
    printf("\n\tEmail: %s", custinfo.email);
    printf("\n\tAddress: %s", custinfo.address);
    printf("\n\n\tNo.\tCode\tItem Name\tItem Price\tQuantity\n");

    for (i = 0; i < 5; i++)
    {
        if (item_qty[i] < 30)
            printf("\t%d\t%d\t%s\t\t%.2f\t  \t%d\n", item_num[i], item_codes[i], item_names[i], item_prices[i], quantity[i]);
    }

    // print total price and payment method
    printf("\n\t======================================================================");
    printf("\n\n\tTotal Price: %.2f", total_price);
    printf("\n\n\t======================================================================");
    printf("\n\n\t\t\t     Thank you for shopping with us.");
    printf("\n\t\t\t\t   Please come again!\n");
}

void itemdisplay()
{
    int i;
    printf("\n\t\t\t\t    ----List of available items----");
    printf("\n\t-----------------------------------------------------------------------------------");
    printf("\n\t| No.\tCode\tItem Name\t\t\t\tPrice\t\tQuantity |\n");
    for (i = 0; i < 5; i++)
        printf("\t| %d\t%d\t%s\t\t\t\t\t%.2f\t\t%d       |\n", item_num[i], item_codes[i], item_names[i], item_prices[i],item_qty[i]);
    printf("\t-----------------------------------------------------------------------------------");
}



