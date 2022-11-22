// https://www.aceptaelreto.com/problem/statement.php?id=621
function pagina(num) {
    return (num % 2 == 0) ? num+1 : num-1;
}

console.log(pagina(2));
console.log(pagina(10));
console.log(pagina(11));
console.log(pagina(1000));