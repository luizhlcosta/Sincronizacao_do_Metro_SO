# 🚇 Sincronização do Metrô

Projeto desenvolvido para a disciplina de **Infraestrutura de Software — CESAR School**, utilizando a linguagem C e a biblioteca POSIX Threads (Pthreads).

## Descrição

O programa simula o embarque de passageiros em uma estação de metrô, utilizando threads para representar passageiros e vagões.

A sincronização é realizada por meio de mutexes e variáveis de condição, garantindo o controle da capacidade dos vagões e a conclusão dos embarques antes da partida.

## Arquivos do projeto

| Arquivo | Descrição |
|---|---|
| `src/sync_car.c` | Implementa as funções de sincronização da estação, controlando a chegada dos vagões, a espera dos passageiros e os embarques. |
| `src/sync_car.h` | Define a estrutura `station` e declara as funções utilizadas na implementação. |
| `tests/sync_car-runner.c` | Código de testes fornecido pelo professor, responsável por simular passageiros e vagões concorrentes e verificar o funcionamento da sincronização. |
| `Makefile` | Automatiza a compilação do programa e a remoção do executável. |
| `evidencias.log` | Registra as compilações e execuções realizadas durante o desenvolvimento. |

## Ambiente de desenvolvimento

- **Sistema operacional:** Ubuntu 24.04 LTS, executado pelo WSL no Windows 11.
- **Linguagem:** C
- **Compilador:** GCC
- **Bibliotecas:** POSIX Threads (Pthreads)
- **Ferramentas:** Make e Visual Studio Code

## Compilação

No terminal Ubuntu, acesse a pasta raiz do projeto e execute:

```bash
make
```

O comando compila os arquivos `src/sync_car.c` e `tests/sync_car-runner.c`, gerando o executável `sync_car`.

## Execução e testes

Para executar o teste oficial fornecido pelo professor:

```bash
./sync_car
```

Para executar com um limite de 10 segundos:

```bash
timeout 10s ./sync_car
```

Uma execução bem-sucedida apresenta a mensagem `Looks good!`.

Para repetir o teste 30 vezes:

```bash
for i in $(seq 1 30); do
    echo "Teste $i"
    timeout 10s ./sync_car || echo "Falha no teste $i"
done
```

Para remover o executável gerado:

```bash
make clean
```

## Registro de evidências

As compilações e execuções podem ser registradas utilizando:

```bash
script -a -f evidencias.log
```

Após executar os testes, utilize `exit` para encerrar o registro.

---

**Disciplina:** Infraestrutura de Software  
**Instituição:** CESAR School