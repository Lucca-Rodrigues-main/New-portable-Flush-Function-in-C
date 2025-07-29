# New-portable-Flush-Function-in-C
The best portable C solution for input buffer issues. The Flush() function safely clears stdin without undefined behavior, replacing problematic approaches like fflush(stdin).

---

## 1. Segue abaixo uma breve introdução sobre alguns conceitos:

### **O que são dados formatados?**
- **Definição:** Organização de informações conforme especificações pré-definidas (geralmente para processamento computacional).
- **Em C:** Funções como `scanf()` foram projetadas para ler entrada formatada (*scan formatted input*).

---

### **Problemas com `scanf()`**
- **Objetivo original:** Ler entrada formatada (ex: arquivos estruturados), **não** entrada do teclado (que é livre).
- **Riscos:**
  - Não valida a entrada — usuário pode digitar qualquer coisa (105+ teclas de liberdade).
  - Pode corromper memória se a entrada não corresponder ao esperado.
  - Retorna um `int` (número de itens lidos) — ignorar esse retorno é um erro comum.
- **Uso prático:**
  - Pode ser útil em casos controlados, mas **não** é adequado para aplicações robustas que exigem validação.

---

### **"Lixo" no teclado?**
- Não existe "lixo" — a entrada é *free form*: o programa deve tratar qualquer input do usuário.
- O teclado permite qualquer combinação de teclas — a responsabilidade de filtrar é do desenvolvedor.

---

### **`fflush(stdin)` é inválido**
- `fflush()` só é definido para streams de **saída** (ex: `stdout`).
- Usar em `stdin` gera *undefined behavior* (UB) — pode funcionar em alguns compiladores, mas é não-portável.

---

### **`setbuf(stdin, NULL)` ou `setbuf(stdin, 0)` não resolvem**
- `setbuf()` não foi projetado para limpar buffers de entrada.
- Buffers de entrada são gerenciados pelo sistema — tentativas de "zerá-los" são ineficazes.
- Necessidade disso geralmente indica mistura inadequada de operações de entrada/saída.

---

## 2. Solução Proposta: Função `Flush()`
A função `Flush()` foi feita para resolver os problemas de buffer de entrada de maneira portável e segura:

### Como Funciona:
1. **`ungetc()`**: Insere um espaço virtual no buffer para garantir que haja algo a ser lido;
2. **Loop `fgetc()`**: Lê todos os caracteres até encontrar uma quebra de linha ou EOF;
3. **Portabilidade**: Funciona em qualquer sistema compatível com C padrão.

### Vantagens:
- Elimina problemas com dados residuais no buffer.
- Não poderá gerar comportamentos indefinidos.
- Solução limpa e reutilizável.
- Mantém a portabilidade do código.

## Exemplo de utilização
Um programador inexperiente poderia ler um inteiro e, logo em sequência, um caractere. Um `\n` ficará restante na stdin após a primeira chamada da `scanf()`, que poderia ser lido na segunda chamada se não houvesse uma chamada intermediara da `Flush()`. É claro que terceirizar o trabalho de lidar com o `\n` restante no buffer de entrada nem sempre é a melhor opção, e para isso o repositório https://github.com/Lucca-Rodrigues-main/Best-Scanf-Usage-in-C oferece mecânicas similares, mas implementadas diretamente no escopo das novas funções sugeridas.

<img width="163" height="145" alt="image" src="https://github.com/user-attachments/assets/d1e46aca-023a-47ba-b40d-b61fc297380b" />
