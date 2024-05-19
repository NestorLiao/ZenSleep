// #include "oled.h"
// #include "f6x8.h"
 
 
// void SSD1306_WriteByte(uint8_t dat,uint8_t cmd)
// {
// 	uint8_t buffer[2];
// 	buffer[0]=cmd;
// 	buffer[1]=dat;
// 	HAL_I2C_Master_Transmit(&hi2c1,0x78,buffer,2,0xffff);
// }
 
// void OLED_Init()
// {
// 	HAL_Delay(100);
// 	SSD1306_WriteByte(0xAE,OLED_CMD); //display off
	
// 	SSD1306_WriteByte(0x20,OLED_CMD); //Set Memory Addressing Mode   
// 	SSD1306_WriteByte(0x10,OLED_CMD); //00,Horizontal Addressing Mode;01,Vertical Addressing Mode;10,Page Addressing Mode (RESET);11,Invalid
	
// 	SSD1306_WriteByte(0xB0,OLED_CMD); //Set Page Start Address for Page Addressing Mode,0-7
	
// 	SSD1306_WriteByte(0x00,OLED_CMD); //---set low column address
// 	SSD1306_WriteByte(0x10,OLED_CMD); //---set high column address
	
// 	SSD1306_WriteByte(0xC8,OLED_CMD); //Set COM Output Scan Direction
 
// 	SSD1306_WriteByte(0x40,OLED_CMD); //--set start line address
	
// 	SSD1306_WriteByte(0x81,OLED_CMD); //--set contrast control register
// 	SSD1306_WriteByte(0xff,OLED_CMD); //对比度设置
	
// 	SSD1306_WriteByte(0xA1,OLED_CMD); //--set segment re-map 0 to 127
// 	SSD1306_WriteByte(0xC8,OLED_CMD); //--set segment re-map 0 to 127
	
// 	SSD1306_WriteByte(0xA6,OLED_CMD); //--set normal display
	
// 	SSD1306_WriteByte(0xA8,OLED_CMD); //--set multiplex ratio(1 to 64)
// 	SSD1306_WriteByte(0x3F,OLED_CMD); //
	
// 	SSD1306_WriteByte(0xA4,OLED_CMD); //0xa4,Output follows RAM content;0xa5,Output ignores RAM content
	
// 	SSD1306_WriteByte(0xD3,OLED_CMD); //-set display offset
// 	SSD1306_WriteByte(0x00,OLED_CMD); //-not offset
	
// 	SSD1306_WriteByte(0xD5,OLED_CMD); //--set display clock divide ratio/oscillator frequency
// 	SSD1306_WriteByte(0xF0,OLED_CMD); //--set divide ratio
	
// 	SSD1306_WriteByte(0xD9,OLED_CMD); //--set pre-charge period
// 	SSD1306_WriteByte(0x22,OLED_CMD); //
	
// 	SSD1306_WriteByte(0xDA,OLED_CMD); //--set com pins hardware configuration
// 	SSD1306_WriteByte(0x12,OLED_CMD);
	
// 	SSD1306_WriteByte(0xDB,OLED_CMD); //--set vcomh
// 	SSD1306_WriteByte(0x20,OLED_CMD); //0x20,0.77xVcc
	
// 	SSD1306_WriteByte(0x8D,OLED_CMD); //--set DC-DC enable
// 	SSD1306_WriteByte(0x14,OLED_CMD); //
// 	SSD1306_WriteByte(0xAF,OLED_CMD); //--turn on SSD1306 panel
// }
// void OLED_Clear()
// {
//      uint8_t i,n;		    
// 	for(i=0;i<8;i++)  
// 	{  
// 		SSD1306_WriteByte (0xb0+i,OLED_CMD);    //设置页地址（0~7）
// 		SSD1306_WriteByte (0x00,OLED_CMD);      //设置显示位置—列低地址
// 		SSD1306_WriteByte (0x10,OLED_CMD);      //设置显示位置—列高地址   
// 		for(n=0;n<128;n++)
// 			SSD1306_WriteByte(0,OLED_DATA); //write 0x00;
// 	} //更新显示
// }
 
 
// void OLED_Set_Pos(unsigned char x, unsigned char y) 
// { 	
// 	SSD1306_WriteByte(0xb0+y,OLED_CMD);						//page y
// 	SSD1306_WriteByte(((x&0xf0)>>4)|0x10,OLED_CMD);			//high 4 address
// 	SSD1306_WriteByte((x&0x0f),OLED_CMD); 					//low 4 address
// } 
 
 
// void OLED_ShowChar(uint8_t x,uint8_t y,uint8_t chr,uint8_t Char_Size)
// {      	
// 	unsigned char c=0,i=0;	
// 		c=chr-' ';//得到偏移后的值			
// 		if(x>Max_Column-1){x=0;y=y+2;}
// 		if(Char_Size ==16)
// 			{
// 				OLED_Set_Pos(x,y);	
// 				for(i=0;i<8;i++)
// 				SSD1306_WriteByte(F8X16[c*16+i],OLED_DATA);
// 				OLED_Set_Pos(x,y+1);
// 				for(i=0;i<8;i++)
// 				SSD1306_WriteByte(F8X16[c*16+i+8],OLED_DATA);
// 			}
// 		else 
// 			{	
// 				OLED_Set_Pos(x,y);
// 				for(i=0;i<6;i++)
// 				SSD1306_WriteByte(F6x8[c][i],OLED_DATA);
// 			}
// }
// void OLED_ShowString(uint8_t x,uint8_t y,uint8_t *chr,uint8_t Char_Size)
// {
// 	unsigned char j=0;
// 	while (chr[j]!='\0')
// 	{		OLED_ShowChar(x,y,chr[j],Char_Size);
// 			x+=8;
// 		if(x>120){x=0;y+=2;}
// 			j++;
// 	}
// }



// void OLED_ShowPic(uint8_t x,uint8_t y,BMP bmp)
// {
// 	uint8_t xsize=bmp.xSize;
// 	uint8_t ysize=bmp.ySize;
// 	OLED_Set_Pos(x,y);
// 	//如果像素高度不是8的倍数，则整除后加1补上
// 	if(ysize%8!=0)
// 		ysize=ysize+8;
// 	uint8_t i,j;
// 	for(i=0;i<ysize/8;i++)
// 	{
// 		OLED_Set_Pos(x,y+i);
// 		for(j=0;j<xsize;j++)
// 		SSD1306_WriteByte(*(bmp.p+i*xsize+j),OLED_DATA);
// 	}
// }



#include "main.h"
#include "OLED_Font.h"
#include "i2c.h"

#define OLED0561_ADD	0x78  //OLED的I2C地址
#define COM				0x00  //OLED 指令
#define DAT 			0x40  //OLED 数据

void OLED_WriteCommand(uint8_t I2C_Command)//写命令
{
	HAL_I2C_Mem_Write(&hi2c1,OLED0561_ADD,COM,I2C_MEMADD_SIZE_8BIT,&I2C_Command,1,100);
}
		
void OLED_WriteData(uint8_t I2C_Data)//写数据
{
	HAL_I2C_Mem_Write(&hi2c1,OLED0561_ADD,DAT,I2C_MEMADD_SIZE_8BIT,&I2C_Data,1,100);
}

/**
  * @brief  OLED设置光标位置
  * @param  Y 以左上角为原点，向下方向的坐标，范围：0~7
  * @param  X 以左上角为原点，向右方向的坐标，范围：0~127
  * @retval 无
  */
void OLED_SetCursor(uint8_t Y, uint8_t X)
{
	OLED_WriteCommand(0xB0 | Y);					//设置Y位置
	OLED_WriteCommand(0x10 | ((X & 0xF0) >> 4));	//设置X位置高4位
	OLED_WriteCommand(0x00 | (X & 0x0F));			//设置X位置低4位
}

/**
  * @brief  OLED清屏
  * @param  无
  * @retval 无
  */
void OLED_Clear(void)
{  
	uint8_t i, j;
	for (j = 0; j < 8; j++)
	{
		OLED_SetCursor(j, 0);
		for(i = 0; i < 128; i++)
		{
			OLED_WriteData(0x00);
		}
	}
}

/**
  * @brief  OLED显示一个字符
  * @param  Line 行位置，范围：1~4
  * @param  Column 列位置，范围：1~16
  * @param  Char 要显示的一个字符，范围：ASCII可见字符
  * @retval 无
  */
void OLED_ShowChar(uint8_t Line, uint8_t Column, char Char)
{      	
	uint8_t i;
	OLED_SetCursor((Line - 1) * 2, (Column - 1) * 8);		//设置光标位置在上半部分
	for (i = 0; i < 8; i++)
	{
		OLED_WriteData(OLED_F8x16[Char - ' '][i]);			//显示上半部分内容
	}
	OLED_SetCursor((Line - 1) * 2 + 1, (Column - 1) * 8);	//设置光标位置在下半部分
	for (i = 0; i < 8; i++)
	{
		OLED_WriteData(OLED_F8x16[Char - ' '][i + 8]);		//显示下半部分内容
	}
}

/**
  * @brief  OLED显示字符串
  * @param  Line 起始行位置，范围：1~4
  * @param  Column 起始列位置，范围：1~16
  * @param  String 要显示的字符串，范围：ASCII可见字符
  * @retval 无
  */
void OLED_ShowString(uint8_t Line, uint8_t Column, char *String)
{
	uint8_t i;
	for (i = 0; String[i] != '\0'; i++)
	{
		OLED_ShowChar(Line, Column + i, String[i]);
	}
}

/**
  * @brief  OLED次方函数
  * @retval 返回值等于X的Y次方
  */
uint32_t OLED_Pow(uint32_t X, uint32_t Y)
{
	uint32_t Result = 1;
	while (Y--)
	{
		Result *= X;
	}
	return Result;
}

/**
  * @brief  OLED显示数字（十进制，正数）
  * @param  Line 起始行位置，范围：1~4
  * @param  Column 起始列位置，范围：1~16
  * @param  Number 要显示的数字，范围：0~4294967295
  * @param  Length 要显示数字的长度，范围：1~10
  * @retval 无
  */
void OLED_ShowNum(uint8_t Line, uint8_t Column, uint32_t Number, uint8_t Length)
{
	uint8_t i;
	for (i = 0; i < Length; i++)							
	{
		OLED_ShowChar(Line, Column + i, Number / OLED_Pow(10, Length - i - 1) % 10 + '0');
	}
}

/**
  * @brief  OLED显示数字（十进制，带符号数）
  * @param  Line 起始行位置，范围：1~4
  * @param  Column 起始列位置，范围：1~16
  * @param  Number 要显示的数字，范围：-2147483648~2147483647
  * @param  Length 要显示数字的长度，范围：1~10
  * @retval 无
  */
void OLED_ShowSignedNum(uint8_t Line, uint8_t Column, int32_t Number, uint8_t Length)
{
	uint8_t i;
	uint32_t Number1;
	if (Number >= 0)
	{
		OLED_ShowChar(Line, Column, '+');
		Number1 = Number;
	}
	else
	{
		OLED_ShowChar(Line, Column, '-');
		Number1 = -Number;
	}
	for (i = 0; i < Length; i++)							
	{
		OLED_ShowChar(Line, Column + i + 1, Number1 / OLED_Pow(10, Length - i - 1) % 10 + '0');
	}
}

/**
  * @brief  OLED显示数字（十六进制，正数）
  * @param  Line 起始行位置，范围：1~4
  * @param  Column 起始列位置，范围：1~16
  * @param  Number 要显示的数字，范围：0~0xFFFFFFFF
  * @param  Length 要显示数字的长度，范围：1~8
  * @retval 无
  */
void OLED_ShowHexNum(uint8_t Line, uint8_t Column, uint32_t Number, uint8_t Length)
{
	uint8_t i, SingleNumber;
	for (i = 0; i < Length; i++)							
	{
		SingleNumber = Number / OLED_Pow(16, Length - i - 1) % 16;
		if (SingleNumber < 10)
		{
			OLED_ShowChar(Line, Column + i, SingleNumber + '0');
		}
		else
		{
			OLED_ShowChar(Line, Column + i, SingleNumber - 10 + 'A');
		}
	}
}

/**
  * @brief  OLED显示数字（二进制，正数）
  * @param  Line 起始行位置，范围：1~4
  * @param  Column 起始列位置，范围：1~16
  * @param  Number 要显示的数字，范围：0~1111 1111 1111 1111
  * @param  Length 要显示数字的长度，范围：1~16
  * @retval 无
  */
void OLED_ShowBinNum(uint8_t Line, uint8_t Column, uint32_t Number, uint8_t Length)
{
	uint8_t i;
	for (i = 0; i < Length; i++)							
	{
		OLED_ShowChar(Line, Column + i, Number / OLED_Pow(2, Length - i - 1) % 2 + '0');
	}
}

/**
  * @brief  OLED初始化
  * @param  无
  * @retval 无
  */
void OLED_Init(void)
{
	HAL_Delay(100);
	
	OLED_WriteCommand(0xAE);	//关闭显示
	
	OLED_WriteCommand(0xD5);	//设置显示时钟分频比/振荡器频率
	OLED_WriteCommand(0x80);
	
	OLED_WriteCommand(0xA8);	//设置多路复用率
	OLED_WriteCommand(0x3F);
	
	OLED_WriteCommand(0xD3);	//设置显示偏移
	OLED_WriteCommand(0x00);
	
	OLED_WriteCommand(0x40);	//设置显示开始行
	
	OLED_WriteCommand(0xA1);	//设置左右方向，0xA1正常 0xA0左右反置
	
	OLED_WriteCommand(0xC8);	//设置上下方向，0xC8正常 0xC0上下反置

	OLED_WriteCommand(0xDA);	//设置COM引脚硬件配置
	OLED_WriteCommand(0x12);
	
	OLED_WriteCommand(0x81);	//设置对比度控制
	OLED_WriteCommand(0xCF);

	OLED_WriteCommand(0xD9);	//设置预充电周期
	OLED_WriteCommand(0xF1);

	OLED_WriteCommand(0xDB);	//设置VCOMH取消选择级别
	OLED_WriteCommand(0x30);

	OLED_WriteCommand(0xA4);	//设置整个显示打开/关闭

	OLED_WriteCommand(0xA6);	//设置正常/倒转显示

	OLED_WriteCommand(0x8D);	//设置充电泵
	OLED_WriteCommand(0x14);

	OLED_WriteCommand(0xAF);	//开启显示
		
	OLED_Clear();				//OLED清屏
}
