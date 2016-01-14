#!/bin/bash
# Este script funciona de manera tal que al no proporcionarle argumentos, suguiere al usuario cuáles son las posibles opciones para su ejecución.
git add . 
if test $# -lt 1 # Si el número de parámetros posicionales o argumentos que se le dan al script es menor que 1, donde "-lt" significa "lower than" y es equivalente a lo que en otros lenguajes se utiliza como "<".
then
git commit -m "pepeeeeee"
else
git commit -m "$1"
fi
git push

Leer más: http://www.monografias.com/trabajos50/ejercicios-shell-script/ejercicios-shell-script2.shtml#ixzz3xEo7PuH3
