
#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <math.h>
int main ()
{    

  double girilen=0;
  int virgulSol;
  double virgulSag;
  
  int signBit=0;
  
  
  printf ("Sayiyi giriniz:");
  scanf ("%lf", &girilen);
  
       if(girilen<0) {signBit=1; }
  
     girilen = fabs(girilen);
  
     virgulSol = (int)girilen;

  printf ("\nTam kisim :%i\n", virgulSol);

     virgulSag = girilen - virgulSol;

  printf ("Virgulden sonraki kisim :%f \n", virgulSag);

   
 
  //HESAP 1 - VIRGUL SOL BINARY ISLEMI


     int bolumSonuc, kalan;
     int ikilikSayi[100];
     int diziIndex = 1;

     bolumSonuc = virgulSol;

         while (bolumSonuc != 0){
    
               ikilikSayi[diziIndex++] = bolumSonuc % 2;
               bolumSonuc = bolumSonuc / 2;
         }

   printf ("->> Tam kismin( %d ) Binary işlemi = ", virgulSol);

         for (int j = diziIndex - 1; j > 0; j--){
      
             printf ("%d", ikilikSayi[j]);
         }

   printf("\n");

    //HESAP 2 - VIRGUL SAG BINARY ISLEMI

    double carpimSonuc;
    int sayacBir=0;
    int kalanlarDizi[100];
    
    carpimSonuc=virgulSag*2;
 
   for (int a=0; a<24; a++){
       sayacBir++;
       
      
       if(carpimSonuc==1){
           
           kalanlarDizi[a]=1;
           break;
       }
       
       else if(carpimSonuc<1){
           
           kalanlarDizi[a]=0;
           carpimSonuc=carpimSonuc*2;
           continue;
       }
       
       else if(carpimSonuc>1){
           
           carpimSonuc = carpimSonuc-1;
           carpimSonuc=carpimSonuc*2;
           kalanlarDizi[a]=1;
           continue;
       }
      
     }   
      
    printf("->> Virgulden sonraki kisim ( %f ) Binary işlemi = ",virgulSag); 
             
        for(int m=0; m<sayacBir;m++){
           printf("%d",kalanlarDizi[m]);
        }
      
    
     //HESAP 3 - VIRGUL KAYDIRMA 
     
        int kaydirDefa;
        int inceHesapSayac=0;
        kaydirDefa = diziIndex-2;
        
        
        if(0<girilen && girilen <1){ //sayi 0 ile 1 arasıysa exponent olayı değişir
            printf("\n sayiniz 0 ile 1 arasında \n");
            
            for(int b=0;b<100;b++){
                
                inceHesapSayac++;
                if(kalanlarDizi[b]==1){break;}
            }
            kaydirDefa= inceHesapSayac * -1; 
          
        }
        
         
        
    printf("\n kac kere virgul kaydi= %d \n",kaydirDefa);
    printf(" \n -------IEE754 FORMAT------- \n");
    printf(" Sign = %d \n", signBit);
        
     //HESAP 4 - EXPONENT
     
          int exponentOnlu;
          exponentOnlu = kaydirDefa + 127;
        
          int bolumSonuc2;
          int exponentBin[100];
          int diziIndex2 = 1;
          bolumSonuc2 = exponentOnlu;

 
          while (bolumSonuc2 != 0){
    
             exponentBin[diziIndex2++] = bolumSonuc2 % 2;
             bolumSonuc2 = bolumSonuc2 / 2;
          }
  
  
      //EXPONENT YAZDIRMA
  
  
    printf(" Exponent  = ");
    
        int sayacExponent=0;
        
        if(0<girilen && girilen <1){
          
          for (int j = diziIndex2 - 1; j > 0; j--){
              sayacExponent++;
          }
         
          for(int a=0; a<diziIndex2-sayacExponent;a++){
             printf("0");
         }
         
          for (int j = diziIndex2 - 1; j > 0; j--){
                                                    
              printf ("%d", exponentBin[j]);
              
          }
   
         
        }
        
         else if(girilen==0){
              
              for(int y=0; y<8; y++){
                printf("0"); 
                  
              }
          }
        
 
         else{
             
             if(1<= girilen && girilen <2){ printf("0"); }
          
             for (int j = diziIndex2 - 1; j > 0; j--){
                                                    
              printf ("%d", exponentBin[j]);
              
          }
        } 
      
    printf("\n Mantissa = ");
        
       
        //HESAP 5 - MANTISSA 
       
            int sayacMantissa=0;  
           
            
            
            if(0<girilen && girilen <1){
                
                 for(int m=kaydirDefa*(-1); m<sayacBir;m++){
              
                printf("%d",kalanlarDizi[m]);
               
                 sayacMantissa++;
             
                if(sayacMantissa==23){break;}
             
                  }
            
                 if(sayacMantissa<24){
                
                    for(int i=0; i < (23-sayacMantissa); i++){
                    
                    printf("0");
                    }               
                }
                
                
            }//if
            
            
            else{
           
             //5.1 TAM SAYI BINARY YAZDIRMA
            for(int m = diziIndex - 2; m > 0; m--){
                 
                  printf("%d",ikilikSayi[m]);
                  sayacMantissa++;
                  
            }
            
            
            //5.2 VİRGULDEN SONRASI BINARY YAZDIRMA
          
            for(int m=0; m<sayacBir;m++){
              
              printf("%d",kalanlarDizi[m]);
               
               sayacMantissa++;
            
                if(sayacMantissa==23){break;}
            
            }
           
            if(sayacMantissa<23){
                
                for(int i=0; i < (23-sayacMantissa); i++){
                    
                    printf("0");
                }               
            }

           
            } //else
  
  
  
  return 0;
}