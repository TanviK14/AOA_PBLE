#include<stdio.h>
#include<conio.h>
#include<math.h>

int n, c;
int p[101], w[101], obj[101];
int ogP[101], ogW[101];
int rc, wu;
float r[101], s[101], pe;

void enterPackages()
{
    int i;

    printf("\nEnter no. of packages and maximum capacity : ");
    scanf("%d%d", &n, &c);

    for(i = 1; i <= n; i++)
    {
        printf("Enter profit and weight of package %d: ", i);
        scanf("%d%d", &p[i], &w[i]);

        ogP[i] = p[i];
        ogW[i] = w[i];

        obj[i] = i;
        r[i] = (float)p[i] / w[i];
        s[i] = 0;
    }

    printf("\nPackage details entered successfully.\n");
}

void displayPackages()
{
    int i;

    printf("\nPackage\tProfit\tWeight\tValue/Weight\n");

    for(i = 1; i <= n; i++)
    {
        printf("%d\t%d\t%d\t%.2f\n",obj[i], p[i], w[i], r[i]);
    }
}

void calculateRatio()
{
    int i;

    for(i = 1; i <= n; i++)
    {
        r[i] = (float)p[i] / w[i];
    }

    printf("\nValue/Weight ratios calculated successfully.\n");

    printf("\nPackage\tProfit\tWeight\tValue/Weight\n");

    for(i = 1; i <= n; i++)
    {
        printf("%d\t%d\t%d\t%.2f\n",obj[i], p[i], w[i], r[i]);
    }
}

void sortPackages()
{
    int i, j;
    int tempInt;
    float tempFloat;

    for(i = 1; i <= n - 1; i++)
    {
        for(j = 1; j <= n - i; j++)
        {
            if(r[j] < r[j + 1])
            {
                tempFloat = r[j];
                r[j] = r[j + 1];
                r[j + 1] = tempFloat;

                tempInt = p[j];
                p[j] = p[j + 1];
                p[j + 1] = tempInt;

                tempInt = w[j];
                w[j] = w[j + 1];
                w[j + 1] = tempInt;

                tempInt = obj[j];
                obj[j] = obj[j + 1];
                obj[j + 1] = tempInt;
            }
        }
    }

    printf("\nPackages sorted in decreasing order of Value/Weight ratio.\n");

    printf("\nPackage\tProfit\tWeight\tValue/Weight\n");

    for(i = 1; i <= n; i++)
    {
        printf("%d\t%d\t%d\t%.2f\n",obj[i], p[i], w[i], r[i]);
    }
}

void findMaximumValue()
{
    int i;
    int totalWeight = 0;

    rc = c;
    pe = 0;

    for(i = 1; i <= n; i++)
    {
        s[i] = 0;
    }

    for(i = 1; i <= n; i++)
    {
        if(rc == 0)
        {
            break;
        }

        if(rc >= w[i])
        {
            wu = w[i];
            s[obj[i]] = 1;
        }
        else
        {
            wu = rc;
            s[obj[i]] = (float)wu / w[i];
        }

        rc = rc - wu;
        totalWeight = totalWeight + wu;
        pe = pe + r[i] * wu;
    }

    printf("\nPackage\tWeight\tWeight Used\tFraction\n");

    for(i = 1; i <= n; i++)
    {
        if(s[obj[i]] > 0)
        {
            printf("%d\t%d\t%d\t\t%.2f\n",obj[i], w[i], (int)(w[i] * s[obj[i]]), s[obj[i]]);
        }
    }

    printf("\nTotal weight used = %d\n", totalWeight);
    printf("Maximum value obtained = %.2f\n", pe);
}

void displaySelectedPackages()
{
    int i;

    printf("\nPackage\tOriginal Weight\tSelected Fraction\tWeight Used\n");

    for(i = 1; i <= n; i++)
    {
        if(s[i] > 0)
        {
            printf("%d\t%d\t\t%.2f\t\t\t%.2f\n",i, originalW[i], s[i],ogW[i] * s[i]);
        }
    }

    printf("\nSolution = {");

    for(i = 1; i <= n; i++)
    {
        printf("%.2f", s[i]);

        if(i != n)
        {
            printf(", ");
        }
    }

    printf("}\n");
    printf("Maximum value obtained = %.2f\n", pe);
}

int main()
{
    int choice;

    do
    {
        printf("\n\n========== FRACTIONAL KNAPSACK ==========\n");
        printf("1. Enter Package Details\n");
        printf("2. Display Package Details\n");
        printf("3. Calculate Value/Weight Ratio\n");
        printf("4. Sort Packages by Ratio\n");
        printf("5. Find Maximum Value\n");
        printf("6. Display Selected Packages\n");
        printf("7. Display Time Complexity\n");
        printf("8. Exit\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice)
        {
            case 1:
                enterPackages();
                break;

            case 2:
                displayPackages();
                break;

            case 3:
                calculateRatio();
                break;

            case 4:
                sortPackages();
                break;

            case 5:
                findMaximumValue();
                break;

            case 6:
                displaySelectedPackages();
                break;

            case 7:
                printf("\nTime Complexity: O(n^2)\n");
                printf("Bubble Sort is used to arrange packages by Value/Weight ratio.\n");
                break;

            case 8:
                printf("\nExiting program...\n");
                break;

            default:
                printf("\nInvalid choice. Please try again.\n");
        }

    }
	while(choice != 8);

    getch();

    return 0;
}
