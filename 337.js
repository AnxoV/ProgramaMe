// https://www.aceptaelreto.com/problem/statement.php?id=337
function abuelaMaria(dientes) {
    let d;
    let encajan = true;
    for (let i = 0; i < dientes[0].length && encajan; i++) {
        if (!d)
            d = dientes[0][i] + dientes[1][i];
        else if (d != dientes[0][i] + dientes[1][i])
            encajan = false;
    }
    return encajan;
}

console.log(abuelaMaria([
    [1, 3, 1, 3, 1, 3],
    [3, 1, 3, 1, 3, 1]
]));

console.log(abuelaMaria([
    [1, 1, 1, 1, 1, 2],
    [1, 2, 1, 1, 1, 1]
]));