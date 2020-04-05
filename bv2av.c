/*本代码参考mcfx的Python代码算法改写而成，同样以WTFPL开源*/
#include<stdio.h>
#include<string.h>
/*所有用到的函数（自定义）*/
long long findec(char x);
long long pow_kano(long long x,long long y);
long long dec(char x[]);
char* enc(long long x);
/*预设全局变量*/
char enc_result[13];
long long xor=177451812,add=8728348608;
/*打乱后的base58字符表*/
char table[]="fZodR9XQDSUm21yCkr6zBqiveYah8bt4xsWpHnJE7jL5VG3guMTKNPAwcF";
/*需要加/解密的av号位置，由于BV有固定值"BV1##4#1#7##"(#表示需要算法还原的字符)
所以只需要算出#所在位置的字符即可*/
long long s[]={11,10,3,8,4,6};
int main(){
    int opt,av;
    char bv[13];
    printf("Please select a number to continue convert (1:BV2AV 2:AV2BV):");
    scanf("%d",&opt);
    switch(opt){
    case 1:
        printf("Please input a BV number:");scanf("%s",bv);printf("AV%d",dec(bv));break;
    case 2:
        printf("Please input a AV number(integer,not include \"AV\"):");scanf("%d",&av);printf("%s",enc(av));break;
    default:
        main();
    }
    return 0;
}
char* enc(long long x){
    int i,j;
    strcpy(enc_result,"BV1##4#1#7##");
    char *point=enc_result;
    x=(x^xor)+add;
    for(i=0;i<6;i++)
            enc_result[s[i]]=table[x/pow_kano(58,i)%58];
    return point;
}
long long dec(char x[]){
     long long r=0;
     int i;
     for(i=0;i<6;i++){
        r+=findec(x[s[i]])*pow_kano(58,i);
     }
     return ((r-add)^xor);
}
/*匹配字典内字符对应的数值*/
long long findec(char x){
    int i;
    for(i=0;i<strlen(table);i++)
    if(table[i]==x)
        break;
    return i;
}
//重写系统函数(自带的pow函数强转会丢精度)
long long pow_kano(long long x,long long y){
    if(y==0)return 1;
    return x*pow_kano(x,y-1);
}
