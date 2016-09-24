
obj-m+=button.o

all:
		make -C /Store/Raspberry/linux-arm-build M=$(PWD) modules

clean:
		make -C /Store/Raspberry/linux-arm-build M=$(PWD) clean
