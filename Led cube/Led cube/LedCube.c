#ifndef F_CPU
#define F_CPU 16000000UL
#endif


#include <avr/io.h>
#include <util/delay.h>


static int cubeC[5][5];
static int cubeB[5][5];


#define time 70
#define hold_time 100


//matrix
// 
//  A05-B10-B15-D20-D25
//   |   |   |   |   |
//  A04-B09-B14-C19-D24
//   |   |   |   |   |
//  A03-A08-B13-C18-D23
//   |   |   |   |   |
//  A02-A07-B12-C17-D22
//	 |   |   |   |   |
//  C01-A06-B11-D16-D21		


//PORTA = 0b11111111; //9-2 leds
//PORTB = 0b00111111; //15-10 leds
//PORTC = 0b11111000; //19-15,x,1 leds
//PORTD = 0b00111111; //x,16,22,23,24,25,20,21 leds
//PORTB|= 0b11000000; //l5,l4 levels
//PORTC|= 0b00000111; //l3,l2,l1 levels

//LEDS (port's letter + led number)
#define C1 0b00001000
#define A2 0b00000001
#define A3 0b00000010
#define A4 0b00000100
#define A5 0b00001000
#define A6 0b00010000
#define A7 0b00100000
#define A8 0b01000000
#define A9 0b10000000
#define B10 0b00000001
#define B11 0b00000010
#define B12 0b00000100
#define B13 0b00001000
#define B14 0b00010000
#define B15 0b00100000
#define D16 0b11000000
#define C17 0b00100000
#define C18 0b01000000
#define C19 0b10000000
#define D20 0b00000001
#define D21 0b00000010
#define D22 0b00100000
#define D23 0b00010000
#define D24 0b00001000
#define D25 0b00000100

//LEVELS (L + port's letter + level number)
#define LC1 0b00000100
#define LC2 0b00000010
#define LC3 0b00000001
#define LB4 0b10000000
#define LB5 0b01000000


void cube_init()
{
	DDRA=0xFF;
	PORTA=0x00;
	DDRB=0xFF;
	PORTB=0x00;
	DDRC=0xFF;
	PORTC=0x00;
	DDRD=0xFF;
	PORTD=0x00;
}

void cube_refresh()
{
	int i=hold_time;

	while(i>0)
	{	
		i-=1;
		////////////////PORTC is active
		//L1 is active
		PORTC = C1;
		PORTC |= cubeC[0][0];
		PORTB = cubeB[0][0];
		_delay_us(time);
		PORTC=0x00;
		////////////////PORTA is active
		//L2 is active
		PORTA = A2;
		PORTC = cubeC[0][1];
		PORTB = cubeB[0][1];
		_delay_us(time);
		//L3 is active
		PORTA = A3;
		PORTC = cubeC[0][2];
		PORTB = cubeB[0][2];
		_delay_us(time);
		//L4 is active
		PORTA = A4;
		PORTC = cubeC[0][3];
		PORTB = cubeB[0][3];
		_delay_us(time);
		//L5 is active
		PORTA = A5;
		PORTC = cubeC[0][4];
		PORTB = cubeB[0][4];
		_delay_us(time);
		//L6 is active
		PORTA = A6;
		PORTC = cubeC[1][0];
		PORTB = cubeB[1][0];
		_delay_us(time);
		//L7 is active
		PORTA = A7;
		PORTC = cubeC[1][1];
		PORTB = cubeB[1][1];
		_delay_us(time);
		//L8 is active
		PORTA = A8;
		PORTC = cubeC[1][2];
		PORTB = cubeB[1][2];
		_delay_us(time);
		//L9 is active
		PORTA = A9;
		PORTC = cubeC[1][3];
		PORTB = cubeB[1][3];
		_delay_us(time);
		PORTA=0x00;
		////////////////PORTB is active
		//L10 is active
		PORTB = B10;
		PORTC = cubeC[1][4];
		PORTB |= cubeB[1][4];
		_delay_us(time);
		//L11 is active
		PORTB = B11;
		PORTC = cubeC[2][0];
		PORTB |= cubeB[2][0];
		_delay_us(time);
		//L12 is active
		PORTB = B12;
		PORTC = cubeC[2][1];
		PORTB |= cubeB[2][1];
		_delay_us(time);
		//L13 is active
		PORTB = B13;
		PORTC = cubeC[2][2];
		PORTB |= cubeB[2][2];
		_delay_us(time);
		//L14 is active
		PORTB = B14;
		PORTC = cubeC[2][3];
		PORTB |= cubeB[2][3];
		_delay_us(time);
		//L15 is active
		PORTB = B15;
		PORTC = cubeC[2][4];
		PORTB  |= cubeB[2][4];
		_delay_us(time);
		PORTB=0x00;		
		////////////////PORTD is active
		//L16 is active
		PORTD = D16;
		PORTC = cubeC[3][0];
		PORTB = cubeB[3][0];
		_delay_us(time);
		PORTD =	0x00;
		////////////////PORTC is active
		//L17 is active
		PORTC = C17;
		PORTC |= cubeC[3][1];
		PORTB = cubeB[3][1];
		_delay_us(time);
		//L18 is active
		PORTC = C18;
		PORTC |= cubeC[3][2];
		PORTB = cubeB[3][2];
		_delay_us(time);
		//L19 is active
		PORTC = C19;
		PORTC |= cubeC[3][3];
		PORTB = cubeB[3][3];
		_delay_us(time);
		PORTC=0x00;
		////////////////PORTD is active
		//L20 is active
		PORTD = D20;
		PORTC = cubeC[3][4];
		PORTB = cubeB[3][4];
		_delay_us(time);
		//L21 is active
		PORTD = D21;
		PORTC = cubeC[4][0];
		PORTB = cubeB[4][0];
		_delay_us(time);
		//L22 is active
		PORTD = D22;
		PORTC = cubeC[4][1];
		PORTB = cubeB[4][1];
		_delay_us(time);
		//L23 is active
		PORTD = D23;
		PORTC = cubeC[4][2];
		PORTB = cubeB[4][2];
		_delay_us(time);
		//L24 is active
		PORTD = D24;
		PORTC = cubeC[4][3];
		PORTB = cubeB[4][3];
		_delay_us(time);
		//L25 is active
		PORTD = D25;
		PORTC = cubeC[4][4];
		PORTB = cubeB[4][4];
		_delay_us(time);
		PORTD=0x00;
	}
}

void cube_clear()
{
	int i,j;
	for(i=0;i<5;i++)
	for(j=0;j<5;j++)
	{
		cubeB[i][j] &= ~(LB4 | LB5);
		cubeC[i][j] &= ~(LC1 | LC2 | LC3);
	}
}

void cube_full()
{
	int i,j;
	for(i=0;i<5;i++)
	for(j=0;j<5;j++)
	{
		cubeB[i][j] |= (LB4 | LB5);
		cubeC[i][j] |= (LC1 | LC2 | LC3);
	}	
}

void cube_x_rot(int repeat)
{
	while(repeat>0)
	{
		repeat-=1;
		int i,j;
		cube_clear();
		for(i=0;i<5;i++)
		{
			for(j=0;j<5;j++)
			{
				cubeB[i][j] = 0x00;
				cubeC[i][j] = LC3;
			}
		}
		cubeB[3][0] = 0x00;
		cube_refresh();
		cube_clear();	
		for(i=0;i<5;i++)
		{
			for(j=0;j<5;j++)
			{
				if(j == 0)
				{
					cubeB[i][j] = LB5;
					cubeC[i][j] = 0x00;
				}
				if(j == 1)
				{
					cubeB[i][j] = LB4;
					cubeC[i][j] = 0x00;
				}
				if (j == 2)
				{
					cubeB[i][j] = 0x00;
					cubeC[i][j] = LC3;
				}
				if (j == 3)
				{
					cubeB[i][j] = 0x00;
					cubeC[i][j] = LC2;
							}
				if (j == 4)
				{
					cubeB[i][j] = 0x00;
					cubeC[i][j] = LC1;
				}
			}
		}
		cube_refresh();
		cube_clear();
		for(i=0;i<5;i++)
		{
			cubeB[i][2]= LB4 | LB5;
			cubeC[i][2]= LC1 | LC2 | LC3;
		}
		cube_refresh();
		cube_clear();
		for(i=0;i<5;i++)
		{
			for(j=0;j<5;j++)
			{
				if(j == 0)
				{
					cubeB[i][j] = 0x00;
					cubeC[i][j] = LC1;
				}
				if(j == 1)
				{
					cubeB[i][j] = 0x00;
					cubeC[i][j] = LC2;
				}
				if (j == 2)
				{
					cubeB[i][j] = 0x00;
					cubeC[i][j] = LC3;
				}
				if (j == 3)
				{
					cubeB[i][j] = LB4;
					cubeC[i][j] = 0x00;
				}
				if (j == 4)
				{
					cubeB[i][j] = LB5;
					cubeC[i][j] = 0x00;
				}
			}
		}
		cube_refresh();
		cube_clear();
	}
}

void cube_bomb(int repeat)
{
	while(repeat>0)
	{
		repeat-=1;
		//1.step
		cubeC[2][2]=LC3;
		cube_refresh();
		//2.step
		cubeC[2][2]= LC2 | LC3;//00001110b
		cubeB[2][2]= LB4 | LB5;//00001110b
		cubeC[2][1]=cubeC[1][2]=cubeC[2][3]=cubeC[3][2]= LC3;
		cube_refresh();
		//3.step
		cubeC[1][2]=cubeC[2][1]=cubeC[2][3]=cubeC[3][2]=cubeC[1][1]=cubeC[3][3]=cubeC[1][3]=cubeC[3][1]= LC2 | LC3;
		cubeB[1][2]=cubeB[2][1]=cubeB[2][3]=cubeB[3][2]=cubeB[1][1]=cubeB[3][3]=cubeB[1][3]=cubeB[3][1]= LB4 | LB5;
		cube_refresh();
		//4.step
		cubeB[2][2]= LB4 | LB5;
		cubeC[2][2]= LC1 | LC2 | LC3;
		cubeB[2][0]=cubeB[0][2]=cubeB[2][4]=cubeB[4][2]=0x00;
		cubeC[2][0]=cubeC[0][2]=cubeC[2][4]=cubeC[4][2]=LC3;
		cube_refresh();
		//5.step
		cubeB[1][1]=cubeB[3][3]=cubeB[2][1]=cubeB[1][2]=cubeB[3][1]=cubeB[1][3]=cubeB[2][3]=cubeB[3][2]= LB4 | LB5;
		cubeC[1][1]=cubeC[3][3]=cubeC[2][1]=cubeC[1][2]=cubeC[3][1]=cubeC[1][3]=cubeC[2][3]=cubeC[3][2]=LC1 | LC2 | LC3;
		cubeB[0][1]=cubeB[1][0]=cubeB[0][2]=cubeB[2][0]=cubeB[0][3]=cubeB[3][0]=cubeB[4][1]=cubeB[1][4]=cubeB[4][2]=cubeB[2][4]=cubeB[4][3]=cubeB[3][4]=LB4 | LB5;
		cubeC[0][1]=cubeC[1][0]=cubeC[0][2]=cubeC[2][0]=cubeC[0][3]=cubeC[3][0]=cubeC[4][1]=cubeC[1][4]=cubeC[4][2]=cubeC[2][4]=cubeC[4][3]=cubeC[3][4]= LC2 | LC3;;
		cube_refresh();
		//6.step
		cube_full();
		cube_refresh();
		cube_clear();
	}
}

void cube_E(int repeat)
{
	while(repeat>0)
	{
		repeat-=1;
		int i;
		//1.step
		for (i = 0; i<5;i++)
		{
			cubeB[i][0]= LB5;
			cubeC[i][0]= LC1 | LC3;
		}
		cubeB[0][0]= LB4 |LB5;
		cubeC[0][0]= LC1 | LC2 | LC3;
		cube_refresh();
		cube_clear();
		//2.step
		for (i = 0; i<5;i++)
		{
			cubeB[i][1]= LB5;
			cubeC[i][1]= LC1 | LC3;
		}
		cubeB[0][1]= LB4 |LB5;
		cubeC[0][1]= LC1 | LC2 | LC3;
		cube_refresh();
		cube_clear();
		//3.step
		for (i = 0; i<5;i++)
		{
			cubeB[i][2]= LB5;
			cubeC[i][2]= LC1 | LC3;
		}
		cubeB[0][2]= LB4 |LB5;
		cubeC[0][2]= LC1 | LC2 | LC3;
		cube_refresh();
		cube_clear();
		//4.step
		for (i = 0; i<5;i++)
		{
			cubeB[i][3]= LB5;
			cubeC[i][3]= LC1 | LC3;
		}
		cubeB[0][3]= LB4 |LB5;
		cubeC[0][3]= LC1 | LC2 | LC3;
		cube_refresh();
		cube_clear();
		//5.step
		for (i = 0; i<5;i++)
		{
			cubeB[i][4]= LB5;
			cubeC[i][4]= LC1 | LC3;
		}
		cubeB[0][4]= LB4 |LB5;
		cubeC[0][4]= LC1 | LC2 | LC3;
		cube_refresh();
		cube_clear();
	}
}

void cube_y_rot(int repeat)
{
	while(repeat>0)
	{
		repeat-=1;
		int i,j;
		cube_clear();
		for(i=0;i<5;i++)
		{
			for(j=0;j<5;j++)
			{
				cubeB[i][j] = 0x00;
				cubeC[i][j] = LC3;
			}
		}
		cubeB[3][0] = 0x00;
		cube_refresh();
		cube_clear();
		for(i=0;i<5;i++)
		{
			for(j=0;j<5;j++)
			{
				if(i == 0)
				{
					cubeB[i][j] = LB5;
					cubeC[i][j] = 0x00;
				}
				if(i == 1)
				{
					cubeB[i][j] = LB4;
					cubeC[i][j] = 0x00;
				}
				if (i == 2)
				{
					cubeB[i][j] = 0x00;
					cubeC[i][j] = LC3;
				}
				if (i == 3)
				{
					cubeB[i][j] = 0x00;
					cubeC[i][j] = LC2;
				}
				if (i == 4)
				{
					cubeB[i][j] = 0x00;
					cubeC[i][j] = LC1;
				}
			}
		}
		cube_refresh();
		cube_clear();
		for(i=0;i<5;i++)
		{
			cubeB[2][i]= LB4 | LB5;
			cubeC[2][i]= LC1 | LC2 | LC3;
		}
		cube_refresh();
		cube_clear();
		for(i=0;i<5;i++)
		{
			for(j=0;j<5;j++)
			{
				if(i == 0)
				{
					cubeB[i][j] = 0x00;
					cubeC[i][j] = LC1;
				}
				if(j == 1)
				{
					cubeB[i][j] = 0x00;
					cubeC[i][j] = LC2;
				}
				if (i == 2)
				{
					cubeB[i][j] = 0x00;
					cubeC[i][j] = LC3;
				}
				if (i == 3)
				{
					cubeB[i][j] = LB4;
					cubeC[i][j] = 0x00;
				}
				if (i == 4)
				{
					cubeB[i][j] = LB5;
					cubeC[i][j] = 0x00;
				}
			}
		}
		cube_refresh();
		cube_clear();
	}
}

int main(void)
{
	cube_init();
	cube_clear();
	while(1)
	{	
		cube_x_rot(3);
		cube_bomb(3);
		cube_y_rot(3);
		cube_E(3);
	}
	return 0;
}
