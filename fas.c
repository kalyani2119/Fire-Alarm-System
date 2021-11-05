#include<reg51.h>
sbit sensor = P1^0;

sbit rs = P1^1;
sbit rw = P1^2;
sbit en = P1^3;

sbit buzzer = P3^0;

void delay(unsigned int count)
{
unsigned int i;
while(count)
{
i=115;
while(i>0);
i--;
count--;
}
}

void lcddata(unsigned char abc)
{
rs = 1;
p2=abc;
en=1;
delay(50);
en=0;
}

void lcd_init()
{
lcd_cmd(0x38);
lcd_cmd(0x01);
lcd_cmd(0x06);
lcd_cmd(0x0E);
lcd_cmd(0x80);
lcd_cmd(0x0c);
}

void lcddis(unsigned char *s)
{
  unsigned char w;
  for(w=0;s[w]!='\0';w++)
  {
    lcddata(s[w]);
  }
}

void main()
{
  sensor = 0;
  buzzer = 0;
  repeat:lcdinit();
  lcddis("FIRE ALARM");
  lcd_cmd(0x0c);
  lcddis("CIRCUIT");
  delay(1000);
  while(1)
  {
    if(sensor==1)
    {
      lcd_cmd(0x01);
      lcddis("FIRE! FIRE! FIRE!");
      buzzer=1;
    }
    goto repeat;
  }
}
  

