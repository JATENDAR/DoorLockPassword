#include<reg51.h>
#include"lcd8.h"
#include"keypad.h"

sbit motor=P3^0;

sbit lamp=P3^1;

void main()
{
	
	unsigned char i,read_pwd[5],count1,count2,j=0,k=0;
	unsigned char load1[5]="45678",load2[5]="56789";
	motor=0;lamp=0;
	init_lcd();
	str_lcd("pwd ckt breaker");
	delay_ms(5000);
	while(1)
	{
		cmd_lcd(0x80);
	str_lcd("enter password    ");
		cmd_lcd(0xc0);
	str_lcd("             ");
		count1=count2=0;
		cmd_lcd(0xc0);
		for(i=0;i<5;i++)
		{
			read_pwd[i]=0x30+keyscan();
			disp_lcd('*');
			//delay_ms(10);
		}	
		//str_lcd(read_pwd);
		for(i=0;i<5;i++)
		{
			if(read_pwd[i]==load1[i])
			count1++;
			if(read_pwd[i]==load2[i])
			count2++;
		}
		cmd_lcd(0x80);
		
		if(count1==5)
		{
			j++;
			if(j%2==0)
			str_lcd("Load1 ckt opened");
			else
			str_lcd("Load1 ckt closed");	
			motor=~motor;	
		}
		else if(count2==5)
		{
			k++;
			if(k%2==0)
			str_lcd("Load2 ckt opened");
			else
			str_lcd("Load2 ckt closed");	
			lamp=~lamp;
		}
		else
		{
			str_lcd("pwd is wrong  ");
		}
		delay_ms(5000);
			
	}
}