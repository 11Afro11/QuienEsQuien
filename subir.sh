#!/bin/bash
# Este script funciona de manera tal que al no proporcionarle argumentos, suguiere al usuario cuáles son las posibles opciones para su ejecución.
Error(){
echo "Error. No se proporcionaron argumentos. Las posibles opciones para la ejecución de este script son:"
echo "$0 nombre_archivo"
echo "$0 nombre_directorio"
}
if test $# -lt 1 # Si el número de parámetros posicionales o argumentos que se le dan al script es menor que 1, donde "-lt" significa "lower than" y es equivalente a lo que en otros lenguajes se utiliza como "<".
then
git add . 
git commit -m "pepeeeeee"
git push
elif test -d $1 # Si el parámetro posicional "$1" existe y es un directorio.
then
echo "$1 es un directorio."
elif test -f $1 # Si el parámetro posicional "$1" existe y es un archivo regular.
then
echo "$1 es un archivo."
else
echo "$1 no existe."
fi

Leer más: http://www.monografias.com/trabajos50/ejercicios-shell-script/ejercicios-shell-script2.shtml#ixzz3xEo7PuH3
