#include "nrf24l01.h"
#include "main.h"
#include "gpio.h"
#include "spi.h"

/*start of low level functions, specific to the mcu and compiler*/

/*delay in miliseconds*/
void delay_function(uint32_t duration_ms)
{
    HAL_Delay(duration_ms);
}

/*contains all SPI configuations, such as pins and control registers*/
/*SPI control: master, interrupts disabled, clock polarity low when idle, clock phase falling edge, clock up tp 1 MHz*/
void SPI_Initializer()
{
}

/*contains all CSN and CE pins gpio configurations, including setting them as gpio outputs and turning SPI off and CE '1'*/
void pinout_Initializer()
{
}

/*CSN pin manipulation to high or low (SPI on or off)*/
void nrf24_SPI(uint8_t input)
{
    HAL_GPIO_WritePin(NRF_CNS_GPIO_Port, NRF_CNS_Pin, input);
}

/*1 byte SPI shift register send and receive routine*/
uint8_t SPI_send_command(uint8_t command)
{
    uint8_t rx_buf;
	HAL_SPI_TransmitReceive(&hspi1, &command, &rx_buf, 1, 1000);
    return rx_buf;
}

/*CE pin maniplation to high or low*/
void nrf24_CE(uint8_t input)
{
    HAL_GPIO_WritePin(NRF_CE_GPIO_Port, NRF_CE_Pin, input);
}
