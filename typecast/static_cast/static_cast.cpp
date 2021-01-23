#include <iostream>

int main(){
    double dou = 10.1234;

    printf("%d\n", (int)dou);
    
    int integer_1 = dou;    //묵시적 형변환
    int integer_2 = (int)dou;   //명시적 형변환
    int integer_3 = static_cast<int>(dou); //static_cast 형변환
    printf("%d\n%d\n%d\n", integer_1, integer_2, integer_3);

    return 0;
}