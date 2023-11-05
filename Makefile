hash:clean 
	@echo
	@echo ==========================
	@echo      TRABALHO HASH 
	@echo ==========================
	@echo Compilando o programa PictureHash
	@gcc -std=c99  -DLOG_USE_COLOR log.h log.c hash.h hash.c DoublyLinkedList.h DoublyLinkedList.c trabalhoHash.c  -o hash
	@echo Tornando o arquivo executável 
	@chmod +x hash
	@echo Executando o programa hash 
	@echo ======================================================
	@echo
	@./hash
TrabalhoHash: clean
	@echo "Compilando o programa TrabalhoHash"
	@gcc  HashDicionario.c HashDicionario.h -o TrabalhoHash
	@chmod +x TrabalhoHash
	@./TrabalhoHash
	@echo "===================================================================="
clean:
	@echo "===================================================================="
	@echo " Removendo os programas compilados							   "
	@echo "===================================================================="
	@rm -f ola
	@echo "===================================================================="
help:
	@echo "===================================================================="
	@echo "								AJUDA								   "
	@echo "===================================================================="
	@echo "help			| ajuda"
	@echo "ola			| executa mensagem de teste"
	@echo "clean		| apaga códigos compilados"