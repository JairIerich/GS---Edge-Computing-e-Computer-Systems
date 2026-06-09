# GS---Edge-Computing-e-Computer-Systems
Projeto Arduino para monitoramento e controle automático de temperatura e umidade em estufa, utilizando DHT22, LCD I2C, relé, buzzer e ventilação automática (Wokwi).


# Sistema Inteligente de Monitoramento para Estufa

## Descrição do Projeto

Este projeto consiste em um sistema automatizado para monitoramento de **temperatura e umidade** em uma estufa agrícola.  
Utilizando sensores e atuadores conectados ao Arduino, o sistema realiza leituras em tempo real e toma decisões automáticas para manter o ambiente dentro das condições ideais para o cultivo.

---

## Objetivo da Solução

O sistema foi desenvolvido para:

- Monitorar continuamente temperatura e umidade do ambiente
- Alertar o usuário quando os valores estiverem fora da faixa ideal
- Acionar automaticamente a ventilação quando necessário
- Exibir informações em tempo real em um display LCD
- Simular o funcionamento de uma estufa inteligente no Wokwi

---

## Componentes Utilizados

| Componente              | Quantidade |
|------------------------|------------|
| Arduino Uno           | 1          |
| Sensor DHT22          | 1          |
| Display LCD I2C 16x2  | 1          |
| Servo Motor           | 1          |
| Relé                  | 1          |
| LED Vermelho          | 1          |
| Buzzer                | 1          |
| Resistores            | Conforme necessário |
| Jumpers               | Conforme necessário |

---

## Estrutura do Circuito

### Ligações principais:

- DHT22 → Pino Digital 2  
- Servo Motor → Pino Digital 6  
- LED → Pino Digital 7  
- Relé → Pino Digital 8  
- Buzzer → Pino Digital 9  

### LCD I2C:
- SDA → A4  
- SCL → A5  

---

## Funcionamento do Sistema

O sistema realiza leitura contínua da temperatura e umidade e executa ações automáticas:

### Temperatura Alta (> 30°C)
- LED aceso  
- Buzzer ativado  
- Relé acionado  
- Ventilação ligada (servo motor)

### Temperatura Baixa (< 18°C)
- LED aceso  
- Buzzer ativado  
- Ventilação desligada  

### Umidade Alta (> 80%)
- LED aceso  
- Buzzer ativado  
- Relé acionado  
- Ventilação ligada  

### Umidade Baixa (< 50%)
- LED aceso  
- Buzzer ativado  
- Ventilação desligada  

### Ambiente Normal
Quando os valores estão dentro das faixas ideais:

- Temperatura entre 18°C e 30°C  
- Umidade entre 50% e 80%  

O sistema mantém:

- LED desligado  
- Buzzer desligado  
- Ventilação desligada  
- Mensagem **"AMBIENTE OK"** exibida no LCD  

---

## Como Executar o Projeto

### Wokwi

1. Abra o projeto no Wokwi  
2. Inicie a simulação  
3. Altere os valores do sensor DHT22  
4. Observe as respostas do sistema  

### Testes

- Temperatura < 18°C → frio  
- Temperatura > 30°C → quente  
- Umidade < 50% → baixa  
- Umidade > 80% → alta  

---

## Observações

O servo motor foi utilizado para simular um ventilador, devido às limitações do Wokwi.  
Em um sistema real, seria utilizado um ventilador alimentado externamente e controlado via relé.

No projeto tem mais um pouco de documentação, onde lá é repassado mais diretamente o que tem aqui.

---

## Integrantes do Grupo

- Jair Ierich – RM569524  
- Maria Gabriela – RM569047  
- Vicente de Souza – RM569205  
- Felipe Marialva – RM569031  
- Bianca Veloso – RM572036  

---

## Links do Projeto

- Simulação no Wokwi:  
  https://wokwi.com/projects/465305675393366017

- Repositório no GitHub:  
  https://github.com/JairIerich/GS---Edge-Computing-e-Computer-Systems/

---

## 📊 Conclusão

Este projeto demonstra um sistema de automação simples aplicado à agricultura inteligente, integrando sensores, atuadores e lógica de controle para manter um ambiente ideal para cultivo.
