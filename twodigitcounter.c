#include<reg51.h>

#define SEGMENT1 P0
#define SEGMENT2 P3
 
sbit UP=P1^0;
sbit DOWN=P1^1;
sbit digit1=P2^0;
sbit digit2=P2^1;

void delay (int);

int x=100,y,z;
unsigned char ch[]={0xc0,0xf9,0xa4,0xb0,0x99,0x92,0x82,0xf8,0x80,0x98};
									//0			1			2		3
void delay (int d)
{
	unsigned char i=0;
	for(;d>0;d--)
	{
		for(i=250;i>0;i--);
		for(i=248;i>0;i--);
	}
}

void main()
{
	UP=1;
	DOWN=1;
	digit1=1;
	digit2=1;

while(1)
{
	if(UP==0)
	{ 
		x++;
		delay(100);
	}
	else if(DOWN==0)
	{
		x--;
		delay(100);
	}
	y=(x/10)%10;
	SEGMENT1=ch[y];
	delay(100);
	z=x%10;
	SEGMENT2=ch[z];
}
}