KERNELDIR ?=/lib/modules/$(shell uname -r)/build
#KERNELDIR ?=/home/linux/Exynos4412/linux-3.14-fs4412

module:
	$(MAKE)  -C $(KERNELDIR)  M=$(shell pwd)  modules
	sudo  cp   *.ko  /source/rootfs
clean:
	$(MAKE)  -C $(KERNELDIR)  M=$(shell pwd)  clean

obj-m := vnet.o

