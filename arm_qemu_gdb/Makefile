all: qemuboot.bin qemuboot.elf

startup.o: startup.s
	@arm-none-eabi-as -g -mcpu=arm926ej-s startup.s -o startup.o

entry.o: entry.c
	@arm-none-eabi-gcc -c -g -mcpu=arm926ej-s entry.c -o entry.o

qemuboot.elf: qemuboot.ld startup.o entry.o
	@arm-none-eabi-ld -T qemuboot.ld entry.o startup.o -o qemuboot.elf

qemuboot.bin: qemuboot.elf
	@arm-none-eabi-objcopy -O binary qemuboot.elf qemuboot.bin

release: all
	@rm *.o

clean: 
	@rm *.o *.elf *.bin

# This section is for helper commands. Should prbably be in a script

arch: qemuboot.elf
	@arm-none-eabi-readelf -A qemuboot.elf

dump: qemuboot.elf
	@arm-none-eabi-objdump -d qemuboot.elf

qemu: qemuboot.bin
	@echo "Ctrl-a, x to quit"
	@qemu-system-arm -M versatilepb -m 128M -nographic -kernel qemuboot.bin

qemudebug: qemuboot.bin
	@qemu-system-arm -M versatilepb -m 128M -nographic -s -S -kernel qemuboot.bin

debug: qemuboot.elf
	@arm-none-eabi-gdb -tui -x qemu.gdbinit

