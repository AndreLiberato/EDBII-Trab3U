# Trabalho - 3ª Unidade

Repositório contendo as especificações do Trabalho da 3ª unidade da disciplina de Estrutura de Dados Básica II.

# Pastas e especificações

- ``src`` - Contém todos os arquivos ``.cpp``;
- ``include`` - Contém todos os arquivos ``.hpp``;
- ``data/in`` - Contém os arquivos com as expressões posfixas e prefixas (opcional) de entrada;
- ``data/out`` - Contém os arquivos com as expressões prefixas, infixas e com os resultados aritméticos das expressões;
- ``build`` - Contém o ``Makefile``, o binário ``calc`` e todos os outros arquivos que o ``cmake`` cria.

# Como compilar o projeto

  ```
  cmake -B build
  cmake --build build
  ```
 
# Como executar o projeto
 Para uma execução padrão, execute:
  ```
  ./build/calc
  ```
 Para uma execução verbosa, ou seja, que mostra todos os processos incluindo o diagrama da árvore criada, execute:
 ``
  ./build/calc --verbose
  ``
  ou
  ```
  ./build/calc -v
  ```
## Especificação
  O projeto é complicado usando as seguintes flags de compilação
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
 As expressões contidas em posfix.in tem os seus números e suas operações separadas por um espaço, possibilitando, assim, a escrita de números com mais de um dígito.
