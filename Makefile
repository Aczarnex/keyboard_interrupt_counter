obj-m += kic_module.o

KVERSION := $(shell uname -r)
PWD := $(CURDIR)

all: module kic run

module: keyboard_interrupt_counter.h kic_module.c
	make -C /lib/modules/$(KVERSION)/build M=$(PWD) modules

run: kic
	sudo insmod kic_module.ko

kic: keyboard_interrupt_counter.h kic_user.c
	gcc -o kic kic_user.c

clean:
	-sudo rmmod kic_module
	make -C /lib/modules/$(KVERSION)/build M=$(PWD) clean
	-rm -f kic
