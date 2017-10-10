EDA - 2.2017

* __Diário de Atividades 01 (08/10/2017)__
  * Grupo:
		* @rafaelmakaha
		* (Inserir referência ao git do) renan
	* Leitura do roteiro do projeto;
  * Realizada listagem de requisitos;
	* Criado __Checklist de Requisitos__ a serem atendidos. *Os itens ainda não atendidos serão implementados de acordo com o andamento do projeto e estarão no início de cada __Diário de Atividades__*
  * Estudo do capítulo 4 do livro "Sistemas Operacionais Modernos";
	
  * __Lista de requisitos de Projeto__
    * Parâmetros de entrada: tamanho (KB) e tempo de execução;
    * Para cada entrada, inserir label de identificação;
    * Alocar na memória simulada de acordo com o tamanho;
    * Alocar do início para o final, onde couber (tamanho em __KB__);
      * Caso não caiba nos espaços disponíveis, reorganizar memória de modo a caber este processo;
			* Se ainda não houver espaço, __IMPRIMIR: NÃO FOI POSSÍVEL ALOCAR__;
		* Tempo de execução do processo é aleatório;
		* Encontrar maneira de simular tempo de execução e término do processo;
			* __SUGESTÃO__: Imprimir "*registro de entrada e saída de processos na memória*";
		* __DEVE SER CAPAZ__: Imprimir a qualquer momento posições ocupadas (P) e livres (H).
			* __SUGESTÃO__: Imaginar um grande vetor onde cada elemento corresponde a um KB;
		* __OPÇÕES__
		  1. Inicialização; *Ler dados de um Arquivo e continuar simulação*
			2. Inserir processo;
			3. Impressão de posições ocupadas e livres;
			4. e sair do programa; *Gravar dados em Arquivo*
		* Gerenciamento de espaços deve ser feito utilizando __LISTA CIRCULAR DUPLAMENTE ENCADEADA COM CABEÇALHO;__
			* Cada nó deve conter ao menos:
				1. Tipo de nó (Ocupado ou Livre);
				2. Posição inicial da memória;
				3. Tamanho da área livre;
				4. Tamanho da área ocupada;
				5. *Posição final da memória*;
		* __FINAL__: "*Caberá ao aluno definir estratégias para inserir processos na memória e realocar processos na memória*".

	* __Checklist de Requisitos__
		- [ ] Implementar lista circular duplamente encadeada com cabeçalho
		- [ ] Modularizar lista implementada
		- [ ] Inserir ENTRADA de parâmetros (processo: tamanho e tempo de execução)
		- [ ] Implementar menu com opções
		- [ ] Inserir label de identificação do processo
		- [ ] Requisito de alocação *De acordo com o tamanho*
		- [ ] Requisito de alocação *Do início para o final*
		- [ ] Exceção de alocação *Reorganizar lista*
		- [ ] Exceção de alocação *Não foi possível alocar*
		- [ ] Encontrar solução para simular tempo de execução e término do processo
		- [ ] Implementar solução p/ tempo de execução
		- [ ] Implementar printf com registro de entrada e saída
		- [ ] Implementar printf com áreas ocupadas (P) e livres (H)
		- [ ] Inserir opção SAÍDA de parâmetros
		- [ ] Inserir opção SAIR DO PROGRAMA
		- [ ] Inserir opção de inicialização *Deseja continuar simulação?*
		- [ ] Implementar abrir simulação em arquivo
		- [ ] Inserir opção de finalização *Deseja salvar simulação em __ARQUIVO__?*
		- [ ] Implementar gravar simulação em arquivo
