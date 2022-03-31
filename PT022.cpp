#include <stdio.h> 
#include <stdbool.h> 
  
bool checkYear(int a) 
{ 
    int T; 
    for(int i=0;i<=T;i++){
    scanf("%d",&T); 
    if (a % 4 == 0 && a % 100 != 0 || a  % 400 == 0 ) 
        return true;
        return false;  
   }
}
  
 
int main() 
{ 
    int a; 
    scanf("%d", &a); 
  
    if(checkYear(a) == true){
        printf("leap year"); 
    }else{
        printf("none");
    }
    return 0; 
}
