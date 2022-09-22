/*
  buggy.ino - Aplicação exemplo para o buggy 4x4
  
  - Exibe os dados dos sensores pelo terminal UART 9600 bps.
  - Recebe comandos da serial para movimentação dos motores.
  
  Created by Renan Augusto Starke, July 26, 2021.  
  Released into the public domain.
*/


#include "Motores.h"
#include "Linha.h"

/* Tarefas básicas do exemplo */
void tarefa_1();
void tarefa_2();
volatile bool exibir_estado = true;

/* Instâncias das classe dos sensores/atuadores */
Motores motores;
Linha linha;

/* Configuração e mensagem inicial */
void setup() {
  
  Serial.begin(9600);
  while (!Serial); 

  Serial.println("Teste buggy 4x4");
  Serial.println("F: mover para frente");
  Serial.println("B: mover para trás");
  Serial.println("L: mover para esquerda");
  Serial.println("R: mover para direita");  
  Serial.println("S: parar o carro");

  delay(5000);  

}

/* Loop de atualização do sensores e das tarefas */
void loop() {

  tarefa_1();
  tarefa_2();
}

/* Tarefa 2: comandos da serial */
void tarefa_1(){

  /* Caso tenha recebido algum dado do PC */
  if (Serial.available()) {
     char dado_recebido = Serial.read();
     
      if (dado_recebido == 'S'){
          motores.parar();
      }          
      else if (dado_recebido == 'F')
          motores.frente(250);      
      else if (dado_recebido == 'B')
          motores.tras(200);      
      else if (dado_recebido == 'L')
          motores.esquerda(150);          
      else if (dado_recebido == 'R')
          motores.direita(150);        
      }

  }

void tarefa_2(){
  static unsigned long tempo_atual = 0;

  /* Escalonamento a cada 1s. Se ativado a exibição */
  if ((exibir_estado) && (millis() - tempo_atual >= 1000)){
    
//    Serial.print(baterias.obter_bateria_0());
//    Serial.print("\t");
//    Serial.print(baterias.obter_bateria_1());
//    Serial.print("\t");
//    Serial.print(encoder_0.obter_velocidade());
//    Serial.print("\t");
//    Serial.print(ultrassom_1.obter_distancia());
//    Serial.print("\t");
    Serial.print(linha.obter_esquerda());
    Serial.print("\t");
    Serial.print(linha.obter_direita());
    
    Serial.println("");
    
    tempo_atual = millis();    
  }  
}
