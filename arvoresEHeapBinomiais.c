//Arvore enraizada = quando possui raiz (diferente dos outros (maior, menor, etc))
//Grau = número de filhos de um nó (grau da raiz é no máximo 2)
//Profundidade = comprimento entre r e um nó x
//Altura é a maior pronfundidade entre r e um nó

//As arvores binomiais são feitas por meio da junção de outras arvores binomiais ->

//propriedades ->
//2^k nós;
//altura = k;
//(k i) = nós na profundidade
// raiz tem o maior grau da árvore;
//se fizermos os filhos da aárvore binomial ser numerados da esquerda para a direita,então o filho é a raiz da árvore b1;

//heap binomial -> é um conjunto de árvores binomiais que satisfazem as seguintes propriedades:
//Cada nó possui uma chave
//cada árvore deve ser um heap minimo
//0 <= k <= lg n (lg = log2 n) [k indica o nível, n indica o número de nós dessa] (só podemos ter uma árvore de cada tipo)

//representação binária indica quantas arvores necessárias e quais devem ser útilizadas
// 13 = 1101
// b3 b2 b1 b0 [arvores binomiais]
// 1  1  0  1

//listas encadeadas
//os graus das raizes aumentam conforme percorremos as raizes (pq aumentamos a arvore binomial)
//
//

//união => juntar sempre as da entrada quando possível (if nivelAt1 == nivelAt2 -> junta entrada e bota na saida; else (if (nivelAt1 or 2 == nivelSaida) -> junta entrada e saida))
//Bj =>
// 0 ->
// 1 ->
// 2 ->
// 3 ->

//para inserir, criar uma nova heap b0 e fazer a união

//para remover o menor elemento, encontrar esse e dividir a arvore que ele era a raiz e depois fazer a únião

void minHeapBin(); //O(lg n)