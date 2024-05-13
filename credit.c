#include <stdlib.h>
#include <stdio.h>

int main(void){

    long long int possibleCard, digit, sum1 = 0, sum2 = 0, check;
    int count = 0;
    int LastAmex = 0, LastMaster = 0;

    printf("Number: ");
    scanf("%lld", &possibleCard);

    //no initaization as iterating over possible card
    for (; possibleCard > 0; possibleCard/=10){
        digit = possibleCard % 10;
        if (count%2!=0){
            check = digit * 2;
            if(check > 9){
                check = check%10;
                sum1 += check+1;
            }
            else
                sum1 += check%10;
        }
        else {
            sum2 += digit;
        }
        if (count == 13)
            LastAmex = digit;

        if (count == 14)
            LastMaster = digit;
        count++;
        check = 0;
    }


    sum1 = sum1 + sum2;


    if (digit == 4 && sum1%10==0 && (count == 13 || count == 16)){
        printf("VISA\n");
        exit(0);
    }

    if (digit == 3 && sum1%10==0 && count == 15 && (LastAmex == 4 || LastAmex == 7)){
        printf("AMEX\n");
        exit(0);
    }

    if (digit == 5 && sum1%10==0 && count == 16 && (LastMaster < 6)){
        printf("MASTERCARD\n");
        exit(0);
    }

    printf("INVALID\n");
    return 0;
}