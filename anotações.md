# Progrma de simplificação de tons de cinza

## Algoritimo de escolhas das cores

os tons de cinza variam entre 0 - 255, então, primeiro eu preciso definir um vetor de tamanho N que vai armazenar as nossas cores BASES

### a formula é: 

```
int cores[n];
int intervalo = 255/n;
int contador = 0;

for(int i; i < n; i++){
  cores[i] = contador;
  contador += intervalo;
}
```

## Algoritimo de verificação de proximidade das cores

fazer um algoritimo que verifique a cor mais proxima da forma mais eficiente possivel

a minha ideia é percorrer elemento por elemento do vetor de cores bases e verificar se a cor passada pra função é maior ou menor doq o a metade entre o elemento atual do vetor e o proximo.

### exemplo
```
c[3] = [0,10,20]
```
```
numero 4


    meio
0---4|----10---------20
^         ^
|         |
c[o]     c[1]

4 é menor que o meio(que é 4), ou seja, o seu valor novo será 0
```
```
numero 7


    meio
0----|-7--10---------20
^         ^
|         |
c[o]     c[1]

o numero 7 é maior que o meio e menor que 10, logo, seu novo valor é 10 
```

e esse ciclo de verificações continua até percorrer por todo o vetor de cores base


## trocar as cores da matriz original pela cor mais proxima

essa é a mais facil, é só eu pegar o resultado da função de descobrir a cor mais proxima no valor da matriz simplificada
