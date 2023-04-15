// Alexander PUKALL PRNG 64 
// LSFR 64 + LCG 64
// 128 bits seed
// prng64.c

// The output will be 2^64 random bits

// With lfsr seed = 0xffffffffffffffff
// and lcg seed = 0xffffffffffffffff
// the 50 first bytes are
// 83 CA C9 DF F3 82 B1 EB 1D 2D A2 6A 08 A4 7C 58 99 EB 8A 4F
// 99 B0 43 01 66 66 49 EC 77 C2 6E 91 6E E0 28 58 DD EF 5D 9D
// BE F4 DF 57 1D 27 CA B4 2B 16 

// Practrand test : ./prng64 | /rng_test stdin8
// All tests OK (no anomalies), test with 2TB

// CODE FREE TO USE EVEN FOR COMMERCIAL APPLICATIONS
// NO RESTRICTION

// Compiled on Raspberry pi with
// gcc prng64.c -o prng64

#include <stdint.h>
#include <stdio.h>

int main()
{
    uint64_t lfsr = 0xffffffffffffffffu; //LFSR 64 seed from 0x1 to 0xffffffffffffffff
    uint64_t b=0xffffffffffffffffu; //LCG 64 seed from 0x0 to 0xffffffffffffffff
    uint8_t rndbyte,tmp,shift;
    int i,q,w;
  
  if (lfsr==0) lfsr=1; // never 0 in an LFSR
  
   
for (i=0;i<64;i++) // mix LFSR 64 times before use
  {

  rndbyte=0;
      for (q=0;q<8;q++)
      {
   
        uint64_t msb= lfsr & 0x8000000000000000;
                
        lfsr <<= 1;                          

       if (msb==0x8000000000000000)  lfsr ^= 0x7287db1e3afac4f1u;
                       
          
      }
}
    

 while(1)
 
  {
    b=(b*0x5851f42d4c957f2d)+1;
        
    for (w=0;w<4;w++)
    {

     rndbyte=0;
      for (q=0;q<8;q++)
      {
  
        uint64_t msb= lfsr & 0x8000000000000000;
                
        lfsr <<= 1;                          


       if (msb==0x8000000000000000) 
       
       {
        
         lfsr ^= 0x7287db1e3afac4f1u;
         tmp=1;
            
        }
        else
          {
            tmp=0;
            
          }
         
  rndbyte=rndbyte+(tmp<<q);

      }
           
      shift=48-(8*w);  
      rndbyte=rndbyte+((b>>shift)& 0xff);
  
      printf("%c",rndbyte);
    
}
    


 
}

return(0);


}
