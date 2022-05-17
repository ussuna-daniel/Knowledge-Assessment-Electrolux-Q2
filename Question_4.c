*char dado_recebido;
*char delimitador;
short var_controle;

void interrupt()
{
if(UART0_IE)
  {
  UART0_IE = false;
  UART0_Interrupt(false);
  UART0_Read_Text(dado_recebido, delimitador); // Recebe a mensagem até encontrar um delimitador
  
  switch(dado_recebido)
    {
     case "Texto1":
          var_controle = 1;
          break ;

     case "Texto2":
          var_controle = 2;
          break;

     case "Texto3":
          var_controle = 3;
          break;
    }
  UART0_Interrupt(true);
  }
}

void main() {
UART0_Init(115200);
UART0_Interrupt(true); // Habilita interrupção da Uart0 Método Genérico
var_controle = 0;

while(1)
  {
  // Código Principal
  
  switch(var_controle)
    {
     case 1:
          funcao1();
          break ;

     case 2:
          funcao2();
          break;

     case 3:
          funcao3();
          break;
          
     default:
     break;
    }
  }

}