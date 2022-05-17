#define BOTAO GPIO_PORTH_AHB_DATA.B0
#define SAIDA GPIO_PORTH_AHB_DATA.B1

// Este c�digo Alterna a sa�da entre ON e OFF a cada vez que o bot�o � pressionado e em cada uma dessas a��es o bot�o fica desabilitado por 10 segundos, mesmo que pressionado n�o gera mudan�a de estado da sa�da.
/*Considera-se a aplica��o de um microcontrolador que tenha interrup�oes e tamb�m que os registradores das interrup�oes e dos I/Os s�o configurados adequadamente dentro das fun��es gen�ricas apresentadas pelos prot�tipos de fun��es*/

void gpio_Digital_Init();// Inicializa I/Os Digitais (define Entradas e Sa�das)
void gpio_Interrupt_Init(); // Inicializa Interrup��o de mudan�a de estado da porta onde o bot�o est� conectado e de Timer
void Ativa_Interrupcao_MEP(bit status_Imep); // Ativa interrup��o de Mudan�a de estado do port onde o bot�o est� instalado com argumento 0 ou 1 para ativa��o ou n�o da interrup��o
void Ativa_Interrupcao_TMR0(bit status_Itmr0); // Ativa interrup��o de TIMER0 com argumento 0 ou 1 para ativa��o ou n�o da interrup��o
void Carrega_Valor_de_Contagem_TMR0_Para_10segundos();

void Interrupt(){
if(TMR0_IE == true) // Avalia Flag da interrup��o de Timer se entrou aqui � porque estourou a contagem de 10 segundos
  {
  TMR0_IE = false;
  Ativa_Interrupcao_TMR0(false);
  Ativa_Interrupcao_MEP(true);
  }
else if(MEP_IE == true) // Avalia Flag da interrup��o de Mudan�a de estado do port do bot�o (C�digo gen�rico dado ser necess�rio conhecer o Microcontrolador aplicado)
  {
  MEP_IE = false;
  SAIDA = !SAIDA; // Muda de estado anterior da sa�da
  Carrega_Valor_de_Contagem_TMR0_Para_10segundos(); // Defini��o gen�rica que necessita de avaliar tempos de m�quinas para chegar nesse tempo;
  Ativa_Interrupcao_TMR0(true);
  Ativa_Interrupcao_MEP(false);
  }
}

void main() {
// Primeira vez que o c�digo � iniciado se da prioridade a atender os bot�o
Ativa_Interrupcao_TMR0(false);
Ativa_Interrupcao_MEP(true);

  while(1)
  {
  //Todo o c�digo principal

  }

}