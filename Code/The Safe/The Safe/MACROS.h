#ifndef MACROS_H_
#define MACROS_H_

#define REGISTER_SIZE 8
#define ENABLE 1
#define DISABLE 0
#define OUTPUT 1
#define INPUT 0
#define PIN0 0
#define PIN1 1
#define PIN2 2
#define PIN3 3
#define PIN4 4
#define PIN5 5
#define PIN6 6
#define PIN7 7
#define SET_BIT(reg, bit) (reg |= (1 << bit))
#define CLR_BIT(reg, bit) (reg &= (~(1 << bit)))
#define TOG_BIT(reg, bit) (reg ^= (1 << bit))
#define READ_BIT(reg, bit) ((reg & (1 << bit)) >> bit)


#endif /* MACROS_H_ */