volatile unsigned char * const UART0_PTR = (unsigned char *) 0x101f1000;

void print_uart0(const char *string)
{
    while (*string != '\0')
    {
        *UART0_PTR = *string;
        string++;
    }
}

int entry(void)
{
    int j = 7;
    print_uart0("Hello, world!\n");
    
    int i = 10;
    
    while (i > 0) {
        i--;
        j++;
    }
    
    print_uart0("Goodbye, cruel world!\n");
    
    return 0;
}
