#include<stdio.h>
#include<conio.h>
#include<math.h>

int main()
{
    int n, c;

    printf("Enter no. of objects and maximum capacity : \n");
    scanf("%d%d", &n, &c);

    /* n+1 because we are using indexes 1 to n */
    int p[n+1], w[n+1], obj[n+1];
    int j, i, rc = c, wu;
    
    float r[n+1], temp, pe = 0, s[n+1];

    /* Initialize solution array */
    for(i = 1; i <= n; i++)
    {
        s[i] = 0;
    }

    /* Input */
    for(i = 1; i <= n; i++)
    {
        printf("Enter profit and weight of object %d: \n", i);
        scanf("%d%d", &p[i], &w[i]);

        r[i] = (float)p[i] / w[i];
        obj[i] = i;
    }

    /* Sort according to profit/weight ratio */
    for(i = 1; i <= n-1; i++)
    {
        for(j = 1; j <= n-1; j++)
        {
            if(r[j] < r[j+1])
            {
                /* Swap ratio */
                temp = r[j];
                r[j] = r[j+1];
                r[j+1] = temp;

                /* Swap profit */
                temp = p[j];
                p[j] = p[j+1];
                p[j+1] = temp;

                /* Swap weight */
                temp = w[j];
                w[j] = w[j+1];
                w[j+1] = temp;

                /* Swap object number */
                temp = obj[j];
                obj[j] = obj[j+1];
                obj[j+1] = temp;
            }
        }
    }

    /* Display sorted objects */
    printf("\nObject\tProfit\tWeight\tPbyW\n");

    for(i = 1; i <= n; i++)
    {
        printf("%d\t%d\t%d\t%f\n",
               obj[i], p[i], w[i], r[i]);
    }

    /* Calculate maximum profit */
    printf("\nObject\tWeight\tWeight Used\tRemaining Capacity\tProfit Earned\n");

    for(i = 1; i <= n; i++)
    {
        if(rc > w[i])
        {
            wu = w[i];
        }
        else
        {
            wu = rc;
        }

        rc = rc - wu;

        pe = pe + r[i] * (float)wu;

        printf("%d\t%d\t%d\t\t%d\t\t%f\n",
               obj[i], w[i], wu, rc, pe);

        /* If capacity is full */
        if(rc == 0)
        {
            s[obj[i]] = (float)wu / w[i];
            break;
        }

        /* Full object */
        if(wu == w[i])
        {
            s[obj[i]] = 1;
        }
        /* Fraction of object */
        else
        {
            s[obj[i]] = (float)wu / w[i];
        }
    }

    /* Display solution */
    printf("\nSolution = {");

    for(i = 1; i <= n; i++)
    {
        printf("%f", s[i]);

        if(i != n)
        {
            printf(", ");
        }
    }

    printf("}");

    printf("\nProfit earned = %f\n", pe);

	getch();

	return 0;
}
