# MovieInfo
Projeto em C++ que acessa OMDb-API para pesquisa de filmes.

Requisitos:

	Instalar a biblioteca cURL
	$ sudo apt install curl libcurl4-openssl-dev

Compilação:

    Makefile nas pastas:
    /movieinfo/Lib/src
    /movieinfo/MovieInfo/src

    Todo projeto pode ser compilado pelo makefile da pasta: /movieinfo/MovieInfo/src
    Exemplo: ~/Projetos/movieinfo/MovieInfo/src$ make 

Execução:

    Exibir o help: ./movieinfo -h

        Usage: movieinfo [-s <movie>]
        or: movieinfo [-s <movie>] [-t <type>]
        or: movieinfo [-a <movie>]
        or: movieinfo [-a <movie>] [-t <type>]
        or: movieinfo [-h]

        Options:
        -s, --search  movie title to search for.
        -a, --all     all movie title to search for.
        -t, --type    type of result to return. (movie, series or episode).
        -h, --help    give this help list.

    Exemplos:
            $./movieinfo -s Batman -t movie
            $./movieinfo -a Batman -t series
            $./movieinfo -search Titanic
    
