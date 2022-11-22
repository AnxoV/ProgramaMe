// https://www.aceptaelreto.com/problem/statement.php?id=540
function hueco_escalera(piso, escalones, pisosC, escalonesC) {
    return `${pisosC*escalones + escalonesC} ${piso*escalones + (pisosC*escalones + escalonesC)}`;
}

console.log(hueco_escalera(7, 18, 6, 5));
console.log(hueco_escalera(10, 10, 10, 0));