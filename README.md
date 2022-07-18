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
## Parâmetros da CLI:
  i: insert
  exemplo: i 2. Insere um nó com chave 2.
  r: remove
  exemplo: r 2. Remove a subárvore com chave 2.
  s: search
  exemplo: r 2. Busca a subárvore com chave 2.

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

