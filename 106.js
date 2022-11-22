// https://www.aceptaelreto.com/problem/statement.php?id=106
function codigoBarras(barcode) {
    barcode = String(barcode);
    let reverse = Array.from(barcode, Number).reverse().slice(1);
    let sum = 0;
    for (let i = 0; i < reverse.length; i++) {
        sum += (i % 2 == 0) ? reverse[i]*3 : reverse[i];
    }

    let result = "SI";
    if (barcode[barcode.length-1] != (((sum / 1) % 10 == 0) ? 0 : 10 - ((sum / 1) % 10))) {
        result = "NO";
    }
        
    if (barcode.length == 13 && result != "NO") {
        let countries = {
            "0": "EEUU",
            "380": "Bulgaria",
            "50": "Inglaterra",
            "539": "Irlanda",
            "560": "Portugal",
            "70": "Noruega",
            "759": "Venezuela",
            "850": "Cuba",
            "890": "India"
        }

        let known = false;
        for (let i = 0; i < Object.keys(countries).length && !known; i++) {
            if (barcode.startsWith(Object.keys(countries)[i])) {

                known = true;
                result += " " + countries[Object.keys(countries)[i]];
            }
        }
        if (!known) {
            result += " Desconocido";
        }
    }

    return result;
}

console.log(codigoBarras(65839522));
console.log(codigoBarras(65839521));
console.log(codigoBarras(8414533043847));
console.log(codigoBarras(5029365779425));
console.log(codigoBarras(5129365779425));