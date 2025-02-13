#include <stdint.h>

#define  GPIOA_CTL1 (*(uint32_t *)(0x40010800 + 0x04))
#define  GPIOA_OCTL (*(uint32_t *)(0x40010800 + 0x0C))
#define  RCU_APB2EN (*(uint32_t *)(0x40021000 + 0x18))

static void Delay(uint32_t count)
{
	while (count--);
}

int main(void)
{
	/*ʹ��GPIO��ʱ��*/
	RCU_APB2EN |= 1 << 2;
	/*����Ϊ�������ģʽ*/
	GPIOA_CTL1 = 0x44444442;
	/*����Ϊ����ߵ�ƽ*/

	while (1)
	{
		GPIOA_OCTL |= 1 << 8;  //00000000 00000000 00000001 00000000	
		Delay(1000000);
		GPIOA_OCTL &= ~(1 << 8); //11111111 11111111 11111110 11111111
		Delay(1000000);
	}
}
