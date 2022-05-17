#define BOTAO GPIO_PORTH_AHB_DATA.B0
#define SAIDA GPIO_PORTH_AHB_DATA.B1

// Este código Alterna a saída entre ON e OFF a cada vez que o botão é pressionado e em cada uma dessas ações o botão fica desabilitado por 10 segundos, mesmo que pressionado não gera mudança de estado da saída.
/*Considera-se a aplicação de um microcontrolador que tenha interrupçoes e também que os registradores das interrupçoes e dos I/Os são configurados adequadamente dentro das funções genéricas apresentadas pelos protótipos de funções*/

void gpio_Digital_Init();// Inicializa I/Os Digitais (define Entradas e Saídas)
void gpio_Interrupt_Init(); // Inicializa Interrupção de mudança de estado da porta onde o botão está conectado e de Timer
void Ativa_Interrupcao_MEP(bit status_Imep); // Ativa interrupção de Mudança de estado do port onde o botão está instalado com argumento 0 ou 1 para ativação ou não da interrupção
void Ativa_Interrupcao_TMR0(bit status_Itmr0); // Ativa interrupção de TIMER0 com argumento 0 ou 1 para ativação ou não da interrupção
void Carrega_Valor_de_Contagem_TMR0_Para_10segundos(); // Definição genérica que necessita de avaliar tempos de máquina para chegar nesse valor de tempo;

void Interrupt(){
if(TMR0_IE == true) // Avalia Flag da interrupção de Timer se entrou aqui é porque estourou a contagem de 10 segundos
  {
  TMR0_IE = false;
  Ativa_Interrupcao_TMR0(false);
  Ativa_Interrupcao_MEP(true);
  }
else if(MEP_IE == true) // Avalia Flag da interrupção de Mudança de estado do port do botão (Código genérico dado ser necessário conhecer o Microcontrolador aplicado)
  {
  MEP_IE = false;
  SAIDA = !SAIDA; // Muda de estado anterior da saída
  Carrega_Valor_de_Contagem_TMR0_Para_10segundos(); 
  Ativa_Interrupcao_TMR0(true);
  Ativa_Interrupcao_MEP(false);
  }
}

void main() {
// Primeira vez que o código é iniciado se da prioridade a atender os botão
Ativa_Interrupcao_TMR0(false);
Ativa_Interrupcao_MEP(true);

  while(1)
  {
  //Todo o código principal

  }

}
