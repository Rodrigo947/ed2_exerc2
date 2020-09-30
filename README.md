[![Work in Repl.it](https://classroom.github.com/assets/work-in-replit-14baed9a392b3a25080506f3b7b6d57f295ec2978f6f33ec97e36a161684cbe9.svg)](https://classroom.github.com/online_ide?assignment_repo_id=3273457&assignment_repo_type=AssignmentRepo)
# Tabela Hash

Implementação Tabela hash

**Objetivos:**
mplementar uma tabela hash com encadeamento separado e comparar as diferentes funções hash em relação a distribuição uniforme nos dados na tabela e números de colisões.

**Funções Hash:**
 
- Método da divisão
- Método da multiplicação 
 
Nesta atividade,  você deve fazer:
 
1. Implementar um tipo abstrato de dados hash com encadeamento separado, com as seguintes rotinas implementadas:
 - *create(m, hash)*: Cria uma tabela de tamanho m que usa a função hash
 - *insert(key,data)*: Insere *data* com chave *key* na tabela. A função deve retornar um ponteiro para o elemento inserido. Se *data* já existir, retorna-se um ponteiro para ele. 
 - *lookup(key,data)*: Pesquisa se data com chave *key* está na tabela. Se estiver, retorna ponteiro para *data*, caso contrário retorne NULL.
 - *destroy()*: Remova a tabela hash da memória.
 
2. Implemente as funções hash acima de modo a ser usado no tipo abstrato. Implemente também uma versão alternativa para as duas hash mencionadas acima, denominada *MinhaHash*.
3. Contabilize todas as colisões ocorridas nas inserções de dados na tabela ao usar uma determinada função hash.
4. Para uma mesma função hash, forneça uma entrada aleatória de inteiros. Teste a mesma entrada para diferentes tamanhos m. Considere fazer testes com valores de m com características relevantes (primos, não-primos, potências de 2 ...)

[![Run on Repl.it](https://repl.it/badge/github/ufjfcamata/dcc012_hash1)](https://repl.it/github/ufjfcamata/dcc012_hash1)

