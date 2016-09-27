#include<stdio.h>

int cwnd = 3, rwnd = 35, sst = 32, cflag = 0, tflag = 0, total = 166, T = 166;

void sender(int cwnd)
{
    do
    {
        if(reciever(cwnd) == 1)         // ACK
        {
            total = total - cwnd;
            printf("Remaining = %d \n",T-(T-total));
            if(tflag == 0)          // threshold frossed
            {
                cwnd = cwnd*2;
                if(total < cwnd)
         {
             printf("\n Last %d bytes sent \n message sent successfully!! \n",total);
             return ;

         }
                if(cwnd > sst)                 // less than threshold
                {
                    tflag = 1;
                    printf("treshold  reached so cwnd/2...");
                    cwnd/=2;
                }
            }
            else
                cwnd = cwnd + 1;


        }
        else if(cflag==1)
            {
                printf("Congestion Started..");
                cwnd = 1;
                tflag=0;

            }
   }while(total > 0);
}

int reciever(int r)
{
    if ( r < rwnd)
    {
         printf("\n%d bytes sent..\n ",r);
         return 1;
    }
    else
        {
            cflag = 1;
            return 0;
        }
}

int main()
{
    sender(cwnd);
    return 0;
}