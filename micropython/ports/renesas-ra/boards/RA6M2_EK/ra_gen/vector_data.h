/* generated vector header file - do not edit */
#ifndef VECTOR_DATA_H
#define VECTOR_DATA_H
/* Number of interrupts allocated */
#ifndef VECTOR_DATA_IRQ_COUNT
#define VECTOR_DATA_IRQ_COUNT    (44)
#endif
/* ISR prototypes */
void sci_uart_rxi_isr(void);
void sci_uart_txi_isr(void);
void sci_uart_tei_isr(void);
void sci_uart_eri_isr(void);
void rtc_alarm_periodic_isr(void);
void rtc_carry_isr(void);
void agt_int_isr(void);
void r_icu_isr(void);
void spi_rxi_isr(void);
void spi_txi_isr(void);
void spi_tei_isr(void);
void spi_eri_isr(void);
void iic_master_rxi_isr(void);
void iic_master_txi_isr(void);
void iic_master_tei_isr(void);
void iic_master_eri_isr(void);

/* Vector table allocations */
#define VECTOR_NUMBER_SCI0_RXI ((IRQn_Type)0)  /* SCI0 RXI (Receive data full) */
#define VECTOR_NUMBER_SCI0_TXI ((IRQn_Type)1)  /* SCI0 TXI (Transmit data empty) */
#define VECTOR_NUMBER_SCI0_TEI ((IRQn_Type)2)  /* SCI0 TEI (Transmit end) */
#define VECTOR_NUMBER_SCI0_ERI ((IRQn_Type)3)  /* SCI0 ERI (Receive error) */
#define VECTOR_NUMBER_SCI7_RXI ((IRQn_Type)4)  /* SCI7 RXI (Received data full) */
#define VECTOR_NUMBER_SCI7_TXI ((IRQn_Type)5)  /* SCI7 TXI (Transmit data empty) */
#define VECTOR_NUMBER_SCI7_TEI ((IRQn_Type)6)  /* SCI7 TEI (Transmit end) */
#define VECTOR_NUMBER_SCI7_ERI ((IRQn_Type)7)  /* SCI7 ERI (Receive error) */
#define VECTOR_NUMBER_SCI9_RXI ((IRQn_Type)8)  /* SCI9 RXI (Received data full) */
#define VECTOR_NUMBER_SCI9_TXI ((IRQn_Type)9)  /* SCI9 TXI (Transmit data empty) */
#define VECTOR_NUMBER_SCI9_TEI ((IRQn_Type)10)  /* SCI9 TEI (Transmit end) */
#define VECTOR_NUMBER_SCI9_ERI ((IRQn_Type)11)  /* SCI9 ERI (Receive error) */
#define VECTOR_NUMBER_RTC_ALARM ((IRQn_Type)12)  /* RTC ALARM (Alarm interrupt) */
#define VECTOR_NUMBER_RTC_PERIOD ((IRQn_Type)13)  /* RTC PERIOD (Periodic interrupt) */
#define VECTOR_NUMBER_RTC_CARRY ((IRQn_Type)14)  /* RTC CARRY (Carry interrupt) */
#define VECTOR_NUMBER_AGT0_INT ((IRQn_Type)15)  /* AGT0 INT (AGT interrupt) */
#define VECTOR_NUMBER_ICU_IRQ0 ((IRQn_Type)16)  /* ICU IRQ0 (External pin interrupt 0) */
#define VECTOR_NUMBER_ICU_IRQ1 ((IRQn_Type)17)  /* ICU IRQ1 (External pin interrupt 1) */
#define VECTOR_NUMBER_ICU_IRQ2 ((IRQn_Type)18)  /* ICU IRQ2 (External pin interrupt 2) */
#define VECTOR_NUMBER_ICU_IRQ3 ((IRQn_Type)19)  /* ICU IRQ3 (External pin interrupt 3) */
#define VECTOR_NUMBER_ICU_IRQ4 ((IRQn_Type)20)  /* ICU IRQ4 (External pin interrupt 4) */
#define VECTOR_NUMBER_ICU_IRQ5 ((IRQn_Type)21)  /* ICU IRQ5 (External pin interrupt 5) */
#define VECTOR_NUMBER_ICU_IRQ6 ((IRQn_Type)22)  /* ICU IRQ6 (External pin interrupt 6) */
#define VECTOR_NUMBER_ICU_IRQ7 ((IRQn_Type)23)  /* ICU IRQ7 (External pin interrupt 7) */
#define VECTOR_NUMBER_ICU_IRQ8 ((IRQn_Type)24)  /* ICU IRQ8 (External pin interrupt 8) */
#define VECTOR_NUMBER_ICU_IRQ9 ((IRQn_Type)25)  /* ICU IRQ9 (External pin interrupt 9) */
#define VECTOR_NUMBER_ICU_IRQ10 ((IRQn_Type)26)  /* ICU IRQ10 (External pin interrupt 10) */
#define VECTOR_NUMBER_ICU_IRQ11 ((IRQn_Type)27)  /* ICU IRQ11 (External pin interrupt 11) */
#define VECTOR_NUMBER_ICU_IRQ12 ((IRQn_Type)28)  /* ICU IRQ12 (External pin interrupt 12) */
#define VECTOR_NUMBER_ICU_IRQ13 ((IRQn_Type)29)  /* ICU IRQ13 (External pin interrupt 13) */
#define VECTOR_NUMBER_ICU_IRQ14 ((IRQn_Type)30)  /* ICU IRQ14 (External pin interrupt 14) */
#define VECTOR_NUMBER_ICU_IRQ15 ((IRQn_Type)31)  /* ICU IRQ15 (External pin interrupt 15) */
#define VECTOR_NUMBER_SPI0_RXI ((IRQn_Type)32)  /* SPI0 RXI (Receive buffer full) */
#define VECTOR_NUMBER_SPI0_TXI ((IRQn_Type)33)  /* SPI0 TXI (Transmit buffer empty) */
#define VECTOR_NUMBER_SPI0_TEI ((IRQn_Type)34)  /* SPI0 TEI (Transmission complete event) */
#define VECTOR_NUMBER_SPI0_ERI ((IRQn_Type)35)  /* SPI0 ERI (Error) */
#define VECTOR_NUMBER_SPI1_RXI ((IRQn_Type)36)  /* SPI1 RXI (Receive buffer full) */
#define VECTOR_NUMBER_SPI1_TXI ((IRQn_Type)37)  /* SPI1 TXI (Transmit buffer empty) */
#define VECTOR_NUMBER_SPI1_TEI ((IRQn_Type)38)  /* SPI1 TEI (Transmission complete event) */
#define VECTOR_NUMBER_SPI1_ERI ((IRQn_Type)39)  /* SPI1 ERI (Error) */
#define VECTOR_NUMBER_IIC2_RXI ((IRQn_Type)40)  /* IIC2 RXI (Receive data full) */
#define VECTOR_NUMBER_IIC2_TXI ((IRQn_Type)41)  /* IIC2 TXI (Transmit data empty) */
#define VECTOR_NUMBER_IIC2_TEI ((IRQn_Type)42)  /* IIC2 TEI (Transmit end) */
#define VECTOR_NUMBER_IIC2_ERI ((IRQn_Type)43)  /* IIC2 ERI (Transfer error) */
typedef enum IRQn
{
    Reset_IRQn = -15,
    NonMaskableInt_IRQn = -14,
    HardFault_IRQn = -13,
    MemoryManagement_IRQn = -12,
    BusFault_IRQn = -11,
    UsageFault_IRQn = -10,
    SecureFault_IRQn = -9,
    SVCall_IRQn = -5,
    DebugMonitor_IRQn = -4,
    PendSV_IRQn = -2,
    SysTick_IRQn = -1,
    SCI0_RXI_IRQn = 0, /* SCI0 RXI (Receive data full) */
    SCI0_TXI_IRQn = 1, /* SCI0 TXI (Transmit data empty) */
    SCI0_TEI_IRQn = 2, /* SCI0 TEI (Transmit end) */
    SCI0_ERI_IRQn = 3, /* SCI0 ERI (Receive error) */
    SCI7_RXI_IRQn = 4, /* SCI7 RXI (Received data full) */
    SCI7_TXI_IRQn = 5, /* SCI7 TXI (Transmit data empty) */
    SCI7_TEI_IRQn = 6, /* SCI7 TEI (Transmit end) */
    SCI7_ERI_IRQn = 7, /* SCI7 ERI (Receive error) */
    SCI9_RXI_IRQn = 8, /* SCI9 RXI (Received data full) */
    SCI9_TXI_IRQn = 9, /* SCI9 TXI (Transmit data empty) */
    SCI9_TEI_IRQn = 10, /* SCI9 TEI (Transmit end) */
    SCI9_ERI_IRQn = 11, /* SCI9 ERI (Receive error) */
    RTC_ALARM_IRQn = 12, /* RTC ALARM (Alarm interrupt) */
    RTC_PERIOD_IRQn = 13, /* RTC PERIOD (Periodic interrupt) */
    RTC_CARRY_IRQn = 14, /* RTC CARRY (Carry interrupt) */
    AGT0_INT_IRQn = 15, /* AGT0 INT (AGT interrupt) */
    ICU_IRQ0_IRQn = 16, /* ICU IRQ0 (External pin interrupt 0) */
    ICU_IRQ1_IRQn = 17, /* ICU IRQ1 (External pin interrupt 1) */
    ICU_IRQ2_IRQn = 18, /* ICU IRQ2 (External pin interrupt 2) */
    ICU_IRQ3_IRQn = 19, /* ICU IRQ3 (External pin interrupt 3) */
    ICU_IRQ4_IRQn = 20, /* ICU IRQ4 (External pin interrupt 4) */
    ICU_IRQ5_IRQn = 21, /* ICU IRQ5 (External pin interrupt 5) */
    ICU_IRQ6_IRQn = 22, /* ICU IRQ6 (External pin interrupt 6) */
    ICU_IRQ7_IRQn = 23, /* ICU IRQ7 (External pin interrupt 7) */
    ICU_IRQ8_IRQn = 24, /* ICU IRQ8 (External pin interrupt 8) */
    ICU_IRQ9_IRQn = 25, /* ICU IRQ9 (External pin interrupt 9) */
    ICU_IRQ10_IRQn = 26, /* ICU IRQ10 (External pin interrupt 10) */
    ICU_IRQ11_IRQn = 27, /* ICU IRQ11 (External pin interrupt 11) */
    ICU_IRQ12_IRQn = 28, /* ICU IRQ12 (External pin interrupt 12) */
    ICU_IRQ13_IRQn = 29, /* ICU IRQ13 (External pin interrupt 13) */
    ICU_IRQ14_IRQn = 30, /* ICU IRQ14 (External pin interrupt 14) */
    ICU_IRQ15_IRQn = 31, /* ICU IRQ15 (External pin interrupt 15) */
    SPI0_RXI_IRQn = 32, /* SPI0 RXI (Receive buffer full) */
    SPI0_TXI_IRQn = 33, /* SPI0 TXI (Transmit buffer empty) */
    SPI0_TEI_IRQn = 34, /* SPI0 TEI (Transmission complete event) */
    SPI0_ERI_IRQn = 35, /* SPI0 ERI (Error) */
    SPI1_RXI_IRQn = 36, /* SPI1 RXI (Receive buffer full) */
    SPI1_TXI_IRQn = 37, /* SPI1 TXI (Transmit buffer empty) */
    SPI1_TEI_IRQn = 38, /* SPI1 TEI (Transmission complete event) */
    SPI1_ERI_IRQn = 39, /* SPI1 ERI (Error) */
    IIC2_RXI_IRQn = 40, /* IIC2 RXI (Receive data full) */
    IIC2_TXI_IRQn = 41, /* IIC2 TXI (Transmit data empty) */
    IIC2_TEI_IRQn = 42, /* IIC2 TEI (Transmit end) */
    IIC2_ERI_IRQn = 43, /* IIC2 ERI (Transfer error) */
} IRQn_Type;
#endif /* VECTOR_DATA_H */
