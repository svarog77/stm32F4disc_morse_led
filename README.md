# stm32F4disc_morse_led
### Краткое описание

В этом проекте демонстрируется передача строки символов в виде азубки Морзе, используя светодиод PD12 на отладочной плате STM32F4Discovery. Также настроим и включим USART1. Для отладки проекта будем использовать QEMU+GDB. 
### Демонстрация работы
Запустим в консоли QEMU с параметрами: 
#### qemu-system-arm -M netduinoplus2 -kernel stm32F4disc_morse_led.elf -gdb tcp::5555 -S
![](https://github.com/svarog77/stm32F4disc_morse_led/blob/main/Doc/2025-07-02_17-40-17.png)

Затем в другой консоли запустим отладчик gdb с параметрами:  
#### arm-none-eabi-gdb stm32F4disc_morse_led.elf. 
Подключимся к localhost: 
#### (gdb)target remote localhost:5555
Запустим проект:
#### (gdb) load
#### (gdb) b main
#### (gdb) c
![](https://github.com/svarog77/stm32F4disc_morse_led/blob/main/Doc/2025-07-02_17-41-04.png)

Проверим работу в эмуляторе.

![](https://github.com/svarog77/stm32F4disc_morse_led/blob/main/Doc/2025-07-02_17-42-00.png)
