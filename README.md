# Estudo C++

## Compilação e linking

Para gerar as unidades de tradução (objetos) separaramente, processo de __compilação__, executar o comando abaixo:

Para todos os arquivos:

```bash
g++ -c *.cpp
```

Ou indicando um arquivo em específico:

```bash
g++ -c jogo.cpp
```

## Linking

Agora para linkar esses objetos e resultar em um executável:

```bash
g++ *.o -o jogo.exe
```

Para executar ambos os processos ao mesmo tempo:

```bash
g++ *.cpp -o jogo.exe
```

Desta forma é possível modificar um arquivo em específico __.cpp__, gerar seu objeto compilado __.o__, realizar o link para um executável, sem necessariamente recompilar todo os demais arquivos, pois o processo de compilação que gera o __.o__ é a etapa mais demorada.
