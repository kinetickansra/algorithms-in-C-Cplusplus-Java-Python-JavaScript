#include <stdio.h>
#define MAX_ITEMS 10
double balanceUp (double balance, double amount)
{
	double at;
	if (amount >= 0)
	{
		at = balance + amount;
		return at;
		
	}
	else
	{
		printf("Error");
return 0;
	}
}
double balanceDown(double balance, double amount)
{
	double at;
	if (amount >= 0)
	{
		at = balance - amount;
		return at;

	}
	else
	{
		printf("Error");
		return 0;
	}
}
double interestCalc(double balance, double rate)
{
	double in;
	in = balance * (rate / 100);
//	printf("%f\n", in);
	return in;
}
int main()
{
	struct Account {
		int acc;
		double bala;
	};
	struct Account acct[MAX_ITEMS];
	acct[0].acc = 11111111;
	acct[1].acc = 22222222;
	acct[2].acc = 33333333;
	acct[3].acc = 44444444;
	acct[4].acc = 55555555;
	acct[0].bala = 123.45;
	acct[1].bala = 12365.50;
	acct[2].bala = 0;
	acct[3].bala = 1475;
	acct[4].bala = 25000.65;
	float a;
	double b;
	float c;
	float d;
	float e;
	double f;
	int choice, acc;
	int l = 1;
	int i;
	printf("***** Welcome to Savings Account Banking *****\n\n");
	while (l) {
		do {
			printf("1.) Deposit \n");
			printf("2.) Withdraw\n");
			printf("3.) Apply monthly interest earnings to all accounts\n");
			printf("4.) Apply service charges to all accounts\n");
			printf("5.) Account Summary\n");
			printf("0.) Log out\n\n");
			printf("Please enter an option to continue: ");
			scanf("%d", &choice);
			if (choice < 0 || choice > 5)
			{
				printf("Invalid input, try again: Please select from the following options:\n");
			}
		} while (choice < 0 || choice > 5);
		if (choice == 0)
		{
			l = 0;
		}
		if (choice == 1)
		{
			printf("\n-- Make a deposit --\n\n");
			printf("Enter account number: ");
			scanf("%d", &acc);
			for (i = 0; i < 5; i++)
			{

				if (acc != acct[i].acc && i == 4)
					printf("ERROR: Account number does not exist.\n\n");
				if (acc == acct[i].acc)
				{
					printf("Enter amount to deposit (CAD): ");
					scanf("%f", &a);
					b = balanceUp(acct[i].bala, a);
					printf("Current balance is : %.2f\n", b);
					acct[i].bala = b;
					break;
				}
			}
			printf("\n");
			}
				if (choice == 2)
				{
					printf("\n-- Withdraw funds --\n\n");
					printf("Enter account number: ");
					scanf("%d", &acc);
					for (i = 0; i < 5; i++)
					{

						if (acc != acct[i].acc && i == 4)
							printf("ERROR: Account number does not exist.\n");
						if (acc == acct[i].acc)
						{
							printf("Enter amount to withdraw (CAD): ");
							scanf("%f", &e);
							if (e > acct[i].bala)
								printf("Withdrawal failed. You only have : %.2f in your account\n",acct[i].bala);
							else {
								f = balanceDown(acct[i].bala, e);
								printf("Current balance is : %.2f\n", f);
								acct[i].bala = f;
							}
							break;
						}

					}
					printf("\n");
				}
				if (choice == 3)
				{
					printf("\n-- Add monthly interest earnings to all accounts --\n\n");
					printf("Account# New Balance Interest Earnings (M)\n");
					printf("-------- ----------- ---------------------\n");
					for (i = 0; i < 5; i++)
					{
						if (acct[i].bala <= 500)
						{
							c = interestCalc(acct[i].bala, 0.99);

							d = balanceUp(acct[i].bala, c);
							acct[i].bala = d;
							printf("%8d %11.2lf %21.2lf\n", acct[i].acc, d, c);
						}
						else if (acct[i].bala > 500 && acct[i].bala <= 1500)
						{
							c = interestCalc(acct[i].bala, 1.66);

							d = balanceUp(acct[i].bala, c);
							acct[i].bala = d;
							printf("%8d %11.2lf %21.2lf\n", acct[i].acc, d, c);
						}
						else if (acct[i].bala > 1500)
						{
							c = interestCalc(acct[i].bala, 2.49);
							d = balanceUp(acct[i].bala, c);
							acct[i].bala = d;
							printf("%8d %11.2lf %21.2lf\n", acct[i].acc, d, c);
						}
					}
					printf("\n");
				}

				if (choice == 4)
				{
					printf("\n-- Apply service charges to all accounts --\n\n");
					printf("Account# New Balance Service charges (M)\n");
					printf("-------- ----------- -------------------\n");					
for (i = 0; i < 5; i++)
					{
						if (acct[i].bala <= 1500)
						{
							d = balanceDown(acct[i].bala, 7.50);
							acct[i].bala = d;
							printf("%8d %11.2lf %19.2lf\n", acct[i].acc, d, 7.50);
						}
						else if (acct[i].bala > 1500)
						{

							d = balanceDown(acct[i].bala, 2.50);
							acct[i].bala = d;
							printf("%8d %11.2lf %19.2lf\n", acct[i].acc, d, 2.50);
						}

					}
					printf("\n");
				}


				if (choice == 5)
				{
					printf("\n-- Account information --\n");
					printf("\nAccount# Balance   \n");
					printf("-------- ----------\n");
					for (i = 0; i < 5; i++)
					{
						printf("%8d %10.2lf\n", acct[i].acc, acct[i].bala);

					}
					printf("\n");
				}
			}
		
			return 0;
		}
