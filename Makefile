TrabalhoHash: clean
	@echo "Compilando o programa TrabalhoHash"
	@gcc  TrabalhoHash.c -o TrabalhoHash
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