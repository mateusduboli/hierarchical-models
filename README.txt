Instruções:

- Compilação

É necessário ter instalada a última versão do OpenGL, juntamente on o freeglut.

No arquivo 'Makefile', altere as duas primeiras linhas, caso necessário para apontar para o diretório onde se encontram as libs e os includes do opengl.

Ex:

LDFLAGS= -L'/usr/lib'
CFLAGS= -I'/usr/include'

O programa foi compilado utilizando OSX 10.9, então é possível que esses caminhos sejam diferentes.

Para compilar simplesmente utilize o comando 'make'

- Rodando

Para rodar o programa utilize o comando 'make run' ou rode o binário 'model'

- Comandos

'Setas' = Movimentam a câmera
'q'     = Fecha o programa
'w'     = Inicia movimento de andar
'r'     = Inicia movimento de empinar
