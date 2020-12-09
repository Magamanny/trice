/*
 * Generated by TASKING Pin Mapper for STM32
 * -----------------------------------------
 * device : STM32F407V(E-G)Tx
 * package: LQFP100
 *
 */

#include "stm32_chip_config.h"


/* GPIO */
void pincfg_gpio_init(void)
{
    pincfg_gpiod_init();
}

/* GPIOD */
void pincfg_gpiod_init(void)
{
    /* GPIO configuration
     * ------------------
     * [PD4]
     */
    GPIO_InitTypeDef GPIO_InitStruct;

    /* GPIO clocks enabling */
    RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOD, ENABLE);

    /* [PD4] configuration */
    GPIO_StructInit(&GPIO_InitStruct);
    GPIO_InitStruct.GPIO_Pin = GPIO_Pin_4;
    GPIO_InitStruct.GPIO_Mode = GPIO_Mode_OUT;
    GPIO_InitStruct.GPIO_Speed = GPIO_Low_Speed;
    GPIO_InitStruct.GPIO_OType = GPIO_OType_PP;
    GPIO_InitStruct.GPIO_PuPd = GPIO_PuPd_NOPULL;
    GPIO_Init(GPIOD, &GPIO_InitStruct);
}

/* I2C1 */
void pincfg_i2c1_init(void)
{
    /* GPIO configuration
     * ------------------
     * I2C1_SCL    : PB6
     * I2C1_SDA    : PB9
     */
    GPIO_InitTypeDef GPIO_InitStruct;

    /* GPIO clocks enabling */
    RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOB, ENABLE);

    /* [PB6, PB9] configuration */
    GPIO_StructInit(&GPIO_InitStruct);
    GPIO_InitStruct.GPIO_Pin = GPIO_Pin_6 | GPIO_Pin_9;
    GPIO_InitStruct.GPIO_Mode = GPIO_Mode_AF;
    GPIO_InitStruct.GPIO_Speed = GPIO_Fast_Speed;
    GPIO_InitStruct.GPIO_OType = GPIO_OType_OD;
    GPIO_InitStruct.GPIO_PuPd = GPIO_PuPd_NOPULL;
    GPIO_Init(GPIOB, &GPIO_InitStruct);

    /* AF configuration */
    GPIO_PinAFConfig(GPIOB, GPIO_PinSource6, GPIO_AF_I2C1); /* PB6 */
    GPIO_PinAFConfig(GPIOB, GPIO_PinSource9, GPIO_AF_I2C1); /* PB9 */
}

/* I2S3 */
void pincfg_i2s3_init(void)
{
    /* GPIO configuration
     * ------------------
     * I2S3_CK     : PC10
     * I2S3_MCK    : PC7
     * I2S3_SD     : PC12
     * I2S3_WS     : PA4
     */
    GPIO_InitTypeDef GPIO_InitStruct;

    /* GPIO clocks enabling */
    RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOA | RCC_AHB1Periph_GPIOC, ENABLE);

    /* [PA4] configuration */
    GPIO_StructInit(&GPIO_InitStruct);
    GPIO_InitStruct.GPIO_Pin = GPIO_Pin_4;
    GPIO_InitStruct.GPIO_Mode = GPIO_Mode_AF;
    GPIO_InitStruct.GPIO_Speed = GPIO_Fast_Speed;
    GPIO_InitStruct.GPIO_OType = GPIO_OType_PP;
    GPIO_InitStruct.GPIO_PuPd = GPIO_PuPd_NOPULL;
    GPIO_Init(GPIOA, &GPIO_InitStruct);

    /* [PC7, PC10, PC12] configuration */
    GPIO_StructInit(&GPIO_InitStruct);
    GPIO_InitStruct.GPIO_Pin = GPIO_Pin_7 | GPIO_Pin_10 | GPIO_Pin_12;
    GPIO_InitStruct.GPIO_Mode = GPIO_Mode_AF;
    GPIO_InitStruct.GPIO_Speed = GPIO_Fast_Speed;
    GPIO_InitStruct.GPIO_OType = GPIO_OType_PP;
    GPIO_InitStruct.GPIO_PuPd = GPIO_PuPd_NOPULL;
    GPIO_Init(GPIOC, &GPIO_InitStruct);

    /* AF configuration */
    GPIO_PinAFConfig(GPIOA, GPIO_PinSource4, GPIO_AF_SPI3); /* PA4 */
    GPIO_PinAFConfig(GPIOC, GPIO_PinSource7, GPIO_AF_SPI3); /* PC7 */
    GPIO_PinAFConfig(GPIOC, GPIO_PinSource10, GPIO_AF_SPI3); /* PC10 */
    GPIO_PinAFConfig(GPIOC, GPIO_PinSource12, GPIO_AF_SPI3); /* PC12 */
}
