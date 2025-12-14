# 🧩 8-Puzzle em C com Inteligência Artificial

Este projeto implementa o clássico **quebra-cabeça 8-Puzzle**, onde o objetivo é organizar os números de **1 a 8** em ordem crescente, deixando o espaço vazio (**0**) na última posição.

O projeto foi totalmente desenvolvido em **C** e permite tanto **jogo manual** quanto **resolução automática utilizando algoritmos de busca (IA)**.

---

## 🎮 Modos de Execução

Ao iniciar o programa, o usuário pode escolher entre:

1. 🎲 **Jogar manualmente**
2. 🤖 **Busca em Largura (BFS)**
3. 🧠 **Busca em Profundidade Limitada (DFS limitada)**
4. ❌ **Sair**

---

## 🚀 Funcionalidades

* 🔄 Geração automática de tabuleiros **sempre solucionáveis**
* 🎹 Movimentação manual das peças pelo usuário
* 🤖 Resolução automática usando:

  * **Busca em Largura (BFS)**
  * **Busca em Profundidade Limitada**
* 🧠 Reconstrução e impressão do **caminho da solução**
* 📊 Contador de **estados visitados**
* 🖥️ Interface simples via **console**
* 📚 Uso de **estruturas de dados**:

  * Pilha
  * Fila
  * Árvores implícitas de estados

---

## 🧠 Algoritmos Utilizados

### 🔹 Busca em Largura (BFS)

* Garante encontrar a **solução mais curta**
* Explora todos os estados nível a nível
* Usa uma **fila** para controle dos nós

### 🔹 Busca em Profundidade Limitada

* Explora caminhos em profundidade até um **limite definido**
* Usa **pilha**
* Evita loops através do controle de profundidade

---

## 📂 Estrutura do Projeto

```
📦 8-puzzle-c
├── main.c        # Contém toda a implementação do jogo, estruturas e algoritmos de busca
└── README.md     # Documentação do projeto
```

---

## ▶️ Como Compilar e Executar

### 1️⃣ Compilar

```bash
gcc main.c -o puzzle
```

### 2️⃣ Executar

```bash
./puzzle
```

> ⚠️ **Observação**
> O código utiliza `system("cls")`, que funciona no **Windows**.
> Em Linux ou macOS, substitua por:
>
> ```c
> system("clear");
> ```

---

## 🎮 Controles (Modo Manual)

Digite o **número da peça** que deseja mover (desde que esteja adjacente ao espaço vazio).

Exemplo de estado final esperado:

```
1 2 3
4 5 6
7 8 _
```

---

## 🧩 Estruturas de Dados Principais

### 🔹 Estrutura `No`

Representa um estado do puzzle:

* Matriz 3×3 do tabuleiro
* Ponteiro para o pai (reconstrução do caminho)
* Profundidade do nó
* Ponteiro para próximo nó

### 🔹 Pilha

Usada na **Busca em Profundidade Limitada**

### 🔹 Fila

Usada na **Busca em Largura**

---

## 🛠️ Funções Principais

* `gerar_puzzle_inicial()` – gera um puzzle aleatório solucionável
* `imprimir_puzzle()` – imprime o tabuleiro no console
* `funcao_suc()` – gera estados sucessores
* `busca_em_largura()` – resolve usando BFS
* `busca_profundidade_limitada()` – resolve usando DFS limitada
* `imprime_caminho()` – exibe o passo a passo da solução
* `completo()` – verifica se o puzzle está resolvido

---

## 🏁 Finalização

Quando o puzzle é resolvido, o programa exibe:

* Número de estados visitados
* Passo a passo completo da solução
* Mensagem de sucesso 🎉

---
## 🇺🇸 (English Version)


➡️ **([English Version](README.en.md))**

---
## 👨‍💻 Autor

**Felipe Salinas Caodaglio**


