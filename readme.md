# Trabalho T2 – Algoritmos e Programação (22760)

**Universidade do Vale do Itajaí**  
**Escola Politécnica – NID (Núcleo Integrado de Disciplinas)**  
**Data de entrega:** 20/05/2025 (até 23:59)  
**Modalidade:** Grupos com 4 integrantes

---

## Visão Geral

O **Mastermind** (no Brasil, *Senha*) é um jogo de tabuleiro inventado por **Mordechai Meirowitz** e distribuído inicialmente pela **Invicta Plastics**. Publicado em 1971, vendeu mais de 50 milhões de tabuleiros em 80 países, sendo o jogo mais bem-sucedido da década de 1970.

Atualmente, no Brasil é vendido pela **Grow**, com o tabuleiro preto e cinza, e pinos coloridos (azul, amarelo, verde, vermelho, rosa, roxo e laranja).  
Fonte: *Wikipedia, 2021*.

---

## Descrição do Jogo

- Pinos de **7 cores diferentes** (exceto preto e branco).
- Pinos **pretos e brancos são menores**, usados para feedback.
- O tabuleiro possui **10 fileiras com 4 buracos grandes** cada.
- Ao lado de cada fileira, um quadrado com **4 buracos menores**.
- A **décima primeira fileira** esconde a combinação correta (a senha).
- O desafiador monta a senha com **4 pinos sem repetição**.
- O desafiado tenta adivinhar a senha em até 10 tentativas.

### Regras dos pinos de feedback:

- **Pino branco:** cor correta, posição errada.
- **Pino preto:** cor e posição corretas.
- **Sem pino:** cor não está na senha.

Se o jogador errar as 10 tentativas, a senha é revelada. Se acertar, o desafiador coloca 4 pinos pretos.

---

## Regras para o Desenvolvimento

O jogo deverá apresentar um **menu** com as seguintes opções:

- **Jogar**
- **Sobre**
- **Sair**

---

### 🔹 Menu: Sair

- Encerra o programa.
- O jogo **só deve terminar** ao escolher esta opção.
- Outras opções retornam ao menu após execução.

---

### 🔹 Menu: Sobre

Deve exibir:
- Nome dos membros do grupo
- Mês e ano da entrega (ex: maio/2025)
- Nome do professor e da disciplina

---

### 🔹 Menu: Jogar

- O jogador deve descobrir uma **senha de 4 dígitos** entre **1 e 6**, sem repetições.
- São **10 tentativas** para acertar.

#### Após cada tentativa, informar:
- Número de tentativas restantes
- Quantos números estão corretos e na posição correta
- Quantos números estão corretos mas fora de posição

#### Final do jogo:
- Se acertar: informar vitória e retornar ao menu.
- Se errar 10 vezes: informar derrota e retornar ao menu.

---

## Dicas de Desenvolvimento

### Exemplo: uso de `rand()` e `srand()`:

```cpp
#include <cstdlib>
#include <ctime>

srand(time(NULL)); // Inicializa semente
int num = rand() % 6 + 1; // Número de 1 a 6
