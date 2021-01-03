#include "sys.h"
#include "delay.h"
#include "usart.h"
#include "led.h"
#include "beep.h"
#include "key.h"
#include "exti.h"

//ALIENTEK ̽����STM32F407������ ʵ��5
//�ⲿ�ж�ʵ��-�⺯���汾
//����֧�֣�www.openedv.com
//�Ա����̣�http://eboard.taobao.com
//������������ӿƼ����޹�˾    
//���ߣ�����ԭ�� @ALIENTEK 

int main(void)
{ 
	extern u8 RE;
	
	//SCB->VTOR = FLASH_BASE |0x10000;
	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2);//����ϵͳ�ж����ȼ�����2
	delay_init(168);    //��ʼ����ʱ����
	uart_init(115200); 	//���ڳ�ʼ�� 
	LED_Init();				  //��ʼ��LED�˿�  
	BEEP_Init();        //��ʼ���������˿�
	EXTIX_Init();       //��ʼ���ⲿ�ж����� 
	LED0=0;					    //�ȵ������
	while(1)
	{
  	printf("OK\r\n");	//��ӡOK��ʾ��������
		delay_ms(1000);	  //ÿ��1s��ӡһ��

		if(RE==1)
		{
			NVIC_SystemReset();
			RE=0;
		}
	}

}

