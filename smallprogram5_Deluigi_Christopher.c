//Christopher Deluigi
//Dr. Steinberg
//COP3223C Section 1
//Small Program 5
#include<stdio.h>

//declares the user defined functions, with paramaters
void change(double *paid, double *due); 
void resterauntReceipt();
void gradeDistribution();
void incrementUpdate(int *val);

int main()
{   
    //Problem 1
    double paid; //declares and passes variable 
    double due; 

    printf("Amount Due: "); //takes in user input for amount due
    scanf("%lf", &due); 

    printf("Amount Paid: ");//takes in user input for amount paid
    scanf("%lf", &paid);

    change(&paid, &due);  //calls user defined function
    //////////////////// 
    //Problem 2
    resterauntReceipt();//calls user defined function
    ////////////////
    //Problem 3
    gradeDistribution();//calls user defined function
    ////////////////
    //Problem 4
    int update_val = 0; //creates new variables, set it to 0;

    int *val = &update_val; //declares new variables from paramaters and passes it

    printf("Before calling incrementUpdate\n"); //sets up welcome statement
    printf("val = %d\n", *val); //prints the value before the function is called and remains at 0
    printf("Updating val now...\n");

    incrementUpdate(val); //calls the function

    printf("After calling incrementUpdate\n"); //prints exit statement
    printf("val = %d",*val); //prints updated value after calling function
    ////////////////
    return 0;
}

void change(double *paid, double *due)
{
    int pennies; //sets a variable for each denomination, starting it at 0
    int nickels;
    int dimes;
    int quarters;
    int dollars;

    pennies = 0;
    nickels = 0;
    dimes = 0;
    quarters = 0;
    dollars = 0;

    double change_back = (*paid - *due); //delcares what change is made from^ user input subtracted
    
    while(change_back !=0) //makes loop to run until change is == 0
    {
        if(change_back >= 1.0) //checks to see if change is at least a $1 if so 1 dollar is counted and saved for every dollar able to fit into the change
        {
           dollars++;
           change_back = change_back - 1.0;
        }

        else if(change_back >= 0.25) //checks to see if change is at least a $0.25 if so 1 quarter is counted and saved for every quarter able to fit into the change
        {
           quarters++;
           change_back = change_back - 0.25;
        }

        else if(change_back >= 0.10) //checks to see if change is at least a $0.10 if so 1 dime is counted and saved for every dime able to fit into the change
        {
           dimes++;
           change_back = change_back - 0.10;
        }

        else if(change_back >= 0.05) //checks to see if change is at least a $0.05 if so 1 nickel is counted and saved for every nickel able to fit into the change
        {
           nickels++;
           change_back = change_back - 0.05;
        }
         
        else if(change_back > 0) //checks to see if change is at least a $0.01 if so 1 penny is counted and saved for every penny able to fit into the change
        {
           pennies = change_back * 100;
           pennies = pennies / 1;
           break; 
        }
      }
   printf("Change\n"); //sets up print statement to preview how much change the user receives back 
   printf("%d dollars\n", dollars);
   printf("%d quarters\n", quarters);
   printf("%d dimes\n", dimes);
   printf("%d nickels\n", nickels);
   printf("%d pennies\n", pennies);
}

void resterauntReceipt()
{
   printf("Welcome to Bob's Burgers! Our burger of the day is Say Cheese Burger!\n"); //sets up welcome statement
   printf("Please enter your order by selecting the option number. Otherwise type 0 and your order receipt will be printed.\n");
   int user_option; //new variable  created for user input, set to 100 so user is already in the loop
   user_option = 100;

   double total = 0; // variable created for orders total for the receipt

   double regular = 0; //delcares how much each food item cost and sets it to 0
   double special = 0;
   double cheese = 0;
   double fries = 0;
   double salad = 0;
   double soft_drink = 0;

   while(user_option != 0) //created loop to run until user input is ==0, once entered user will exit the loop
   {
      printf("-----------------------\n"); //sets up repeat for menu
      printf("1: Regular\t$5.00\n");
      printf("2: Special\t$5.95\n");
      printf("3: Cheese\t$5.50\n");
      printf("4: Fries\t$2.00\n");
      printf("5: Salad\t$2.50\n");
      printf("6: Soft Drink\t$2.00\n");
      printf("-----------------------\n");
      printf("What will you add to your order: "); //asks user what item they would like to add, once user reponse is collected, option is saved
      scanf("%d", &user_option); 

      if (user_option == 1) //sets up options for user to collect, with each item being saved for how many times they select it
      {
         printf("Adding regular to your order.\n");
         printf("Please enter your order by selecting the option number. Otherwise type 0 and your order receipt will be printed.\n");
         regular++;
      }

      if (user_option == 2) //sets up options for user to collect, with each item being saved for how many times they select it
      {
         printf("Adding special to your order.\n");
         printf("Please enter your order by selecting the option number. Otherwise type 0 and your order receipt will be printed.\n");
         special++;
      }
         
      if (user_option == 3) //sets up options for user to collect, with each item being saved for how many times they select it
      {
         printf("Adding cheese to your order.\n");
         printf("Please enter your order by selecting the option number. Otherwise type 0 and your order receipt will be printed.\n");
         cheese++;
      }

      if (user_option == 4) //sets up options for user to collect, with each item being saved for how many times they select it
      {
         printf("Adding fries to your order.\n");
         printf("Please enter your order by selecting the option number. Otherwise type 0 and your order receipt will be printed.\n");
         fries++;
      }
      
      if (user_option == 5) //sets up options for user to collect, with each item being saved for how many times they select it
      {
         printf("Adding salad to your order.\n");
         printf("Please enter your order by selecting the option number. Otherwise type 0 and your order receipt will be printed.\n");
         salad++;
      }

      if (user_option == 6) //sets up options for user to collect, with each item being saved for how many times they select it
      {
         printf("Adding soft drink to your order.\n");
         printf("Please enter your order by selecting the option number. Otherwise type 0 and your order receipt will be printed.\n");
         soft_drink++;
      }

      if (user_option == 0) //if user is finished and they enter 0 file gets created
      {
         printf("Order is now placed. Printing receipt.\n");
         total = (regular * 5.00) + (special * 5.95) + (fries * 2.00) + (salad * 2.50) + (soft_drink * 2.00) + (cheese * 5.50); //total is calculated by add up the value of everything ordered
         FILE *receipt;
         receipt = fopen("myreceipt.txt", "w"); //creates and open file
         fprintf(receipt, "Bob's Burgers Restaurant Receipt Order\n"); //sets title
         fprintf(receipt, "-----------------------\n"); //prints how many of the following items they have ordered
         fprintf(receipt, "%1.lf Regular(s)\n", regular);
         fprintf(receipt, "%1.lf Special(s)\n", special);
         fprintf(receipt, "%1.lf Cheese(s)\n", cheese);
         fprintf(receipt, "%1.lf Fries\n", fries);
         fprintf(receipt, "%1.lf Salad(s)\n", salad);
         fprintf(receipt, "%1.lf Soft Drink(s)\n", soft_drink);
         fprintf(receipt, "-----------------------\n");

         fprintf(receipt, "Total: $%.2lf\n",total); //prints the total of the order and exit statement at bottom of receipt.
         fprintf(receipt, "Thank you and come again!\n");
         fclose(receipt); //closes the receipt
      }
   }
}

void gradeDistribution()
{
   FILE *grade_check; //opens file to read
   grade_check = fopen("grades.txt", "r");

   // creates variable for each letter grades and sets them to 0
   int A = 0;
   int B = 0;
   int C = 0;
   int D = 0;
   int F = 0;

   char letter_grade; // will hold the character that is scanned from the file.

   while(fscanf(grade_check, " %c", &letter_grade) != -1) // loop set up to run unitl entire file is checked and scanned. 
   {
      switch(letter_grade)  //After scanning it it will assign each letter grade +1 for every for every time that letter appears saving it to the correct letter variable above 
      {
         case('A'): //uses switch to check for each "condition" (letter) and if one matches then +1 gets added to the letter grades variable
         ++A;
         break;
         case('B'):
         ++B;
         break;
         case('C'):
         ++C;
         break;
         case('D'):
         ++D;
         break;
         case('F'):
         ++F;
         break;
      }
   }

   printf("Here is the grade distribution.\n"); //prints distribution for the amount of grades received by letter
   printf("A: %d\n",A);
   printf("B: %d\n",B);
   printf("C: %d\n",C);
   printf("D: %d\n",D);
   printf("F: %d\n",F);

   fclose(grade_check); //closes file
}

void incrementUpdate(int *val)
{
   int user_input = 0; //creates variables called user input to collect and save user input. set to 0 to start
   *val = *val +1;

   while(user_input == 0) //loops runs as long as the user input does not equal 0. as long as 0 is not inputed loop repeats
   {
      printf("Would you like to update ...\n"); //asks user update statement, repeats until 0 is entered
      printf("Enter 0 if you would like to update again. Anything else will exit the update.\n");
      printf("Option: ");
      scanf("%d", &user_input); // takes in user input and saves it to user_input

      if( user_input == 0) //checks to see if user_input is == 0, if user typed it in then update statement is made, and *val is updated by 1
      {
         printf("Updating val now...\n");
         *val = *val +1;
      }
      else
      printf("val is now done updating...\n"); //if user input doesnt equal 0 then update statement prints and then loop repeats
   }
}