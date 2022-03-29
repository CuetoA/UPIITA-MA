#define FIL1	0X0F & ~(0X01)  ////0X0E	0b0000 1110
#define FIL2	0X0F & ~(0X02)  ////0X0D	0b0000 1101
#define FIL3	0X0F & ~(0X04)  ////0X0B	0b0000 1011
#define FIL4	0X0F & ~(0X08)  ////0X07	0b0000 0111

#define COL1	0XFF & ~(0X10)  ////0XEF	0b1110 1111
#define COL2	0XFF & ~(0X20)  ////0XDF	0b1101 1111
#define COL3	0XFF & ~(0X40)  ////0XBF	0b1011 1111
#define COL4	0XFF & ~(0X80)  ////0X7F	0b0111 1111

char VALOR_TECLADO=' ';


char LEE_TECLADO()
{
	
	switch(PORTD)
	{
		case COL1:
		switch(PIND&0X0F)
		{
			case FIL1:	VALOR_TECLADO='1';	break;//0X0E
			case FIL2:	VALOR_TECLADO='2';	break;//0X0D:
			case FIL3:	VALOR_TECLADO='3';	break;//0X0B
			case FIL4:	VALOR_TECLADO='A';	break;//0X07
		}
		break;
		case COL2:
		switch(PIND&0X0F)
		{
			case FIL1:	VALOR_TECLADO='4';	break;
			case FIL2:	VALOR_TECLADO='5';	break;
			case FIL3:	VALOR_TECLADO='6';	break;
			case FIL4:	VALOR_TECLADO='B';	break;
		}
		break;
		case COL3:
		switch(PIND&0X0F)
		{
			case FIL1:	VALOR_TECLADO='7';	break;
			case FIL2:	VALOR_TECLADO='8';	break;
			case FIL3:	VALOR_TECLADO='9';	break;
			case FIL4:	VALOR_TECLADO='C';	break;
		}
		break;
		case COL4:
		switch(PIND&0X0F)
		{
			case FIL1:	VALOR_TECLADO='*';	break;
			case FIL2:	VALOR_TECLADO='0';	break;
			case FIL3:	VALOR_TECLADO='#';	break;
			case FIL4:	VALOR_TECLADO='D';	break;
		}
		break;
	}
	return VALOR_TECLADO;
}

void BARRE_TECLADO()
{
	switch(PORTD)
	{
		case COL1:	PORTD=COL2;		break;
		case COL2:	PORTD=COL3;		break;
		case COL3:	PORTD=COL4;		break;
		//case COL4:	PORTD=COL1;		break;
		default:	PORTD=COL1;
	}
}