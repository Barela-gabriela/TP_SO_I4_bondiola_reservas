2 - Alfa clona el repositorio, crea una nueva rama, agrega sus datos y hace el push.

    git clone https://github.com/Barela-gabriela/TP_SO_I4_bondiola_
    git checkout -b Morel

(Agrega a datos.txt nombre y apellido, IP y hora)

    git add .
    git commit -m "Alfa modifica datos.txt"
    git push -u origin Morel

3 - Beta clona el repositorio, crea una nueva rama, agrega sus datos y hace el push.

    git clone https://github.com/Barela-gabriela/TP_SO_I4_bondiola_
    git checkout -b Passucci

(Agrega a datos.txt nombre y apellido, IP y hora)

    git add .
    git commit -m "Beta modifica datos.txt"
    git push -u origin Passucci

4 - Gamma intenta hacer el merge entre las ramas de Alfa y Beta en master pero se generan conflictos.

    git pull
    git merge origin/Morel origin/Passucci

(Se generan los conflictos y se procede a intentar corregirlos)

    git mergetool

(Se decide solo quedarse con el datos.txt de Beta)

    :diffg RE

(Se genera un error y no es posible realizar el merge, recurre a realizar merge cambiando un nombre de datos.txt)

    git checkout Morel datos.txt
    git show origin/Passucci:datos.txt > datos2.txt
    git add .
    git commit -m "Gamma hace merge desde ambas ramas"
    git push -u origin master

¿Se pueden mantener los dos datos? ¿Como?

La unica manera que conocemos de hacer merge de los datos de Alfa y Beta en master seria a partir de un cambio de nombre del datos.txt en cualquiera de las dos ramas (fue lo que se hizo en el punto 4).

En caso de querer todo en un mismo archivo, realizamos append a traves del comando git show:

    git checkout Morel datos.txt
    git show origin/Passucci:datos.txt >> datos.txt

¿Se pueden mantener los dos datos sólo de un ALFA o BETA? ¿Como?

Se haria un (git merge rama_deseada) de los datos que se quieran tener en el master. Tambien podria ser (git checkout nombre_rama nombre_archivo)
