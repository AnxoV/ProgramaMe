// https://www.aceptaelreto.com/problem/statement.php?id=293
function artropodos(numIns, numArac, numCrust, numEsc, numAn) {
    return 6*numIns + 8*numArac + 10*numCrust + 2*numAn*numEsc;
}

console.log(artropodos(1, 1, 1, 1, 15));
console.log(artropodos(2, 3, 1, 4, 52));