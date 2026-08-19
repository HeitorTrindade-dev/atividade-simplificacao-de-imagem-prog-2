# Programa de Simplificação de Tons de Cinza

Este projeto tem como objetivo **reduzir a quantidade de tons de cinza de uma imagem**, substituindo cada tom original por um dos tons definidos em uma paleta de cores base.

Os tons de cinza variam de **0 a 255**, onde:

* `0` representa preto;
* `255` representa branco;
* os valores entre eles representam os diferentes tons de cinza.

A ideia é escolher uma quantidade `N` de cores base e substituir cada pixel da imagem pela cor base mais próxima.

---

## 1. Algoritmo de escolha das cores base

Primeiro, é necessário definir um vetor de tamanho `N` que armazenará as **cores base** que serão utilizadas para simplificar a imagem.

Por exemplo, se escolhermos `N = 7`, podemos ter uma paleta semelhante a:

```text
0, 42, 84, 126, 168, 210, 252
```

Uma primeira abordagem para gerar esse vetor é dividir o intervalo de `0` a `255` em `N` partes:

```c
int cores[n];
int intervalo = 255 / n;
int contador = 0;

for (int i = 0; i < n; i++) {
    cores[i] = contador;
    contador += intervalo;
}
```

Cada posição do vetor representa uma das cores que poderão ser utilizadas na imagem simplificada.

> **Observação:** se for necessário garantir que `255` seja uma das cores base, o intervalo pode ser calculado considerando `N - 1` divisões, ou cada posição pode ser calculada proporcionalmente ao intervalo `0–255`.

---

## 2. Algoritmo de verificação da proximidade das cores

Depois de definir as cores base, é necessário descobrir **qual delas é mais próxima de uma determinada cor original**.

A ideia é percorrer o vetor de cores base e verificar se a cor recebida pela função está antes ou depois do **ponto médio entre duas cores consecutivas**.

### Exemplo

Considere:

```text
c = [0, 10, 20]
```

Queremos descobrir qual cor representa melhor o número `4`.

O ponto médio entre `0` e `10` é:

```text
(0 + 10) / 2 = 5
```

Visualmente:

```text
0---------5---------10----------------20
^                   ^
|                   |
c[0]                c[1]
```

Como `4` é menor que `5`, ele está mais próximo de `0`.

Portanto:

```text
4 → 0
```

---

### Outro exemplo

Agora queremos descobrir qual cor representa melhor o número `7`.

O ponto médio continua sendo `5`:

```text
0---------5----7----10----------------20
^                   ^
|                   |
c[0]                c[1]
```

Como `7` é maior que `5`, mas ainda é menor que `10`, ele está mais próximo de `10`.

Portanto:

```text
7 → 10
```

---

### Continuando o processo

Esse processo continua para cada par de cores consecutivas do vetor.

Por exemplo:

```text
cores = [0, 10, 20, 30]
```

Os pontos médios seriam:

```text
0 ---- 5 ---- 10 ---- 15 ---- 20 ---- 25 ---- 30
      ↑             ↑             ↑
    limite         limite        limite
```

Assim, cada intervalo determina qual cor base deve representar os valores daquela região.

A função pode ser implementada percorrendo o vetor até encontrar o intervalo correspondente.

---

## 3. Substituição das cores da matriz

Depois de descobrir qual é a cor base mais próxima, basta substituir o valor original da matriz pelo resultado da função.

A lógica é:

```text
matriz_original[i][j]
        ↓
descobrirCorMaisProxima()
        ↓
matriz_simplificada[i][j]
```

Por exemplo, supondo:

```text
matriz_original[i][j] = 73
```

e que as cores base sejam:

```text
0, 42, 84, 126, 168, 210, 252
```

Como `73` está mais próximo de `84` do que de `42`:

```text
73 → 84
```

Então:

```c
matriz_simplificada[i][j] =
    descobrirCorMaisProxima(matriz_original[i][j]);
```

Esse processo é repetido para **todos os elementos da matriz**, produzindo uma nova matriz contendo apenas as cores base escolhidas.

---

## Fluxo do algoritmo

O funcionamento completo pode ser resumido da seguinte forma:

```text
Imagem / Matriz original
          │
          ▼
   Definir quantidade N
          │
          ▼
    Gerar cores base
          │
          ▼
 Para cada pixel da matriz
          │
          ▼
 Encontrar cor base mais próxima
          │
          ▼
Substituir pixel pela cor encontrada
          │
          ▼
  Matriz simplificada
```

O objetivo final é transformar uma imagem que pode possuir **256 tons diferentes de cinza** em uma imagem contendo apenas `N` tons, mantendo os valores originais o mais próximo possível das cores disponíveis na paleta.
