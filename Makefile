
obj-m+=gpio_test.o

all:
		make -C /Store/Raspberry/linux-arm-build M=$(PWD) modules

clean:
		make -C /Store/Raspberry/linux-arm-build M=$(PWD) clean
