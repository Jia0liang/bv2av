/*������ο�mcfx��Python�����㷨��д���ɣ�ͬ����WTFPL��Դ*/
#include<stdio.h>
#include<string.h>
/*�����õ��ĺ������Զ��壩*/
long long findec(char x);
long long pow_kano(long long x,long long y);
long long dec(char x[]);
char* enc(long long x);
/*Ԥ��ȫ�ֱ���*/
char enc_result[12];
long long xor=177451812,add=8728348608;
/*���Һ��base58�ַ���*/
char table[]="fZodR9XQDSUm21yCkr6zBqiveYah8bt4xsWpHnJE7jL5VG3guMTKNPAwcF";
/*��Ҫ��/���ܵ�av��λ�ã�����BV�й̶�ֵ"BV1##4#1#7##"(#��ʾ��Ҫ�㷨��ԭ���ַ�)
����ֻ��Ҫ���#����λ�õ��ַ�����*/
long long s[]={11,10,3,8,4,6};
int main(){
        printf("%lld\n",dec("BV17x411w7KC"));
        printf("%lld\n",dec("BV1Q541167Qg"));
        printf("%lld\n",dec("BV1mK4y1C7Bz"));
        printf("%s\n",enc(170001));
        printf("%s\n",enc(455017605));
        printf("%s\n",enc(882584971));
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
/*ƥ���ֵ����ַ���Ӧ����ֵ*/
long long findec(char x){
    int i;
    for(i=0;i<strlen(table);i++)
    if(table[i]==x)
        break;
    return i;
}
//��дϵͳ����(�Դ���pow����ǿת�ᶪ����)
long long pow_kano(long long x,long long y){
    if(y==0)return 1;
    return x*pow_kano(x,y-1);
}
