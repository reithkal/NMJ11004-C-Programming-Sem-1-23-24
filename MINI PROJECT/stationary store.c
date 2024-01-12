#include <stdio.h>
#include <string.h>
#include <stdbool.h>

// declaring array
char nama_brg[5][30]={"Eraser","Exampad","Puncher","Pen","Testpad"};
int code_brg[5]={01,02,03,04,05};
int qty_brg[5]={30,30,30,30,30};
int no_brg[5]={1,2,3,4,5};
float harga_brg[5]={0.90,4.90,25.60,5.80,6.50};

// function prototype
void itemdisplay();
void cust();
void staff();

int main()
{
    char mode;
	int i, main_menu;

	do
	{
		//main menu and asking the user's mode (staff or customer)
		printf("\n\n          \t===== Welcome to Stationary Store Application =====");
		printf("\n\t\t                  ----Main menu----");
		printf("\n\n\tAre you a Customer or Staff? :");
		printf("\n\t('C' if you are a Customer)");
		printf("\n\t('S' if you are a Staff)");
		printf("\n\tCustomer/Staff: ");
		scanf(" %c", &mode);

			if (mode == 'S' || mode == 's')
 	        	staff(); 					// go to staff function
			else if (mode== 'C'||mode == 'c')
				cust();  					// go to customer function
			else
 	           printf("Invalid user type. Please Re-enter.\n");

		printf("\n\tReturn to Main Menu?");
		printf("\n\tPress 1 to return to main menu");
		printf("\n\tPress 0 to terminate the program\n");
		printf("\tReturn: ");
		scanf(" %d", &main_menu);

	}while ( main_menu > 0 );

	printf("\n\t\t\t  The Stationary Store Application");
	printf("\n\t\tDeveloped by Group 2 from UR6523002 of UNIMAP\n\n");

	return 0;
}

void staff() //staff menu
{
    char pin[5];
    char s_mode;
    int i, proceed, added_qty[5];
    int attempts;

    //  staff's verification
    for (attempts = 0; attempts < 3; attempts++)
    {
        // staff's verification
        printf("\tPlease Enter Staff PIN (Attempt %d):", attempts + 1);
        scanf("%4s", pin);

        if (strcmp(pin, "1234") == 0) // PIN entered is true
        {
            printf("\t[ ACCESS GRANTED - STAFF ]\n\n");
            printf("\n\t\t    ----Welcome, STAFF of Stationary Store!----");
            printf("\n\n\tWhat would you like to do today; ");

            do
            {
                // staff mode to add, delete, display, or continue
                printf("\n\tPress D to Display all available items");
                printf("\n\tEnter Y to End the staff mode");
                printf("\n\tEnter E to Edit Data");
                printf("\n\n\tInput Staff mode: ");
                scanf(" %c", &s_mode);

                // edit mode
                if (s_mode == 'E' || s_mode == 'e')
                {
                    printf("\n\t\t\t===You're now in Staff-Edit Mode===");
                    printf("\n\n\tEditing the quantity item list. Please enter the quantity to add\n");
                    for (i = 0; i < 5; i++) // receive staff edit input
                    {
                        printf("\n\tQuantity of item %d to add:", i + 1);
                        scanf("%d", &added_qty[i]);
                        // Assuming qty_brg is declared and initialized before this point
                        // If not, make sure to declare and initialize it appropriately
                        qty_brg[i] = (qty_brg[i] + added_qty[i]); // calculate new item's quantity after editing
                    }
                }
                // display current items
                else if (s_mode == 'D' || s_mode == 'd')
                {
                    printf("\n\t\t    ----List of available items----");
                    printf("\n\t-----------------------------------------------------------------------------------");
                    printf("\n\t| No.\tCode\tItem Name\t\t\t\tPrice\t\tQuantity |\n");
                    for (i = 0; i < 5; i++)
                        printf("\t| %d\t%d\t%s\t\t\t\t\t%.2f\t\t%d       |\n", no_brg[i], code_brg[i], nama_brg[i], harga_brg[i], qty_brg[i]);
                    printf("\t-----------------------------------------------------------------------------------");
                }
                else
                {
                    printf("Enter 0 to end or 1 to keep going: ");
                    scanf(" %d", &proceed);
                }
            } while (proceed == 1);

            break; // Exit the PIN entry loop if the correct PIN is entered
        }
        else
        {
            if (attempts < 2)
            {
                printf("\tInvalid PIN. Please try again.\n");
            }
            else
            {
                printf("\tInvalid PIN. Exceeded maximum attempts. Returning to main menu.\n");
            }
        }
    }
}

void cust() // customer menu
{
    char name[30], proceed, pay, method[30], address[999];
    int phone_no = 0, selected_item, quantity;
    int i;
    float total_price = 0, price;

    // asking customer's information
    printf("\n\n\t\t[ Hello, our customer! ]\n");
    printf("\n\tENTER YOUR INFORMATION BELOW !");
    printf("\n\tName: ");
    scanf(" %[^\n]", name);
    printf("\tPhone Number: ");
    scanf("%d", &phone_no);
    printf("\tAddress: ");
    scanf(" %[^\n]", address);

    // displaying list of available items
    itemdisplay();//fn call to display items

    do
    {
        // asking customer's confirmation of purchase
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
                printf("\n\tHow many of item No.%d do you want to purchase?\n", no_brg[selected_item - 1]);
                printf("\n\t-Quantity: ");
                scanf("%d", &quantity);

                if (quantity > 0 && quantity <= qty_brg[selected_item - 1])
                {
                    qty_brg[selected_item - 1] -= quantity; // calculating new item quantity after purchase
                    price = harga_brg[selected_item - 1] * quantity;
                    total_price += price; // calculating the total price
                    printf("\n\tItem %d added to your cart.\n", selected_item);
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
        }
        else if (proceed == 'N' || proceed == 'n') // when customer doesn't want to purchase
        {
            printf("\n\tHave a good day, Mr / Mrs!\n");
        }
        else
        {
            printf("\n\t[ INVALID INPUT ]\n"); // when customer input is false
        }

    } while (proceed == 'Y' || proceed == 'y');
		   // selecting payment method
		   printf("\n\tChoose a Payment Method: ");
		   printf("\n\t'C' for Cash on Delivery");
		   printf("\n\t'O' for Online Banking");

			while(1) // receiving input for payment method
			{
				printf("\n\tPayment Method: ");
			    scanf(" %c", &pay);

				if (pay == 'C' || pay == 'c')
				{
					strcpy(method, "Cash on Delivery (COD)"); 	// assigning the string "COD" to var method
					break;
			    }

			    else if (pay == 'O' || pay == 'o')
				{
					strcpy(method, "Online Banking");			// assigning the string "Online banking" to var method
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
    printf("\n\tName: %s", name);
    printf("\n\tPhone Number: %d", phone_no);
    printf("\n\tAddress: %s", address);
    printf("\n\n\tNo.\tCode\tItem Name\tItem Price\tQuantity\n");
    for (i = 0; i < 5; i++)
    {
        if (qty_brg[i] < 30)
        {
            printf("\t%d\t%d\t%s\t\t%.2f\t  \t%d\n", no_brg[i], code_brg[i], nama_brg[i], harga_brg[i], quantity);
        }
    }
    printf("\n\t======================================================================"); // print total price and payment method
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
        printf("\t| %d\t%d\t%s\t\t\t\t\t%.2f\t\t%d       |\n", no_brg[i], code_brg[i], nama_brg[i], harga_brg[i], qty_brg[i]);
    printf("\t-----------------------------------------------------------------------------------");
}



