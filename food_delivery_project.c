// Parth Goswami
// Yashwant Dhakar
// Srishty Singh
// Pranav Tanwar
// Pramit Kumar

#include<stdio.h>
 typedef struct item{
    char name[50];
    float price;
} ITEM;
 
 int main()
 {
     ITEM menu[] = { 
    {"Pizza",250},
     {"Burger",120},
     {"Spring Roll",90},
     {"Mojito",50}
  

 };
 int choice, qty;
 float total = 0;
 char name[50], address[100];
 FILE *fp;
 
 
 
 printf("\n====Online Food Delivery System ====\n");
 menu:
 printf("\nMenu:\n");
 for( int table = 0; table < 4; table++)
 {
     printf("%d. %s - Rs %.2f\n",table+1,menu[table].name,menu[table].price);
 }
 
 printf("5. Finish Order\n");
 
 printf("Enter your Craving: ");
 scanf("%d", &choice);
 if(choice>= 1 && choice <= 4){
     printf("Enter Quantity: ");
     scanf("%d", &qty);
     total = total+menu[choice-1].price*qty;
     goto menu;
 }
 
 else if ( choice == 5) goto bill;
 else{
     printf("Invalid choice! Try Again, \n");
     goto menu;
 }
 bill:
 printf("\n------Bill Summary------\n");
 printf("Total Amount: Rs%.2f\n",total);
 
 float gst = total*0.05;
 float final = total+gst;
 
 printf("(5%%) GST: Rs %.2f\n",gst);
 printf("Final Payment: Rs %.2f\n", final);
 
 printf("Enter your name: ");
 scanf("%s", name);
 printf("Enter your Address: ");
 scanf("%s", address);
 
 fp = fopen("order.txt", "w");
 fprintf(fp, "Customer: %s\nAddress: %s\nFinal Bill: %.2f\n", name, address, final);


 fclose(fp);

 
 printf("\nOrder Confirmed\n");
 printf("Thanks %s your food will be delivered to %s in 15 minutes.\n",name,address);

 
 return 0;
 
 }
 
