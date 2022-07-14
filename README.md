# Trabalho - 3ª Unidade

Repositório contendo as especificações do Trabalho da 3ª unidade da disciplina de Estrutura de Dados Básica II.

# Pastas e especificações

- ``src`` - Contém todos os arquivos ``.cpp``;
- ``include`` - Contém todos os arquivos ``.hpp``;
- ``data/in`` - Contém os arquivos com as chaves a serem inseridas, removidas ou buscadas em ordem;
- ``build`` - Contém o ``Makefile``, o binário ``calc`` e todos os outros arquivos que o ``cmake`` cria.

# Como compilar o projeto

  ```
  cmake -B build
  cmake --build build
  ```

# Como executar o projeto
 Para uma execução padrão, execute:
  ```
  ./build/avltree
  ```

 O programa irá te guiar por um prompt. Exemplo:

  ```
  O que desejas fazer? [I: inserir, R: remover, B: buscar]
  I
  4
  "Printa a árvore com um nó com a chave 4."
  B
  4
  Verdadeiro. Existe nó com essa chave.
  "Printa árvore com nó destacado."
  R
  4
  "Printa árvore vazia."
  B
  4
  Falso. Não existe nó com essa chave.
  "Printa árvore"
  R
  5
  O nó 5 não existe! Não é possível remover.
  ```

  Ou execute informando o arquivo.

  ```
  ./build/avltree data/in/data.in
  ```
  
  Por exemplo.

## Especificação
  O projeto é compilado usando as seguintes "flags" de compilação
  -g
  -Wall
  -Werror
  -Wextra
  -Wpedantic
  -ansi
  -Ofast
  -fsanitize=address,undefined
  -lm

## Observações
 As expressões contidas em data.in tem os seus números e suas operações separadas por um espaço, possibilitando, assim, a escrita de números com mais de um dígito.

 Exemplo de arquivo data.in

 ```
  I4 B4 R4 B4 R5 I7 I7
  B3 I456 B123 R314 B71 R5 I7
 ```
