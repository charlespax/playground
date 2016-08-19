target remote localhost:1234
file qemuboot.elf
define go
continue
info locals
end
break startup.s:1
break entry.c:14
break entry.c:20
continue
