#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <math.h>

uint64_t next_prime(uint64_t);

int main()
{
  uint64_t luku1,luku2,feed1,feed2,res;
  
  feed1 = 1000000000; //10 digits
  feed2 = 10000000000; //11 digits

  luku1 = next_prime(feed1);
  luku2 = next_prime(feed2);
  res = (luku1) * (luku2) % 1000000000000000ULL;
  printf("10-digit prime:%llu, 11-digit prime:%llu, result:%015llu\n",luku1,luku2,res);

  return 0;
}

uint64_t next_prime(uint64_t feed)
{
  uint64_t i,j,sq;
  int flag;

  for(i = feed+1;i < feed+200;++i) //
  {
    flag = 0;
    sq = sqrt(i);

    for(j=2;j<=sq;j++)
    {
      if(i % j == 0)
      {
        flag = 1;
        break;
      }
    }
    if(flag == 0) return i; //first prime found
  }

  return 0;
}
